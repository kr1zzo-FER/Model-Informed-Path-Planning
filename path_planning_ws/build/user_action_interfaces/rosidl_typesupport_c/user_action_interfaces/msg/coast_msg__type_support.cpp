// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from user_action_interfaces:msg/CoastMsg.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "user_action_interfaces/msg/detail/coast_msg__struct.h"
#include "user_action_interfaces/msg/detail/coast_msg__type_support.h"
#include "user_action_interfaces/msg/detail/coast_msg__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace user_action_interfaces
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _CoastMsg_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CoastMsg_type_support_ids_t;

static const _CoastMsg_type_support_ids_t _CoastMsg_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _CoastMsg_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CoastMsg_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CoastMsg_type_support_symbol_names_t _CoastMsg_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, msg, CoastMsg)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, msg, CoastMsg)),
  }
};

typedef struct _CoastMsg_type_support_data_t
{
  void * data[2];
} _CoastMsg_type_support_data_t;

static _CoastMsg_type_support_data_t _CoastMsg_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CoastMsg_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_CoastMsg_message_typesupport_ids.typesupport_identifier[0],
  &_CoastMsg_message_typesupport_symbol_names.symbol_name[0],
  &_CoastMsg_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CoastMsg_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CoastMsg_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__msg__CoastMsg__get_type_hash,
  &user_action_interfaces__msg__CoastMsg__get_type_description,
  &user_action_interfaces__msg__CoastMsg__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, msg, CoastMsg)() {
  return &::user_action_interfaces::msg::rosidl_typesupport_c::CoastMsg_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
