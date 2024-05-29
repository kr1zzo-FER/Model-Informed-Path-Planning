// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from user_action_interfaces:msg/CoastMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "user_action_interfaces/msg/detail/coast_msg__rosidl_typesupport_introspection_c.h"
#include "user_action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "user_action_interfaces/msg/detail/coast_msg__functions.h"
#include "user_action_interfaces/msg/detail/coast_msg__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `frame_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `coast_points`
// Member `green_points`
// Member `red_points`
// Member `yellow_points`
#include "sensor_msgs/msg/point_cloud2.h"
// Member `coast_points`
// Member `green_points`
// Member `red_points`
// Member `yellow_points`
#include "sensor_msgs/msg/detail/point_cloud2__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_action_interfaces__msg__CoastMsg__init(message_memory);
}

void user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_fini_function(void * message_memory)
{
  user_action_interfaces__msg__CoastMsg__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_message_member_array[7] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__msg__CoastMsg, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frame_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__msg__CoastMsg, frame_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "coast_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__msg__CoastMsg, coast_points),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "green_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__msg__CoastMsg, green_points),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "red_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__msg__CoastMsg, red_points),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yellow_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__msg__CoastMsg, yellow_points),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "grid_size",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__msg__CoastMsg, grid_size),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_message_members = {
  "user_action_interfaces__msg",  // message namespace
  "CoastMsg",  // message name
  7,  // number of fields
  sizeof(user_action_interfaces__msg__CoastMsg),
  user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_message_member_array,  // message members
  user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_message_type_support_handle = {
  0,
  &user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_message_members,
  get_message_typesupport_handle_function,
  &user_action_interfaces__msg__CoastMsg__get_type_hash,
  &user_action_interfaces__msg__CoastMsg__get_type_description,
  &user_action_interfaces__msg__CoastMsg__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, msg, CoastMsg)() {
  user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, PointCloud2)();
  user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, PointCloud2)();
  user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, PointCloud2)();
  user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, PointCloud2)();
  if (!user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_message_type_support_handle.typesupport_identifier) {
    user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_action_interfaces__msg__CoastMsg__rosidl_typesupport_introspection_c__CoastMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
