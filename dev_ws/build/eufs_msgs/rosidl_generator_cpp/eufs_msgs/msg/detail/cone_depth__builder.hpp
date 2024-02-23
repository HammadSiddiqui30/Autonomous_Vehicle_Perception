// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from eufs_msgs:msg/ConeDepth.idl
// generated code does not contain a copyright notice

#ifndef EUFS_MSGS__MSG__DETAIL__CONE_DEPTH__BUILDER_HPP_
#define EUFS_MSGS__MSG__DETAIL__CONE_DEPTH__BUILDER_HPP_

#include "eufs_msgs/msg/detail/cone_depth__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace eufs_msgs
{

namespace msg
{

namespace builder
{

class Init_ConeDepth_depth
{
public:
  explicit Init_ConeDepth_depth(::eufs_msgs::msg::ConeDepth & msg)
  : msg_(msg)
  {}
  ::eufs_msgs::msg::ConeDepth depth(::eufs_msgs::msg::ConeDepth::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return std::move(msg_);
  }

private:
  ::eufs_msgs::msg::ConeDepth msg_;
};

class Init_ConeDepth_color
{
public:
  Init_ConeDepth_color()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConeDepth_depth color(::eufs_msgs::msg::ConeDepth::_color_type arg)
  {
    msg_.color = std::move(arg);
    return Init_ConeDepth_depth(msg_);
  }

private:
  ::eufs_msgs::msg::ConeDepth msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::eufs_msgs::msg::ConeDepth>()
{
  return eufs_msgs::msg::builder::Init_ConeDepth_color();
}

}  // namespace eufs_msgs

#endif  // EUFS_MSGS__MSG__DETAIL__CONE_DEPTH__BUILDER_HPP_
