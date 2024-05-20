// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from user_action_interfaces:action/PathPlanning.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "user_action_interfaces/action/detail/path_planning__struct.h"
#include "user_action_interfaces/action/detail/path_planning__type_support.h"
#include "user_action_interfaces/action/detail/path_planning__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace user_action_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PathPlanning_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PathPlanning_Goal_type_support_ids_t;

static const _PathPlanning_Goal_type_support_ids_t _PathPlanning_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PathPlanning_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PathPlanning_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PathPlanning_Goal_type_support_symbol_names_t _PathPlanning_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, PathPlanning_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, PathPlanning_Goal)),
  }
};

typedef struct _PathPlanning_Goal_type_support_data_t
{
  void * data[2];
} _PathPlanning_Goal_type_support_data_t;

static _PathPlanning_Goal_type_support_data_t _PathPlanning_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PathPlanning_Goal_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_PathPlanning_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_PathPlanning_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_PathPlanning_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PathPlanning_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PathPlanning_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__PathPlanning_Goal__get_type_hash,
  &user_action_interfaces__action__PathPlanning_Goal__get_type_description,
  &user_action_interfaces__action__PathPlanning_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, PathPlanning_Goal)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::PathPlanning_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace user_action_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PathPlanning_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PathPlanning_Result_type_support_ids_t;

static const _PathPlanning_Result_type_support_ids_t _PathPlanning_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PathPlanning_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PathPlanning_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PathPlanning_Result_type_support_symbol_names_t _PathPlanning_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, PathPlanning_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, PathPlanning_Result)),
  }
};

typedef struct _PathPlanning_Result_type_support_data_t
{
  void * data[2];
} _PathPlanning_Result_type_support_data_t;

static _PathPlanning_Result_type_support_data_t _PathPlanning_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PathPlanning_Result_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_PathPlanning_Result_message_typesupport_ids.typesupport_identifier[0],
  &_PathPlanning_Result_message_typesupport_symbol_names.symbol_name[0],
  &_PathPlanning_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PathPlanning_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PathPlanning_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__PathPlanning_Result__get_type_hash,
  &user_action_interfaces__action__PathPlanning_Result__get_type_description,
  &user_action_interfaces__action__PathPlanning_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, PathPlanning_Result)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::PathPlanning_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace user_action_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PathPlanning_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PathPlanning_Feedback_type_support_ids_t;

static const _PathPlanning_Feedback_type_support_ids_t _PathPlanning_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PathPlanning_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PathPlanning_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PathPlanning_Feedback_type_support_symbol_names_t _PathPlanning_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, PathPlanning_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, PathPlanning_Feedback)),
  }
};

typedef struct _PathPlanning_Feedback_type_support_data_t
{
  void * data[2];
} _PathPlanning_Feedback_type_support_data_t;

static _PathPlanning_Feedback_type_support_data_t _PathPlanning_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PathPlanning_Feedback_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_PathPlanning_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_PathPlanning_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_PathPlanning_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PathPlanning_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PathPlanning_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__PathPlanning_Feedback__get_type_hash,
  &user_action_interfaces__action__PathPlanning_Feedback__get_type_description,
  &user_action_interfaces__action__PathPlanning_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, PathPlanning_Feedback)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::PathPlanning_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace user_action_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PathPlanning_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PathPlanning_SendGoal_Request_type_support_ids_t;

static const _PathPlanning_SendGoal_Request_type_support_ids_t _PathPlanning_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PathPlanning_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PathPlanning_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PathPlanning_SendGoal_Request_type_support_symbol_names_t _PathPlanning_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, PathPlanning_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, PathPlanning_SendGoal_Request)),
  }
};

typedef struct _PathPlanning_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _PathPlanning_SendGoal_Request_type_support_data_t;

static _PathPlanning_SendGoal_Request_type_support_data_t _PathPlanning_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PathPlanning_SendGoal_Request_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_PathPlanning_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PathPlanning_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PathPlanning_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PathPlanning_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PathPlanning_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__PathPlanning_SendGoal_Request__get_type_hash,
  &user_action_interfaces__action__PathPlanning_SendGoal_Request__get_type_description,
  &user_action_interfaces__action__PathPlanning_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, PathPlanning_SendGoal_Request)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::PathPlanning_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace user_action_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PathPlanning_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PathPlanning_SendGoal_Response_type_support_ids_t;

static const _PathPlanning_SendGoal_Response_type_support_ids_t _PathPlanning_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PathPlanning_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PathPlanning_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PathPlanning_SendGoal_Response_type_support_symbol_names_t _PathPlanning_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, PathPlanning_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, PathPlanning_SendGoal_Response)),
  }
};

typedef struct _PathPlanning_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _PathPlanning_SendGoal_Response_type_support_data_t;

static _PathPlanning_SendGoal_Response_type_support_data_t _PathPlanning_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PathPlanning_SendGoal_Response_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_PathPlanning_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PathPlanning_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PathPlanning_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PathPlanning_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PathPlanning_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__PathPlanning_SendGoal_Response__get_type_hash,
  &user_action_interfaces__action__PathPlanning_SendGoal_Response__get_type_description,
  &user_action_interfaces__action__PathPlanning_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, PathPlanning_SendGoal_Response)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::PathPlanning_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace user_action_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PathPlanning_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PathPlanning_SendGoal_Event_type_support_ids_t;

static const _PathPlanning_SendGoal_Event_type_support_ids_t _PathPlanning_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PathPlanning_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PathPlanning_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PathPlanning_SendGoal_Event_type_support_symbol_names_t _PathPlanning_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, PathPlanning_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, PathPlanning_SendGoal_Event)),
  }
};

typedef struct _PathPlanning_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _PathPlanning_SendGoal_Event_type_support_data_t;

static _PathPlanning_SendGoal_Event_type_support_data_t _PathPlanning_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PathPlanning_SendGoal_Event_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_PathPlanning_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_PathPlanning_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_PathPlanning_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PathPlanning_SendGoal_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PathPlanning_SendGoal_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__PathPlanning_SendGoal_Event__get_type_hash,
  &user_action_interfaces__action__PathPlanning_SendGoal_Event__get_type_description,
  &user_action_interfaces__action__PathPlanning_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, PathPlanning_SendGoal_Event)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::PathPlanning_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace user_action_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{
typedef struct _PathPlanning_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PathPlanning_SendGoal_type_support_ids_t;

static const _PathPlanning_SendGoal_type_support_ids_t _PathPlanning_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PathPlanning_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PathPlanning_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PathPlanning_SendGoal_type_support_symbol_names_t _PathPlanning_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, PathPlanning_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, PathPlanning_SendGoal)),
  }
};

typedef struct _PathPlanning_SendGoal_type_support_data_t
{
  void * data[2];
} _PathPlanning_SendGoal_type_support_data_t;

static _PathPlanning_SendGoal_type_support_data_t _PathPlanning_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PathPlanning_SendGoal_service_typesupport_map = {
  2,
  "user_action_interfaces",
  &_PathPlanning_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_PathPlanning_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_PathPlanning_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PathPlanning_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PathPlanning_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &PathPlanning_SendGoal_Request_message_type_support_handle,
  &PathPlanning_SendGoal_Response_message_type_support_handle,
  &PathPlanning_SendGoal_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    user_action_interfaces,
    action,
    PathPlanning_SendGoal
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    user_action_interfaces,
    action,
    PathPlanning_SendGoal
  ),
  &user_action_interfaces__action__PathPlanning_SendGoal__get_type_hash,
  &user_action_interfaces__action__PathPlanning_SendGoal__get_type_description,
  &user_action_interfaces__action__PathPlanning_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, PathPlanning_SendGoal)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::PathPlanning_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace user_action_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PathPlanning_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PathPlanning_GetResult_Request_type_support_ids_t;

static const _PathPlanning_GetResult_Request_type_support_ids_t _PathPlanning_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PathPlanning_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PathPlanning_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PathPlanning_GetResult_Request_type_support_symbol_names_t _PathPlanning_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, PathPlanning_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, PathPlanning_GetResult_Request)),
  }
};

typedef struct _PathPlanning_GetResult_Request_type_support_data_t
{
  void * data[2];
} _PathPlanning_GetResult_Request_type_support_data_t;

static _PathPlanning_GetResult_Request_type_support_data_t _PathPlanning_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PathPlanning_GetResult_Request_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_PathPlanning_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PathPlanning_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PathPlanning_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PathPlanning_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PathPlanning_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__PathPlanning_GetResult_Request__get_type_hash,
  &user_action_interfaces__action__PathPlanning_GetResult_Request__get_type_description,
  &user_action_interfaces__action__PathPlanning_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, PathPlanning_GetResult_Request)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::PathPlanning_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace user_action_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PathPlanning_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PathPlanning_GetResult_Response_type_support_ids_t;

static const _PathPlanning_GetResult_Response_type_support_ids_t _PathPlanning_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PathPlanning_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PathPlanning_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PathPlanning_GetResult_Response_type_support_symbol_names_t _PathPlanning_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, PathPlanning_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, PathPlanning_GetResult_Response)),
  }
};

typedef struct _PathPlanning_GetResult_Response_type_support_data_t
{
  void * data[2];
} _PathPlanning_GetResult_Response_type_support_data_t;

static _PathPlanning_GetResult_Response_type_support_data_t _PathPlanning_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PathPlanning_GetResult_Response_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_PathPlanning_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PathPlanning_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PathPlanning_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PathPlanning_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PathPlanning_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__PathPlanning_GetResult_Response__get_type_hash,
  &user_action_interfaces__action__PathPlanning_GetResult_Response__get_type_description,
  &user_action_interfaces__action__PathPlanning_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, PathPlanning_GetResult_Response)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::PathPlanning_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace user_action_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PathPlanning_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PathPlanning_GetResult_Event_type_support_ids_t;

static const _PathPlanning_GetResult_Event_type_support_ids_t _PathPlanning_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PathPlanning_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PathPlanning_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PathPlanning_GetResult_Event_type_support_symbol_names_t _PathPlanning_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, PathPlanning_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, PathPlanning_GetResult_Event)),
  }
};

typedef struct _PathPlanning_GetResult_Event_type_support_data_t
{
  void * data[2];
} _PathPlanning_GetResult_Event_type_support_data_t;

static _PathPlanning_GetResult_Event_type_support_data_t _PathPlanning_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PathPlanning_GetResult_Event_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_PathPlanning_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_PathPlanning_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_PathPlanning_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PathPlanning_GetResult_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PathPlanning_GetResult_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__PathPlanning_GetResult_Event__get_type_hash,
  &user_action_interfaces__action__PathPlanning_GetResult_Event__get_type_description,
  &user_action_interfaces__action__PathPlanning_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, PathPlanning_GetResult_Event)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::PathPlanning_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "service_msgs/msg/service_event_info.h"
// already included above
// #include "builtin_interfaces/msg/time.h"

namespace user_action_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{
typedef struct _PathPlanning_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PathPlanning_GetResult_type_support_ids_t;

static const _PathPlanning_GetResult_type_support_ids_t _PathPlanning_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PathPlanning_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PathPlanning_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PathPlanning_GetResult_type_support_symbol_names_t _PathPlanning_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, PathPlanning_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, PathPlanning_GetResult)),
  }
};

typedef struct _PathPlanning_GetResult_type_support_data_t
{
  void * data[2];
} _PathPlanning_GetResult_type_support_data_t;

static _PathPlanning_GetResult_type_support_data_t _PathPlanning_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PathPlanning_GetResult_service_typesupport_map = {
  2,
  "user_action_interfaces",
  &_PathPlanning_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_PathPlanning_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_PathPlanning_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PathPlanning_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PathPlanning_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &PathPlanning_GetResult_Request_message_type_support_handle,
  &PathPlanning_GetResult_Response_message_type_support_handle,
  &PathPlanning_GetResult_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    user_action_interfaces,
    action,
    PathPlanning_GetResult
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    user_action_interfaces,
    action,
    PathPlanning_GetResult
  ),
  &user_action_interfaces__action__PathPlanning_GetResult__get_type_hash,
  &user_action_interfaces__action__PathPlanning_GetResult__get_type_description,
  &user_action_interfaces__action__PathPlanning_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, PathPlanning_GetResult)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::PathPlanning_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace user_action_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PathPlanning_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PathPlanning_FeedbackMessage_type_support_ids_t;

static const _PathPlanning_FeedbackMessage_type_support_ids_t _PathPlanning_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PathPlanning_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PathPlanning_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PathPlanning_FeedbackMessage_type_support_symbol_names_t _PathPlanning_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, PathPlanning_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, PathPlanning_FeedbackMessage)),
  }
};

typedef struct _PathPlanning_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _PathPlanning_FeedbackMessage_type_support_data_t;

static _PathPlanning_FeedbackMessage_type_support_data_t _PathPlanning_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PathPlanning_FeedbackMessage_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_PathPlanning_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_PathPlanning_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_PathPlanning_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PathPlanning_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PathPlanning_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__PathPlanning_FeedbackMessage__get_type_hash,
  &user_action_interfaces__action__PathPlanning_FeedbackMessage__get_type_description,
  &user_action_interfaces__action__PathPlanning_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, PathPlanning_FeedbackMessage)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::PathPlanning_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "user_action_interfaces/action/path_planning.h"
// already included above
// #include "user_action_interfaces/action/detail/path_planning__type_support.h"

static rosidl_action_type_support_t _user_action_interfaces__action__PathPlanning__typesupport_c = {
  NULL, NULL, NULL, NULL, NULL,
  &user_action_interfaces__action__PathPlanning__get_type_hash,
  &user_action_interfaces__action__PathPlanning__get_type_description,
  &user_action_interfaces__action__PathPlanning__get_type_description_sources,
};

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, user_action_interfaces, action, PathPlanning)()
{
  // Thread-safe by always writing the same values to the static struct
  _user_action_interfaces__action__PathPlanning__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, user_action_interfaces, action, PathPlanning_SendGoal)();
  _user_action_interfaces__action__PathPlanning__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, user_action_interfaces, action, PathPlanning_GetResult)();
  _user_action_interfaces__action__PathPlanning__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _user_action_interfaces__action__PathPlanning__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, user_action_interfaces, action, PathPlanning_FeedbackMessage)();
  _user_action_interfaces__action__PathPlanning__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_user_action_interfaces__action__PathPlanning__typesupport_c;
}

#ifdef __cplusplus
}
#endif
