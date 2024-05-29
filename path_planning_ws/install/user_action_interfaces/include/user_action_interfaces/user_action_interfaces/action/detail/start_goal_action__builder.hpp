// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from user_action_interfaces:action/StartGoalAction.idl
// generated code does not contain a copyright notice

#ifndef USER_ACTION_INTERFACES__ACTION__DETAIL__START_GOAL_ACTION__BUILDER_HPP_
#define USER_ACTION_INTERFACES__ACTION__DETAIL__START_GOAL_ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "user_action_interfaces/action/detail/start_goal_action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace user_action_interfaces
{

namespace action
{

namespace builder
{

class Init_StartGoalAction_Goal_goal
{
public:
  explicit Init_StartGoalAction_Goal_goal(::user_action_interfaces::action::StartGoalAction_Goal & msg)
  : msg_(msg)
  {}
  ::user_action_interfaces::action::StartGoalAction_Goal goal(::user_action_interfaces::action::StartGoalAction_Goal::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_Goal msg_;
};

class Init_StartGoalAction_Goal_start
{
public:
  Init_StartGoalAction_Goal_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartGoalAction_Goal_goal start(::user_action_interfaces::action::StartGoalAction_Goal::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_StartGoalAction_Goal_goal(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_action_interfaces::action::StartGoalAction_Goal>()
{
  return user_action_interfaces::action::builder::Init_StartGoalAction_Goal_start();
}

}  // namespace user_action_interfaces


namespace user_action_interfaces
{

namespace action
{

namespace builder
{

class Init_StartGoalAction_Result_path
{
public:
  Init_StartGoalAction_Result_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::user_action_interfaces::action::StartGoalAction_Result path(::user_action_interfaces::action::StartGoalAction_Result::_path_type arg)
  {
    msg_.path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_action_interfaces::action::StartGoalAction_Result>()
{
  return user_action_interfaces::action::builder::Init_StartGoalAction_Result_path();
}

}  // namespace user_action_interfaces


namespace user_action_interfaces
{

namespace action
{

namespace builder
{

class Init_StartGoalAction_Feedback_partial_path
{
public:
  Init_StartGoalAction_Feedback_partial_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::user_action_interfaces::action::StartGoalAction_Feedback partial_path(::user_action_interfaces::action::StartGoalAction_Feedback::_partial_path_type arg)
  {
    msg_.partial_path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_action_interfaces::action::StartGoalAction_Feedback>()
{
  return user_action_interfaces::action::builder::Init_StartGoalAction_Feedback_partial_path();
}

}  // namespace user_action_interfaces


namespace user_action_interfaces
{

namespace action
{

namespace builder
{

class Init_StartGoalAction_SendGoal_Request_goal
{
public:
  explicit Init_StartGoalAction_SendGoal_Request_goal(::user_action_interfaces::action::StartGoalAction_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::user_action_interfaces::action::StartGoalAction_SendGoal_Request goal(::user_action_interfaces::action::StartGoalAction_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_SendGoal_Request msg_;
};

class Init_StartGoalAction_SendGoal_Request_goal_id
{
public:
  Init_StartGoalAction_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartGoalAction_SendGoal_Request_goal goal_id(::user_action_interfaces::action::StartGoalAction_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_StartGoalAction_SendGoal_Request_goal(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_action_interfaces::action::StartGoalAction_SendGoal_Request>()
{
  return user_action_interfaces::action::builder::Init_StartGoalAction_SendGoal_Request_goal_id();
}

}  // namespace user_action_interfaces


namespace user_action_interfaces
{

namespace action
{

namespace builder
{

class Init_StartGoalAction_SendGoal_Response_stamp
{
public:
  explicit Init_StartGoalAction_SendGoal_Response_stamp(::user_action_interfaces::action::StartGoalAction_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::user_action_interfaces::action::StartGoalAction_SendGoal_Response stamp(::user_action_interfaces::action::StartGoalAction_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_SendGoal_Response msg_;
};

class Init_StartGoalAction_SendGoal_Response_accepted
{
public:
  Init_StartGoalAction_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartGoalAction_SendGoal_Response_stamp accepted(::user_action_interfaces::action::StartGoalAction_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_StartGoalAction_SendGoal_Response_stamp(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_action_interfaces::action::StartGoalAction_SendGoal_Response>()
{
  return user_action_interfaces::action::builder::Init_StartGoalAction_SendGoal_Response_accepted();
}

}  // namespace user_action_interfaces


namespace user_action_interfaces
{

namespace action
{

namespace builder
{

class Init_StartGoalAction_SendGoal_Event_response
{
public:
  explicit Init_StartGoalAction_SendGoal_Event_response(::user_action_interfaces::action::StartGoalAction_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::user_action_interfaces::action::StartGoalAction_SendGoal_Event response(::user_action_interfaces::action::StartGoalAction_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_SendGoal_Event msg_;
};

class Init_StartGoalAction_SendGoal_Event_request
{
public:
  explicit Init_StartGoalAction_SendGoal_Event_request(::user_action_interfaces::action::StartGoalAction_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_StartGoalAction_SendGoal_Event_response request(::user_action_interfaces::action::StartGoalAction_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_StartGoalAction_SendGoal_Event_response(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_SendGoal_Event msg_;
};

class Init_StartGoalAction_SendGoal_Event_info
{
public:
  Init_StartGoalAction_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartGoalAction_SendGoal_Event_request info(::user_action_interfaces::action::StartGoalAction_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_StartGoalAction_SendGoal_Event_request(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_action_interfaces::action::StartGoalAction_SendGoal_Event>()
{
  return user_action_interfaces::action::builder::Init_StartGoalAction_SendGoal_Event_info();
}

}  // namespace user_action_interfaces


namespace user_action_interfaces
{

namespace action
{

namespace builder
{

class Init_StartGoalAction_GetResult_Request_goal_id
{
public:
  Init_StartGoalAction_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::user_action_interfaces::action::StartGoalAction_GetResult_Request goal_id(::user_action_interfaces::action::StartGoalAction_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_action_interfaces::action::StartGoalAction_GetResult_Request>()
{
  return user_action_interfaces::action::builder::Init_StartGoalAction_GetResult_Request_goal_id();
}

}  // namespace user_action_interfaces


namespace user_action_interfaces
{

namespace action
{

namespace builder
{

class Init_StartGoalAction_GetResult_Response_result
{
public:
  explicit Init_StartGoalAction_GetResult_Response_result(::user_action_interfaces::action::StartGoalAction_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::user_action_interfaces::action::StartGoalAction_GetResult_Response result(::user_action_interfaces::action::StartGoalAction_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_GetResult_Response msg_;
};

class Init_StartGoalAction_GetResult_Response_status
{
public:
  Init_StartGoalAction_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartGoalAction_GetResult_Response_result status(::user_action_interfaces::action::StartGoalAction_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_StartGoalAction_GetResult_Response_result(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_action_interfaces::action::StartGoalAction_GetResult_Response>()
{
  return user_action_interfaces::action::builder::Init_StartGoalAction_GetResult_Response_status();
}

}  // namespace user_action_interfaces


namespace user_action_interfaces
{

namespace action
{

namespace builder
{

class Init_StartGoalAction_GetResult_Event_response
{
public:
  explicit Init_StartGoalAction_GetResult_Event_response(::user_action_interfaces::action::StartGoalAction_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::user_action_interfaces::action::StartGoalAction_GetResult_Event response(::user_action_interfaces::action::StartGoalAction_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_GetResult_Event msg_;
};

class Init_StartGoalAction_GetResult_Event_request
{
public:
  explicit Init_StartGoalAction_GetResult_Event_request(::user_action_interfaces::action::StartGoalAction_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_StartGoalAction_GetResult_Event_response request(::user_action_interfaces::action::StartGoalAction_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_StartGoalAction_GetResult_Event_response(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_GetResult_Event msg_;
};

class Init_StartGoalAction_GetResult_Event_info
{
public:
  Init_StartGoalAction_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartGoalAction_GetResult_Event_request info(::user_action_interfaces::action::StartGoalAction_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_StartGoalAction_GetResult_Event_request(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_action_interfaces::action::StartGoalAction_GetResult_Event>()
{
  return user_action_interfaces::action::builder::Init_StartGoalAction_GetResult_Event_info();
}

}  // namespace user_action_interfaces


namespace user_action_interfaces
{

namespace action
{

namespace builder
{

class Init_StartGoalAction_FeedbackMessage_feedback
{
public:
  explicit Init_StartGoalAction_FeedbackMessage_feedback(::user_action_interfaces::action::StartGoalAction_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::user_action_interfaces::action::StartGoalAction_FeedbackMessage feedback(::user_action_interfaces::action::StartGoalAction_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_FeedbackMessage msg_;
};

class Init_StartGoalAction_FeedbackMessage_goal_id
{
public:
  Init_StartGoalAction_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartGoalAction_FeedbackMessage_feedback goal_id(::user_action_interfaces::action::StartGoalAction_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_StartGoalAction_FeedbackMessage_feedback(msg_);
  }

private:
  ::user_action_interfaces::action::StartGoalAction_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::user_action_interfaces::action::StartGoalAction_FeedbackMessage>()
{
  return user_action_interfaces::action::builder::Init_StartGoalAction_FeedbackMessage_goal_id();
}

}  // namespace user_action_interfaces

#endif  // USER_ACTION_INTERFACES__ACTION__DETAIL__START_GOAL_ACTION__BUILDER_HPP_
