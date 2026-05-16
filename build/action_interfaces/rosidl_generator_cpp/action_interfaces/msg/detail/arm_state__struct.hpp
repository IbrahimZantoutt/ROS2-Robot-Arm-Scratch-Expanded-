// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from action_interfaces:msg/ArmState.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__ARM_STATE__STRUCT_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__ARM_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__action_interfaces__msg__ArmState __attribute__((deprecated))
#else
# define DEPRECATED__action_interfaces__msg__ArmState __declspec(deprecated)
#endif

namespace action_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArmState_
{
  using Type = ArmState_<ContainerAllocator>;

  explicit ArmState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shoulder_angle = 0.0f;
      this->elbow_angle = 0.0f;
      this->status = "";
    }
  }

  explicit ArmState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shoulder_angle = 0.0f;
      this->elbow_angle = 0.0f;
      this->status = "";
    }
  }

  // field types and members
  using _shoulder_angle_type =
    float;
  _shoulder_angle_type shoulder_angle;
  using _elbow_angle_type =
    float;
  _elbow_angle_type elbow_angle;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__shoulder_angle(
    const float & _arg)
  {
    this->shoulder_angle = _arg;
    return *this;
  }
  Type & set__elbow_angle(
    const float & _arg)
  {
    this->elbow_angle = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interfaces::msg::ArmState_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interfaces::msg::ArmState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interfaces::msg::ArmState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interfaces::msg::ArmState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interfaces::msg::ArmState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::msg::ArmState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interfaces::msg::ArmState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::msg::ArmState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interfaces::msg::ArmState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interfaces::msg::ArmState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interfaces__msg__ArmState
    std::shared_ptr<action_interfaces::msg::ArmState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interfaces__msg__ArmState
    std::shared_ptr<action_interfaces::msg::ArmState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmState_ & other) const
  {
    if (this->shoulder_angle != other.shoulder_angle) {
      return false;
    }
    if (this->elbow_angle != other.elbow_angle) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmState_

// alias to use template instance with default allocator
using ArmState =
  action_interfaces::msg::ArmState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__MSG__DETAIL__ARM_STATE__STRUCT_HPP_
