// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from action_interfaces:msg/GripCommand.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__GRIP_COMMAND__STRUCT_HPP_
#define ACTION_INTERFACES__MSG__DETAIL__GRIP_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__action_interfaces__msg__GripCommand __attribute__((deprecated))
#else
# define DEPRECATED__action_interfaces__msg__GripCommand __declspec(deprecated)
#endif

namespace action_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GripCommand_
{
  using Type = GripCommand_<ContainerAllocator>;

  explicit GripCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->grip_command = "";
    }
  }

  explicit GripCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : grip_command(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->grip_command = "";
    }
  }

  // field types and members
  using _grip_command_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _grip_command_type grip_command;

  // setters for named parameter idiom
  Type & set__grip_command(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->grip_command = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interfaces::msg::GripCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interfaces::msg::GripCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interfaces::msg::GripCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interfaces::msg::GripCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interfaces::msg::GripCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::msg::GripCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interfaces::msg::GripCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::msg::GripCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interfaces::msg::GripCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interfaces::msg::GripCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interfaces__msg__GripCommand
    std::shared_ptr<action_interfaces::msg::GripCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interfaces__msg__GripCommand
    std::shared_ptr<action_interfaces::msg::GripCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GripCommand_ & other) const
  {
    if (this->grip_command != other.grip_command) {
      return false;
    }
    return true;
  }
  bool operator!=(const GripCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GripCommand_

// alias to use template instance with default allocator
using GripCommand =
  action_interfaces::msg::GripCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__MSG__DETAIL__GRIP_COMMAND__STRUCT_HPP_
