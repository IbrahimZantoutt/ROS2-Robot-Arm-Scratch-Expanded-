#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "action_interfaces/action/move_arm.hpp"


using MoveArm = action_interfaces::action::MoveArm;
using GoalHandle = rclcpp_action::ClientGoalHandle<MoveArm>;

class TaskPlanner: public rclcpp::Node{

    public:
    TaskPlanner(): Node("task_planner"){
        RCLCPP_INFO(this->get_logger(), "TaskPlanner node has been started.");

        client_action_ = rclcpp_action::create_client<action_interfaces::action::MoveArm>(this, "move_arm");
        // X_pickup_ = x;
        // Y_pickup_ = y;
        // Z_pickup_ = z;

        // X_drop_ = x;
        // Y_drop_ = y;
        // Z_drop_ = z;

        options_ = rclcpp_action::Client<action_interfaces::action::MoveArm>::SendGoalOptions();
        options_.feedback_callback = [this](GoalHandle::SharedPtr, const std::shared_ptr<const action_interfaces::action::MoveArm::Feedback> feedback){
            RCLCPP_INFO(this->get_logger(), "Current: shoulder:%f, elbow:%f, wrist:%f, spin:%f)", feedback->shoulder_angle_fb, feedback->elbow_angle_fb, feedback->wrist_angle_fb, feedback->spin_angle_fb);
        };
        options_.result_callback = [this](const GoalHandle::WrappedResult & result){
            switch(result.code){
                case rclcpp_action::ResultCode::SUCCEEDED:
                    RCLCPP_INFO(this->get_logger(), "Goal succeeded with new angles shoulder: %f, elbow: %f , wrist: %f , spin: %f)", result.result->shoulder_angle_rs, result.result->elbow_angle_rs,  result.result->wrist_angle_rs,  result.result->spin_angle_rs);
                    //grip command example
                    publishGripCommand(grip_command_);
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

}