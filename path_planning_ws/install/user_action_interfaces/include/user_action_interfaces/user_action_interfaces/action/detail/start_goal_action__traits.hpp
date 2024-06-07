// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from user_action_interfaces:action/StartGoalAction.idl
// generated code does not contain a copyright notice

#ifndef USER_ACTION_INTERFACES__ACTION__DETAIL__START_GOAL_ACTION__TRAITS_HPP_
#define USER_ACTION_INTERFACES__ACTION__DETAIL__START_GOAL_ACTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "user_action_interfaces/action/detail/start_goal_action__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace user_action_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const StartGoalAction_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: start
  {
    if (msg.start.size() == 0) {
      out << "start: []";
    } else {
      out << "start: [";
      size_t pending_items = msg.start.size();
      for (auto item : msg.start) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: goal
  {
    if (msg.goal.size() == 0) {
      out << "goal: []";
    } else {
      out << "goal: [";
      size_t pending_items = msg.goal.size();
      for (auto item : msg.goal) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartGoalAction_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.start.size() == 0) {
      out << "start: []\n";
    } else {
      out << "start:\n";
      for (auto item : msg.start) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.goal.size() == 0) {
      out << "goal: []\n";
    } else {
      out << "goal:\n";
      for (auto item : msg.goal) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartGoalAction_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace user_action_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use user_action_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const user_action_interfaces::action::StartGoalAction_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_action_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_action_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const user_action_interfaces::action::StartGoalAction_Goal & msg)
{
  return user_action_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<user_action_interfaces::action::StartGoalAction_Goal>()
{
  return "user_action_interfaces::action::StartGoalAction_Goal";
}

template<>
inline const char * name<user_action_interfaces::action::StartGoalAction_Goal>()
{
  return "user_action_interfaces/action/StartGoalAction_Goal";
}

template<>
struct has_fixed_size<user_action_interfaces::action::StartGoalAction_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<user_action_interfaces::action::StartGoalAction_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<user_action_interfaces::action::StartGoalAction_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace user_action_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const StartGoalAction_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: path_x
  {
    if (msg.path_x.size() == 0) {
      out << "path_x: []";
    } else {
      out << "path_x: [";
      size_t pending_items = msg.path_x.size();
      for (auto item : msg.path_x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: path_y
  {
    if (msg.path_y.size() == 0) {
      out << "path_y: []";
    } else {
      out << "path_y: [";
      size_t pending_items = msg.path_y.size();
      for (auto item : msg.path_y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartGoalAction_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: path_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.path_x.size() == 0) {
      out << "path_x: []\n";
    } else {
      out << "path_x:\n";
      for (auto item : msg.path_x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: path_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.path_y.size() == 0) {
      out << "path_y: []\n";
    } else {
      out << "path_y:\n";
      for (auto item : msg.path_y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartGoalAction_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace user_action_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use user_action_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const user_action_interfaces::action::StartGoalAction_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_action_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_action_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const user_action_interfaces::action::StartGoalAction_Result & msg)
{
  return user_action_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<user_action_interfaces::action::StartGoalAction_Result>()
{
  return "user_action_interfaces::action::StartGoalAction_Result";
}

template<>
inline const char * name<user_action_interfaces::action::StartGoalAction_Result>()
{
  return "user_action_interfaces/action/StartGoalAction_Result";
}

template<>
struct has_fixed_size<user_action_interfaces::action::StartGoalAction_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<user_action_interfaces::action::StartGoalAction_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<user_action_interfaces::action::StartGoalAction_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace user_action_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const StartGoalAction_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: partial_path_x
  {
    if (msg.partial_path_x.size() == 0) {
      out << "partial_path_x: []";
    } else {
      out << "partial_path_x: [";
      size_t pending_items = msg.partial_path_x.size();
      for (auto item : msg.partial_path_x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: partial_path_y
  {
    if (msg.partial_path_y.size() == 0) {
      out << "partial_path_y: []";
    } else {
      out << "partial_path_y: [";
      size_t pending_items = msg.partial_path_y.size();
      for (auto item : msg.partial_path_y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartGoalAction_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: partial_path_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.partial_path_x.size() == 0) {
      out << "partial_path_x: []\n";
    } else {
      out << "partial_path_x:\n";
      for (auto item : msg.partial_path_x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: partial_path_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.partial_path_y.size() == 0) {
      out << "partial_path_y: []\n";
    } else {
      out << "partial_path_y:\n";
      for (auto item : msg.partial_path_y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartGoalAction_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace user_action_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use user_action_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const user_action_interfaces::action::StartGoalAction_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_action_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_action_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const user_action_interfaces::action::StartGoalAction_Feedback & msg)
{
  return user_action_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<user_action_interfaces::action::StartGoalAction_Feedback>()
{
  return "user_action_interfaces::action::StartGoalAction_Feedback";
}

template<>
inline const char * name<user_action_interfaces::action::StartGoalAction_Feedback>()
{
  return "user_action_interfaces/action/StartGoalAction_Feedback";
}

template<>
struct has_fixed_size<user_action_interfaces::action::StartGoalAction_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<user_action_interfaces::action::StartGoalAction_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<user_action_interfaces::action::StartGoalAction_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "user_action_interfaces/action/detail/start_goal_action__traits.hpp"

namespace user_action_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const StartGoalAction_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartGoalAction_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartGoalAction_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace user_action_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use user_action_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const user_action_interfaces::action::StartGoalAction_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_action_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_action_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const user_action_interfaces::action::StartGoalAction_SendGoal_Request & msg)
{
  return user_action_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<user_action_interfaces::action::StartGoalAction_SendGoal_Request>()
{
  return "user_action_interfaces::action::StartGoalAction_SendGoal_Request";
}

template<>
inline const char * name<user_action_interfaces::action::StartGoalAction_SendGoal_Request>()
{
  return "user_action_interfaces/action/StartGoalAction_SendGoal_Request";
}

template<>
struct has_fixed_size<user_action_interfaces::action::StartGoalAction_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value && has_fixed_size<user_action_interfaces::action::StartGoalAction_Goal>::value> {};

template<>
struct has_bounded_size<user_action_interfaces::action::StartGoalAction_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value && has_bounded_size<user_action_interfaces::action::StartGoalAction_Goal>::value> {};

template<>
struct is_message<user_action_interfaces::action::StartGoalAction_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace user_action_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const StartGoalAction_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartGoalAction_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartGoalAction_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace user_action_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use user_action_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const user_action_interfaces::action::StartGoalAction_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_action_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_action_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const user_action_interfaces::action::StartGoalAction_SendGoal_Response & msg)
{
  return user_action_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<user_action_interfaces::action::StartGoalAction_SendGoal_Response>()
{
  return "user_action_interfaces::action::StartGoalAction_SendGoal_Response";
}

template<>
inline const char * name<user_action_interfaces::action::StartGoalAction_SendGoal_Response>()
{
  return "user_action_interfaces/action/StartGoalAction_SendGoal_Response";
}

template<>
struct has_fixed_size<user_action_interfaces::action::StartGoalAction_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<user_action_interfaces::action::StartGoalAction_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<user_action_interfaces::action::StartGoalAction_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace user_action_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const StartGoalAction_SendGoal_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartGoalAction_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartGoalAction_SendGoal_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace user_action_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use user_action_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const user_action_interfaces::action::StartGoalAction_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_action_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_action_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const user_action_interfaces::action::StartGoalAction_SendGoal_Event & msg)
{
  return user_action_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<user_action_interfaces::action::StartGoalAction_SendGoal_Event>()
{
  return "user_action_interfaces::action::StartGoalAction_SendGoal_Event";
}

template<>
inline const char * name<user_action_interfaces::action::StartGoalAction_SendGoal_Event>()
{
  return "user_action_interfaces/action/StartGoalAction_SendGoal_Event";
}

template<>
struct has_fixed_size<user_action_interfaces::action::StartGoalAction_SendGoal_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<user_action_interfaces::action::StartGoalAction_SendGoal_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<user_action_interfaces::action::StartGoalAction_SendGoal_Request>::value && has_bounded_size<user_action_interfaces::action::StartGoalAction_SendGoal_Response>::value> {};

template<>
struct is_message<user_action_interfaces::action::StartGoalAction_SendGoal_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<user_action_interfaces::action::StartGoalAction_SendGoal>()
{
  return "user_action_interfaces::action::StartGoalAction_SendGoal";
}

template<>
inline const char * name<user_action_interfaces::action::StartGoalAction_SendGoal>()
{
  return "user_action_interfaces/action/StartGoalAction_SendGoal";
}

template<>
struct has_fixed_size<user_action_interfaces::action::StartGoalAction_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<user_action_interfaces::action::StartGoalAction_SendGoal_Request>::value &&
    has_fixed_size<user_action_interfaces::action::StartGoalAction_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<user_action_interfaces::action::StartGoalAction_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<user_action_interfaces::action::StartGoalAction_SendGoal_Request>::value &&
    has_bounded_size<user_action_interfaces::action::StartGoalAction_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<user_action_interfaces::action::StartGoalAction_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<user_action_interfaces::action::StartGoalAction_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<user_action_interfaces::action::StartGoalAction_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace user_action_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const StartGoalAction_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartGoalAction_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartGoalAction_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace user_action_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use user_action_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const user_action_interfaces::action::StartGoalAction_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_action_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_action_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const user_action_interfaces::action::StartGoalAction_GetResult_Request & msg)
{
  return user_action_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<user_action_interfaces::action::StartGoalAction_GetResult_Request>()
{
  return "user_action_interfaces::action::StartGoalAction_GetResult_Request";
}

template<>
inline const char * name<user_action_interfaces::action::StartGoalAction_GetResult_Request>()
{
  return "user_action_interfaces/action/StartGoalAction_GetResult_Request";
}

template<>
struct has_fixed_size<user_action_interfaces::action::StartGoalAction_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<user_action_interfaces::action::StartGoalAction_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<user_action_interfaces::action::StartGoalAction_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__traits.hpp"

namespace user_action_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const StartGoalAction_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartGoalAction_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartGoalAction_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace user_action_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use user_action_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const user_action_interfaces::action::StartGoalAction_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_action_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_action_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const user_action_interfaces::action::StartGoalAction_GetResult_Response & msg)
{
  return user_action_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<user_action_interfaces::action::StartGoalAction_GetResult_Response>()
{
  return "user_action_interfaces::action::StartGoalAction_GetResult_Response";
}

template<>
inline const char * name<user_action_interfaces::action::StartGoalAction_GetResult_Response>()
{
  return "user_action_interfaces/action/StartGoalAction_GetResult_Response";
}

template<>
struct has_fixed_size<user_action_interfaces::action::StartGoalAction_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<user_action_interfaces::action::StartGoalAction_Result>::value> {};

template<>
struct has_bounded_size<user_action_interfaces::action::StartGoalAction_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<user_action_interfaces::action::StartGoalAction_Result>::value> {};

template<>
struct is_message<user_action_interfaces::action::StartGoalAction_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace user_action_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const StartGoalAction_GetResult_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartGoalAction_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartGoalAction_GetResult_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace user_action_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use user_action_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const user_action_interfaces::action::StartGoalAction_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_action_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_action_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const user_action_interfaces::action::StartGoalAction_GetResult_Event & msg)
{
  return user_action_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<user_action_interfaces::action::StartGoalAction_GetResult_Event>()
{
  return "user_action_interfaces::action::StartGoalAction_GetResult_Event";
}

template<>
inline const char * name<user_action_interfaces::action::StartGoalAction_GetResult_Event>()
{
  return "user_action_interfaces/action/StartGoalAction_GetResult_Event";
}

template<>
struct has_fixed_size<user_action_interfaces::action::StartGoalAction_GetResult_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<user_action_interfaces::action::StartGoalAction_GetResult_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<user_action_interfaces::action::StartGoalAction_GetResult_Request>::value && has_bounded_size<user_action_interfaces::action::StartGoalAction_GetResult_Response>::value> {};

template<>
struct is_message<user_action_interfaces::action::StartGoalAction_GetResult_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<user_action_interfaces::action::StartGoalAction_GetResult>()
{
  return "user_action_interfaces::action::StartGoalAction_GetResult";
}

template<>
inline const char * name<user_action_interfaces::action::StartGoalAction_GetResult>()
{
  return "user_action_interfaces/action/StartGoalAction_GetResult";
}

template<>
struct has_fixed_size<user_action_interfaces::action::StartGoalAction_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<user_action_interfaces::action::StartGoalAction_GetResult_Request>::value &&
    has_fixed_size<user_action_interfaces::action::StartGoalAction_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<user_action_interfaces::action::StartGoalAction_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<user_action_interfaces::action::StartGoalAction_GetResult_Request>::value &&
    has_bounded_size<user_action_interfaces::action::StartGoalAction_GetResult_Response>::value
  >
{
};

template<>
struct is_service<user_action_interfaces::action::StartGoalAction_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<user_action_interfaces::action::StartGoalAction_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<user_action_interfaces::action::StartGoalAction_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "user_action_interfaces/action/detail/start_goal_action__traits.hpp"

namespace user_action_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const StartGoalAction_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartGoalAction_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartGoalAction_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace user_action_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use user_action_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const user_action_interfaces::action::StartGoalAction_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_action_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_action_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const user_action_interfaces::action::StartGoalAction_FeedbackMessage & msg)
{
  return user_action_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<user_action_interfaces::action::StartGoalAction_FeedbackMessage>()
{
  return "user_action_interfaces::action::StartGoalAction_FeedbackMessage";
}

template<>
inline const char * name<user_action_interfaces::action::StartGoalAction_FeedbackMessage>()
{
  return "user_action_interfaces/action/StartGoalAction_FeedbackMessage";
}

template<>
struct has_fixed_size<user_action_interfaces::action::StartGoalAction_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value && has_fixed_size<user_action_interfaces::action::StartGoalAction_Feedback>::value> {};

template<>
struct has_bounded_size<user_action_interfaces::action::StartGoalAction_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value && has_bounded_size<user_action_interfaces::action::StartGoalAction_Feedback>::value> {};

template<>
struct is_message<user_action_interfaces::action::StartGoalAction_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<user_action_interfaces::action::StartGoalAction>
  : std::true_type
{
};

template<>
struct is_action_goal<user_action_interfaces::action::StartGoalAction_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<user_action_interfaces::action::StartGoalAction_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<user_action_interfaces::action::StartGoalAction_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // USER_ACTION_INTERFACES__ACTION__DETAIL__START_GOAL_ACTION__TRAITS_HPP_
