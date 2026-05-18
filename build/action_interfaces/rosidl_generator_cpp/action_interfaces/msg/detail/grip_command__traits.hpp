// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from action_interfaces:msg/GripCommand.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__GRIP_COMMAND__TRAITS_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__GRIP_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "action_interfaces/msg/detail/grip_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace action_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const GripCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: grip_command
  {
    out << "grip_command: ";
    rosidl_generator_traits::value_to_yaml(msg.grip_command, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GripCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: grip_command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "grip_command: ";
    rosidl_generator_traits::value_to_yaml(msg.grip_command, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GripCommand & msg, bool use_flow_style = false)
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
  const action_interfaces::msg::GripCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const action_interfaces::msg::GripCommand & msg)
{
  return action_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<action_interfaces::msg::GripCommand>()
{
  return "action_interfaces::msg::GripCommand";
}

template<>
inline const char * name<action_interfaces::msg::GripCommand>()
{
  return "action_interfaces/msg/GripCommand";
}

template<>
struct has_fixed_size<action_interfaces::msg::GripCommand>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interfaces::msg::GripCommand>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_interfaces::msg::GripCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ACTION_INTERFACES__MSG__DETAIL__GRIP_COMMAND__TRAITS_HPP_
