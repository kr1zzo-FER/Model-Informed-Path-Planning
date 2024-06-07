// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from user_action_interfaces:msg/PathMsg.idl
// generated code does not contain a copyright notice

#ifndef USER_ACTION_INTERFACES__MSG__DETAIL__PATH_MSG__STRUCT_H_
#define USER_ACTION_INTERFACES__MSG__DETAIL__PATH_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'frame_id'
#include "rosidl_runtime_c/string.h"
// Member 'path_x'
// Member 'path_y'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/PathMsg in the package user_action_interfaces.
typedef struct user_action_interfaces__msg__PathMsg
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String frame_id;
  rosidl_runtime_c__float__Sequence path_x;
  rosidl_runtime_c__float__Sequence path_y;
} user_action_interfaces__msg__PathMsg;

// Struct for a sequence of user_action_interfaces__msg__PathMsg.
typedef struct user_action_interfaces__msg__PathMsg__Sequence
{
  user_action_interfaces__msg__PathMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_action_interfaces__msg__PathMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USER_ACTION_INTERFACES__MSG__DETAIL__PATH_MSG__STRUCT_H_
