// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from user_action_interfaces:msg/CoastMsg.idl
// generated code does not contain a copyright notice

#ifndef USER_ACTION_INTERFACES__MSG__DETAIL__COAST_MSG__TRAITS_HPP_
#define USER_ACTION_INTERFACES__MSG__DETAIL__COAST_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "user_action_interfaces/msg/detail/coast_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'coast_points_x'
// Member 'green_points_x'
// Member 'red_points_x'
// Member 'yellow_points_x'
// Member 'coast_points_y'
// Member 'green_points_y'
// Member 'red_points_y'
// Member 'yellow_points_y'
#include "std_msgs/msg/detail/float32_multi_array__traits.hpp"

namespace user_action_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const CoastMsg & msg,
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

  // member: coast_points_x
  {
    out << "coast_points_x: ";
    to_flow_style_yaml(msg.coast_points_x, out);
    out << ", ";
  }

  // member: green_points_x
  {
    out << "green_points_x: ";
    to_flow_style_yaml(msg.green_points_x, out);
    out << ", ";
  }

  // member: red_points_x
  {
    out << "red_points_x: ";
    to_flow_style_yaml(msg.red_points_x, out);
    out << ", ";
  }

  // member: yellow_points_x
  {
    out << "yellow_points_x: ";
    to_flow_style_yaml(msg.yellow_points_x, out);
    out << ", ";
  }

  // member: coast_points_y
  {
    out << "coast_points_y: ";
    to_flow_style_yaml(msg.coast_points_y, out);
    out << ", ";
  }

  // member: green_points_y
  {
    out << "green_points_y: ";
    to_flow_style_yaml(msg.green_points_y, out);
    out << ", ";
  }

  // member: red_points_y
  {
    out << "red_points_y: ";
    to_flow_style_yaml(msg.red_points_y, out);
    out << ", ";
  }

  // member: yellow_points_y
  {
    out << "yellow_points_y: ";
    to_flow_style_yaml(msg.yellow_points_y, out);
    out << ", ";
  }

  // member: grid_size
  {
    out << "grid_size: ";
    rosidl_generator_traits::value_to_yaml(msg.grid_size, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CoastMsg & msg,
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

  // member: coast_points_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "coast_points_x:\n";
    to_block_style_yaml(msg.coast_points_x, out, indentation + 2);
  }

  // member: green_points_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "green_points_x:\n";
    to_block_style_yaml(msg.green_points_x, out, indentation + 2);
  }

  // member: red_points_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "red_points_x:\n";
    to_block_style_yaml(msg.red_points_x, out, indentation + 2);
  }

  // member: yellow_points_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yellow_points_x:\n";
    to_block_style_yaml(msg.yellow_points_x, out, indentation + 2);
  }

  // member: coast_points_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "coast_points_y:\n";
    to_block_style_yaml(msg.coast_points_y, out, indentation + 2);
  }

  // member: green_points_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "green_points_y:\n";
    to_block_style_yaml(msg.green_points_y, out, indentation + 2);
  }

  // member: red_points_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "red_points_y:\n";
    to_block_style_yaml(msg.red_points_y, out, indentation + 2);
  }

  // member: yellow_points_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yellow_points_y:\n";
    to_block_style_yaml(msg.yellow_points_y, out, indentation + 2);
  }

  // member: grid_size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "grid_size: ";
    rosidl_generator_traits::value_to_yaml(msg.grid_size, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CoastMsg & msg, bool use_flow_style = false)
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
  const user_action_interfaces::msg::CoastMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  user_action_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use user_action_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const user_action_interfaces::msg::CoastMsg & msg)
{
  return user_action_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<user_action_interfaces::msg::CoastMsg>()
{
  return "user_action_interfaces::msg::CoastMsg";
}

template<>
inline const char * name<user_action_interfaces::msg::CoastMsg>()
{
  return "user_action_interfaces/msg/CoastMsg";
}

template<>
struct has_fixed_size<user_action_interfaces::msg::CoastMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<user_action_interfaces::msg::CoastMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<user_action_interfaces::msg::CoastMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // USER_ACTION_INTERFACES__MSG__DETAIL__COAST_MSG__TRAITS_HPP_
