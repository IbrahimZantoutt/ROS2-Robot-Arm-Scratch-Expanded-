// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interfaces:msg/ArmState.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__ARM_STATE__BUILDER_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__ARM_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "action_interfaces/msg/detail/arm_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace action_interfaces
{

namespace msg
{

namespace builder
{

class Init_ArmState_status
{
public:
  explicit Init_ArmState_status(::action_interfaces::msg::ArmState & msg)
  : msg_(msg)
  {}
  ::action_interfaces::msg::ArmState status(::action_interfaces::msg::ArmState::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::msg::ArmState msg_;
};

class Init_ArmState_elbow_angle
{
public:
  explicit Init_ArmState_elbow_angle(::action_interfaces::msg::ArmState & msg)
  : msg_(msg)
  {}
  Init_ArmState_status elbow_angle(::action_interfaces::msg::ArmState::_elbow_angle_type arg)
  {
    msg_.elbow_angle = std::move(arg);
    return Init_ArmState_status(msg_);
  }

private:
  ::action_interfaces::msg::ArmState msg_;
};

class Init_ArmState_shoulder_angle
{
public:
  Init_ArmState_shoulder_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmState_elbow_angle shoulder_angle(::action_interfaces::msg::ArmState::_shoulder_angle_type arg)
  {
    msg_.shoulder_angle = std::move(arg);
    return Init_ArmState_elbow_angle(msg_);
  }

private:
  ::action_interfaces::msg::ArmState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::msg::ArmState>()
{
  return action_interfaces::msg::builder::Init_ArmState_shoulder_angle();
}

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__MSG__DETAIL__ARM_STATE__BUILDER_HPP_
