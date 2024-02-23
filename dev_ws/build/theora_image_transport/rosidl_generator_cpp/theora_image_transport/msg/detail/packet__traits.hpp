// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from theora_image_transport:msg/Packet.idl
// generated code does not contain a copyright notice

#ifndef THEORA_IMAGE_TRANSPORT__MSG__DETAIL__PACKET__TRAITS_HPP_
#define THEORA_IMAGE_TRANSPORT__MSG__DETAIL__PACKET__TRAITS_HPP_

#include "theora_image_transport/msg/detail/packet__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const theora_image_transport::msg::Packet & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_yaml(msg.header, out, indentation + 2);
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: b_o_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b_o_s: ";
    value_to_yaml(msg.b_o_s, out);
    out << "\n";
  }

  // member: e_o_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "e_o_s: ";
    value_to_yaml(msg.e_o_s, out);
    out << "\n";
  }

  // member: granulepos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "granulepos: ";
    value_to_yaml(msg.granulepos, out);
    out << "\n";
  }

  // member: packetno
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "packetno: ";
    value_to_yaml(msg.packetno, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const theora_image_transport::msg::Packet & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<theora_image_transport::msg::Packet>()
{
  return "theora_image_transport::msg::Packet";
}

template<>
inline const char * name<theora_image_transport::msg::Packet>()
{
  return "theora_image_transport/msg/Packet";
}

template<>
struct has_fixed_size<theora_image_transport::msg::Packet>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<theora_image_transport::msg::Packet>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<theora_image_transport::msg::Packet>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // THEORA_IMAGE_TRANSPORT__MSG__DETAIL__PACKET__TRAITS_HPP_
