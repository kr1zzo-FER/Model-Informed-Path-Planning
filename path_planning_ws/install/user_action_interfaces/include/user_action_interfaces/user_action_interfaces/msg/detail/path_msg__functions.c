// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from user_action_interfaces:msg/PathMsg.idl
// generated code does not contain a copyright notice
#include "user_action_interfaces/msg/detail/path_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `frame_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `path_x`
// Member `path_y`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
user_action_interfaces__msg__PathMsg__init(user_action_interfaces__msg__PathMsg * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    user_action_interfaces__msg__PathMsg__fini(msg);
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__init(&msg->frame_id)) {
    user_action_interfaces__msg__PathMsg__fini(msg);
    return false;
  }
  // path_x
  if (!rosidl_runtime_c__float__Sequence__init(&msg->path_x, 0)) {
    user_action_interfaces__msg__PathMsg__fini(msg);
    return false;
  }
  // path_y
  if (!rosidl_runtime_c__float__Sequence__init(&msg->path_y, 0)) {
    user_action_interfaces__msg__PathMsg__fini(msg);
    return false;
  }
  return true;
}

void
user_action_interfaces__msg__PathMsg__fini(user_action_interfaces__msg__PathMsg * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // frame_id
  rosidl_runtime_c__String__fini(&msg->frame_id);
  // path_x
  rosidl_runtime_c__float__Sequence__fini(&msg->path_x);
  // path_y
  rosidl_runtime_c__float__Sequence__fini(&msg->path_y);
}

bool
user_action_interfaces__msg__PathMsg__are_equal(const user_action_interfaces__msg__PathMsg * lhs, const user_action_interfaces__msg__PathMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->frame_id), &(rhs->frame_id)))
  {
    return false;
  }
  // path_x
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->path_x), &(rhs->path_x)))
  {
    return false;
  }
  // path_y
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->path_y), &(rhs->path_y)))
  {
    return false;
  }
  return true;
}

bool
user_action_interfaces__msg__PathMsg__copy(
  const user_action_interfaces__msg__PathMsg * input,
  user_action_interfaces__msg__PathMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // frame_id
  if (!rosidl_runtime_c__String__copy(
      &(input->frame_id), &(output->frame_id)))
  {
    return false;
  }
  // path_x
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->path_x), &(output->path_x)))
  {
    return false;
  }
  // path_y
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->path_y), &(output->path_y)))
  {
    return false;
  }
  return true;
}

user_action_interfaces__msg__PathMsg *
user_action_interfaces__msg__PathMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  user_action_interfaces__msg__PathMsg * msg = (user_action_interfaces__msg__PathMsg *)allocator.allocate(sizeof(user_action_interfaces__msg__PathMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(user_action_interfaces__msg__PathMsg));
  bool success = user_action_interfaces__msg__PathMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
user_action_interfaces__msg__PathMsg__destroy(user_action_interfaces__msg__PathMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    user_action_interfaces__msg__PathMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
user_action_interfaces__msg__PathMsg__Sequence__init(user_action_interfaces__msg__PathMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  user_action_interfaces__msg__PathMsg * data = NULL;

  if (size) {
    data = (user_action_interfaces__msg__PathMsg *)allocator.zero_allocate(size, sizeof(user_action_interfaces__msg__PathMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = user_action_interfaces__msg__PathMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        user_action_interfaces__msg__PathMsg__fini(&data[i - 1]);
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
user_action_interfaces__msg__PathMsg__Sequence__fini(user_action_interfaces__msg__PathMsg__Sequence * array)
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
      user_action_interfaces__msg__PathMsg__fini(&array->data[i]);
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

user_action_interfaces__msg__PathMsg__Sequence *
user_action_interfaces__msg__PathMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  user_action_interfaces__msg__PathMsg__Sequence * array = (user_action_interfaces__msg__PathMsg__Sequence *)allocator.allocate(sizeof(user_action_interfaces__msg__PathMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = user_action_interfaces__msg__PathMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
user_action_interfaces__msg__PathMsg__Sequence__destroy(user_action_interfaces__msg__PathMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    user_action_interfaces__msg__PathMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
user_action_interfaces__msg__PathMsg__Sequence__are_equal(const user_action_interfaces__msg__PathMsg__Sequence * lhs, const user_action_interfaces__msg__PathMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!user_action_interfaces__msg__PathMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
user_action_interfaces__msg__PathMsg__Sequence__copy(
  const user_action_interfaces__msg__PathMsg__Sequence * input,
  user_action_interfaces__msg__PathMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(user_action_interfaces__msg__PathMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    user_action_interfaces__msg__PathMsg * data =
      (user_action_interfaces__msg__PathMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!user_action_interfaces__msg__PathMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          user_action_interfaces__msg__PathMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!user_action_interfaces__msg__PathMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
