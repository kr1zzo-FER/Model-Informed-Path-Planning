// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from user_action_interfaces:msg/StartGoalMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "user_action_interfaces/msg/detail/start_goal_msg__rosidl_typesupport_introspection_c.h"
#include "user_action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "user_action_interfaces/msg/detail/start_goal_msg__functions.h"
#include "user_action_interfaces/msg/detail/start_goal_msg__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `frame_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `start`
// Member `goal`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__StartGoalMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_action_interfaces__msg__StartGoalMsg__init(message_memory);
}

void user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__StartGoalMsg_fini_function(void * message_memory)
{
  user_action_interfaces__msg__StartGoalMsg__fini(message_memory);
}

size_t user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__size_function__StartGoalMsg__start(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__get_const_function__StartGoalMsg__start(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__get_function__StartGoalMsg__start(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__fetch_function__StartGoalMsg__start(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__get_const_function__StartGoalMsg__start(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__assign_function__StartGoalMsg__start(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__get_function__StartGoalMsg__start(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__resize_function__StartGoalMsg__start(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__size_function__StartGoalMsg__goal(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__get_const_function__StartGoalMsg__goal(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__get_function__StartGoalMsg__goal(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__fetch_function__StartGoalMsg__goal(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__get_const_function__StartGoalMsg__goal(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__assign_function__StartGoalMsg__goal(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__get_function__StartGoalMsg__goal(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__resize_function__StartGoalMsg__goal(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__StartGoalMsg_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__msg__StartGoalMsg, header),  // bytes offset in struct
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
    offsetof(user_action_interfaces__msg__StartGoalMsg, frame_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "start",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__msg__StartGoalMsg, start),  // bytes offset in struct
    NULL,  // default value
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__size_function__StartGoalMsg__start,  // size() function pointer
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__get_const_function__StartGoalMsg__start,  // get_const(index) function pointer
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__get_function__StartGoalMsg__start,  // get(index) function pointer
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__fetch_function__StartGoalMsg__start,  // fetch(index, &value) function pointer
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__assign_function__StartGoalMsg__start,  // assign(index, value) function pointer
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__resize_function__StartGoalMsg__start  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__msg__StartGoalMsg, goal),  // bytes offset in struct
    NULL,  // default value
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__size_function__StartGoalMsg__goal,  // size() function pointer
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__get_const_function__StartGoalMsg__goal,  // get_const(index) function pointer
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__get_function__StartGoalMsg__goal,  // get(index) function pointer
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__fetch_function__StartGoalMsg__goal,  // fetch(index, &value) function pointer
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__assign_function__StartGoalMsg__goal,  // assign(index, value) function pointer
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__resize_function__StartGoalMsg__goal  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__StartGoalMsg_message_members = {
  "user_action_interfaces__msg",  // message namespace
  "StartGoalMsg",  // message name
  4,  // number of fields
  sizeof(user_action_interfaces__msg__StartGoalMsg),
  user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__StartGoalMsg_message_member_array,  // message members
  user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__StartGoalMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__StartGoalMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__StartGoalMsg_message_type_support_handle = {
  0,
  &user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__StartGoalMsg_message_members,
  get_message_typesupport_handle_function,
  &user_action_interfaces__msg__StartGoalMsg__get_type_hash,
  &user_action_interfaces__msg__StartGoalMsg__get_type_description,
  &user_action_interfaces__msg__StartGoalMsg__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, msg, StartGoalMsg)() {
  user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__StartGoalMsg_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__StartGoalMsg_message_type_support_handle.typesupport_identifier) {
    user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__StartGoalMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_action_interfaces__msg__StartGoalMsg__rosidl_typesupport_introspection_c__StartGoalMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
