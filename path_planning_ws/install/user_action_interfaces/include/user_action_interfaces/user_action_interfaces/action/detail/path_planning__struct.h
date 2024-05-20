// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from user_action_interfaces:action/PathPlanning.idl
// generated code does not contain a copyright notice

#ifndef USER_ACTION_INTERFACES__ACTION__DETAIL__PATH_PLANNING__STRUCT_H_
#define USER_ACTION_INTERFACES__ACTION__DETAIL__PATH_PLANNING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'start_goal'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/PathPlanning in the package user_action_interfaces.
typedef struct user_action_interfaces__action__PathPlanning_Goal
{
  rosidl_runtime_c__int32__Sequence start_goal;
} user_action_interfaces__action__PathPlanning_Goal;

// Struct for a sequence of user_action_interfaces__action__PathPlanning_Goal.
typedef struct user_action_interfaces__action__PathPlanning_Goal__Sequence
{
  user_action_interfaces__action__PathPlanning_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_action_interfaces__action__PathPlanning_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'path'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/PathPlanning in the package user_action_interfaces.
typedef struct user_action_interfaces__action__PathPlanning_Result
{
  rosidl_runtime_c__int32__Sequence path;
} user_action_interfaces__action__PathPlanning_Result;

// Struct for a sequence of user_action_interfaces__action__PathPlanning_Result.
typedef struct user_action_interfaces__action__PathPlanning_Result__Sequence
{
  user_action_interfaces__action__PathPlanning_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_action_interfaces__action__PathPlanning_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'partial_path'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/PathPlanning in the package user_action_interfaces.
typedef struct user_action_interfaces__action__PathPlanning_Feedback
{
  rosidl_runtime_c__int32__Sequence partial_path;
} user_action_interfaces__action__PathPlanning_Feedback;

// Struct for a sequence of user_action_interfaces__action__PathPlanning_Feedback.
typedef struct user_action_interfaces__action__PathPlanning_Feedback__Sequence
{
  user_action_interfaces__action__PathPlanning_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_action_interfaces__action__PathPlanning_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "user_action_interfaces/action/detail/path_planning__struct.h"

/// Struct defined in action/PathPlanning in the package user_action_interfaces.
typedef struct user_action_interfaces__action__PathPlanning_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  user_action_interfaces__action__PathPlanning_Goal goal;
} user_action_interfaces__action__PathPlanning_SendGoal_Request;

// Struct for a sequence of user_action_interfaces__action__PathPlanning_SendGoal_Request.
typedef struct user_action_interfaces__action__PathPlanning_SendGoal_Request__Sequence
{
  user_action_interfaces__action__PathPlanning_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_action_interfaces__action__PathPlanning_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/PathPlanning in the package user_action_interfaces.
typedef struct user_action_interfaces__action__PathPlanning_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} user_action_interfaces__action__PathPlanning_SendGoal_Response;

// Struct for a sequence of user_action_interfaces__action__PathPlanning_SendGoal_Response.
typedef struct user_action_interfaces__action__PathPlanning_SendGoal_Response__Sequence
{
  user_action_interfaces__action__PathPlanning_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_action_interfaces__action__PathPlanning_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  user_action_interfaces__action__PathPlanning_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  user_action_interfaces__action__PathPlanning_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/PathPlanning in the package user_action_interfaces.
typedef struct user_action_interfaces__action__PathPlanning_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  user_action_interfaces__action__PathPlanning_SendGoal_Request__Sequence request;
  user_action_interfaces__action__PathPlanning_SendGoal_Response__Sequence response;
} user_action_interfaces__action__PathPlanning_SendGoal_Event;

// Struct for a sequence of user_action_interfaces__action__PathPlanning_SendGoal_Event.
typedef struct user_action_interfaces__action__PathPlanning_SendGoal_Event__Sequence
{
  user_action_interfaces__action__PathPlanning_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_action_interfaces__action__PathPlanning_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/PathPlanning in the package user_action_interfaces.
typedef struct user_action_interfaces__action__PathPlanning_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} user_action_interfaces__action__PathPlanning_GetResult_Request;

// Struct for a sequence of user_action_interfaces__action__PathPlanning_GetResult_Request.
typedef struct user_action_interfaces__action__PathPlanning_GetResult_Request__Sequence
{
  user_action_interfaces__action__PathPlanning_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_action_interfaces__action__PathPlanning_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "user_action_interfaces/action/detail/path_planning__struct.h"

/// Struct defined in action/PathPlanning in the package user_action_interfaces.
typedef struct user_action_interfaces__action__PathPlanning_GetResult_Response
{
  int8_t status;
  user_action_interfaces__action__PathPlanning_Result result;
} user_action_interfaces__action__PathPlanning_GetResult_Response;

// Struct for a sequence of user_action_interfaces__action__PathPlanning_GetResult_Response.
typedef struct user_action_interfaces__action__PathPlanning_GetResult_Response__Sequence
{
  user_action_interfaces__action__PathPlanning_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_action_interfaces__action__PathPlanning_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  user_action_interfaces__action__PathPlanning_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  user_action_interfaces__action__PathPlanning_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/PathPlanning in the package user_action_interfaces.
typedef struct user_action_interfaces__action__PathPlanning_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  user_action_interfaces__action__PathPlanning_GetResult_Request__Sequence request;
  user_action_interfaces__action__PathPlanning_GetResult_Response__Sequence response;
} user_action_interfaces__action__PathPlanning_GetResult_Event;

// Struct for a sequence of user_action_interfaces__action__PathPlanning_GetResult_Event.
typedef struct user_action_interfaces__action__PathPlanning_GetResult_Event__Sequence
{
  user_action_interfaces__action__PathPlanning_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_action_interfaces__action__PathPlanning_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "user_action_interfaces/action/detail/path_planning__struct.h"

/// Struct defined in action/PathPlanning in the package user_action_interfaces.
typedef struct user_action_interfaces__action__PathPlanning_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  user_action_interfaces__action__PathPlanning_Feedback feedback;
} user_action_interfaces__action__PathPlanning_FeedbackMessage;

// Struct for a sequence of user_action_interfaces__action__PathPlanning_FeedbackMessage.
typedef struct user_action_interfaces__action__PathPlanning_FeedbackMessage__Sequence
{
  user_action_interfaces__action__PathPlanning_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} user_action_interfaces__action__PathPlanning_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USER_ACTION_INTERFACES__ACTION__DETAIL__PATH_PLANNING__STRUCT_H_
