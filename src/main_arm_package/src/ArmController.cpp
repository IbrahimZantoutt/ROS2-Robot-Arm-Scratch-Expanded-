#include "rclcpp/rclcpp.hpp"
#include "action_interfaces/msg/arm_state.hpp"
#include "action_interfaces/msg/arm_command.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

class ArmController: public rclcpp::Node{
  public:
    ArmController(float an1, float an2, float an3): Node("arm_controller"){
      RCLCPP_INFO(this->get_logger(), "ArmController node has been started.");
      arm_state_publisher_ = this->create_publisher<action_interfaces::msg::ArmState>("arm_state", 10);
      joint_state_publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
      timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&ArmController::publishArmState, this));
      arm_command_subscription_ = this->create_subscription<action_interfaces::msg::ArmCommand>("arm_command", 10, std::bind(&ArmController::handleArmCommand, this, std::placeholders::_1));
      shoulder_angle_ = an1;
      elbow_angle_ = an2;
      wrist_angle_ = an3;
      
    }

    void setShoulderAngle(float angle){
      RCLCPP_INFO(this->get_logger(), "Setting shoulder angle to: %f", angle);
      shoulder_angle_ = angle;
    }

    void setElbowAngle(float angle){
      RCLCPP_INFO(this->get_logger(), "Setting elbow angle to: %f", angle);
      elbow_angle_ = angle;
    }

    void setWristAngle(float angle){
      RCLCPP_INFO(this->get_logger(), "Setting wrist angle to: %f", angle);
      wrist_angle_ = angle;
    }

    void publishArmState(){
      auto message = action_interfaces::msg::ArmState();
      message.shoulder_angle = shoulder_angle_;
      message.elbow_angle = elbow_angle_;
      message.wrist_angle = wrist_angle_;
      arm_state_publisher_->publish(message);

      auto js = sensor_msgs::msg::JointState();
      js.header.stamp = this->get_clock()->now();
      js.name = {"shoulder_main_joint", "shoulder_arm_joint", "elbow_main_joint", "elbow_arm_joint", "wrist_main_joint", "wrist_arm_joint"};
      js.position = {shoulder_angle_ * M_PI / 180.0, 0.0, elbow_angle_ * M_PI / 180.0, 0.0, wrist_angle_ * M_PI / 180.0, 0.0};
      joint_state_publisher_->publish(js);
    }

    void handleArmCommand(const action_interfaces::msg::ArmCommand::SharedPtr msg){
      setShoulderAngle(msg->shoulder_angle_cmd);
      setElbowAngle(msg->elbow_angle_cmd);
      setWristAngle(msg->wrist_angle_cmd);
    }

    private:
      rclcpp::Publisher<action_interfaces::msg::ArmState>::SharedPtr arm_state_publisher_;
      rclcpp::TimerBase::SharedPtr timer_;
      float shoulder_angle_;
      float elbow_angle_;
      float wrist_angle_;
      rclcpp::Subscription<action_interfaces::msg::ArmCommand>::SharedPtr arm_command_subscription_;

      rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_publisher_;
};


int main(int argc, char** argv){
    rclcpp::init(argc,argv);
    auto arm_controller_node = std::make_shared<ArmController>(-55.0, 120, 65);
    rclcpp::spin(arm_controller_node);
    rclcpp::shutdown();
    return 0;
}