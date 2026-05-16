// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from action_interfaces:msg/ArmState.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__ARM_STATE__TRAITS_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__ARM_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "action_interfaces/msg/detail/arm_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace action_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ArmState & msg,
  std::ostream & out)
{
  out << "{";
  // member: shoulder_angle
  {
    out << "shoulder_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.shoulder_angle, out);
    out << ", ";
  }

  // member: elbow_angle
  {
    out << "elbow_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.elbow_angle, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArmState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: shoulder_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shoulder_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.shoulder_angle, out);
    out << "\n";
  }

  // member: elbow_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "elbow_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.elbow_angle, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArmState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace action_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use action_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interfaces::msg::ArmState & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const action_interfaces::msg::ArmState & msg)
{
  return action_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<action_interfaces::msg::ArmState>()
{
  return "action_interfaces::msg::ArmState";
}

template<>
inline const char * name<action_interfaces::msg::ArmState>()
{
  return "action_interfaces/msg/ArmState";
}

template<>
struct has_fixed_size<action_interfaces::msg::ArmState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interfaces::msg::ArmState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_interfaces::msg::ArmState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ACTION_INTERFACES__MSG__DETAIL__ARM_STATE__TRAITS_HPP_
