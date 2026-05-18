// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interfaces:msg/GripCommand.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__GRIP_COMMAND__BUILDER_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__GRIP_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "action_interfaces/msg/detail/grip_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace action_interfaces
{

namespace msg
{

namespace builder
{

class Init_GripCommand_grip_command
{
public:
  Init_GripCommand_grip_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interfaces::msg::GripCommand grip_command(::action_interfaces::msg::GripCommand::_grip_command_type arg)
  {
    msg_.grip_command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::msg::GripCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::msg::GripCommand>()
{
  return action_interfaces::msg::builder::Init_GripCommand_grip_command();
}

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__MSG__DETAIL__GRIP_COMMAND__BUILDER_HPP_
