// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from action_interfaces:msg/GripCommand.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__GRIP_COMMAND__STRUCT_H_
#define ACTION_INTERFACES__MSG__DETAIL__GRIP_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'grip_command'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/GripCommand in the package action_interfaces.
typedef struct action_interfaces__msg__GripCommand
{
  rosidl_runtime_c__String grip_command;
} action_interfaces__msg__GripCommand;

// Struct for a sequence of action_interfaces__msg__GripCommand.
typedef struct action_interfaces__msg__GripCommand__Sequence
{
  action_interfaces__msg__GripCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__msg__GripCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACES__MSG__DETAIL__GRIP_COMMAND__STRUCT_H_
