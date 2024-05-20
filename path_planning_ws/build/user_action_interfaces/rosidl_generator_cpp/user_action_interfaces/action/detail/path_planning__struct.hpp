// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from user_action_interfaces:action/PathPlanning.idl
// generated code does not contain a copyright notice

#ifndef USER_ACTION_INTERFACES__ACTION__DETAIL__PATH_PLANNING__STRUCT_HPP_
#define USER_ACTION_INTERFACES__ACTION__DETAIL__PATH_PLANNING__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__user_action_interfaces__action__PathPlanning_Goal __attribute__((deprecated))
#else
# define DEPRECATED__user_action_interfaces__action__PathPlanning_Goal __declspec(deprecated)
#endif

namespace user_action_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PathPlanning_Goal_
{
  using Type = PathPlanning_Goal_<ContainerAllocator>;

  explicit PathPlanning_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit PathPlanning_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _start_goal_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _start_goal_type start_goal;

  // setters for named parameter idiom
  Type & set__start_goal(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->start_goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_action_interfaces::action::PathPlanning_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_action_interfaces::action::PathPlanning_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_Goal
    std::shared_ptr<user_action_interfaces::action::PathPlanning_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_Goal
    std::shared_ptr<user_action_interfaces::action::PathPlanning_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathPlanning_Goal_ & other) const
  {
    if (this->start_goal != other.start_goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathPlanning_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathPlanning_Goal_

// alias to use template instance with default allocator
using PathPlanning_Goal =
  user_action_interfaces::action::PathPlanning_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace user_action_interfaces


#ifndef _WIN32
# define DEPRECATED__user_action_interfaces__action__PathPlanning_Result __attribute__((deprecated))
#else
# define DEPRECATED__user_action_interfaces__action__PathPlanning_Result __declspec(deprecated)
#endif

namespace user_action_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PathPlanning_Result_
{
  using Type = PathPlanning_Result_<ContainerAllocator>;

  explicit PathPlanning_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit PathPlanning_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _path_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _path_type path;

  // setters for named parameter idiom
  Type & set__path(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->path = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_action_interfaces::action::PathPlanning_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_action_interfaces::action::PathPlanning_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_Result
    std::shared_ptr<user_action_interfaces::action::PathPlanning_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_Result
    std::shared_ptr<user_action_interfaces::action::PathPlanning_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathPlanning_Result_ & other) const
  {
    if (this->path != other.path) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathPlanning_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathPlanning_Result_

// alias to use template instance with default allocator
using PathPlanning_Result =
  user_action_interfaces::action::PathPlanning_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace user_action_interfaces


#ifndef _WIN32
# define DEPRECATED__user_action_interfaces__action__PathPlanning_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__user_action_interfaces__action__PathPlanning_Feedback __declspec(deprecated)
#endif

namespace user_action_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PathPlanning_Feedback_
{
  using Type = PathPlanning_Feedback_<ContainerAllocator>;

  explicit PathPlanning_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit PathPlanning_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _partial_path_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _partial_path_type partial_path;

  // setters for named parameter idiom
  Type & set__partial_path(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->partial_path = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_action_interfaces::action::PathPlanning_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_action_interfaces::action::PathPlanning_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_Feedback
    std::shared_ptr<user_action_interfaces::action::PathPlanning_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_Feedback
    std::shared_ptr<user_action_interfaces::action::PathPlanning_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathPlanning_Feedback_ & other) const
  {
    if (this->partial_path != other.partial_path) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathPlanning_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathPlanning_Feedback_

// alias to use template instance with default allocator
using PathPlanning_Feedback =
  user_action_interfaces::action::PathPlanning_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace user_action_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "user_action_interfaces/action/detail/path_planning__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__user_action_interfaces__action__PathPlanning_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__user_action_interfaces__action__PathPlanning_SendGoal_Request __declspec(deprecated)
#endif

namespace user_action_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PathPlanning_SendGoal_Request_
{
  using Type = PathPlanning_SendGoal_Request_<ContainerAllocator>;

  explicit PathPlanning_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit PathPlanning_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    user_action_interfaces::action::PathPlanning_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const user_action_interfaces::action::PathPlanning_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_SendGoal_Request
    std::shared_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_SendGoal_Request
    std::shared_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathPlanning_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathPlanning_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathPlanning_SendGoal_Request_

// alias to use template instance with default allocator
using PathPlanning_SendGoal_Request =
  user_action_interfaces::action::PathPlanning_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace user_action_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__user_action_interfaces__action__PathPlanning_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__user_action_interfaces__action__PathPlanning_SendGoal_Response __declspec(deprecated)
#endif

namespace user_action_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PathPlanning_SendGoal_Response_
{
  using Type = PathPlanning_SendGoal_Response_<ContainerAllocator>;

  explicit PathPlanning_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit PathPlanning_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_SendGoal_Response
    std::shared_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_SendGoal_Response
    std::shared_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathPlanning_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathPlanning_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathPlanning_SendGoal_Response_

// alias to use template instance with default allocator
using PathPlanning_SendGoal_Response =
  user_action_interfaces::action::PathPlanning_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace user_action_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__user_action_interfaces__action__PathPlanning_SendGoal_Event __attribute__((deprecated))
#else
# define DEPRECATED__user_action_interfaces__action__PathPlanning_SendGoal_Event __declspec(deprecated)
#endif

namespace user_action_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PathPlanning_SendGoal_Event_
{
  using Type = PathPlanning_SendGoal_Event_<ContainerAllocator>;

  explicit PathPlanning_SendGoal_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit PathPlanning_SendGoal_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<user_action_interfaces::action::PathPlanning_SendGoal_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<user_action_interfaces::action::PathPlanning_SendGoal_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_action_interfaces::action::PathPlanning_SendGoal_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_action_interfaces::action::PathPlanning_SendGoal_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_SendGoal_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_SendGoal_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_SendGoal_Event
    std::shared_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_SendGoal_Event
    std::shared_ptr<user_action_interfaces::action::PathPlanning_SendGoal_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathPlanning_SendGoal_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathPlanning_SendGoal_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathPlanning_SendGoal_Event_

// alias to use template instance with default allocator
using PathPlanning_SendGoal_Event =
  user_action_interfaces::action::PathPlanning_SendGoal_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace user_action_interfaces

namespace user_action_interfaces
{

namespace action
{

struct PathPlanning_SendGoal
{
  using Request = user_action_interfaces::action::PathPlanning_SendGoal_Request;
  using Response = user_action_interfaces::action::PathPlanning_SendGoal_Response;
  using Event = user_action_interfaces::action::PathPlanning_SendGoal_Event;
};

}  // namespace action

}  // namespace user_action_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__user_action_interfaces__action__PathPlanning_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__user_action_interfaces__action__PathPlanning_GetResult_Request __declspec(deprecated)
#endif

namespace user_action_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PathPlanning_GetResult_Request_
{
  using Type = PathPlanning_GetResult_Request_<ContainerAllocator>;

  explicit PathPlanning_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit PathPlanning_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_GetResult_Request
    std::shared_ptr<user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_GetResult_Request
    std::shared_ptr<user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathPlanning_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathPlanning_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathPlanning_GetResult_Request_

// alias to use template instance with default allocator
using PathPlanning_GetResult_Request =
  user_action_interfaces::action::PathPlanning_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace user_action_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "user_action_interfaces/action/detail/path_planning__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__user_action_interfaces__action__PathPlanning_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__user_action_interfaces__action__PathPlanning_GetResult_Response __declspec(deprecated)
#endif

namespace user_action_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PathPlanning_GetResult_Response_
{
  using Type = PathPlanning_GetResult_Response_<ContainerAllocator>;

  explicit PathPlanning_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit PathPlanning_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    user_action_interfaces::action::PathPlanning_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const user_action_interfaces::action::PathPlanning_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_GetResult_Response
    std::shared_ptr<user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_GetResult_Response
    std::shared_ptr<user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathPlanning_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathPlanning_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathPlanning_GetResult_Response_

// alias to use template instance with default allocator
using PathPlanning_GetResult_Response =
  user_action_interfaces::action::PathPlanning_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace user_action_interfaces


// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__user_action_interfaces__action__PathPlanning_GetResult_Event __attribute__((deprecated))
#else
# define DEPRECATED__user_action_interfaces__action__PathPlanning_GetResult_Event __declspec(deprecated)
#endif

namespace user_action_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PathPlanning_GetResult_Event_
{
  using Type = PathPlanning_GetResult_Event_<ContainerAllocator>;

  explicit PathPlanning_GetResult_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit PathPlanning_GetResult_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<user_action_interfaces::action::PathPlanning_GetResult_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<user_action_interfaces::action::PathPlanning_GetResult_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_action_interfaces::action::PathPlanning_GetResult_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_action_interfaces::action::PathPlanning_GetResult_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_GetResult_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_GetResult_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_GetResult_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_GetResult_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_GetResult_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_GetResult_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_GetResult_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_GetResult_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_GetResult_Event
    std::shared_ptr<user_action_interfaces::action::PathPlanning_GetResult_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_GetResult_Event
    std::shared_ptr<user_action_interfaces::action::PathPlanning_GetResult_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathPlanning_GetResult_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathPlanning_GetResult_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathPlanning_GetResult_Event_

// alias to use template instance with default allocator
using PathPlanning_GetResult_Event =
  user_action_interfaces::action::PathPlanning_GetResult_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace user_action_interfaces

namespace user_action_interfaces
{

namespace action
{

struct PathPlanning_GetResult
{
  using Request = user_action_interfaces::action::PathPlanning_GetResult_Request;
  using Response = user_action_interfaces::action::PathPlanning_GetResult_Response;
  using Event = user_action_interfaces::action::PathPlanning_GetResult_Event;
};

}  // namespace action

}  // namespace user_action_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "user_action_interfaces/action/detail/path_planning__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__user_action_interfaces__action__PathPlanning_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__user_action_interfaces__action__PathPlanning_FeedbackMessage __declspec(deprecated)
#endif

namespace user_action_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PathPlanning_FeedbackMessage_
{
  using Type = PathPlanning_FeedbackMessage_<ContainerAllocator>;

  explicit PathPlanning_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit PathPlanning_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    user_action_interfaces::action::PathPlanning_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const user_action_interfaces::action::PathPlanning_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_action_interfaces::action::PathPlanning_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_action_interfaces::action::PathPlanning_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_action_interfaces::action::PathPlanning_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::action::PathPlanning_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::action::PathPlanning_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_action_interfaces::action::PathPlanning_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_FeedbackMessage
    std::shared_ptr<user_action_interfaces::action::PathPlanning_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_action_interfaces__action__PathPlanning_FeedbackMessage
    std::shared_ptr<user_action_interfaces::action::PathPlanning_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathPlanning_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathPlanning_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathPlanning_FeedbackMessage_

// alias to use template instance with default allocator
using PathPlanning_FeedbackMessage =
  user_action_interfaces::action::PathPlanning_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace user_action_interfaces

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace user_action_interfaces
{

namespace action
{

struct PathPlanning
{
  /// The goal message defined in the action definition.
  using Goal = user_action_interfaces::action::PathPlanning_Goal;
  /// The result message defined in the action definition.
  using Result = user_action_interfaces::action::PathPlanning_Result;
  /// The feedback message defined in the action definition.
  using Feedback = user_action_interfaces::action::PathPlanning_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = user_action_interfaces::action::PathPlanning_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = user_action_interfaces::action::PathPlanning_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = user_action_interfaces::action::PathPlanning_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct PathPlanning PathPlanning;

}  // namespace action

}  // namespace user_action_interfaces

#endif  // USER_ACTION_INTERFACES__ACTION__DETAIL__PATH_PLANNING__STRUCT_HPP_
