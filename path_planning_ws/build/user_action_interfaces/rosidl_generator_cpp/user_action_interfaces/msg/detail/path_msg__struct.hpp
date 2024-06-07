// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from user_action_interfaces:msg/PathMsg.idl
// generated code does not contain a copyright notice

#ifndef USER_ACTION_INTERFACES__MSG__DETAIL__PATH_MSG__STRUCT_HPP_
#define USER_ACTION_INTERFACES__MSG__DETAIL__PATH_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__user_action_interfaces__msg__PathMsg __attribute__((deprecated))
#else
# define DEPRECATED__user_action_interfaces__msg__PathMsg __declspec(deprecated)
#endif

namespace user_action_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PathMsg_
{
  using Type = PathMsg_<ContainerAllocator>;

  explicit PathMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_id = "";
    }
  }

  explicit PathMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    frame_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_id = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _frame_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _frame_id_type frame_id;
  using _path_x_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _path_x_type path_x;
  using _path_y_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _path_y_type path_y;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__frame_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->frame_id = _arg;
    return *this;
  }
  Type & set__path_x(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->path_x = _arg;
    return *this;
  }
  Type & set__path_y(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->path_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_action_interfaces::msg::PathMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_action_interfaces::msg::PathMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_action_interfaces::msg::PathMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_action_interfaces::msg::PathMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::msg::PathMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::msg::PathMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::msg::PathMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::msg::PathMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_action_interfaces::msg::PathMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_action_interfaces::msg::PathMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_action_interfaces__msg__PathMsg
    std::shared_ptr<user_action_interfaces::msg::PathMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_action_interfaces__msg__PathMsg
    std::shared_ptr<user_action_interfaces::msg::PathMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathMsg_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->frame_id != other.frame_id) {
      return false;
    }
    if (this->path_x != other.path_x) {
      return false;
    }
    if (this->path_y != other.path_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathMsg_

// alias to use template instance with default allocator
using PathMsg =
  user_action_interfaces::msg::PathMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace user_action_interfaces

#endif  // USER_ACTION_INTERFACES__MSG__DETAIL__PATH_MSG__STRUCT_HPP_
