#include "rclcpp/rclcpp.hpp"
#include "action_interfaces/msg/arm_state.hpp"
#include "action_interfaces/msg/arm_command.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "action_interfaces/msg/grip_command.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include <string>

class ArmController: public rclcpp::Node{
  public:
    ArmController(float an1, float an2, float an3, float an4): Node("arm_controller"){
      RCLCPP_INFO(this->get_logger(), "ArmController node has been started.");
      arm_state_publisher_ = this->create_publisher<action_interfaces::msg::ArmState>("arm_state", 10);
      joint_state_publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
      // drives Gazebo joints via arm_position_controller
      position_cmd_publisher_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("arm_position_controller/commands", 10);

      timer_ = this->create_wall_timer(std::chrono::milliseconds(50), std::bind(&ArmController::publishArmState, this));
      arm_command_subscription_ = this->create_subscription<action_interfaces::msg::ArmCommand>("arm_command", 10, std::bind(&ArmController::handleArmCommand, this, std::placeholders::_1));
      grip_command_subscription_ = this->create_subscription<action_interfaces::msg::GripCommand>("grip_command", 10, std::bind(&ArmController::handleGripCommand, this, std::placeholders::_1));
      shoulder_angle_ = an1;
      elbow_angle_ = an2;
      wrist_angle_ = an3;
      spin_angle_ = an4;
      f1_pos_ = 0.0f;
      f2_pos_ = 0.0f;
      grip_status_ = "open";
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

    void setSpinAngle(float angle){
      RCLCPP_INFO(this->get_logger(), "Setting spin angle to: %f", angle);
      spin_angle_ = angle;
    }

    void CloseGrip(){
      RCLCPP_INFO(this->get_logger(), "Closing grip");
      f1_pos_ = -0.015f;   // left finger moves in -y (toward center)
      f2_pos_ = -0.015f;   // right finger axis is -y, so -0.015 also moves toward center
      grip_status_ = "closed";
    }

    void OpenGrip(){
      RCLCPP_INFO(this->get_logger(), "Opening grip");
      f1_pos_ = 0.0f;
      f2_pos_ = 0.0f;
      grip_status_ = "open";
    }

    void publishArmState(){
      float shoulder_rad = shoulder_angle_ * M_PI / 180.0f;
      float elbow_rad    = elbow_angle_    * M_PI / 180.0f;
      float wrist_rad    = wrist_angle_    * M_PI / 180.0f;
      float spin_rad     = spin_angle_     * M_PI / 180.0f;

      // arm_state for ArmMover / ArmMonitor
      auto message = action_interfaces::msg::ArmState();
      message.shoulder_angle = shoulder_angle_;
      message.elbow_angle    = elbow_angle_;
      message.wrist_angle    = wrist_angle_;
      message.spin_angle     = spin_angle_;
      arm_state_publisher_->publish(message);

      // joint_states for RViz (active joints only — passive joints are now fixed in URDF)
      auto js = sensor_msgs::msg::JointState();
      js.header.stamp = this->get_clock()->now();
      js.name     = {"shoulder_main_joint", "elbow_main_joint", "wrist_main_joint",
                     "spin_main_joint", "gripper_left_finger_joint", "gripper_right_finger_joint"};
      js.position = {shoulder_rad, elbow_rad, wrist_rad, spin_rad, f1_pos_, f2_pos_};
      joint_state_publisher_->publish(js);

      // position commands for Gazebo — same joint order as controllers.yaml
      auto cmd = std_msgs::msg::Float64MultiArray();
      cmd.data = {shoulder_rad, elbow_rad, wrist_rad, spin_rad, f1_pos_, f2_pos_};
      position_cmd_publisher_->publish(cmd);
    }

    void handleArmCommand(const action_interfaces::msg::ArmCommand::SharedPtr msg){
      setShoulderAngle(msg->shoulder_angle_cmd);
      setElbowAngle(msg->elbow_angle_cmd);
      setWristAngle(msg->wrist_angle_cmd);
      setSpinAngle(msg->spin_angle_cmd);
    }

    void handleGripCommand(const action_interfaces::msg::GripCommand::SharedPtr msg){
      if(msg->grip_command == "close"){
        CloseGrip();
      } else if(msg->grip_command == "open"){
        OpenGrip();
      }
    }

    private:
      rclcpp::Publisher<action_interfaces::msg::ArmState>::SharedPtr arm_state_publisher_;
      rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_publisher_;
      rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr position_cmd_publisher_;
      rclcpp::TimerBase::SharedPtr timer_;

      float shoulder_angle_;
      float elbow_angle_;
      float wrist_angle_;
      float spin_angle_;
      float f1_pos_;
      float f2_pos_;
      std::string grip_status_;

      rclcpp::Subscription<action_interfaces::msg::ArmCommand>::SharedPtr arm_command_subscription_;
      rclcpp::Subscription<action_interfaces::msg::GripCommand>::SharedPtr grip_command_subscription_;
};


int main(int argc, char** argv){
    rclcpp::init(argc,argv);
    auto arm_controller_node = std::make_shared<ArmController>(0, 0, 0, 0);
    rclcpp::spin(arm_controller_node);
    rclcpp::shutdown();
    return 0;
}
