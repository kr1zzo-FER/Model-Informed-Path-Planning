// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from user_action_interfaces:msg/PathMsg.idl
// generated code does not contain a copyright notice

#ifndef USER_ACTION_INTERFACES__MSG__DETAIL__PATH_MSG__TRAITS_HPP_
#define USER_ACTION_INTERFACES__MSG__DETAIL__PATH_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "user_action_interfaces/msg/detail/path_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace user_action_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const PathMsg & msg,
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
  const PathMsg & msg,
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

inline std::string to_yaml(const PathMsg & msg, bool use_flow_style = false)
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
  const user_action_interfaces::msg::PathMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_action_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_action_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const user_action_interfaces::msg::PathMsg & msg)
{
  return user_action_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<user_action_interfaces::msg::PathMsg>()
{
  return "user_action_interfaces::msg::PathMsg";
}

template<>
inline const char * name<user_action_interfaces::msg::PathMsg>()
{
  return "user_action_interfaces/msg/PathMsg";
}

template<>
struct has_fixed_size<user_action_interfaces::msg::PathMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<user_action_interfaces::msg::PathMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<user_action_interfaces::msg::PathMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // USER_ACTION_INTERFACES__MSG__DETAIL__PATH_MSG__TRAITS_HPP_
