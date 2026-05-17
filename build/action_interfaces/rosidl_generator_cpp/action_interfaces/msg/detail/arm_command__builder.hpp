// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interfaces:msg/ArmCommand.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__ARM_COMMAND__BUILDER_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__ARM_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "action_interfaces/msg/detail/arm_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace action_interfaces
{

namespace msg
{

namespace builder
{

class Init_ArmCommand_wrist_angle_cmd
{
public:
  explicit Init_ArmCommand_wrist_angle_cmd(::action_interfaces::msg::ArmCommand & msg)
  : msg_(msg)
  {}
  ::action_interfaces::msg::ArmCommand wrist_angle_cmd(::action_interfaces::msg::ArmCommand::_wrist_angle_cmd_type arg)
  {
    msg_.wrist_angle_cmd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::msg::ArmCommand msg_;
};

class Init_ArmCommand_elbow_angle_cmd
{
public:
  explicit Init_ArmCommand_elbow_angle_cmd(::action_interfaces::msg::ArmCommand & msg)
  : msg_(msg)
  {}
  Init_ArmCommand_wrist_angle_cmd elbow_angle_cmd(::action_interfaces::msg::ArmCommand::_elbow_angle_cmd_type arg)
  {
    msg_.elbow_angle_cmd = std::move(arg);
    return Init_ArmCommand_wrist_angle_cmd(msg_);
  }

private:
  ::action_interfaces::msg::ArmCommand msg_;
};

class Init_ArmCommand_shoulder_angle_cmd
{
public:
  Init_ArmCommand_shoulder_angle_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmCommand_elbow_angle_cmd shoulder_angle_cmd(::action_interfaces::msg::ArmCommand::_shoulder_angle_cmd_type arg)
  {
    msg_.shoulder_angle_cmd = std::move(arg);
    return Init_ArmCommand_elbow_angle_cmd(msg_);
  }

private:
  ::action_interfaces::msg::ArmCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::msg::ArmCommand>()
{
  return action_interfaces::msg::builder::Init_ArmCommand_shoulder_angle_cmd();
}

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__MSG__DETAIL__ARM_COMMAND__BUILDER_HPP_
