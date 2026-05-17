// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from action_interfaces:msg/ArmState.idl
// generated code does not contain a copyright notice
#include "action_interfaces/msg/detail/arm_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `status`
#include "rosidl_runtime_c/string_functions.h"

bool
action_interfaces__msg__ArmState__init(action_interfaces__msg__ArmState * msg)
{
  if (!msg) {
    return false;
  }
  // shoulder_angle
  // elbow_angle
  // wrist_angle
  // spin_angle
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    action_interfaces__msg__ArmState__fini(msg);
    return false;
  }
  return true;
}

void
action_interfaces__msg__ArmState__fini(action_interfaces__msg__ArmState * msg)
{
  if (!msg) {
    return;
  }
  // shoulder_angle
  // elbow_angle
  // wrist_angle
  // spin_angle
  // status
  rosidl_runtime_c__String__fini(&msg->status);
}

bool
action_interfaces__msg__ArmState__are_equal(const action_interfaces__msg__ArmState * lhs, const action_interfaces__msg__ArmState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // shoulder_angle
  if (lhs->shoulder_angle != rhs->shoulder_angle) {
    return false;
  }
  // elbow_angle
  if (lhs->elbow_angle != rhs->elbow_angle) {
    return false;
  }
  // wrist_angle
  if (lhs->wrist_angle != rhs->wrist_angle) {
    return false;
  }
  // spin_angle
  if (lhs->spin_angle != rhs->spin_angle) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  return true;
}

bool
action_interfaces__msg__ArmState__copy(
  const action_interfaces__msg__ArmState * input,
  action_interfaces__msg__ArmState * output)
{
  if (!input || !output) {
    return false;
  }
  // shoulder_angle
  output->shoulder_angle = input->shoulder_angle;
  // elbow_angle
  output->elbow_angle = input->elbow_angle;
  // wrist_angle
  output->wrist_angle = input->wrist_angle;
  // spin_angle
  output->spin_angle = input->spin_angle;
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  return true;
}

action_interfaces__msg__ArmState *
action_interfaces__msg__ArmState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_interfaces__msg__ArmState * msg = (action_interfaces__msg__ArmState *)allocator.allocate(sizeof(action_interfaces__msg__ArmState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_interfaces__msg__ArmState));
  bool success = action_interfaces__msg__ArmState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
action_interfaces__msg__ArmState__destroy(action_interfaces__msg__ArmState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    action_interfaces__msg__ArmState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
action_interfaces__msg__ArmState__Sequence__init(action_interfaces__msg__ArmState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_interfaces__msg__ArmState * data = NULL;

  if (size) {
    data = (action_interfaces__msg__ArmState *)allocator.zero_allocate(size, sizeof(action_interfaces__msg__ArmState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_interfaces__msg__ArmState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_interfaces__msg__ArmState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
action_interfaces__msg__ArmState__Sequence__fini(action_interfaces__msg__ArmState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      action_interfaces__msg__ArmState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

action_interfaces__msg__ArmState__Sequence *
action_interfaces__msg__ArmState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_interfaces__msg__ArmState__Sequence * array = (action_interfaces__msg__ArmState__Sequence *)allocator.allocate(sizeof(action_interfaces__msg__ArmState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = action_interfaces__msg__ArmState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
action_interfaces__msg__ArmState__Sequence__destroy(action_interfaces__msg__ArmState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    action_interfaces__msg__ArmState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
action_interfaces__msg__ArmState__Sequence__are_equal(const action_interfaces__msg__ArmState__Sequence * lhs, const action_interfaces__msg__ArmState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_interfaces__msg__ArmState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_interfaces__msg__ArmState__Sequence__copy(
  const action_interfaces__msg__ArmState__Sequence * input,
  action_interfaces__msg__ArmState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_interfaces__msg__ArmState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    action_interfaces__msg__ArmState * data =
      (action_interfaces__msg__ArmState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_interfaces__msg__ArmState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          action_interfaces__msg__ArmState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_interfaces__msg__ArmState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
