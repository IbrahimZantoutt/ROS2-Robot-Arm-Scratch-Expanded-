// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from action_interfaces:msg/GripCommand.idl
// generated code does not contain a copyright notice
#include "action_interfaces/msg/detail/grip_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `grip_command`
#include "rosidl_runtime_c/string_functions.h"

bool
action_interfaces__msg__GripCommand__init(action_interfaces__msg__GripCommand * msg)
{
  if (!msg) {
    return false;
  }
  // grip_command
  if (!rosidl_runtime_c__String__init(&msg->grip_command)) {
    action_interfaces__msg__GripCommand__fini(msg);
    return false;
  }
  return true;
}

void
action_interfaces__msg__GripCommand__fini(action_interfaces__msg__GripCommand * msg)
{
  if (!msg) {
    return;
  }
  // grip_command
  rosidl_runtime_c__String__fini(&msg->grip_command);
}

bool
action_interfaces__msg__GripCommand__are_equal(const action_interfaces__msg__GripCommand * lhs, const action_interfaces__msg__GripCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // grip_command
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->grip_command), &(rhs->grip_command)))
  {
    return false;
  }
  return true;
}

bool
action_interfaces__msg__GripCommand__copy(
  const action_interfaces__msg__GripCommand * input,
  action_interfaces__msg__GripCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // grip_command
  if (!rosidl_runtime_c__String__copy(
      &(input->grip_command), &(output->grip_command)))
  {
    return false;
  }
  return true;
}

action_interfaces__msg__GripCommand *
action_interfaces__msg__GripCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_interfaces__msg__GripCommand * msg = (action_interfaces__msg__GripCommand *)allocator.allocate(sizeof(action_interfaces__msg__GripCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(action_interfaces__msg__GripCommand));
  bool success = action_interfaces__msg__GripCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
action_interfaces__msg__GripCommand__destroy(action_interfaces__msg__GripCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    action_interfaces__msg__GripCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
action_interfaces__msg__GripCommand__Sequence__init(action_interfaces__msg__GripCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_interfaces__msg__GripCommand * data = NULL;

  if (size) {
    data = (action_interfaces__msg__GripCommand *)allocator.zero_allocate(size, sizeof(action_interfaces__msg__GripCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = action_interfaces__msg__GripCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        action_interfaces__msg__GripCommand__fini(&data[i - 1]);
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
action_interfaces__msg__GripCommand__Sequence__fini(action_interfaces__msg__GripCommand__Sequence * array)
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
      action_interfaces__msg__GripCommand__fini(&array->data[i]);
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

action_interfaces__msg__GripCommand__Sequence *
action_interfaces__msg__GripCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  action_interfaces__msg__GripCommand__Sequence * array = (action_interfaces__msg__GripCommand__Sequence *)allocator.allocate(sizeof(action_interfaces__msg__GripCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = action_interfaces__msg__GripCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
action_interfaces__msg__GripCommand__Sequence__destroy(action_interfaces__msg__GripCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    action_interfaces__msg__GripCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
action_interfaces__msg__GripCommand__Sequence__are_equal(const action_interfaces__msg__GripCommand__Sequence * lhs, const action_interfaces__msg__GripCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!action_interfaces__msg__GripCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
action_interfaces__msg__GripCommand__Sequence__copy(
  const action_interfaces__msg__GripCommand__Sequence * input,
  action_interfaces__msg__GripCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(action_interfaces__msg__GripCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    action_interfaces__msg__GripCommand * data =
      (action_interfaces__msg__GripCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!action_interfaces__msg__GripCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          action_interfaces__msg__GripCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!action_interfaces__msg__GripCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
