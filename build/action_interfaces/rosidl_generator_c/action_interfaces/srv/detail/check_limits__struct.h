// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from action_interfaces:srv/CheckLimits.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__SRV__DETAIL__CHECK_LIMITS__STRUCT_H_
#define ACTION_INTERFACES__SRV__DETAIL__CHECK_LIMITS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/CheckLimits in the package action_interfaces.
typedef struct action_interfaces__srv__CheckLimits_Request
{
  float shoulder_angle;
  float elbow_angle;
  float wrist_angle;
  float spin_angle;
} action_interfaces__srv__CheckLimits_Request;

// Struct for a sequence of action_interfaces__srv__CheckLimits_Request.
typedef struct action_interfaces__srv__CheckLimits_Request__Sequence
{
  action_interfaces__srv__CheckLimits_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__srv__CheckLimits_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/CheckLimits in the package action_interfaces.
typedef struct action_interfaces__srv__CheckLimits_Response
{
  bool is_safe;
  rosidl_runtime_c__String message;
} action_interfaces__srv__CheckLimits_Response;

// Struct for a sequence of action_interfaces__srv__CheckLimits_Response.
typedef struct action_interfaces__srv__CheckLimits_Response__Sequence
{
  action_interfaces__srv__CheckLimits_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__srv__CheckLimits_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACES__SRV__DETAIL__CHECK_LIMITS__STRUCT_H_
