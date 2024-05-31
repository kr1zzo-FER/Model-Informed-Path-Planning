// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from user_action_interfaces:msg/PathMsg.idl
// generated code does not contain a copyright notice

#ifndef USER_ACTION_INTERFACES__MSG__DETAIL__PATH_MSG__BUILDER_HPP_
#define USER_ACTION_INTERFACES__MSG__DETAIL__PATH_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "user_action_interfaces/msg/detail/path_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace user_action_interfaces
{

namespace msg
{

namespace builder
{

class Init_PathMsg_path_y
{
public:
  explicit Init_PathMsg_path_y(::user_action_interfaces::msg::PathMsg & msg)
  : msg_(msg)
  {}
  ::user_action_interfaces::msg::PathMsg path_y(::user_action_interfaces::msg::PathMsg::_path_y_type arg)
  {
    msg_.path_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_action_interfaces::msg::PathMsg msg_;
};

class Init_PathMsg_path_x
{
public:
  explicit Init_PathMsg_path_x(::user_action_interfaces::msg::PathMsg & msg)
  : msg_(msg)
  {}
  Init_PathMsg_path_y path_x(::user_action_interfaces::msg::PathMsg::_path_x_type arg)
  {
    msg_.path_x = std::move(arg);
    return Init_PathMsg_path_y(msg_);
  }

private:
  ::user_action_interfaces::msg::PathMsg msg_;
};

class Init_PathMsg_frame_id
{
public:
  explicit Init_PathMsg_frame_id(::user_action_interfaces::msg::PathMsg & msg)
  : msg_(msg)
  {}
  Init_PathMsg_path_x frame_id(::user_action_interfaces::msg::PathMsg::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return Init_PathMsg_path_x(msg_);
  }

private:
  ::user_action_interfaces::msg::PathMsg msg_;
};

class Init_PathMsg_header
{
public:
  Init_PathMsg_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PathMsg_frame_id header(::user_action_interfaces::msg::PathMsg::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PathMsg_frame_id(msg_);
  }

private:
  ::user_action_interfaces::msg::PathMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_action_interfaces::msg::PathMsg>()
{
  return user_action_interfaces::msg::builder::Init_PathMsg_header();
}

}  // namespace user_action_interfaces

#endif  // USER_ACTION_INTERFACES__MSG__DETAIL__PATH_MSG__BUILDER_HPP_
