// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from user_action_interfaces:msg/CoastMsg.idl
// generated code does not contain a copyright notice

#ifndef USER_ACTION_INTERFACES__MSG__DETAIL__COAST_MSG__BUILDER_HPP_
#define USER_ACTION_INTERFACES__MSG__DETAIL__COAST_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "user_action_interfaces/msg/detail/coast_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace user_action_interfaces
{

namespace msg
{

namespace builder
{

class Init_CoastMsg_grid_size
{
public:
  explicit Init_CoastMsg_grid_size(::user_action_interfaces::msg::CoastMsg & msg)
  : msg_(msg)
  {}
  ::user_action_interfaces::msg::CoastMsg grid_size(::user_action_interfaces::msg::CoastMsg::_grid_size_type arg)
  {
    msg_.grid_size = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_action_interfaces::msg::CoastMsg msg_;
};

class Init_CoastMsg_yellow_points
{
public:
  explicit Init_CoastMsg_yellow_points(::user_action_interfaces::msg::CoastMsg & msg)
  : msg_(msg)
  {}
  Init_CoastMsg_grid_size yellow_points(::user_action_interfaces::msg::CoastMsg::_yellow_points_type arg)
  {
    msg_.yellow_points = std::move(arg);
    return Init_CoastMsg_grid_size(msg_);
  }

private:
  ::user_action_interfaces::msg::CoastMsg msg_;
};

class Init_CoastMsg_red_points
{
public:
  explicit Init_CoastMsg_red_points(::user_action_interfaces::msg::CoastMsg & msg)
  : msg_(msg)
  {}
  Init_CoastMsg_yellow_points red_points(::user_action_interfaces::msg::CoastMsg::_red_points_type arg)
  {
    msg_.red_points = std::move(arg);
    return Init_CoastMsg_yellow_points(msg_);
  }

private:
  ::user_action_interfaces::msg::CoastMsg msg_;
};

class Init_CoastMsg_green_points
{
public:
  explicit Init_CoastMsg_green_points(::user_action_interfaces::msg::CoastMsg & msg)
  : msg_(msg)
  {}
  Init_CoastMsg_red_points green_points(::user_action_interfaces::msg::CoastMsg::_green_points_type arg)
  {
    msg_.green_points = std::move(arg);
    return Init_CoastMsg_red_points(msg_);
  }

private:
  ::user_action_interfaces::msg::CoastMsg msg_;
};

class Init_CoastMsg_coast_points
{
public:
  explicit Init_CoastMsg_coast_points(::user_action_interfaces::msg::CoastMsg & msg)
  : msg_(msg)
  {}
  Init_CoastMsg_green_points coast_points(::user_action_interfaces::msg::CoastMsg::_coast_points_type arg)
  {
    msg_.coast_points = std::move(arg);
    return Init_CoastMsg_green_points(msg_);
  }

private:
  ::user_action_interfaces::msg::CoastMsg msg_;
};

class Init_CoastMsg_frame_id
{
public:
  explicit Init_CoastMsg_frame_id(::user_action_interfaces::msg::CoastMsg & msg)
  : msg_(msg)
  {}
  Init_CoastMsg_coast_points frame_id(::user_action_interfaces::msg::CoastMsg::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return Init_CoastMsg_coast_points(msg_);
  }

private:
  ::user_action_interfaces::msg::CoastMsg msg_;
};

class Init_CoastMsg_header
{
public:
  Init_CoastMsg_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CoastMsg_frame_id header(::user_action_interfaces::msg::CoastMsg::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_CoastMsg_frame_id(msg_);
  }

private:
  ::user_action_interfaces::msg::CoastMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_action_interfaces::msg::CoastMsg>()
{
  return user_action_interfaces::msg::builder::Init_CoastMsg_header();
}

}  // namespace user_action_interfaces

#endif  // USER_ACTION_INTERFACES__MSG__DETAIL__COAST_MSG__BUILDER_HPP_
