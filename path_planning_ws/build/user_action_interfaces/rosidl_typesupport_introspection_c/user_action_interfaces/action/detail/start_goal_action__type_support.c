// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from user_action_interfaces:action/StartGoalAction.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"
#include "user_action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "user_action_interfaces/action/detail/start_goal_action__functions.h"
#include "user_action_interfaces/action/detail/start_goal_action__struct.h"


// Include directives for member types
// Member `start`
// Member `goal`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__StartGoalAction_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_action_interfaces__action__StartGoalAction_Goal__init(message_memory);
}

void user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__StartGoalAction_Goal_fini_function(void * message_memory)
{
  user_action_interfaces__action__StartGoalAction_Goal__fini(message_memory);
}

size_t user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__size_function__StartGoalAction_Goal__start(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Goal__start(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Goal__start(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_Goal__start(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Goal__start(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_Goal__start(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Goal__start(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_Goal__start(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__size_function__StartGoalAction_Goal__goal(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Goal__goal(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Goal__goal(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_Goal__goal(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Goal__goal(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_Goal__goal(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Goal__goal(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_Goal__goal(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__StartGoalAction_Goal_message_member_array[2] = {
  {
    "start",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_Goal, start),  // bytes offset in struct
    NULL,  // default value
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__size_function__StartGoalAction_Goal__start,  // size() function pointer
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Goal__start,  // get_const(index) function pointer
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Goal__start,  // get(index) function pointer
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_Goal__start,  // fetch(index, &value) function pointer
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_Goal__start,  // assign(index, value) function pointer
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_Goal__start  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_Goal, goal),  // bytes offset in struct
    NULL,  // default value
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__size_function__StartGoalAction_Goal__goal,  // size() function pointer
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Goal__goal,  // get_const(index) function pointer
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Goal__goal,  // get(index) function pointer
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_Goal__goal,  // fetch(index, &value) function pointer
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_Goal__goal,  // assign(index, value) function pointer
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_Goal__goal  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__StartGoalAction_Goal_message_members = {
  "user_action_interfaces__action",  // message namespace
  "StartGoalAction_Goal",  // message name
  2,  // number of fields
  sizeof(user_action_interfaces__action__StartGoalAction_Goal),
  user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__StartGoalAction_Goal_message_member_array,  // message members
  user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__StartGoalAction_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__StartGoalAction_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__StartGoalAction_Goal_message_type_support_handle = {
  0,
  &user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__StartGoalAction_Goal_message_members,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_Goal__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_Goal__get_type_description,
  &user_action_interfaces__action__StartGoalAction_Goal__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_Goal)() {
  if (!user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__StartGoalAction_Goal_message_type_support_handle.typesupport_identifier) {
    user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__StartGoalAction_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_action_interfaces__action__StartGoalAction_Goal__rosidl_typesupport_introspection_c__StartGoalAction_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"


// Include directives for member types
// Member `path_x`
// Member `path_y`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__StartGoalAction_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_action_interfaces__action__StartGoalAction_Result__init(message_memory);
}

void user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__StartGoalAction_Result_fini_function(void * message_memory)
{
  user_action_interfaces__action__StartGoalAction_Result__fini(message_memory);
}

size_t user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__size_function__StartGoalAction_Result__path_x(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Result__path_x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Result__path_x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_Result__path_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Result__path_x(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_Result__path_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Result__path_x(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_Result__path_x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__size_function__StartGoalAction_Result__path_y(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Result__path_y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Result__path_y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_Result__path_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Result__path_y(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_Result__path_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Result__path_y(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_Result__path_y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__StartGoalAction_Result_message_member_array[2] = {
  {
    "path_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_Result, path_x),  // bytes offset in struct
    NULL,  // default value
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__size_function__StartGoalAction_Result__path_x,  // size() function pointer
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Result__path_x,  // get_const(index) function pointer
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Result__path_x,  // get(index) function pointer
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_Result__path_x,  // fetch(index, &value) function pointer
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_Result__path_x,  // assign(index, value) function pointer
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_Result__path_x  // resize(index) function pointer
  },
  {
    "path_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_Result, path_y),  // bytes offset in struct
    NULL,  // default value
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__size_function__StartGoalAction_Result__path_y,  // size() function pointer
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Result__path_y,  // get_const(index) function pointer
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Result__path_y,  // get(index) function pointer
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_Result__path_y,  // fetch(index, &value) function pointer
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_Result__path_y,  // assign(index, value) function pointer
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_Result__path_y  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__StartGoalAction_Result_message_members = {
  "user_action_interfaces__action",  // message namespace
  "StartGoalAction_Result",  // message name
  2,  // number of fields
  sizeof(user_action_interfaces__action__StartGoalAction_Result),
  user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__StartGoalAction_Result_message_member_array,  // message members
  user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__StartGoalAction_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__StartGoalAction_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__StartGoalAction_Result_message_type_support_handle = {
  0,
  &user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__StartGoalAction_Result_message_members,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_Result__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_Result__get_type_description,
  &user_action_interfaces__action__StartGoalAction_Result__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_Result)() {
  if (!user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__StartGoalAction_Result_message_type_support_handle.typesupport_identifier) {
    user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__StartGoalAction_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_action_interfaces__action__StartGoalAction_Result__rosidl_typesupport_introspection_c__StartGoalAction_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"


// Include directives for member types
// Member `partial_path_x`
// Member `partial_path_y`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__StartGoalAction_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_action_interfaces__action__StartGoalAction_Feedback__init(message_memory);
}

void user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__StartGoalAction_Feedback_fini_function(void * message_memory)
{
  user_action_interfaces__action__StartGoalAction_Feedback__fini(message_memory);
}

size_t user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__size_function__StartGoalAction_Feedback__partial_path_x(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Feedback__partial_path_x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Feedback__partial_path_x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_Feedback__partial_path_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Feedback__partial_path_x(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_Feedback__partial_path_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Feedback__partial_path_x(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_Feedback__partial_path_x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__size_function__StartGoalAction_Feedback__partial_path_y(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Feedback__partial_path_y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Feedback__partial_path_y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_Feedback__partial_path_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Feedback__partial_path_y(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_Feedback__partial_path_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Feedback__partial_path_y(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_Feedback__partial_path_y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__StartGoalAction_Feedback_message_member_array[2] = {
  {
    "partial_path_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_Feedback, partial_path_x),  // bytes offset in struct
    NULL,  // default value
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__size_function__StartGoalAction_Feedback__partial_path_x,  // size() function pointer
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Feedback__partial_path_x,  // get_const(index) function pointer
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Feedback__partial_path_x,  // get(index) function pointer
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_Feedback__partial_path_x,  // fetch(index, &value) function pointer
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_Feedback__partial_path_x,  // assign(index, value) function pointer
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_Feedback__partial_path_x  // resize(index) function pointer
  },
  {
    "partial_path_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_Feedback, partial_path_y),  // bytes offset in struct
    NULL,  // default value
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__size_function__StartGoalAction_Feedback__partial_path_y,  // size() function pointer
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_Feedback__partial_path_y,  // get_const(index) function pointer
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__get_function__StartGoalAction_Feedback__partial_path_y,  // get(index) function pointer
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_Feedback__partial_path_y,  // fetch(index, &value) function pointer
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_Feedback__partial_path_y,  // assign(index, value) function pointer
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_Feedback__partial_path_y  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__StartGoalAction_Feedback_message_members = {
  "user_action_interfaces__action",  // message namespace
  "StartGoalAction_Feedback",  // message name
  2,  // number of fields
  sizeof(user_action_interfaces__action__StartGoalAction_Feedback),
  user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__StartGoalAction_Feedback_message_member_array,  // message members
  user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__StartGoalAction_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__StartGoalAction_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__StartGoalAction_Feedback_message_type_support_handle = {
  0,
  &user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__StartGoalAction_Feedback_message_members,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_Feedback__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_Feedback__get_type_description,
  &user_action_interfaces__action__StartGoalAction_Feedback__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_Feedback)() {
  if (!user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__StartGoalAction_Feedback_message_type_support_handle.typesupport_identifier) {
    user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__StartGoalAction_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_action_interfaces__action__StartGoalAction_Feedback__rosidl_typesupport_introspection_c__StartGoalAction_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "user_action_interfaces/action/start_goal_action.h"
// Member `goal`
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_action_interfaces__action__StartGoalAction_SendGoal_Request__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_action_interfaces__action__StartGoalAction_SendGoal_Request__init(message_memory);
}

void user_action_interfaces__action__StartGoalAction_SendGoal_Request__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_fini_function(void * message_memory)
{
  user_action_interfaces__action__StartGoalAction_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember user_action_interfaces__action__StartGoalAction_SendGoal_Request__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_action_interfaces__action__StartGoalAction_SendGoal_Request__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_message_members = {
  "user_action_interfaces__action",  // message namespace
  "StartGoalAction_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(user_action_interfaces__action__StartGoalAction_SendGoal_Request),
  user_action_interfaces__action__StartGoalAction_SendGoal_Request__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_message_member_array,  // message members
  user_action_interfaces__action__StartGoalAction_SendGoal_Request__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  user_action_interfaces__action__StartGoalAction_SendGoal_Request__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_action_interfaces__action__StartGoalAction_SendGoal_Request__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_message_type_support_handle = {
  0,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Request__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Request__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Request__get_type_description,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal_Request)() {
  user_action_interfaces__action__StartGoalAction_SendGoal_Request__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  user_action_interfaces__action__StartGoalAction_SendGoal_Request__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_Goal)();
  if (!user_action_interfaces__action__StartGoalAction_SendGoal_Request__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    user_action_interfaces__action__StartGoalAction_SendGoal_Request__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_action_interfaces__action__StartGoalAction_SendGoal_Request__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_action_interfaces__action__StartGoalAction_SendGoal_Response__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_action_interfaces__action__StartGoalAction_SendGoal_Response__init(message_memory);
}

void user_action_interfaces__action__StartGoalAction_SendGoal_Response__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_fini_function(void * message_memory)
{
  user_action_interfaces__action__StartGoalAction_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember user_action_interfaces__action__StartGoalAction_SendGoal_Response__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_action_interfaces__action__StartGoalAction_SendGoal_Response__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_message_members = {
  "user_action_interfaces__action",  // message namespace
  "StartGoalAction_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(user_action_interfaces__action__StartGoalAction_SendGoal_Response),
  user_action_interfaces__action__StartGoalAction_SendGoal_Response__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_message_member_array,  // message members
  user_action_interfaces__action__StartGoalAction_SendGoal_Response__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  user_action_interfaces__action__StartGoalAction_SendGoal_Response__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_action_interfaces__action__StartGoalAction_SendGoal_Response__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_message_type_support_handle = {
  0,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Response__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Response__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Response__get_type_description,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal_Response)() {
  user_action_interfaces__action__StartGoalAction_SendGoal_Response__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!user_action_interfaces__action__StartGoalAction_SendGoal_Response__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    user_action_interfaces__action__StartGoalAction_SendGoal_Response__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_action_interfaces__action__StartGoalAction_SendGoal_Response__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
// already included above
// #include "user_action_interfaces/action/start_goal_action.h"
// Member `request`
// Member `response`
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_action_interfaces__action__StartGoalAction_SendGoal_Event__init(message_memory);
}

void user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_fini_function(void * message_memory)
{
  user_action_interfaces__action__StartGoalAction_SendGoal_Event__fini(message_memory);
}

size_t user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__StartGoalAction_SendGoal_Event__request(
  const void * untyped_member)
{
  const user_action_interfaces__action__StartGoalAction_SendGoal_Request__Sequence * member =
    (const user_action_interfaces__action__StartGoalAction_SendGoal_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_SendGoal_Event__request(
  const void * untyped_member, size_t index)
{
  const user_action_interfaces__action__StartGoalAction_SendGoal_Request__Sequence * member =
    (const user_action_interfaces__action__StartGoalAction_SendGoal_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__StartGoalAction_SendGoal_Event__request(
  void * untyped_member, size_t index)
{
  user_action_interfaces__action__StartGoalAction_SendGoal_Request__Sequence * member =
    (user_action_interfaces__action__StartGoalAction_SendGoal_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_SendGoal_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const user_action_interfaces__action__StartGoalAction_SendGoal_Request * item =
    ((const user_action_interfaces__action__StartGoalAction_SendGoal_Request *)
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_SendGoal_Event__request(untyped_member, index));
  user_action_interfaces__action__StartGoalAction_SendGoal_Request * value =
    (user_action_interfaces__action__StartGoalAction_SendGoal_Request *)(untyped_value);
  *value = *item;
}

void user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_SendGoal_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  user_action_interfaces__action__StartGoalAction_SendGoal_Request * item =
    ((user_action_interfaces__action__StartGoalAction_SendGoal_Request *)
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__StartGoalAction_SendGoal_Event__request(untyped_member, index));
  const user_action_interfaces__action__StartGoalAction_SendGoal_Request * value =
    (const user_action_interfaces__action__StartGoalAction_SendGoal_Request *)(untyped_value);
  *item = *value;
}

bool user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_SendGoal_Event__request(
  void * untyped_member, size_t size)
{
  user_action_interfaces__action__StartGoalAction_SendGoal_Request__Sequence * member =
    (user_action_interfaces__action__StartGoalAction_SendGoal_Request__Sequence *)(untyped_member);
  user_action_interfaces__action__StartGoalAction_SendGoal_Request__Sequence__fini(member);
  return user_action_interfaces__action__StartGoalAction_SendGoal_Request__Sequence__init(member, size);
}

size_t user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__StartGoalAction_SendGoal_Event__response(
  const void * untyped_member)
{
  const user_action_interfaces__action__StartGoalAction_SendGoal_Response__Sequence * member =
    (const user_action_interfaces__action__StartGoalAction_SendGoal_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_SendGoal_Event__response(
  const void * untyped_member, size_t index)
{
  const user_action_interfaces__action__StartGoalAction_SendGoal_Response__Sequence * member =
    (const user_action_interfaces__action__StartGoalAction_SendGoal_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__StartGoalAction_SendGoal_Event__response(
  void * untyped_member, size_t index)
{
  user_action_interfaces__action__StartGoalAction_SendGoal_Response__Sequence * member =
    (user_action_interfaces__action__StartGoalAction_SendGoal_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_SendGoal_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const user_action_interfaces__action__StartGoalAction_SendGoal_Response * item =
    ((const user_action_interfaces__action__StartGoalAction_SendGoal_Response *)
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_SendGoal_Event__response(untyped_member, index));
  user_action_interfaces__action__StartGoalAction_SendGoal_Response * value =
    (user_action_interfaces__action__StartGoalAction_SendGoal_Response *)(untyped_value);
  *value = *item;
}

void user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_SendGoal_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  user_action_interfaces__action__StartGoalAction_SendGoal_Response * item =
    ((user_action_interfaces__action__StartGoalAction_SendGoal_Response *)
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__StartGoalAction_SendGoal_Event__response(untyped_member, index));
  const user_action_interfaces__action__StartGoalAction_SendGoal_Response * value =
    (const user_action_interfaces__action__StartGoalAction_SendGoal_Response *)(untyped_value);
  *item = *value;
}

bool user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_SendGoal_Event__response(
  void * untyped_member, size_t size)
{
  user_action_interfaces__action__StartGoalAction_SendGoal_Response__Sequence * member =
    (user_action_interfaces__action__StartGoalAction_SendGoal_Response__Sequence *)(untyped_member);
  user_action_interfaces__action__StartGoalAction_SendGoal_Response__Sequence__fini(member);
  return user_action_interfaces__action__StartGoalAction_SendGoal_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_SendGoal_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_SendGoal_Event, request),  // bytes offset in struct
    NULL,  // default value
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__StartGoalAction_SendGoal_Event__request,  // size() function pointer
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_SendGoal_Event__request,  // get_const(index) function pointer
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__StartGoalAction_SendGoal_Event__request,  // get(index) function pointer
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_SendGoal_Event__request,  // fetch(index, &value) function pointer
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_SendGoal_Event__request,  // assign(index, value) function pointer
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_SendGoal_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_SendGoal_Event, response),  // bytes offset in struct
    NULL,  // default value
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__StartGoalAction_SendGoal_Event__response,  // size() function pointer
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_SendGoal_Event__response,  // get_const(index) function pointer
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__StartGoalAction_SendGoal_Event__response,  // get(index) function pointer
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_SendGoal_Event__response,  // fetch(index, &value) function pointer
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_SendGoal_Event__response,  // assign(index, value) function pointer
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_SendGoal_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_message_members = {
  "user_action_interfaces__action",  // message namespace
  "StartGoalAction_SendGoal_Event",  // message name
  3,  // number of fields
  sizeof(user_action_interfaces__action__StartGoalAction_SendGoal_Event),
  user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_message_member_array,  // message members
  user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_message_type_support_handle = {
  0,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_message_members,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Event__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Event__get_type_description,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal_Event)() {
  user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal_Request)();
  user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal_Response)();
  if (!user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_message_type_support_handle.typesupport_identifier) {
    user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_service_members = {
  "user_action_interfaces__action",  // service namespace
  "StartGoalAction_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_message_type_support_handle,
  NULL,  // response message
  // user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_message_type_support_handle
  NULL  // event_message
  // user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_message_type_support_handle
};


static rosidl_service_type_support_t user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_service_type_support_handle = {
  0,
  &user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_service_members,
  get_service_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Request__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Request_message_type_support_handle,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Response__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Response_message_type_support_handle,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Event__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    user_action_interfaces,
    action,
    StartGoalAction_SendGoal
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    user_action_interfaces,
    action,
    StartGoalAction_SendGoal
  ),
  &user_action_interfaces__action__StartGoalAction_SendGoal__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_SendGoal__get_type_description,
  &user_action_interfaces__action__StartGoalAction_SendGoal__get_type_description_sources,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal_Response)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal_Event)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_action_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal)() {
  if (!user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_service_type_support_handle.typesupport_identifier) {
    user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal_Event)()->data;
  }

  return &user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_action_interfaces__action__StartGoalAction_GetResult_Request__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_action_interfaces__action__StartGoalAction_GetResult_Request__init(message_memory);
}

void user_action_interfaces__action__StartGoalAction_GetResult_Request__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Request_fini_function(void * message_memory)
{
  user_action_interfaces__action__StartGoalAction_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember user_action_interfaces__action__StartGoalAction_GetResult_Request__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_action_interfaces__action__StartGoalAction_GetResult_Request__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Request_message_members = {
  "user_action_interfaces__action",  // message namespace
  "StartGoalAction_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(user_action_interfaces__action__StartGoalAction_GetResult_Request),
  user_action_interfaces__action__StartGoalAction_GetResult_Request__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Request_message_member_array,  // message members
  user_action_interfaces__action__StartGoalAction_GetResult_Request__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  user_action_interfaces__action__StartGoalAction_GetResult_Request__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_action_interfaces__action__StartGoalAction_GetResult_Request__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Request_message_type_support_handle = {
  0,
  &user_action_interfaces__action__StartGoalAction_GetResult_Request__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_GetResult_Request__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_GetResult_Request__get_type_description,
  &user_action_interfaces__action__StartGoalAction_GetResult_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult_Request)() {
  user_action_interfaces__action__StartGoalAction_GetResult_Request__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!user_action_interfaces__action__StartGoalAction_GetResult_Request__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    user_action_interfaces__action__StartGoalAction_GetResult_Request__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_action_interfaces__action__StartGoalAction_GetResult_Request__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "user_action_interfaces/action/start_goal_action.h"
// Member `result`
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_action_interfaces__action__StartGoalAction_GetResult_Response__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_action_interfaces__action__StartGoalAction_GetResult_Response__init(message_memory);
}

void user_action_interfaces__action__StartGoalAction_GetResult_Response__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_fini_function(void * message_memory)
{
  user_action_interfaces__action__StartGoalAction_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember user_action_interfaces__action__StartGoalAction_GetResult_Response__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_action_interfaces__action__StartGoalAction_GetResult_Response__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_message_members = {
  "user_action_interfaces__action",  // message namespace
  "StartGoalAction_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(user_action_interfaces__action__StartGoalAction_GetResult_Response),
  user_action_interfaces__action__StartGoalAction_GetResult_Response__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_message_member_array,  // message members
  user_action_interfaces__action__StartGoalAction_GetResult_Response__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  user_action_interfaces__action__StartGoalAction_GetResult_Response__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_action_interfaces__action__StartGoalAction_GetResult_Response__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_message_type_support_handle = {
  0,
  &user_action_interfaces__action__StartGoalAction_GetResult_Response__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_GetResult_Response__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_GetResult_Response__get_type_description,
  &user_action_interfaces__action__StartGoalAction_GetResult_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult_Response)() {
  user_action_interfaces__action__StartGoalAction_GetResult_Response__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_Result)();
  if (!user_action_interfaces__action__StartGoalAction_GetResult_Response__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    user_action_interfaces__action__StartGoalAction_GetResult_Response__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_action_interfaces__action__StartGoalAction_GetResult_Response__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/service_event_info.h"
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
// already included above
// #include "user_action_interfaces/action/start_goal_action.h"
// Member `request`
// Member `response`
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_action_interfaces__action__StartGoalAction_GetResult_Event__init(message_memory);
}

void user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_fini_function(void * message_memory)
{
  user_action_interfaces__action__StartGoalAction_GetResult_Event__fini(message_memory);
}

size_t user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__size_function__StartGoalAction_GetResult_Event__request(
  const void * untyped_member)
{
  const user_action_interfaces__action__StartGoalAction_GetResult_Request__Sequence * member =
    (const user_action_interfaces__action__StartGoalAction_GetResult_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_GetResult_Event__request(
  const void * untyped_member, size_t index)
{
  const user_action_interfaces__action__StartGoalAction_GetResult_Request__Sequence * member =
    (const user_action_interfaces__action__StartGoalAction_GetResult_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__get_function__StartGoalAction_GetResult_Event__request(
  void * untyped_member, size_t index)
{
  user_action_interfaces__action__StartGoalAction_GetResult_Request__Sequence * member =
    (user_action_interfaces__action__StartGoalAction_GetResult_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_GetResult_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const user_action_interfaces__action__StartGoalAction_GetResult_Request * item =
    ((const user_action_interfaces__action__StartGoalAction_GetResult_Request *)
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_GetResult_Event__request(untyped_member, index));
  user_action_interfaces__action__StartGoalAction_GetResult_Request * value =
    (user_action_interfaces__action__StartGoalAction_GetResult_Request *)(untyped_value);
  *value = *item;
}

void user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_GetResult_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  user_action_interfaces__action__StartGoalAction_GetResult_Request * item =
    ((user_action_interfaces__action__StartGoalAction_GetResult_Request *)
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__get_function__StartGoalAction_GetResult_Event__request(untyped_member, index));
  const user_action_interfaces__action__StartGoalAction_GetResult_Request * value =
    (const user_action_interfaces__action__StartGoalAction_GetResult_Request *)(untyped_value);
  *item = *value;
}

bool user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_GetResult_Event__request(
  void * untyped_member, size_t size)
{
  user_action_interfaces__action__StartGoalAction_GetResult_Request__Sequence * member =
    (user_action_interfaces__action__StartGoalAction_GetResult_Request__Sequence *)(untyped_member);
  user_action_interfaces__action__StartGoalAction_GetResult_Request__Sequence__fini(member);
  return user_action_interfaces__action__StartGoalAction_GetResult_Request__Sequence__init(member, size);
}

size_t user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__size_function__StartGoalAction_GetResult_Event__response(
  const void * untyped_member)
{
  const user_action_interfaces__action__StartGoalAction_GetResult_Response__Sequence * member =
    (const user_action_interfaces__action__StartGoalAction_GetResult_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_GetResult_Event__response(
  const void * untyped_member, size_t index)
{
  const user_action_interfaces__action__StartGoalAction_GetResult_Response__Sequence * member =
    (const user_action_interfaces__action__StartGoalAction_GetResult_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__get_function__StartGoalAction_GetResult_Event__response(
  void * untyped_member, size_t index)
{
  user_action_interfaces__action__StartGoalAction_GetResult_Response__Sequence * member =
    (user_action_interfaces__action__StartGoalAction_GetResult_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_GetResult_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const user_action_interfaces__action__StartGoalAction_GetResult_Response * item =
    ((const user_action_interfaces__action__StartGoalAction_GetResult_Response *)
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_GetResult_Event__response(untyped_member, index));
  user_action_interfaces__action__StartGoalAction_GetResult_Response * value =
    (user_action_interfaces__action__StartGoalAction_GetResult_Response *)(untyped_value);
  *value = *item;
}

void user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_GetResult_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  user_action_interfaces__action__StartGoalAction_GetResult_Response * item =
    ((user_action_interfaces__action__StartGoalAction_GetResult_Response *)
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__get_function__StartGoalAction_GetResult_Event__response(untyped_member, index));
  const user_action_interfaces__action__StartGoalAction_GetResult_Response * value =
    (const user_action_interfaces__action__StartGoalAction_GetResult_Response *)(untyped_value);
  *item = *value;
}

bool user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_GetResult_Event__response(
  void * untyped_member, size_t size)
{
  user_action_interfaces__action__StartGoalAction_GetResult_Response__Sequence * member =
    (user_action_interfaces__action__StartGoalAction_GetResult_Response__Sequence *)(untyped_member);
  user_action_interfaces__action__StartGoalAction_GetResult_Response__Sequence__fini(member);
  return user_action_interfaces__action__StartGoalAction_GetResult_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_GetResult_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_GetResult_Event, request),  // bytes offset in struct
    NULL,  // default value
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__size_function__StartGoalAction_GetResult_Event__request,  // size() function pointer
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_GetResult_Event__request,  // get_const(index) function pointer
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__get_function__StartGoalAction_GetResult_Event__request,  // get(index) function pointer
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_GetResult_Event__request,  // fetch(index, &value) function pointer
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_GetResult_Event__request,  // assign(index, value) function pointer
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_GetResult_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_GetResult_Event, response),  // bytes offset in struct
    NULL,  // default value
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__size_function__StartGoalAction_GetResult_Event__response,  // size() function pointer
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__StartGoalAction_GetResult_Event__response,  // get_const(index) function pointer
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__get_function__StartGoalAction_GetResult_Event__response,  // get(index) function pointer
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__StartGoalAction_GetResult_Event__response,  // fetch(index, &value) function pointer
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__StartGoalAction_GetResult_Event__response,  // assign(index, value) function pointer
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__StartGoalAction_GetResult_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_message_members = {
  "user_action_interfaces__action",  // message namespace
  "StartGoalAction_GetResult_Event",  // message name
  3,  // number of fields
  sizeof(user_action_interfaces__action__StartGoalAction_GetResult_Event),
  user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_message_member_array,  // message members
  user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_message_type_support_handle = {
  0,
  &user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_message_members,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_GetResult_Event__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_GetResult_Event__get_type_description,
  &user_action_interfaces__action__StartGoalAction_GetResult_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult_Event)() {
  user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult_Request)();
  user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult_Response)();
  if (!user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_message_type_support_handle.typesupport_identifier) {
    user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_service_members = {
  "user_action_interfaces__action",  // service namespace
  "StartGoalAction_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Request_message_type_support_handle,
  NULL,  // response message
  // user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_message_type_support_handle
  NULL  // event_message
  // user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_message_type_support_handle
};


static rosidl_service_type_support_t user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_service_type_support_handle = {
  0,
  &user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_service_members,
  get_service_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_GetResult_Request__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Request_message_type_support_handle,
  &user_action_interfaces__action__StartGoalAction_GetResult_Response__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Response_message_type_support_handle,
  &user_action_interfaces__action__StartGoalAction_GetResult_Event__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    user_action_interfaces,
    action,
    StartGoalAction_GetResult
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    user_action_interfaces,
    action,
    StartGoalAction_GetResult
  ),
  &user_action_interfaces__action__StartGoalAction_GetResult__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_GetResult__get_type_description,
  &user_action_interfaces__action__StartGoalAction_GetResult__get_type_description_sources,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult_Response)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult_Event)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_action_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult)() {
  if (!user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_service_type_support_handle.typesupport_identifier) {
    user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult_Event)()->data;
  }

  return &user_action_interfaces__action__detail__start_goal_action__rosidl_typesupport_introspection_c__StartGoalAction_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "user_action_interfaces/action/start_goal_action.h"
// Member `feedback`
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void user_action_interfaces__action__StartGoalAction_FeedbackMessage__rosidl_typesupport_introspection_c__StartGoalAction_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  user_action_interfaces__action__StartGoalAction_FeedbackMessage__init(message_memory);
}

void user_action_interfaces__action__StartGoalAction_FeedbackMessage__rosidl_typesupport_introspection_c__StartGoalAction_FeedbackMessage_fini_function(void * message_memory)
{
  user_action_interfaces__action__StartGoalAction_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember user_action_interfaces__action__StartGoalAction_FeedbackMessage__rosidl_typesupport_introspection_c__StartGoalAction_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces__action__StartGoalAction_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers user_action_interfaces__action__StartGoalAction_FeedbackMessage__rosidl_typesupport_introspection_c__StartGoalAction_FeedbackMessage_message_members = {
  "user_action_interfaces__action",  // message namespace
  "StartGoalAction_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(user_action_interfaces__action__StartGoalAction_FeedbackMessage),
  user_action_interfaces__action__StartGoalAction_FeedbackMessage__rosidl_typesupport_introspection_c__StartGoalAction_FeedbackMessage_message_member_array,  // message members
  user_action_interfaces__action__StartGoalAction_FeedbackMessage__rosidl_typesupport_introspection_c__StartGoalAction_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  user_action_interfaces__action__StartGoalAction_FeedbackMessage__rosidl_typesupport_introspection_c__StartGoalAction_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t user_action_interfaces__action__StartGoalAction_FeedbackMessage__rosidl_typesupport_introspection_c__StartGoalAction_FeedbackMessage_message_type_support_handle = {
  0,
  &user_action_interfaces__action__StartGoalAction_FeedbackMessage__rosidl_typesupport_introspection_c__StartGoalAction_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_FeedbackMessage__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_FeedbackMessage__get_type_description,
  &user_action_interfaces__action__StartGoalAction_FeedbackMessage__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_user_action_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_FeedbackMessage)() {
  user_action_interfaces__action__StartGoalAction_FeedbackMessage__rosidl_typesupport_introspection_c__StartGoalAction_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  user_action_interfaces__action__StartGoalAction_FeedbackMessage__rosidl_typesupport_introspection_c__StartGoalAction_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_Feedback)();
  if (!user_action_interfaces__action__StartGoalAction_FeedbackMessage__rosidl_typesupport_introspection_c__StartGoalAction_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    user_action_interfaces__action__StartGoalAction_FeedbackMessage__rosidl_typesupport_introspection_c__StartGoalAction_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &user_action_interfaces__action__StartGoalAction_FeedbackMessage__rosidl_typesupport_introspection_c__StartGoalAction_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
