// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from user_action_interfaces:msg/CoastMsg.idl
// generated code does not contain a copyright notice

#ifndef USER_ACTION_INTERFACES__MSG__DETAIL__COAST_MSG__STRUCT_H_
#define USER_ACTION_INTERFACES__MSG__DETAIL__COAST_MSG__STRUCT_H_

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
// Member 'coast_points_x'
// Member 'green_points_x'
// Member 'red_points_x'
// Member 'yellow_points_x'
// Member 'coast_points_y'
// Member 'green_points_y'
// Member 'red_points_y'
// Member 'yellow_points_y'
#include "std_msgs/msg/detail/float32_multi_array__struct.h"

/// Struct defined in msg/CoastMsg in the package user_action_interfaces.
typedef struct user_action_interfaces__msg__CoastMsg
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String frame_id;
  std_msgs__msg__Float32MultiArray coast_points_x;
  std_msgs__msg__Float32MultiArray green_points_x;
  std_msgs__msg__Float32MultiArray red_points_x;
  std_msgs__msg__Float32MultiArray yellow_points_x;
  std_msgs__msg__Float32MultiArray coast_points_y;
  std_msgs__msg__Float32MultiArray green_points_y;
  std_msgs__msg__Float32MultiArray red_points_y;
  std_msgs__msg__Float32MultiArray yellow_points_y;
  int32_t grid_size;
} user_action_interfaces__msg__CoastMsg;

// Struct for a sequence of user_action_interfaces__msg__CoastMsg.
typedef struct user_action_interfaces__msg__CoastMsg__Sequence
{
  user_action_interfaces__msg__CoastMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_action_interfaces__msg__CoastMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USER_ACTION_INTERFACES__MSG__DETAIL__COAST_MSG__STRUCT_H_
