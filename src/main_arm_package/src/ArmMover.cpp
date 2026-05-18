#include "rclcpp_action/rclcpp_action.hpp"
#include "action_interfaces/action/move_arm.hpp"
#include "rclcpp/rclcpp.hpp"
#include "action_interfaces/msg/arm_command.hpp"
#include "action_interfaces/msg/arm_state.hpp"
#include <thread>
#include <future>
#include <cmath>
#include "action_interfaces/srv/check_limits.hpp"



struct ArmSolution {
    double spin;
    double shoulder;
    double elbow;
    double wrist;
    bool valid;
    std::string config;
};

class ArmMover: public rclcpp::Node{
    public:
        using MoveArm = action_interfaces::action::MoveArm;
        using GoalHandle = rclcpp_action::ServerGoalHandle<MoveArm>;
        ArmMover(): Node("arm_mover"){
            RCLCPP_INFO(this->get_logger(), "ArmMover node has been started.");
            arm_command_publisher_ = this->create_publisher<action_interfaces::msg::ArmCommand>("arm_command", 10);

            arm_state_subscription_ = this->create_subscription<action_interfaces::msg::ArmState>("arm_state", 10, std::bind(&ArmMover::handleArmState, this, std::placeholders::_1));

            arm_server_ = rclcpp_action::create_server<action_interfaces::action::MoveArm>(
                this,
                "move_arm",
                std::bind(&ArmMover::handleGoal, this, std::placeholders::_1, std::placeholders::_2),
                std::bind(&ArmMover::handleCancel, this, std::placeholders::_1),
                std::bind(&ArmMover::handleAccepted, this, std::placeholders::_1)
            );

            client_check_ = this->create_client<action_interfaces::srv::CheckLimits>("check_limits");


        }

        rclcpp_action::GoalResponse handleGoal(const rclcpp_action::GoalUUID& uuid,std::shared_ptr<const MoveArm::Goal> goal){
            RCLCPP_INFO(this->get_logger(), "Received goal request with target x: %f, y: %f, z: %f", goal->target_x, goal->target_y, goal->target_z);
            (void)uuid;
            return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
        }
        rclcpp_action::CancelResponse handleCancel(const std::shared_ptr<GoalHandle> goal_handle){
            RCLCPP_INFO(this->get_logger(), "Received cancel request");
            (void)goal_handle;
            return rclcpp_action::CancelResponse::ACCEPT;
        }
        void handleAccepted(const std::shared_ptr<GoalHandle> goal_handle){
            std::thread{[this, goal_handle](){ execute(goal_handle); }}.detach();
        }

        void execute(const std::shared_ptr<GoalHandle> goal_handle){
            RCLCPP_INFO(this->get_logger(),  "Executing goal");
            auto feedback = std::make_shared<MoveArm::Feedback>();
            auto result = std::make_shared<MoveArm::Result>();

            bool elbow_up = (goal_handle->get_goal()->configuration == "elbow_up");
            ArmSolution ik_solution = solveIK(goal_handle->get_goal()->target_x, goal_handle->get_goal()->target_y, goal_handle->get_goal()->target_z, elbow_up);
            if(!ik_solution.valid){
                RCLCPP_ERROR(this->get_logger(), "Target position is unreachable");
                goal_handle->abort(result);
                return;
            }

            float goalSA = ik_solution.shoulder;
            float goalEA = ik_solution.elbow;
            float goalWA = ik_solution.wrist;
            float goalSpA = ik_solution.spin;

            float shoulder, elbow, wrist, spin;
            {
                std::lock_guard<std::mutex> lock(angle_mutex_);
                shoulder = current_angle_shoulder_;
                elbow = current_angle_elbow_;
                wrist = current_angle_wrist_;
                spin = current_angle_spin_;
            }
            
            while(std::abs(shoulder - goalSA) > 0.01 || std::abs(elbow - goalEA) > 0.01 || std::abs(wrist - goalWA) > 0.01 || std::abs(spin - goalSpA) > 0.01){
                if(goal_handle->is_canceling()){
                    goal_handle->canceled(result);
                    RCLCPP_INFO(this->get_logger(), "Goal canceled");
                    return;
                }

                auto command_msg = action_interfaces::msg::ArmCommand();
                auto step_toward = [](float current, float goal) -> float {
                    float diff = goal - current;
                    if(std::abs(diff) <= 0.01f) return current;
                    float step = std::min(1.0f, std::abs(diff));
                    return current + (diff > 0 ? step : -step);
                };

                command_msg.shoulder_angle_cmd = step_toward(shoulder, goalSA);
                command_msg.elbow_angle_cmd    = step_toward(elbow,    goalEA);
                command_msg.wrist_angle_cmd    = step_toward(wrist,    goalWA);
                command_msg.spin_angle_cmd     = step_toward(spin,     goalSpA);

                arm_command_publisher_->publish(command_msg);

                shoulder = command_msg.shoulder_angle_cmd;
                elbow   = command_msg.elbow_angle_cmd;
                wrist   = command_msg.wrist_angle_cmd;
                spin   = command_msg.spin_angle_cmd;

                feedback->shoulder_angle_fb = shoulder;
                feedback->elbow_angle_fb = elbow;
                feedback->wrist_angle_fb = wrist;
                feedback->spin_angle_fb = spin;
                goal_handle->publish_feedback(feedback);

                rclcpp::sleep_for(std::chrono::milliseconds(100));
            }
            {
                std::lock_guard<std::mutex> lock(angle_mutex_);
                result->shoulder_angle_rs = current_angle_shoulder_;
                result->elbow_angle_rs = current_angle_elbow_;
                result->wrist_angle_rs = current_angle_wrist_;
                result->spin_angle_rs = current_angle_spin_;
            }
            goal_handle->succeed(result);
            RCLCPP_INFO(this->get_logger(), "Goal succeeded");
        }


        ArmSolution solveIK(double target_x, double target_y, double target_z, bool elbow_up){
            double spin = std::atan2(target_y, target_x);

            double r = std::sqrt(target_x*target_x + target_y*target_y);

            double r_adj = r - L3_;  // wrist points straight horizontally toward target
            double z_adj = target_z - z_shoulder_;

            double dist2 = r_adj*r_adj + z_adj*z_adj;
            double D = (dist2 - L1_*L1_ - L2_*L2_) / (2*L1_*L2_);
            if (std::abs(D) > 1.0) return {0,0,0,0, false, ""};  // unreachable

            double sign = elbow_up ? 1.0 : -1.0;
            double elbow = std::atan2(sign * std::sqrt(1.0 - D*D), D);

            double shoulder = std::atan2(z_adj, r_adj) - std::atan2(L2_ * std::sin(elbow), L1_ + L2_ * std::cos(elbow));

            double wrist_angle = 0.0;

            double wrist = wrist_angle - shoulder - elbow;

            // IK angles are from horizontal; URDF joints measure from vertical (0° = arm up).
            // Convert: shoulder_URDF = 90 - shoulder_IK, elbow/wrist URDF = -IK
            double spin_deg     =  spin                     * 180.0 / M_PI;
            double shoulder_deg = (M_PI / 2.0 - shoulder)  * 180.0 / M_PI;
            double elbow_deg    = -elbow                    * 180.0 / M_PI;
            double wrist_deg    = -wrist                    * 180.0 / M_PI;

            if(checkLimits(spin_deg, shoulder_deg, elbow_deg, wrist_deg)){
                RCLCPP_INFO(this->get_logger(), "IK solution found: Shoulder: %f deg  Elbow: %f deg  Wrist: %f deg  Spin: %f deg", shoulder_deg, elbow_deg, wrist_deg, spin_deg);
                return {spin_deg, shoulder_deg, elbow_deg, wrist_deg, true, elbow_up ? "elbow_up" : "elbow_down"};
            } else {
                RCLCPP_WARN(this->get_logger(), "IK solution is out of limits: Shoulder: %f deg  Elbow: %f deg  Wrist: %f deg  Spin: %f deg", shoulder_deg, elbow_deg, wrist_deg, spin_deg);
                return {0, 0, 0, 0, false, ""};
            }
        }

        bool checkLimits(float spin, float shoulder, float elbow, float wrist){
            auto request = std::make_shared<action_interfaces::srv::CheckLimits::Request>();
            request->spin_angle = spin;
            request->shoulder_angle = shoulder;
            request->elbow_angle = elbow;
            request->wrist_angle = wrist;

            auto promise = std::make_shared<std::promise<bool>>();
            auto future = promise->get_future();

            client_check_->async_send_request(request,
                [promise](rclcpp::Client<action_interfaces::srv::CheckLimits>::SharedFuture f){
                    promise->set_value(f.get()->is_safe);
                });

            return future.get(); 
        }



    private:
        rclcpp::Publisher<action_interfaces::msg::ArmCommand>::SharedPtr arm_command_publisher_;
        rclcpp_action::Server<action_interfaces::action::MoveArm>::SharedPtr arm_server_;
        rclcpp::Subscription<action_interfaces::msg::ArmState>::SharedPtr arm_state_subscription_;

        rclcpp::Client<action_interfaces::srv::CheckLimits>::SharedPtr client_check_;

        std::mutex angle_mutex_;

        float current_angle_shoulder_ = 0.0f;
        float current_angle_elbow_ = 0.0f;
        float current_angle_wrist_ = 0.0f;
        float current_angle_spin_ = 0.0f;

        float L1_ = 0.39;       // shoulder_arm_joint(0.04) + elbow_main_joint(0.35)
        float L2_ = 0.355;      // elbow_arm_joint(0.035) + wrist_main_joint(0.32)
        float L3_ = 0.18;       // wrist_arm_joint(0.005) + cylinder tip(0.175)
        float z_shoulder_ = 0.18f; // spin_main(0.06) + spin_arm(0.02) + shoulder_main(0.10)

        void handleArmState(const action_interfaces::msg::ArmState::SharedPtr msg){
            std::lock_guard<std::mutex> lock(angle_mutex_);
            current_angle_shoulder_ = msg->shoulder_angle;
            current_angle_elbow_ = msg->elbow_angle;
            current_angle_wrist_ = msg->wrist_angle;
            current_angle_spin_ = msg->spin_angle;
        }
};

int main(int argc, char** argv){
    rclcpp::init(argc,argv);
    auto arm_mover_node = std::make_shared<ArmMover>();
    rclcpp::spin(arm_mover_node);
    rclcpp::shutdown();
    return 0;
}