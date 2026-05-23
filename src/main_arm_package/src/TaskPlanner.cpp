#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "action_interfaces/action/move_arm.hpp"
#include "action_interfaces/msg/grip_command.hpp"

using MoveArm = action_interfaces::action::MoveArm;
using GoalHandle = rclcpp_action::ClientGoalHandle<MoveArm>;

class TaskPlanner : public rclcpp::Node {

public:
    TaskPlanner() : Node("task_planner") {
        RCLCPP_INFO(this->get_logger(), "TaskPlanner node has been started.");

        grip_command_publisher_ = this->create_publisher<action_interfaces::msg::GripCommand>("grip_command", 10);

        client_action_ = rclcpp_action::create_client<MoveArm>(this, "move_arm");

        options_.feedback_callback = [this](GoalHandle::SharedPtr, const std::shared_ptr<const MoveArm::Feedback> feedback) {
            RCLCPP_INFO(this->get_logger(), "Current: shoulder:%f, elbow:%f, wrist:%f, spin:%f",
                feedback->shoulder_angle_fb, feedback->elbow_angle_fb,
                feedback->wrist_angle_fb, feedback->spin_angle_fb);
        };

        options_.result_callback = [this](const GoalHandle::WrappedResult & result) {
            if (result.code != rclcpp_action::ResultCode::SUCCEEDED) {
                RCLCPP_INFO(this->get_logger(), "Goal did not succeed — aborting task");
                return;
            }
            if (phase_ == Phase::MOVING_TO_PICK) {
                RCLCPP_INFO(this->get_logger(), "Reached pick position — closing grip");
                publishGripCommand("close");
                phase_ = Phase::MOVING_TO_DROP;
                sendMoveArmGoal(drop_x_, drop_y_, drop_z_);
            } else if (phase_ == Phase::MOVING_TO_DROP) {
                RCLCPP_INFO(this->get_logger(), "Reached drop position — opening grip");
                publishGripCommand("open");
                phase_ = Phase::DONE;
                RCLCPP_INFO(this->get_logger(), "Task complete");
            }
        };

        while (!client_action_->wait_for_action_server(std::chrono::seconds(1))) {
            RCLCPP_INFO(this->get_logger(), "Waiting for action server...");
        }

        // Pick box1 at world (0.8, 0, 0.265); drop on box3 at world (-0.8, 0, top=0.25)
        publishGripCommand("open");
        callMoveSequence(0.8f, 0.0f, 0.265f, -0.8f, 0.0f, 0.28f);
    }

    void callMoveSequence(float px, float py, float pz, float dx, float dy, float dz) {
        drop_x_ = dx;
        drop_y_ = dy;
        drop_z_ = dz;
        phase_ = Phase::MOVING_TO_PICK;
        sendMoveArmGoal(px, py, pz);
    }

    void sendMoveArmGoal(float tarX, float tarY, float tarZ) {
        auto goal_msg = MoveArm::Goal();
        goal_msg.target_x = tarX;
        goal_msg.target_y = tarY;
        goal_msg.target_z = tarZ;
        goal_msg.configuration = (elbow_config_ == 'U' || elbow_config_ == 'u') ? "elbow_up" : "elbow_down";
        client_action_->async_send_goal(goal_msg, options_);
    }

    void publishGripCommand(const std::string & command) {
        auto msg = action_interfaces::msg::GripCommand();
        msg.grip_command = command;
        grip_command_publisher_->publish(msg);
    }

private:
    enum class Phase { MOVING_TO_PICK, MOVING_TO_DROP, DONE };

    Phase phase_ = Phase::MOVING_TO_PICK;
    float drop_x_ = 0.0f, drop_y_ = 0.0f, drop_z_ = 0.0f;
    char elbow_config_ = 'D';

    rclcpp_action::Client<MoveArm>::SharedPtr client_action_;
    rclcpp_action::Client<MoveArm>::SendGoalOptions options_;
    rclcpp::Publisher<action_interfaces::msg::GripCommand>::SharedPtr grip_command_publisher_;
};

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TaskPlanner>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
