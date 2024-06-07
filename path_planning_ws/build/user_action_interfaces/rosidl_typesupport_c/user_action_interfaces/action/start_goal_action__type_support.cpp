// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from user_action_interfaces:action/StartGoalAction.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "user_action_interfaces/action/detail/start_goal_action__struct.h"
#include "user_action_interfaces/action/detail/start_goal_action__type_support.h"
#include "user_action_interfaces/action/detail/start_goal_action__functions.h"
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

typedef struct _StartGoalAction_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StartGoalAction_Goal_type_support_ids_t;

static const _StartGoalAction_Goal_type_support_ids_t _StartGoalAction_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StartGoalAction_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StartGoalAction_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StartGoalAction_Goal_type_support_symbol_names_t _StartGoalAction_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_Goal)),
  }
};

typedef struct _StartGoalAction_Goal_type_support_data_t
{
  void * data[2];
} _StartGoalAction_Goal_type_support_data_t;

static _StartGoalAction_Goal_type_support_data_t _StartGoalAction_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StartGoalAction_Goal_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_StartGoalAction_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_StartGoalAction_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_StartGoalAction_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StartGoalAction_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StartGoalAction_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_Goal__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_Goal__get_type_description,
  &user_action_interfaces__action__StartGoalAction_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction_Goal)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::StartGoalAction_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
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

typedef struct _StartGoalAction_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StartGoalAction_Result_type_support_ids_t;

static const _StartGoalAction_Result_type_support_ids_t _StartGoalAction_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StartGoalAction_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StartGoalAction_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StartGoalAction_Result_type_support_symbol_names_t _StartGoalAction_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_Result)),
  }
};

typedef struct _StartGoalAction_Result_type_support_data_t
{
  void * data[2];
} _StartGoalAction_Result_type_support_data_t;

static _StartGoalAction_Result_type_support_data_t _StartGoalAction_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StartGoalAction_Result_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_StartGoalAction_Result_message_typesupport_ids.typesupport_identifier[0],
  &_StartGoalAction_Result_message_typesupport_symbol_names.symbol_name[0],
  &_StartGoalAction_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StartGoalAction_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StartGoalAction_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_Result__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_Result__get_type_description,
  &user_action_interfaces__action__StartGoalAction_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction_Result)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::StartGoalAction_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
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

typedef struct _StartGoalAction_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StartGoalAction_Feedback_type_support_ids_t;

static const _StartGoalAction_Feedback_type_support_ids_t _StartGoalAction_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StartGoalAction_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StartGoalAction_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StartGoalAction_Feedback_type_support_symbol_names_t _StartGoalAction_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_Feedback)),
  }
};

typedef struct _StartGoalAction_Feedback_type_support_data_t
{
  void * data[2];
} _StartGoalAction_Feedback_type_support_data_t;

static _StartGoalAction_Feedback_type_support_data_t _StartGoalAction_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StartGoalAction_Feedback_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_StartGoalAction_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_StartGoalAction_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_StartGoalAction_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StartGoalAction_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StartGoalAction_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_Feedback__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_Feedback__get_type_description,
  &user_action_interfaces__action__StartGoalAction_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction_Feedback)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::StartGoalAction_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
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

typedef struct _StartGoalAction_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StartGoalAction_SendGoal_Request_type_support_ids_t;

static const _StartGoalAction_SendGoal_Request_type_support_ids_t _StartGoalAction_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StartGoalAction_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StartGoalAction_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StartGoalAction_SendGoal_Request_type_support_symbol_names_t _StartGoalAction_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal_Request)),
  }
};

typedef struct _StartGoalAction_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _StartGoalAction_SendGoal_Request_type_support_data_t;

static _StartGoalAction_SendGoal_Request_type_support_data_t _StartGoalAction_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StartGoalAction_SendGoal_Request_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_StartGoalAction_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_StartGoalAction_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_StartGoalAction_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StartGoalAction_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StartGoalAction_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Request__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Request__get_type_description,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction_SendGoal_Request)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::StartGoalAction_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
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

typedef struct _StartGoalAction_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StartGoalAction_SendGoal_Response_type_support_ids_t;

static const _StartGoalAction_SendGoal_Response_type_support_ids_t _StartGoalAction_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StartGoalAction_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StartGoalAction_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StartGoalAction_SendGoal_Response_type_support_symbol_names_t _StartGoalAction_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal_Response)),
  }
};

typedef struct _StartGoalAction_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _StartGoalAction_SendGoal_Response_type_support_data_t;

static _StartGoalAction_SendGoal_Response_type_support_data_t _StartGoalAction_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StartGoalAction_SendGoal_Response_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_StartGoalAction_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_StartGoalAction_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_StartGoalAction_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StartGoalAction_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StartGoalAction_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Response__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Response__get_type_description,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction_SendGoal_Response)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::StartGoalAction_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
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

typedef struct _StartGoalAction_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StartGoalAction_SendGoal_Event_type_support_ids_t;

static const _StartGoalAction_SendGoal_Event_type_support_ids_t _StartGoalAction_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StartGoalAction_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StartGoalAction_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StartGoalAction_SendGoal_Event_type_support_symbol_names_t _StartGoalAction_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal_Event)),
  }
};

typedef struct _StartGoalAction_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _StartGoalAction_SendGoal_Event_type_support_data_t;

static _StartGoalAction_SendGoal_Event_type_support_data_t _StartGoalAction_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StartGoalAction_SendGoal_Event_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_StartGoalAction_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_StartGoalAction_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_StartGoalAction_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StartGoalAction_SendGoal_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StartGoalAction_SendGoal_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Event__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Event__get_type_description,
  &user_action_interfaces__action__StartGoalAction_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction_SendGoal_Event)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::StartGoalAction_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__type_support.h"
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
typedef struct _StartGoalAction_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StartGoalAction_SendGoal_type_support_ids_t;

static const _StartGoalAction_SendGoal_type_support_ids_t _StartGoalAction_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StartGoalAction_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StartGoalAction_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StartGoalAction_SendGoal_type_support_symbol_names_t _StartGoalAction_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_SendGoal)),
  }
};

typedef struct _StartGoalAction_SendGoal_type_support_data_t
{
  void * data[2];
} _StartGoalAction_SendGoal_type_support_data_t;

static _StartGoalAction_SendGoal_type_support_data_t _StartGoalAction_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StartGoalAction_SendGoal_service_typesupport_map = {
  2,
  "user_action_interfaces",
  &_StartGoalAction_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_StartGoalAction_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_StartGoalAction_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t StartGoalAction_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StartGoalAction_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &StartGoalAction_SendGoal_Request_message_type_support_handle,
  &StartGoalAction_SendGoal_Response_message_type_support_handle,
  &StartGoalAction_SendGoal_Event_message_type_support_handle,
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

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction_SendGoal)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::StartGoalAction_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
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

typedef struct _StartGoalAction_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StartGoalAction_GetResult_Request_type_support_ids_t;

static const _StartGoalAction_GetResult_Request_type_support_ids_t _StartGoalAction_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StartGoalAction_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StartGoalAction_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StartGoalAction_GetResult_Request_type_support_symbol_names_t _StartGoalAction_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult_Request)),
  }
};

typedef struct _StartGoalAction_GetResult_Request_type_support_data_t
{
  void * data[2];
} _StartGoalAction_GetResult_Request_type_support_data_t;

static _StartGoalAction_GetResult_Request_type_support_data_t _StartGoalAction_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StartGoalAction_GetResult_Request_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_StartGoalAction_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_StartGoalAction_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_StartGoalAction_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StartGoalAction_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StartGoalAction_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_GetResult_Request__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_GetResult_Request__get_type_description,
  &user_action_interfaces__action__StartGoalAction_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction_GetResult_Request)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::StartGoalAction_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
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

typedef struct _StartGoalAction_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StartGoalAction_GetResult_Response_type_support_ids_t;

static const _StartGoalAction_GetResult_Response_type_support_ids_t _StartGoalAction_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StartGoalAction_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StartGoalAction_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StartGoalAction_GetResult_Response_type_support_symbol_names_t _StartGoalAction_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult_Response)),
  }
};

typedef struct _StartGoalAction_GetResult_Response_type_support_data_t
{
  void * data[2];
} _StartGoalAction_GetResult_Response_type_support_data_t;

static _StartGoalAction_GetResult_Response_type_support_data_t _StartGoalAction_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StartGoalAction_GetResult_Response_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_StartGoalAction_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_StartGoalAction_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_StartGoalAction_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StartGoalAction_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StartGoalAction_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_GetResult_Response__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_GetResult_Response__get_type_description,
  &user_action_interfaces__action__StartGoalAction_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction_GetResult_Response)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::StartGoalAction_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
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

typedef struct _StartGoalAction_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StartGoalAction_GetResult_Event_type_support_ids_t;

static const _StartGoalAction_GetResult_Event_type_support_ids_t _StartGoalAction_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StartGoalAction_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StartGoalAction_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StartGoalAction_GetResult_Event_type_support_symbol_names_t _StartGoalAction_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult_Event)),
  }
};

typedef struct _StartGoalAction_GetResult_Event_type_support_data_t
{
  void * data[2];
} _StartGoalAction_GetResult_Event_type_support_data_t;

static _StartGoalAction_GetResult_Event_type_support_data_t _StartGoalAction_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StartGoalAction_GetResult_Event_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_StartGoalAction_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_StartGoalAction_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_StartGoalAction_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StartGoalAction_GetResult_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StartGoalAction_GetResult_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_GetResult_Event__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_GetResult_Event__get_type_description,
  &user_action_interfaces__action__StartGoalAction_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction_GetResult_Event)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::StartGoalAction_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__type_support.h"
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
typedef struct _StartGoalAction_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StartGoalAction_GetResult_type_support_ids_t;

static const _StartGoalAction_GetResult_type_support_ids_t _StartGoalAction_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StartGoalAction_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StartGoalAction_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StartGoalAction_GetResult_type_support_symbol_names_t _StartGoalAction_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_GetResult)),
  }
};

typedef struct _StartGoalAction_GetResult_type_support_data_t
{
  void * data[2];
} _StartGoalAction_GetResult_type_support_data_t;

static _StartGoalAction_GetResult_type_support_data_t _StartGoalAction_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StartGoalAction_GetResult_service_typesupport_map = {
  2,
  "user_action_interfaces",
  &_StartGoalAction_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_StartGoalAction_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_StartGoalAction_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t StartGoalAction_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StartGoalAction_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &StartGoalAction_GetResult_Request_message_type_support_handle,
  &StartGoalAction_GetResult_Response_message_type_support_handle,
  &StartGoalAction_GetResult_Event_message_type_support_handle,
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

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction_GetResult)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::StartGoalAction_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__struct.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__type_support.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__functions.h"
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

typedef struct _StartGoalAction_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StartGoalAction_FeedbackMessage_type_support_ids_t;

static const _StartGoalAction_FeedbackMessage_type_support_ids_t _StartGoalAction_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StartGoalAction_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StartGoalAction_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StartGoalAction_FeedbackMessage_type_support_symbol_names_t _StartGoalAction_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, user_action_interfaces, action, StartGoalAction_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, user_action_interfaces, action, StartGoalAction_FeedbackMessage)),
  }
};

typedef struct _StartGoalAction_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _StartGoalAction_FeedbackMessage_type_support_data_t;

static _StartGoalAction_FeedbackMessage_type_support_data_t _StartGoalAction_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StartGoalAction_FeedbackMessage_message_typesupport_map = {
  2,
  "user_action_interfaces",
  &_StartGoalAction_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_StartGoalAction_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_StartGoalAction_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StartGoalAction_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StartGoalAction_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &user_action_interfaces__action__StartGoalAction_FeedbackMessage__get_type_hash,
  &user_action_interfaces__action__StartGoalAction_FeedbackMessage__get_type_description,
  &user_action_interfaces__action__StartGoalAction_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace user_action_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction_FeedbackMessage)() {
  return &::user_action_interfaces::action::rosidl_typesupport_c::StartGoalAction_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "user_action_interfaces/action/start_goal_action.h"
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__type_support.h"

static rosidl_action_type_support_t _user_action_interfaces__action__StartGoalAction__typesupport_c = {
  NULL, NULL, NULL, NULL, NULL,
  &user_action_interfaces__action__StartGoalAction__get_type_hash,
  &user_action_interfaces__action__StartGoalAction__get_type_description,
  &user_action_interfaces__action__StartGoalAction__get_type_description_sources,
};

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction)()
{
  // Thread-safe by always writing the same values to the static struct
  _user_action_interfaces__action__StartGoalAction__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction_SendGoal)();
  _user_action_interfaces__action__StartGoalAction__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction_GetResult)();
  _user_action_interfaces__action__StartGoalAction__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _user_action_interfaces__action__StartGoalAction__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, user_action_interfaces, action, StartGoalAction_FeedbackMessage)();
  _user_action_interfaces__action__StartGoalAction__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_user_action_interfaces__action__StartGoalAction__typesupport_c;
}

#ifdef __cplusplus
}
#endif
