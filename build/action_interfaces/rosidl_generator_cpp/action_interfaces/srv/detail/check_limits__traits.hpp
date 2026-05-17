// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from action_interfaces:srv/CheckLimits.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__SRV__DETAIL__CHECK_LIMITS__TRAITS_HPP_
#define ACTION_INTERFACES__SRV__DETAIL__CHECK_LIMITS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "action_interfaces/srv/detail/check_limits__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace action_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CheckLimits_Request & msg,
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

  // member: wrist_angle
  {
    out << "wrist_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.wrist_angle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CheckLimits_Request & msg,
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

  // member: wrist_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wrist_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.wrist_angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CheckLimits_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace action_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use action_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interfaces::srv::CheckLimits_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const action_interfaces::srv::CheckLimits_Request & msg)
{
  return action_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<action_interfaces::srv::CheckLimits_Request>()
{
  return "action_interfaces::srv::CheckLimits_Request";
}

template<>
inline const char * name<action_interfaces::srv::CheckLimits_Request>()
{
  return "action_interfaces/srv/CheckLimits_Request";
}

template<>
struct has_fixed_size<action_interfaces::srv::CheckLimits_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<action_interfaces::srv::CheckLimits_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<action_interfaces::srv::CheckLimits_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace action_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CheckLimits_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_safe
  {
    out << "is_safe: ";
    rosidl_generator_traits::value_to_yaml(msg.is_safe, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CheckLimits_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_safe
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_safe: ";
    rosidl_generator_traits::value_to_yaml(msg.is_safe, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CheckLimits_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace action_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use action_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interfaces::srv::CheckLimits_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const action_interfaces::srv::CheckLimits_Response & msg)
{
  return action_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<action_interfaces::srv::CheckLimits_Response>()
{
  return "action_interfaces::srv::CheckLimits_Response";
}

template<>
inline const char * name<action_interfaces::srv::CheckLimits_Response>()
{
  return "action_interfaces/srv/CheckLimits_Response";
}

template<>
struct has_fixed_size<action_interfaces::srv::CheckLimits_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interfaces::srv::CheckLimits_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_interfaces::srv::CheckLimits_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interfaces::srv::CheckLimits>()
{
  return "action_interfaces::srv::CheckLimits";
}

template<>
inline const char * name<action_interfaces::srv::CheckLimits>()
{
  return "action_interfaces/srv/CheckLimits";
}

template<>
struct has_fixed_size<action_interfaces::srv::CheckLimits>
  : std::integral_constant<
    bool,
    has_fixed_size<action_interfaces::srv::CheckLimits_Request>::value &&
    has_fixed_size<action_interfaces::srv::CheckLimits_Response>::value
  >
{
};

template<>
struct has_bounded_size<action_interfaces::srv::CheckLimits>
  : std::integral_constant<
    bool,
    has_bounded_size<action_interfaces::srv::CheckLimits_Request>::value &&
    has_bounded_size<action_interfaces::srv::CheckLimits_Response>::value
  >
{
};

template<>
struct is_service<action_interfaces::srv::CheckLimits>
  : std::true_type
{
};

template<>
struct is_service_request<action_interfaces::srv::CheckLimits_Request>
  : std::true_type
{
};

template<>
struct is_service_response<action_interfaces::srv::CheckLimits_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ACTION_INTERFACES__SRV__DETAIL__CHECK_LIMITS__TRAITS_HPP_
