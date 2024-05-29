// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from user_action_interfaces:msg/CoastMsg.idl
// generated code does not contain a copyright notice

#ifndef USER_ACTION_INTERFACES__MSG__DETAIL__COAST_MSG__STRUCT_HPP_
#define USER_ACTION_INTERFACES__MSG__DETAIL__COAST_MSG__STRUCT_HPP_

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
// Member 'coast_points'
// Member 'green_points'
// Member 'red_points'
// Member 'yellow_points'
#include "sensor_msgs/msg/detail/point_cloud2__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__user_action_interfaces__msg__CoastMsg __attribute__((deprecated))
#else
# define DEPRECATED__user_action_interfaces__msg__CoastMsg __declspec(deprecated)
#endif

namespace user_action_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CoastMsg_
{
  using Type = CoastMsg_<ContainerAllocator>;

  explicit CoastMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    coast_points(_init),
    green_points(_init),
    red_points(_init),
    yellow_points(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_id = "";
      this->grid_size = 0l;
    }
  }

  explicit CoastMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    frame_id(_alloc),
    coast_points(_alloc, _init),
    green_points(_alloc, _init),
    red_points(_alloc, _init),
    yellow_points(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->frame_id = "";
      this->grid_size = 0l;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _frame_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _frame_id_type frame_id;
  using _coast_points_type =
    sensor_msgs::msg::PointCloud2_<ContainerAllocator>;
  _coast_points_type coast_points;
  using _green_points_type =
    sensor_msgs::msg::PointCloud2_<ContainerAllocator>;
  _green_points_type green_points;
  using _red_points_type =
    sensor_msgs::msg::PointCloud2_<ContainerAllocator>;
  _red_points_type red_points;
  using _yellow_points_type =
    sensor_msgs::msg::PointCloud2_<ContainerAllocator>;
  _yellow_points_type yellow_points;
  using _grid_size_type =
    int32_t;
  _grid_size_type grid_size;

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
  Type & set__coast_points(
    const sensor_msgs::msg::PointCloud2_<ContainerAllocator> & _arg)
  {
    this->coast_points = _arg;
    return *this;
  }
  Type & set__green_points(
    const sensor_msgs::msg::PointCloud2_<ContainerAllocator> & _arg)
  {
    this->green_points = _arg;
    return *this;
  }
  Type & set__red_points(
    const sensor_msgs::msg::PointCloud2_<ContainerAllocator> & _arg)
  {
    this->red_points = _arg;
    return *this;
  }
  Type & set__yellow_points(
    const sensor_msgs::msg::PointCloud2_<ContainerAllocator> & _arg)
  {
    this->yellow_points = _arg;
    return *this;
  }
  Type & set__grid_size(
    const int32_t & _arg)
  {
    this->grid_size = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    user_action_interfaces::msg::CoastMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const user_action_interfaces::msg::CoastMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<user_action_interfaces::msg::CoastMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<user_action_interfaces::msg::CoastMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::msg::CoastMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::msg::CoastMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      user_action_interfaces::msg::CoastMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<user_action_interfaces::msg::CoastMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<user_action_interfaces::msg::CoastMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<user_action_interfaces::msg::CoastMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__user_action_interfaces__msg__CoastMsg
    std::shared_ptr<user_action_interfaces::msg::CoastMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__user_action_interfaces__msg__CoastMsg
    std::shared_ptr<user_action_interfaces::msg::CoastMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CoastMsg_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->frame_id != other.frame_id) {
      return false;
    }
    if (this->coast_points != other.coast_points) {
      return false;
    }
    if (this->green_points != other.green_points) {
      return false;
    }
    if (this->red_points != other.red_points) {
      return false;
    }
    if (this->yellow_points != other.yellow_points) {
      return false;
    }
    if (this->grid_size != other.grid_size) {
      return false;
    }
    return true;
  }
  bool operator!=(const CoastMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CoastMsg_

// alias to use template instance with default allocator
using CoastMsg =
  user_action_interfaces::msg::CoastMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace user_action_interfaces

#endif  // USER_ACTION_INTERFACES__MSG__DETAIL__COAST_MSG__STRUCT_HPP_
