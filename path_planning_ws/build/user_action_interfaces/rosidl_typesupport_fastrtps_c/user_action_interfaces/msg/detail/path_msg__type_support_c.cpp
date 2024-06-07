// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from user_action_interfaces:msg/PathMsg.idl
// generated code does not contain a copyright notice
#include "user_action_interfaces/msg/detail/path_msg__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "user_action_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "user_action_interfaces/msg/detail/path_msg__struct.h"
#include "user_action_interfaces/msg/detail/path_msg__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // path_x, path_y
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // path_x, path_y
#include "rosidl_runtime_c/string.h"  // frame_id
#include "rosidl_runtime_c/string_functions.h"  // frame_id
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_user_action_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _PathMsg__ros_msg_type = user_action_interfaces__msg__PathMsg;

static bool _PathMsg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PathMsg__ros_msg_type * ros_message = static_cast<const _PathMsg__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: frame_id
  {
    const rosidl_runtime_c__String * str = &ros_message->frame_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

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

static bool _PathMsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PathMsg__ros_msg_type * ros_message = static_cast<_PathMsg__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: frame_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->frame_id.data) {
      rosidl_runtime_c__String__init(&ros_message->frame_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->frame_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'frame_id'\n");
      return false;
    }
  }

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
size_t get_serialized_size_user_action_interfaces__msg__PathMsg(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PathMsg__ros_msg_type * ros_message = static_cast<const _PathMsg__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name frame_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->frame_id.size + 1);
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

static uint32_t _PathMsg__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_user_action_interfaces__msg__PathMsg(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_user_action_interfaces
size_t max_serialized_size_user_action_interfaces__msg__PathMsg(
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

  // member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: frame_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
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
    using DataType = user_action_interfaces__msg__PathMsg;
    is_plain =
      (
      offsetof(DataType, path_y) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PathMsg__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_user_action_interfaces__msg__PathMsg(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PathMsg = {
  "user_action_interfaces::msg",
  "PathMsg",
  _PathMsg__cdr_serialize,
  _PathMsg__cdr_deserialize,
  _PathMsg__get_serialized_size,
  _PathMsg__max_serialized_size
};

static rosidl_message_type_support_t _PathMsg__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PathMsg,
  get_message_typesupport_handle_function,
  &user_action_interfaces__msg__PathMsg__get_type_hash,
  &user_action_interfaces__msg__PathMsg__get_type_description,
  &user_action_interfaces__msg__PathMsg__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, msg, PathMsg)() {
  return &_PathMsg__type_support;
}

#if defined(__cplusplus)
}
#endif
