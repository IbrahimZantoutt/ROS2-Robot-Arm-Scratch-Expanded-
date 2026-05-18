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
       ArmClient(float x, float y, float z, char elbow_config): Node("arm_client"){
        RCLCPP_INFO(this->get_logger(), "ArmClient node has been started.");
        client_action_ = rclcpp_action::create_client<action_interfaces::action::MoveArm>(this, "move_arm");

        X_ = x;
        Y_ = y;
        Z_ = z;
        elbow_config_ = elbow_config;

        options_ = rclcpp_action::Client<action_interfaces::action::MoveArm>::SendGoalOptions();
        options_.feedback_callback = [this](GoalHandle::SharedPtr, const std::shared_ptr<const action_interfaces::action::MoveArm::Feedback> feedback){
            RCLCPP_INFO(this->get_logger(), "Current: shoulder:%f, elbow:%f, wrist:%f, spin:%f)", feedback->shoulder_angle_fb, feedback->elbow_angle_fb, feedback->wrist_angle_fb, feedback->spin_angle_fb);
        };
        options_.result_callback = [this](const GoalHandle::WrappedResult & result){
            switch(result.code){
                case rclcpp_action::ResultCode::SUCCEEDED:
                    RCLCPP_INFO(this->get_logger(), "Goal succeeded with new angles shoulder: %f, elbow: %f , wrist: %f , spin: %f)", result.result->shoulder_angle_rs, result.result->elbow_angle_rs,  result.result->wrist_angle_rs,  result.result->spin_angle_rs);
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
            this->sendMoveArmGoal(X_, Y_, Z_);
        };

       void sendMoveArmGoal(float tarX, float tarY, float tarZ){
         while(!client_action_->wait_for_action_server(std::chrono::seconds(1))){
            RCLCPP_INFO(this->get_logger(), "Waiting for action server...");
         }

        auto goal_msg = MoveArm::Goal();
        goal_msg.target_x = tarX;
        goal_msg.target_y = tarY;
        goal_msg.target_z = tarZ;
        if(elbow_config_ == 'U' || elbow_config_ == 'u'){
            goal_msg.configuration = "elbow_up";
        } else {
            goal_msg.configuration = "elbow_down";
        }
        client_action_->async_send_goal(goal_msg, options_);
       }

    private:
    float X_;
    float Y_;
    float Z_;
    char elbow_config_;
    rclcpp_action::Client<action_interfaces::action::MoveArm>::SharedPtr client_action_;
    rclcpp_action::Client<action_interfaces::action::MoveArm>::SendGoalOptions options_;
    
};

int main(int argc, char** argv){
    if(argc < 3 || argc > 5){
        printf("Usage: ros2 run main_arm_package ArmClient <target_x> <target_y> [target_z] [U/D]\n");
        printf("  target_z defaults to 0.18 (shoulder height) if not specified\n");
        printf("  elbow: U=elbow_up, D=elbow_down (default)\n");
        return 1;
    }
    float x = std::stof(argv[1]);
    float y = std::stof(argv[2]);
    float z = (argc >= 4) ? std::stof(argv[3]) : 0.18f;
    char El = (argc == 5) ? argv[4][0] : 'D';
    rclcpp::init(argc, argv);
    auto arm_client_node = std::make_shared<ArmClient>(x, y, z, El);
    rclcpp::spin(arm_client_node);
    rclcpp::shutdown();
    return 0;
}