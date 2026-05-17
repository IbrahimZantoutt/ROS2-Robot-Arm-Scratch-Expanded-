// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from action_interfaces:srv/CheckLimits.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__SRV__DETAIL__CHECK_LIMITS__STRUCT_HPP_
#define ACTION_INTERFACES__SRV__DETAIL__CHECK_LIMITS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__action_interfaces__srv__CheckLimits_Request __attribute__((deprecated))
#else
# define DEPRECATED__action_interfaces__srv__CheckLimits_Request __declspec(deprecated)
#endif

namespace action_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CheckLimits_Request_
{
  using Type = CheckLimits_Request_<ContainerAllocator>;

  explicit CheckLimits_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shoulder_angle = 0.0f;
      this->elbow_angle = 0.0f;
      this->wrist_angle = 0.0f;
      this->spin_angle = 0.0f;
    }
  }

  explicit CheckLimits_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shoulder_angle = 0.0f;
      this->elbow_angle = 0.0f;
      this->wrist_angle = 0.0f;
      this->spin_angle = 0.0f;
    }
  }

  // field types and members
  using _shoulder_angle_type =
    float;
  _shoulder_angle_type shoulder_angle;
  using _elbow_angle_type =
    float;
  _elbow_angle_type elbow_angle;
  using _wrist_angle_type =
    float;
  _wrist_angle_type wrist_angle;
  using _spin_angle_type =
    float;
  _spin_angle_type spin_angle;

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
  Type & set__wrist_angle(
    const float & _arg)
  {
    this->wrist_angle = _arg;
    return *this;
  }
  Type & set__spin_angle(
    const float & _arg)
  {
    this->spin_angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interfaces::srv::CheckLimits_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interfaces::srv::CheckLimits_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interfaces::srv::CheckLimits_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interfaces::srv::CheckLimits_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interfaces::srv::CheckLimits_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::srv::CheckLimits_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interfaces::srv::CheckLimits_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::srv::CheckLimits_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interfaces::srv::CheckLimits_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interfaces::srv::CheckLimits_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interfaces__srv__CheckLimits_Request
    std::shared_ptr<action_interfaces::srv::CheckLimits_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interfaces__srv__CheckLimits_Request
    std::shared_ptr<action_interfaces::srv::CheckLimits_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CheckLimits_Request_ & other) const
  {
    if (this->shoulder_angle != other.shoulder_angle) {
      return false;
    }
    if (this->elbow_angle != other.elbow_angle) {
      return false;
    }
    if (this->wrist_angle != other.wrist_angle) {
      return false;
    }
    if (this->spin_angle != other.spin_angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const CheckLimits_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CheckLimits_Request_

// alias to use template instance with default allocator
using CheckLimits_Request =
  action_interfaces::srv::CheckLimits_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace action_interfaces


#ifndef _WIN32
# define DEPRECATED__action_interfaces__srv__CheckLimits_Response __attribute__((deprecated))
#else
# define DEPRECATED__action_interfaces__srv__CheckLimits_Response __declspec(deprecated)
#endif

namespace action_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CheckLimits_Response_
{
  using Type = CheckLimits_Response_<ContainerAllocator>;

  explicit CheckLimits_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_safe = false;
      this->message = "";
    }
  }

  explicit CheckLimits_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_safe = false;
      this->message = "";
    }
  }

  // field types and members
  using _is_safe_type =
    bool;
  _is_safe_type is_safe;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__is_safe(
    const bool & _arg)
  {
    this->is_safe = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interfaces::srv::CheckLimits_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interfaces::srv::CheckLimits_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interfaces::srv::CheckLimits_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interfaces::srv::CheckLimits_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interfaces::srv::CheckLimits_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::srv::CheckLimits_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interfaces::srv::CheckLimits_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interfaces::srv::CheckLimits_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interfaces::srv::CheckLimits_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interfaces::srv::CheckLimits_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interfaces__srv__CheckLimits_Response
    std::shared_ptr<action_interfaces::srv::CheckLimits_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interfaces__srv__CheckLimits_Response
    std::shared_ptr<action_interfaces::srv::CheckLimits_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CheckLimits_Response_ & other) const
  {
    if (this->is_safe != other.is_safe) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const CheckLimits_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CheckLimits_Response_

// alias to use template instance with default allocator
using CheckLimits_Response =
  action_interfaces::srv::CheckLimits_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace action_interfaces

namespace action_interfaces
{

namespace srv
{

struct CheckLimits
{
  using Request = action_interfaces::srv::CheckLimits_Request;
  using Response = action_interfaces::srv::CheckLimits_Response;
};

}  // namespace srv

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__SRV__DETAIL__CHECK_LIMITS__STRUCT_HPP_
