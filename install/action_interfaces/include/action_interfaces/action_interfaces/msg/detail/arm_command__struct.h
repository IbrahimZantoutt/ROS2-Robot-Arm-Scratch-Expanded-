// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from action_interfaces:msg/ArmCommand.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__MSG__DETAIL__ARM_COMMAND__STRUCT_H_
#define ACTION_INTERFACES__MSG__DETAIL__ARM_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ArmCommand in the package action_interfaces.
typedef struct action_interfaces__msg__ArmCommand
{
  float shoulder_angle_cmd;
  float elbow_angle_cmd;
  float wrist_angle_cmd;
  float spin_angle_cmd;
} action_interfaces__msg__ArmCommand;

// Struct for a sequence of action_interfaces__msg__ArmCommand.
typedef struct action_interfaces__msg__ArmCommand__Sequence
{
  action_interfaces__msg__ArmCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__msg__ArmCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACES__MSG__DETAIL__ARM_COMMAND__STRUCT_H_
