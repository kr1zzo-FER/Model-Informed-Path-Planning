// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from user_action_interfaces:msg/StartGoalMsg.idl
// generated code does not contain a copyright notice

#ifndef USER_ACTION_INTERFACES__MSG__DETAIL__START_GOAL_MSG__TRAITS_HPP_
#define USER_ACTION_INTERFACES__MSG__DETAIL__START_GOAL_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "user_action_interfaces/msg/detail/start_goal_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace user_action_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const StartGoalMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: frame_id
  {
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
    out << ", ";
  }

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
  const StartGoalMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_id, out);
    out << "\n";
  }

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

inline std::string to_yaml(const StartGoalMsg & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace user_action_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use user_action_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const user_action_interfaces::msg::StartGoalMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_action_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_action_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const user_action_interfaces::msg::StartGoalMsg & msg)
{
  return user_action_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<user_action_interfaces::msg::StartGoalMsg>()
{
  return "user_action_interfaces::msg::StartGoalMsg";
}

template<>
inline const char * name<user_action_interfaces::msg::StartGoalMsg>()
{
  return "user_action_interfaces/msg/StartGoalMsg";
}

template<>
struct has_fixed_size<user_action_interfaces::msg::StartGoalMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<user_action_interfaces::msg::StartGoalMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<user_action_interfaces::msg::StartGoalMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // USER_ACTION_INTERFACES__MSG__DETAIL__START_GOAL_MSG__TRAITS_HPP_
