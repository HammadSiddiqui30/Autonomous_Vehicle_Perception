// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from eufs_msgs:msg/ConesDepth.idl
// generated code does not contain a copyright notice

#ifndef EUFS_MSGS__MSG__DETAIL__CONES_DEPTH__BUILDER_HPP_
#define EUFS_MSGS__MSG__DETAIL__CONES_DEPTH__BUILDER_HPP_

#include "eufs_msgs/msg/detail/cones_depth__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace eufs_msgs
{

namespace msg
{

namespace builder
{

class Init_ConesDepth_cones_depth
{
public:
  explicit Init_ConesDepth_cones_depth(::eufs_msgs::msg::ConesDepth & msg)
  : msg_(msg)
  {}
  ::eufs_msgs::msg::ConesDepth cones_depth(::eufs_msgs::msg::ConesDepth::_cones_depth_type arg)
  {
    msg_.cones_depth = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eufs_msgs::msg::ConesDepth msg_;
};

class Init_ConesDepth_image_header
{
public:
  explicit Init_ConesDepth_image_header(::eufs_msgs::msg::ConesDepth & msg)
  : msg_(msg)
  {}
  Init_ConesDepth_cones_depth image_header(::eufs_msgs::msg::ConesDepth::_image_header_type arg)
  {
    msg_.image_header = std::move(arg);
    return Init_ConesDepth_cones_depth(msg_);
  }

private:
  ::eufs_msgs::msg::ConesDepth msg_;
};

class Init_ConesDepth_header
{
public:
  Init_ConesDepth_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConesDepth_image_header header(::eufs_msgs::msg::ConesDepth::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ConesDepth_image_header(msg_);
  }

private:
  ::eufs_msgs::msg::ConesDepth msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::eufs_msgs::msg::ConesDepth>()
{
  return eufs_msgs::msg::builder::Init_ConesDepth_header();
}

}  // namespace eufs_msgs

#endif  // EUFS_MSGS__MSG__DETAIL__CONES_DEPTH__BUILDER_HPP_
