// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from action_interfaces:msg/ArmCommand.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__ARM_COMMAND__STRUCT_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__ARM_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__action_interfaces__msg__ArmCommand __attribute__((deprecated))
#else
# define DEPRECATED__action_interfaces__msg__ArmCommand __declspec(deprecated)
#endif

namespace action_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArmCommand_
{
  using Type = ArmCommand_<ContainerAllocator>;

  explicit ArmCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shoulder_angle_cmd = 0.0f;
      this->elbow_angle_cmd = 0.0f;
    }
  }

  explicit ArmCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shoulder_angle_cmd = 0.0f;
      this->elbow_angle_cmd = 0.0f;
    }
  }

  // field types and members
  using _shoulder_angle_cmd_type =
    float;
  _shoulder_angle_cmd_type shoulder_angle_cmd;
  using _elbow_angle_cmd_type =
    float;
  _elbow_angle_cmd_type elbow_angle_cmd;

  // setters for named parameter idiom
  Type & set__shoulder_angle_cmd(
    const float & _arg)
  {
    this->shoulder_angle_cmd = _arg;
    return *this;
  }
  Type & set__elbow_angle_cmd(
    const float & _arg)
  {
    this->elbow_angle_cmd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interfaces::msg::ArmCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interfaces::msg::ArmCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interfaces::msg::ArmCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interfaces::msg::ArmCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interfaces::msg::ArmCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::msg::ArmCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interfaces::msg::ArmCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::msg::ArmCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interfaces::msg::ArmCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interfaces::msg::ArmCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interfaces__msg__ArmCommand
    std::shared_ptr<action_interfaces::msg::ArmCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interfaces__msg__ArmCommand
    std::shared_ptr<action_interfaces::msg::ArmCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmCommand_ & other) const
  {
    if (this->shoulder_angle_cmd != other.shoulder_angle_cmd) {
      return false;
    }
    if (this->elbow_angle_cmd != other.elbow_angle_cmd) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmCommand_

// alias to use template instance with default allocator
using ArmCommand =
  action_interfaces::msg::ArmCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__MSG__DETAIL__ARM_COMMAND__STRUCT_HPP_
