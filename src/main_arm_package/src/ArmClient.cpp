#include "rclcpp_action/rclcpp_action.hpp"
#include "action_interfaces/action/move_arm.hpp"
#include "rclcpp/rclcpp.hpp"
#include "action_interfaces/msg/arm_command.hpp"
#include "action_interfaces/msg/arm_state.hpp"
#include "action_interfaces/srv/check_limits.hpp"


using MoveArm = action_interfaces::action::MoveArm;
using GoalHandle = rclcpp_action::ClientGoalHandle<MoveArm>;

class ArmClient: public rclcpp::Node{
    public:
       ArmClient(float a1, float a2): Node("arm_client"){
        RCLCPP_INFO(this->get_logger(), "ArmClient node has been started.");
        client_check_ = this->create_client<action_interfaces::srv::CheckLimits>("check_limits");
        client_action_ = rclcpp_action::create_client<action_interfaces::action::MoveArm>(this, "move_arm");

        wanted_shoulder_angle_ = a1;
        wanted_elbow_angle_ = a2;

        options_ = rclcpp_action::Client<action_interfaces::action::MoveArm>::SendGoalOptions();
        options_.feedback_callback = [this](GoalHandle::SharedPtr, const std::shared_ptr<const action_interfaces::action::MoveArm::Feedback> feedback){
            RCLCPP_INFO(this->get_logger(), "Current: shoulder:%f, elbow:%f)", feedback->shoulder_angle_fb, feedback->elbow_angle_fb);
        };
        options_.result_callback = [this](const GoalHandle::WrappedResult & result){
            switch(result.code){
                case rclcpp_action::ResultCode::SUCCEEDED:
                    RCLCPP_INFO(this->get_logger(), "Goal succeeded with new angles shoulder: %f, elbow: %f)", result.result->shoulder_angle_rs, result.result->elbow_angle_rs);
                    break;
                case rclcpp_action::ResultCode::ABORTED:
                    RCLCPP_INFO(this->get_logger(), "Goal was aborted");
                    break;
                case rclcpp_action::ResultCode::CANCELED:
                    RCLCPP_INFO(this->get_logger(), "Goal was canceled");
                    break;
                default:
                    RCLCPP_INFO(this->get_logger(), "Unknown result code");
            }
        };

        while(!client_action_->wait_for_action_server(std::chrono::seconds(1))){
            RCLCPP_INFO(this->get_logger(), "Waiting for action server...");
        }

        this->callMoveSequence();

       } 

       void callMoveSequence(){
        auto request = std::make_shared<action_interfaces::srv::CheckLimits::Request>();
        request->shoulder_angle = wanted_shoulder_angle_;
        request->elbow_angle = wanted_elbow_angle_;

        while(!client_check_->wait_for_service(std::chrono::seconds(1))){
            if(!rclcpp::ok()){
                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Service not available, waiting again...");
        }

        auto future_check = client_check_->async_send_request(request, [this](rclcpp::Client<action_interfaces::srv::CheckLimits>::SharedFuture future){
            auto response = future.get();
            if(response->is_safe){
                RCLCPP_INFO(this->get_logger(), "Arm angles are within limits, sending action goal...");
                this->sendMoveArmGoal(wanted_shoulder_angle_, wanted_elbow_angle_);
            } else {
                RCLCPP_WARN(this->get_logger(), "Arm angles are out of bounds, cannot send action goal.");
            }
        });
        
       }

       void sendMoveArmGoal(float angleSH, float angleEL){
         while(!client_action_->wait_for_action_server(std::chrono::seconds(1))){
            RCLCPP_INFO(this->get_logger(), "Waiting for action server...");
         }

        auto goal_msg = MoveArm::Goal();
        goal_msg.shoulder_angle_goal = angleSH;
        goal_msg.elbow_angle_goal = angleEL;
        client_action_->async_send_goal(goal_msg, options_);
       }

    private:
    float wanted_shoulder_angle_;
    float wanted_elbow_angle_;
    rclcpp_action::Client<action_interfaces::action::MoveArm>::SharedPtr client_action_;
    rclcpp::Client<action_interfaces::srv::CheckLimits>::SharedPtr client_check_;
    rclcpp_action::Client<action_interfaces::action::MoveArm>::SendGoalOptions options_;
};

int main(int argc, char** argv){
    if(argc != 3){
        printf("Usage: ros2 run main_arm_package ArmClient <shoulder_angle> <elbow_angle>\n");
        return 1;
    }
    float shoulder = std::stof(argv[1]);
    float elbow = std::stof(argv[2]);
    rclcpp::init(argc, argv);
    auto arm_client_node = std::make_shared<ArmClient>(shoulder, elbow);
    rclcpp::spin(arm_client_node);
    rclcpp::shutdown();
    return 0;
}