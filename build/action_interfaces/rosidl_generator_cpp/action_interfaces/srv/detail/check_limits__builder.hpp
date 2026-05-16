// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interfaces:srv/CheckLimits.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__SRV__DETAIL__CHECK_LIMITS__BUILDER_HPP_
#define ACTION_INTERFACES__SRV__DETAIL__CHECK_LIMITS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "action_interfaces/srv/detail/check_limits__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace action_interfaces
{

namespace srv
{

namespace builder
{

class Init_CheckLimits_Request_elbow_angle
{
public:
  explicit Init_CheckLimits_Request_elbow_angle(::action_interfaces::srv::CheckLimits_Request & msg)
  : msg_(msg)
  {}
  ::action_interfaces::srv::CheckLimits_Request elbow_angle(::action_interfaces::srv::CheckLimits_Request::_elbow_angle_type arg)
  {
    msg_.elbow_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::srv::CheckLimits_Request msg_;
};

class Init_CheckLimits_Request_shoulder_angle
{
public:
  Init_CheckLimits_Request_shoulder_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CheckLimits_Request_elbow_angle shoulder_angle(::action_interfaces::srv::CheckLimits_Request::_shoulder_angle_type arg)
  {
    msg_.shoulder_angle = std::move(arg);
    return Init_CheckLimits_Request_elbow_angle(msg_);
  }

private:
  ::action_interfaces::srv::CheckLimits_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::srv::CheckLimits_Request>()
{
  return action_interfaces::srv::builder::Init_CheckLimits_Request_shoulder_angle();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace srv
{

namespace builder
{

class Init_CheckLimits_Response_message
{
public:
  explicit Init_CheckLimits_Response_message(::action_interfaces::srv::CheckLimits_Response & msg)
  : msg_(msg)
  {}
  ::action_interfaces::srv::CheckLimits_Response message(::action_interfaces::srv::CheckLimits_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::srv::CheckLimits_Response msg_;
};

class Init_CheckLimits_Response_is_safe
{
public:
  Init_CheckLimits_Response_is_safe()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CheckLimits_Response_message is_safe(::action_interfaces::srv::CheckLimits_Response::_is_safe_type arg)
  {
    msg_.is_safe = std::move(arg);
    return Init_CheckLimits_Response_message(msg_);
  }

private:
  ::action_interfaces::srv::CheckLimits_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::srv::CheckLimits_Response>()
{
  return action_interfaces::srv::builder::Init_CheckLimits_Response_is_safe();
}

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__SRV__DETAIL__CHECK_LIMITS__BUILDER_HPP_
