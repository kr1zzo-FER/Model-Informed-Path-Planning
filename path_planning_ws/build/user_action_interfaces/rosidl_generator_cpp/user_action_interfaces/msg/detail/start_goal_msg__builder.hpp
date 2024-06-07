// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from user_action_interfaces:msg/StartGoalMsg.idl
// generated code does not contain a copyright notice

#ifndef USER_ACTION_INTERFACES__MSG__DETAIL__START_GOAL_MSG__BUILDER_HPP_
#define USER_ACTION_INTERFACES__MSG__DETAIL__START_GOAL_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "user_action_interfaces/msg/detail/start_goal_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace user_action_interfaces
{

namespace msg
{

namespace builder
{

class Init_StartGoalMsg_goal
{
public:
  explicit Init_StartGoalMsg_goal(::user_action_interfaces::msg::StartGoalMsg & msg)
  : msg_(msg)
  {}
  ::user_action_interfaces::msg::StartGoalMsg goal(::user_action_interfaces::msg::StartGoalMsg::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_action_interfaces::msg::StartGoalMsg msg_;
};

class Init_StartGoalMsg_start
{
public:
  explicit Init_StartGoalMsg_start(::user_action_interfaces::msg::StartGoalMsg & msg)
  : msg_(msg)
  {}
  Init_StartGoalMsg_goal start(::user_action_interfaces::msg::StartGoalMsg::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_StartGoalMsg_goal(msg_);
  }

private:
  ::user_action_interfaces::msg::StartGoalMsg msg_;
};

class Init_StartGoalMsg_frame_id
{
public:
  explicit Init_StartGoalMsg_frame_id(::user_action_interfaces::msg::StartGoalMsg & msg)
  : msg_(msg)
  {}
  Init_StartGoalMsg_start frame_id(::user_action_interfaces::msg::StartGoalMsg::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return Init_StartGoalMsg_start(msg_);
  }

private:
  ::user_action_interfaces::msg::StartGoalMsg msg_;
};

class Init_StartGoalMsg_header
{
public:
  Init_StartGoalMsg_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartGoalMsg_frame_id header(::user_action_interfaces::msg::StartGoalMsg::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_StartGoalMsg_frame_id(msg_);
  }

private:
  ::user_action_interfaces::msg::StartGoalMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_action_interfaces::msg::StartGoalMsg>()
{
  return user_action_interfaces::msg::builder::Init_StartGoalMsg_header();
}

}  // namespace user_action_interfaces

#endif  // USER_ACTION_INTERFACES__MSG__DETAIL__START_GOAL_MSG__BUILDER_HPP_
