// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from user_action_interfaces:msg/PathMsg.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "user_action_interfaces/msg/detail/path_msg__functions.h"
#include "user_action_interfaces/msg/detail/path_msg__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace user_action_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void PathMsg_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) user_action_interfaces::msg::PathMsg(_init);
}

void PathMsg_fini_function(void * message_memory)
{
  auto typed_message = static_cast<user_action_interfaces::msg::PathMsg *>(message_memory);
  typed_message->~PathMsg();
}

size_t size_function__PathMsg__path_x(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PathMsg__path_x(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__PathMsg__path_x(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__PathMsg__path_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__PathMsg__path_x(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__PathMsg__path_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__PathMsg__path_x(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__PathMsg__path_x(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__PathMsg__path_y(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PathMsg__path_y(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__PathMsg__path_y(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__PathMsg__path_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__PathMsg__path_y(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__PathMsg__path_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__PathMsg__path_y(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__PathMsg__path_y(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PathMsg_message_member_array[4] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces::msg::PathMsg, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "frame_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces::msg::PathMsg, frame_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "path_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces::msg::PathMsg, path_x),  // bytes offset in struct
    nullptr,  // default value
    size_function__PathMsg__path_x,  // size() function pointer
    get_const_function__PathMsg__path_x,  // get_const(index) function pointer
    get_function__PathMsg__path_x,  // get(index) function pointer
    fetch_function__PathMsg__path_x,  // fetch(index, &value) function pointer
    assign_function__PathMsg__path_x,  // assign(index, value) function pointer
    resize_function__PathMsg__path_x  // resize(index) function pointer
  },
  {
    "path_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(user_action_interfaces::msg::PathMsg, path_y),  // bytes offset in struct
    nullptr,  // default value
    size_function__PathMsg__path_y,  // size() function pointer
    get_const_function__PathMsg__path_y,  // get_const(index) function pointer
    get_function__PathMsg__path_y,  // get(index) function pointer
    fetch_function__PathMsg__path_y,  // fetch(index, &value) function pointer
    assign_function__PathMsg__path_y,  // assign(index, value) function pointer
    resize_function__PathMsg__path_y  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PathMsg_message_members = {
  "user_action_interfaces::msg",  // message namespace
  "PathMsg",  // message name
  4,  // number of fields
  sizeof(user_action_interfaces::msg::PathMsg),
  PathMsg_message_member_array,  // message members
  PathMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  PathMsg_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PathMsg_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PathMsg_message_members,
  get_message_typesupport_handle_function,
  &user_action_interfaces__msg__PathMsg__get_type_hash,
  &user_action_interfaces__msg__PathMsg__get_type_description,
  &user_action_interfaces__msg__PathMsg__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace user_action_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<user_action_interfaces::msg::PathMsg>()
{
  return &::user_action_interfaces::msg::rosidl_typesupport_introspection_cpp::PathMsg_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, user_action_interfaces, msg, PathMsg)() {
  return &::user_action_interfaces::msg::rosidl_typesupport_introspection_cpp::PathMsg_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
