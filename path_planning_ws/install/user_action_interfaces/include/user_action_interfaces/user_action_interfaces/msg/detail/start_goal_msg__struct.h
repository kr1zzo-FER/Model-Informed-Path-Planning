// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from user_action_interfaces:msg/StartGoalMsg.idl
// generated code does not contain a copyright notice

#ifndef USER_ACTION_INTERFACES__MSG__DETAIL__START_GOAL_MSG__STRUCT_H_
#define USER_ACTION_INTERFACES__MSG__DETAIL__START_GOAL_MSG__STRUCT_H_

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
// Member 'start'
// Member 'goal'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/StartGoalMsg in the package user_action_interfaces.
typedef struct user_action_interfaces__msg__StartGoalMsg
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String frame_id;
  rosidl_runtime_c__float__Sequence start;
  rosidl_runtime_c__float__Sequence goal;
} user_action_interfaces__msg__StartGoalMsg;

// Struct for a sequence of user_action_interfaces__msg__StartGoalMsg.
typedef struct user_action_interfaces__msg__StartGoalMsg__Sequence
{
  user_action_interfaces__msg__StartGoalMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_action_interfaces__msg__StartGoalMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USER_ACTION_INTERFACES__MSG__DETAIL__START_GOAL_MSG__STRUCT_H_
