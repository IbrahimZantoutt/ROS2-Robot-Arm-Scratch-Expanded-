#include "rclcpp_action/rclcpp_action.hpp"
#include "action_interfaces/action/move_arm.hpp"
#include "rclcpp/rclcpp.hpp"
#include "action_interfaces/msg/arm_command.hpp"
#include "action_interfaces/msg/arm_state.hpp"
#include <thread>


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


        }

        rclcpp_action::GoalResponse handleGoal(const rclcpp_action::GoalUUID& uuid,std::shared_ptr<const MoveArm::Goal> goal){
            RCLCPP_INFO(this->get_logger(), "Received goal request with target Shoulder: %f deg  Elbow: %f deg", goal->shoulder_angle_goal, goal->elbow_angle_goal);
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

            float goalSA = goal_handle->get_goal()->shoulder_angle_goal;
            float goalEA = goal_handle->get_goal()->elbow_angle_goal;
            float goalWA = goal_handle->get_goal()->wrist_angle_goal;

            float shoulder, elbow, wrist;
            {
                std::lock_guard<std::mutex> lock(angle_mutex_);
                shoulder = current_angle_shoulder_;
                elbow = current_angle_elbow_;
                wrist = current_angle_wrist_;
            }
            
            while(std::abs(shoulder - goalSA) > 0.01 || std::abs(elbow - goalEA) > 0.01 || std::abs(wrist - goalWA) > 0.01){
                if(goal_handle->is_canceling()){
                    goal_handle->canceled(result);
                    RCLCPP_INFO(this->get_logger(), "Goal canceled");
                    return;
                }

                auto command_msg = action_interfaces::msg::ArmCommand();
                if(std::abs(shoulder - goalSA) > 0.01){
                    if(shoulder < goalSA){
                        command_msg.shoulder_angle_cmd = shoulder + 1.0;
                    } else {
                        command_msg.shoulder_angle_cmd = shoulder - 1.0;
                    }
                }
                else{
                    command_msg.shoulder_angle_cmd = shoulder;
                }
                
                if(std::abs(elbow - goalEA) > 0.01){
                    if(elbow < goalEA){
                        command_msg.elbow_angle_cmd = elbow + 1.0;
                    } else {
                        command_msg.elbow_angle_cmd = elbow - 1.0;
                    }
                }
                else{
                    command_msg.elbow_angle_cmd = elbow;
                }

                if(std::abs(wrist - goalWA) > 0.01){
                    if(wrist < goalWA){
                        command_msg.wrist_angle_cmd = wrist + 1.0;
                    } else {
                        command_msg.wrist_angle_cmd = wrist - 1.0;
                    }
                }
                else{
                    command_msg.wrist_angle_cmd = wrist;
                }

                arm_command_publisher_->publish(command_msg);

                shoulder = command_msg.shoulder_angle_cmd;
                elbow   = command_msg.elbow_angle_cmd;
                wrist   = command_msg.wrist_angle_cmd;

                feedback->shoulder_angle_fb = shoulder;
                feedback->elbow_angle_fb = elbow;
                feedback->wrist_angle_fb = wrist;
                goal_handle->publish_feedback(feedback);

                rclcpp::sleep_for(std::chrono::milliseconds(100));
            }
            result->shoulder_angle_rs = current_angle_shoulder_;
            result->elbow_angle_rs = current_angle_elbow_;
            result->wrist_angle_rs = current_angle_wrist_;
            goal_handle->succeed(result);
            RCLCPP_INFO(this->get_logger(), "Goal succeeded");
        }


    private:
        rclcpp::Publisher<action_interfaces::msg::ArmCommand>::SharedPtr arm_command_publisher_;
        rclcpp_action::Server<action_interfaces::action::MoveArm>::SharedPtr arm_server_;
        rclcpp::Subscription<action_interfaces::msg::ArmState>::SharedPtr arm_state_subscription_;


        std::mutex angle_mutex_;

        float current_angle_shoulder_;
        float current_angle_elbow_;
        float current_angle_wrist_;

        void handleArmState(const action_interfaces::msg::ArmState::SharedPtr msg){
            std::lock_guard<std::mutex> lock(angle_mutex_);
            current_angle_shoulder_ = msg->shoulder_angle;
            current_angle_elbow_ = msg->elbow_angle;
            current_angle_wrist_ = msg->wrist_angle;
        }
};

int main(int argc, char** argv){
    rclcpp::init(argc,argv);
    auto arm_mover_node = std::make_shared<ArmMover>();
    rclcpp::spin(arm_mover_node);
    rclcpp::shutdown();
    return 0;
}