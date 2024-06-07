// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from user_action_interfaces:action/StartGoalAction.idl
// generated code does not contain a copyright notice
#include "user_action_interfaces/action/detail/start_goal_action__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "user_action_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "user_action_interfaces/action/detail/start_goal_action__struct.h"
#include "user_action_interfaces/action/detail/start_goal_action__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // goal, start
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // goal, start

// forward declare type support functions


using _StartGoalAction_Goal__ros_msg_type = user_action_interfaces__action__StartGoalAction_Goal;

static bool _StartGoalAction_Goal__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StartGoalAction_Goal__ros_msg_type * ros_message = static_cast<const _StartGoalAction_Goal__ros_msg_type *>(untyped_ros_message);
  // Field name: start
  {
    size_t size = ros_message->start.size;
    auto array_ptr = ros_message->start.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: goal
  {
    size_t size = ros_message->goal.size;
    auto array_ptr = ros_message->goal.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _StartGoalAction_Goal__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StartGoalAction_Goal__ros_msg_type * ros_message = static_cast<_StartGoalAction_Goal__ros_msg_type *>(untyped_ros_message);
  // Field name: start
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->start.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->start);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->start, size)) {
      fprintf(stderr, "failed to create array for field 'start'");
      return false;
    }
    auto array_ptr = ros_message->start.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: goal
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->goal.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->goal);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->goal, size)) {
      fprintf(stderr, "failed to create array for field 'goal'");
      return false;
    }
    auto array_ptr = ros_message->goal.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_Goal(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StartGoalAction_Goal__ros_msg_type * ros_message = static_cast<const _StartGoalAction_Goal__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name start
  {
    size_t array_size = ros_message->start.size;
    auto array_ptr = ros_message->start.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name goal
  {
    size_t array_size = ros_message->goal.size;
    auto array_ptr = ros_message->goal.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _StartGoalAction_Goal__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_user_action_interfaces__action__StartGoalAction_Goal(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_Goal(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: start
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: goal
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = user_action_interfaces__action__StartGoalAction_Goal;
    is_plain =
      (
      offsetof(DataType, goal) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _StartGoalAction_Goal__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_user_action_interfaces__action__StartGoalAction_Goal(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StartGoalAction_Goal = {
  "user_action_interfaces::action",
  "StartGoalAction_Goal",
  _StartGoalAction_Goal__cdr_serialize,
  _StartGoalAction_Goal__cdr_deserialize,
  _StartGoalAction_Goal__get_serialized_size,
  _StartGoalAction_Goal__max_serialized_size
};

static rosidl_message_type_support_t _StartGoalAction_Goal__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StartGoalAction_Goal,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_Goal__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_Goal__get_type_description,
  &user_action_interfaces__action__StartGoalAction_Goal__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_Goal)() {
  return &_StartGoalAction_Goal__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"  // path_x, path_y
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"  // path_x, path_y

// forward declare type support functions


using _StartGoalAction_Result__ros_msg_type = user_action_interfaces__action__StartGoalAction_Result;

static bool _StartGoalAction_Result__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StartGoalAction_Result__ros_msg_type * ros_message = static_cast<const _StartGoalAction_Result__ros_msg_type *>(untyped_ros_message);
  // Field name: path_x
  {
    size_t size = ros_message->path_x.size;
    auto array_ptr = ros_message->path_x.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: path_y
  {
    size_t size = ros_message->path_y.size;
    auto array_ptr = ros_message->path_y.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _StartGoalAction_Result__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StartGoalAction_Result__ros_msg_type * ros_message = static_cast<_StartGoalAction_Result__ros_msg_type *>(untyped_ros_message);
  // Field name: path_x
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->path_x.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->path_x);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->path_x, size)) {
      fprintf(stderr, "failed to create array for field 'path_x'");
      return false;
    }
    auto array_ptr = ros_message->path_x.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: path_y
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->path_y.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->path_y);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->path_y, size)) {
      fprintf(stderr, "failed to create array for field 'path_y'");
      return false;
    }
    auto array_ptr = ros_message->path_y.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_Result(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StartGoalAction_Result__ros_msg_type * ros_message = static_cast<const _StartGoalAction_Result__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name path_x
  {
    size_t array_size = ros_message->path_x.size;
    auto array_ptr = ros_message->path_x.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name path_y
  {
    size_t array_size = ros_message->path_y.size;
    auto array_ptr = ros_message->path_y.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _StartGoalAction_Result__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_user_action_interfaces__action__StartGoalAction_Result(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_Result(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: path_x
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: path_y
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = user_action_interfaces__action__StartGoalAction_Result;
    is_plain =
      (
      offsetof(DataType, path_y) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _StartGoalAction_Result__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_user_action_interfaces__action__StartGoalAction_Result(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StartGoalAction_Result = {
  "user_action_interfaces::action",
  "StartGoalAction_Result",
  _StartGoalAction_Result__cdr_serialize,
  _StartGoalAction_Result__cdr_deserialize,
  _StartGoalAction_Result__get_serialized_size,
  _StartGoalAction_Result__max_serialized_size
};

static rosidl_message_type_support_t _StartGoalAction_Result__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StartGoalAction_Result,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_Result__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_Result__get_type_description,
  &user_action_interfaces__action__StartGoalAction_Result__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_Result)() {
  return &_StartGoalAction_Result__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"  // partial_path_x, partial_path_y
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"  // partial_path_x, partial_path_y

// forward declare type support functions


using _StartGoalAction_Feedback__ros_msg_type = user_action_interfaces__action__StartGoalAction_Feedback;

static bool _StartGoalAction_Feedback__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StartGoalAction_Feedback__ros_msg_type * ros_message = static_cast<const _StartGoalAction_Feedback__ros_msg_type *>(untyped_ros_message);
  // Field name: partial_path_x
  {
    size_t size = ros_message->partial_path_x.size;
    auto array_ptr = ros_message->partial_path_x.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: partial_path_y
  {
    size_t size = ros_message->partial_path_y.size;
    auto array_ptr = ros_message->partial_path_y.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _StartGoalAction_Feedback__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StartGoalAction_Feedback__ros_msg_type * ros_message = static_cast<_StartGoalAction_Feedback__ros_msg_type *>(untyped_ros_message);
  // Field name: partial_path_x
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->partial_path_x.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->partial_path_x);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->partial_path_x, size)) {
      fprintf(stderr, "failed to create array for field 'partial_path_x'");
      return false;
    }
    auto array_ptr = ros_message->partial_path_x.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: partial_path_y
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->partial_path_y.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->partial_path_y);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->partial_path_y, size)) {
      fprintf(stderr, "failed to create array for field 'partial_path_y'");
      return false;
    }
    auto array_ptr = ros_message->partial_path_y.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_Feedback(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StartGoalAction_Feedback__ros_msg_type * ros_message = static_cast<const _StartGoalAction_Feedback__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name partial_path_x
  {
    size_t array_size = ros_message->partial_path_x.size;
    auto array_ptr = ros_message->partial_path_x.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name partial_path_y
  {
    size_t array_size = ros_message->partial_path_y.size;
    auto array_ptr = ros_message->partial_path_y.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _StartGoalAction_Feedback__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_user_action_interfaces__action__StartGoalAction_Feedback(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_Feedback(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: partial_path_x
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: partial_path_y
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = user_action_interfaces__action__StartGoalAction_Feedback;
    is_plain =
      (
      offsetof(DataType, partial_path_y) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _StartGoalAction_Feedback__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_user_action_interfaces__action__StartGoalAction_Feedback(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StartGoalAction_Feedback = {
  "user_action_interfaces::action",
  "StartGoalAction_Feedback",
  _StartGoalAction_Feedback__cdr_serialize,
  _StartGoalAction_Feedback__cdr_deserialize,
  _StartGoalAction_Feedback__get_serialized_size,
  _StartGoalAction_Feedback__max_serialized_size
};

static rosidl_message_type_support_t _StartGoalAction_Feedback__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StartGoalAction_Feedback,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_Feedback__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_Feedback__get_type_description,
  &user_action_interfaces__action__StartGoalAction_Feedback__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_Feedback)() {
  return &_StartGoalAction_Feedback__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"  // goal

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
size_t get_serialized_size_unique_identifier_msgs__msg__UUID(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
size_t max_serialized_size_unique_identifier_msgs__msg__UUID(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID)();
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_Goal(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_Goal(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_Goal)();


using _StartGoalAction_SendGoal_Request__ros_msg_type = user_action_interfaces__action__StartGoalAction_SendGoal_Request;

static bool _StartGoalAction_SendGoal_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StartGoalAction_SendGoal_Request__ros_msg_type * ros_message = static_cast<const _StartGoalAction_SendGoal_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: goal_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->goal_id, cdr))
    {
      return false;
    }
  }

  // Field name: goal
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_Goal
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->goal, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _StartGoalAction_SendGoal_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StartGoalAction_SendGoal_Request__ros_msg_type * ros_message = static_cast<_StartGoalAction_SendGoal_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: goal_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->goal_id))
    {
      return false;
    }
  }

  // Field name: goal
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_Goal
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->goal))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StartGoalAction_SendGoal_Request__ros_msg_type * ros_message = static_cast<const _StartGoalAction_SendGoal_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name goal_id

  current_alignment += get_serialized_size_unique_identifier_msgs__msg__UUID(
    &(ros_message->goal_id), current_alignment);
  // field.name goal

  current_alignment += get_serialized_size_user_action_interfaces__action__StartGoalAction_Goal(
    &(ros_message->goal), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _StartGoalAction_SendGoal_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: goal_id
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_unique_identifier_msgs__msg__UUID(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: goal
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_user_action_interfaces__action__StartGoalAction_Goal(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = user_action_interfaces__action__StartGoalAction_SendGoal_Request;
    is_plain =
      (
      offsetof(DataType, goal) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _StartGoalAction_SendGoal_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StartGoalAction_SendGoal_Request = {
  "user_action_interfaces::action",
  "StartGoalAction_SendGoal_Request",
  _StartGoalAction_SendGoal_Request__cdr_serialize,
  _StartGoalAction_SendGoal_Request__cdr_deserialize,
  _StartGoalAction_SendGoal_Request__get_serialized_size,
  _StartGoalAction_SendGoal_Request__max_serialized_size
};

static rosidl_message_type_support_t _StartGoalAction_SendGoal_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StartGoalAction_SendGoal_Request,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Request__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Request__get_type_description,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Request__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal_Request)() {
  return &_StartGoalAction_SendGoal_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "builtin_interfaces/msg/detail/time__functions.h"  // stamp

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time)();


using _StartGoalAction_SendGoal_Response__ros_msg_type = user_action_interfaces__action__StartGoalAction_SendGoal_Response;

static bool _StartGoalAction_SendGoal_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StartGoalAction_SendGoal_Response__ros_msg_type * ros_message = static_cast<const _StartGoalAction_SendGoal_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: accepted
  {
    cdr << (ros_message->accepted ? true : false);
  }

  // Field name: stamp
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->stamp, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _StartGoalAction_SendGoal_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StartGoalAction_SendGoal_Response__ros_msg_type * ros_message = static_cast<_StartGoalAction_SendGoal_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: accepted
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->accepted = tmp ? true : false;
  }

  // Field name: stamp
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->stamp))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StartGoalAction_SendGoal_Response__ros_msg_type * ros_message = static_cast<const _StartGoalAction_SendGoal_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name accepted
  {
    size_t item_size = sizeof(ros_message->accepted);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name stamp

  current_alignment += get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->stamp), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _StartGoalAction_SendGoal_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: accepted
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: stamp
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = user_action_interfaces__action__StartGoalAction_SendGoal_Response;
    is_plain =
      (
      offsetof(DataType, stamp) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _StartGoalAction_SendGoal_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StartGoalAction_SendGoal_Response = {
  "user_action_interfaces::action",
  "StartGoalAction_SendGoal_Response",
  _StartGoalAction_SendGoal_Response__cdr_serialize,
  _StartGoalAction_SendGoal_Response__cdr_deserialize,
  _StartGoalAction_SendGoal_Response__get_serialized_size,
  _StartGoalAction_SendGoal_Response__max_serialized_size
};

static rosidl_message_type_support_t _StartGoalAction_SendGoal_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StartGoalAction_SendGoal_Response,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Response__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Response__get_type_description,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Response__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal_Response)() {
  return &_StartGoalAction_SendGoal_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "service_msgs/msg/detail/service_event_info__functions.h"  // info

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
size_t get_serialized_size_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
size_t max_serialized_size_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, service_msgs, msg, ServiceEventInfo)();
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal_Request)();
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal_Response)();


using _StartGoalAction_SendGoal_Event__ros_msg_type = user_action_interfaces__action__StartGoalAction_SendGoal_Event;

static bool _StartGoalAction_SendGoal_Event__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StartGoalAction_SendGoal_Event__ros_msg_type * ros_message = static_cast<const _StartGoalAction_SendGoal_Event__ros_msg_type *>(untyped_ros_message);
  // Field name: info
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, service_msgs, msg, ServiceEventInfo
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->info, cdr))
    {
      return false;
    }
  }

  // Field name: request
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal_Request
      )()->data);
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: response
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal_Response
      )()->data);
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _StartGoalAction_SendGoal_Event__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StartGoalAction_SendGoal_Event__ros_msg_type * ros_message = static_cast<_StartGoalAction_SendGoal_Event__ros_msg_type *>(untyped_ros_message);
  // Field name: info
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, service_msgs, msg, ServiceEventInfo
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->info))
    {
      return false;
    }
  }

  // Field name: request
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal_Request
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->request.data) {
      user_action_interfaces__action__StartGoalAction_SendGoal_Request__Sequence__fini(&ros_message->request);
    }
    if (!user_action_interfaces__action__StartGoalAction_SendGoal_Request__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: response
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal_Response
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->response.data) {
      user_action_interfaces__action__StartGoalAction_SendGoal_Response__Sequence__fini(&ros_message->response);
    }
    if (!user_action_interfaces__action__StartGoalAction_SendGoal_Response__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StartGoalAction_SendGoal_Event__ros_msg_type * ros_message = static_cast<const _StartGoalAction_SendGoal_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name info

  current_alignment += get_serialized_size_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);
  // field.name request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Request(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _StartGoalAction_SendGoal_Event__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Event(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: info
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = user_action_interfaces__action__StartGoalAction_SendGoal_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _StartGoalAction_SendGoal_Event__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_user_action_interfaces__action__StartGoalAction_SendGoal_Event(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StartGoalAction_SendGoal_Event = {
  "user_action_interfaces::action",
  "StartGoalAction_SendGoal_Event",
  _StartGoalAction_SendGoal_Event__cdr_serialize,
  _StartGoalAction_SendGoal_Event__cdr_deserialize,
  _StartGoalAction_SendGoal_Event__get_serialized_size,
  _StartGoalAction_SendGoal_Event__max_serialized_size
};

static rosidl_message_type_support_t _StartGoalAction_SendGoal_Event__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StartGoalAction_SendGoal_Event,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Event__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Event__get_type_description,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Event__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal_Event)() {
  return &_StartGoalAction_SendGoal_Event__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "user_action_interfaces/action/start_goal_action.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t StartGoalAction_SendGoal__callbacks = {
  "user_action_interfaces::action",
  "StartGoalAction_SendGoal",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal_Response)(),
};

static rosidl_service_type_support_t StartGoalAction_SendGoal__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &StartGoalAction_SendGoal__callbacks,
  get_service_typesupport_handle_function,
  &_StartGoalAction_SendGoal_Request__type_support,
  &_StartGoalAction_SendGoal_Response__type_support,
  &_StartGoalAction_SendGoal_Event__type_support,
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

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal)() {
  return &StartGoalAction_SendGoal__handle;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
size_t get_serialized_size_unique_identifier_msgs__msg__UUID(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
size_t max_serialized_size_unique_identifier_msgs__msg__UUID(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID)();


using _StartGoalAction_GetResult_Request__ros_msg_type = user_action_interfaces__action__StartGoalAction_GetResult_Request;

static bool _StartGoalAction_GetResult_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StartGoalAction_GetResult_Request__ros_msg_type * ros_message = static_cast<const _StartGoalAction_GetResult_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: goal_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->goal_id, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _StartGoalAction_GetResult_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StartGoalAction_GetResult_Request__ros_msg_type * ros_message = static_cast<_StartGoalAction_GetResult_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: goal_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->goal_id))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StartGoalAction_GetResult_Request__ros_msg_type * ros_message = static_cast<const _StartGoalAction_GetResult_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name goal_id

  current_alignment += get_serialized_size_unique_identifier_msgs__msg__UUID(
    &(ros_message->goal_id), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _StartGoalAction_GetResult_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: goal_id
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_unique_identifier_msgs__msg__UUID(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = user_action_interfaces__action__StartGoalAction_GetResult_Request;
    is_plain =
      (
      offsetof(DataType, goal_id) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _StartGoalAction_GetResult_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StartGoalAction_GetResult_Request = {
  "user_action_interfaces::action",
  "StartGoalAction_GetResult_Request",
  _StartGoalAction_GetResult_Request__cdr_serialize,
  _StartGoalAction_GetResult_Request__cdr_deserialize,
  _StartGoalAction_GetResult_Request__get_serialized_size,
  _StartGoalAction_GetResult_Request__max_serialized_size
};

static rosidl_message_type_support_t _StartGoalAction_GetResult_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StartGoalAction_GetResult_Request,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_GetResult_Request__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_GetResult_Request__get_type_description,
  &user_action_interfaces__action__StartGoalAction_GetResult_Request__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult_Request)() {
  return &_StartGoalAction_GetResult_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"  // result

// forward declare type support functions
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_Result(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_Result(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_Result)();


using _StartGoalAction_GetResult_Response__ros_msg_type = user_action_interfaces__action__StartGoalAction_GetResult_Response;

static bool _StartGoalAction_GetResult_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StartGoalAction_GetResult_Response__ros_msg_type * ros_message = static_cast<const _StartGoalAction_GetResult_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    cdr << ros_message->status;
  }

  // Field name: result
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_Result
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->result, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _StartGoalAction_GetResult_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StartGoalAction_GetResult_Response__ros_msg_type * ros_message = static_cast<_StartGoalAction_GetResult_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: status
  {
    cdr >> ros_message->status;
  }

  // Field name: result
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_Result
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->result))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StartGoalAction_GetResult_Response__ros_msg_type * ros_message = static_cast<const _StartGoalAction_GetResult_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name status
  {
    size_t item_size = sizeof(ros_message->status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name result

  current_alignment += get_serialized_size_user_action_interfaces__action__StartGoalAction_Result(
    &(ros_message->result), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _StartGoalAction_GetResult_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: result
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_user_action_interfaces__action__StartGoalAction_Result(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = user_action_interfaces__action__StartGoalAction_GetResult_Response;
    is_plain =
      (
      offsetof(DataType, result) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _StartGoalAction_GetResult_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StartGoalAction_GetResult_Response = {
  "user_action_interfaces::action",
  "StartGoalAction_GetResult_Response",
  _StartGoalAction_GetResult_Response__cdr_serialize,
  _StartGoalAction_GetResult_Response__cdr_deserialize,
  _StartGoalAction_GetResult_Response__get_serialized_size,
  _StartGoalAction_GetResult_Response__max_serialized_size
};

static rosidl_message_type_support_t _StartGoalAction_GetResult_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StartGoalAction_GetResult_Response,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_GetResult_Response__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_GetResult_Response__get_type_description,
  &user_action_interfaces__action__StartGoalAction_GetResult_Response__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult_Response)() {
  return &_StartGoalAction_GetResult_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"  // info

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
size_t get_serialized_size_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
size_t max_serialized_size_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, service_msgs, msg, ServiceEventInfo)();
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult_Request)();
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult_Response)();


using _StartGoalAction_GetResult_Event__ros_msg_type = user_action_interfaces__action__StartGoalAction_GetResult_Event;

static bool _StartGoalAction_GetResult_Event__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StartGoalAction_GetResult_Event__ros_msg_type * ros_message = static_cast<const _StartGoalAction_GetResult_Event__ros_msg_type *>(untyped_ros_message);
  // Field name: info
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, service_msgs, msg, ServiceEventInfo
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->info, cdr))
    {
      return false;
    }
  }

  // Field name: request
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult_Request
      )()->data);
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: response
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult_Response
      )()->data);
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _StartGoalAction_GetResult_Event__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StartGoalAction_GetResult_Event__ros_msg_type * ros_message = static_cast<_StartGoalAction_GetResult_Event__ros_msg_type *>(untyped_ros_message);
  // Field name: info
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, service_msgs, msg, ServiceEventInfo
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->info))
    {
      return false;
    }
  }

  // Field name: request
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult_Request
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->request.data) {
      user_action_interfaces__action__StartGoalAction_GetResult_Request__Sequence__fini(&ros_message->request);
    }
    if (!user_action_interfaces__action__StartGoalAction_GetResult_Request__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: response
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult_Response
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->response.data) {
      user_action_interfaces__action__StartGoalAction_GetResult_Response__Sequence__fini(&ros_message->response);
    }
    if (!user_action_interfaces__action__StartGoalAction_GetResult_Response__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StartGoalAction_GetResult_Event__ros_msg_type * ros_message = static_cast<const _StartGoalAction_GetResult_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name info

  current_alignment += get_serialized_size_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);
  // field.name request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Request(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _StartGoalAction_GetResult_Event__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Event(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: info
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = user_action_interfaces__action__StartGoalAction_GetResult_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _StartGoalAction_GetResult_Event__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_user_action_interfaces__action__StartGoalAction_GetResult_Event(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StartGoalAction_GetResult_Event = {
  "user_action_interfaces::action",
  "StartGoalAction_GetResult_Event",
  _StartGoalAction_GetResult_Event__cdr_serialize,
  _StartGoalAction_GetResult_Event__cdr_deserialize,
  _StartGoalAction_GetResult_Event__get_serialized_size,
  _StartGoalAction_GetResult_Event__max_serialized_size
};

static rosidl_message_type_support_t _StartGoalAction_GetResult_Event__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StartGoalAction_GetResult_Event,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_GetResult_Event__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_GetResult_Event__get_type_description,
  &user_action_interfaces__action__StartGoalAction_GetResult_Event__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult_Event)() {
  return &_StartGoalAction_GetResult_Event__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "user_action_interfaces/action/start_goal_action.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t StartGoalAction_GetResult__callbacks = {
  "user_action_interfaces::action",
  "StartGoalAction_GetResult",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult_Response)(),
};

static rosidl_service_type_support_t StartGoalAction_GetResult__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &StartGoalAction_GetResult__callbacks,
  get_service_typesupport_handle_function,
  &_StartGoalAction_GetResult_Request__type_support,
  &_StartGoalAction_GetResult_Response__type_support,
  &_StartGoalAction_GetResult_Event__type_support,
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

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult)() {
  return &StartGoalAction_GetResult__handle;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "user_action_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"  // feedback

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
size_t get_serialized_size_unique_identifier_msgs__msg__UUID(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
size_t max_serialized_size_unique_identifier_msgs__msg__UUID(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID)();
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_Feedback(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_Feedback(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_Feedback)();


using _StartGoalAction_FeedbackMessage__ros_msg_type = user_action_interfaces__action__StartGoalAction_FeedbackMessage;

static bool _StartGoalAction_FeedbackMessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StartGoalAction_FeedbackMessage__ros_msg_type * ros_message = static_cast<const _StartGoalAction_FeedbackMessage__ros_msg_type *>(untyped_ros_message);
  // Field name: goal_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->goal_id, cdr))
    {
      return false;
    }
  }

  // Field name: feedback
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_Feedback
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->feedback, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _StartGoalAction_FeedbackMessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StartGoalAction_FeedbackMessage__ros_msg_type * ros_message = static_cast<_StartGoalAction_FeedbackMessage__ros_msg_type *>(untyped_ros_message);
  // Field name: goal_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->goal_id))
    {
      return false;
    }
  }

  // Field name: feedback
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_Feedback
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->feedback))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t get_serialized_size_user_action_interfaces__action__StartGoalAction_FeedbackMessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StartGoalAction_FeedbackMessage__ros_msg_type * ros_message = static_cast<const _StartGoalAction_FeedbackMessage__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name goal_id

  current_alignment += get_serialized_size_unique_identifier_msgs__msg__UUID(
    &(ros_message->goal_id), current_alignment);
  // field.name feedback

  current_alignment += get_serialized_size_user_action_interfaces__action__StartGoalAction_Feedback(
    &(ros_message->feedback), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _StartGoalAction_FeedbackMessage__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_user_action_interfaces__action__StartGoalAction_FeedbackMessage(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t max_serialized_size_user_action_interfaces__action__StartGoalAction_FeedbackMessage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: goal_id
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_unique_identifier_msgs__msg__UUID(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: feedback
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_user_action_interfaces__action__StartGoalAction_Feedback(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = user_action_interfaces__action__StartGoalAction_FeedbackMessage;
    is_plain =
      (
      offsetof(DataType, feedback) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _StartGoalAction_FeedbackMessage__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_user_action_interfaces__action__StartGoalAction_FeedbackMessage(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StartGoalAction_FeedbackMessage = {
  "user_action_interfaces::action",
  "StartGoalAction_FeedbackMessage",
  _StartGoalAction_FeedbackMessage__cdr_serialize,
  _StartGoalAction_FeedbackMessage__cdr_deserialize,
  _StartGoalAction_FeedbackMessage__get_serialized_size,
  _StartGoalAction_FeedbackMessage__max_serialized_size
};

static rosidl_message_type_support_t _StartGoalAction_FeedbackMessage__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StartGoalAction_FeedbackMessage,
  get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_FeedbackMessage__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_FeedbackMessage__get_type_description,
  &user_action_interfaces__action__StartGoalAction_FeedbackMessage__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_FeedbackMessage)() {
  return &_StartGoalAction_FeedbackMessage__type_support;
}

#if defined(__cplusplus)
}
#endif
