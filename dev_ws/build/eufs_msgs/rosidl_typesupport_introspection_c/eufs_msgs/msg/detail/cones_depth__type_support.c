// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from eufs_msgs:msg/ConesDepth.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "eufs_msgs/msg/detail/cones_depth__rosidl_typesupport_introspection_c.h"
#include "eufs_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "eufs_msgs/msg/detail/cones_depth__functions.h"
#include "eufs_msgs/msg/detail/cones_depth__struct.h"


// Include directives for member types
// Member `header`
// Member `image_header`
#include "std_msgs/msg/header.h"
// Member `header`
// Member `image_header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `cones_depth`
#include "eufs_msgs/msg/cone_depth.h"
// Member `cones_depth`
#include "eufs_msgs/msg/detail/cone_depth__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ConesDepth__rosidl_typesupport_introspection_c__ConesDepth_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  eufs_msgs__msg__ConesDepth__init(message_memory);
}

void ConesDepth__rosidl_typesupport_introspection_c__ConesDepth_fini_function(void * message_memory)
{
  eufs_msgs__msg__ConesDepth__fini(message_memory);
}

size_t ConesDepth__rosidl_typesupport_introspection_c__size_function__ConeDepth__cones_depth(
  const void * untyped_member)
{
  const eufs_msgs__msg__ConeDepth__Sequence * member =
    (const eufs_msgs__msg__ConeDepth__Sequence *)(untyped_member);
  return member->size;
}

const void * ConesDepth__rosidl_typesupport_introspection_c__get_const_function__ConeDepth__cones_depth(
  const void * untyped_member, size_t index)
{
  const eufs_msgs__msg__ConeDepth__Sequence * member =
    (const eufs_msgs__msg__ConeDepth__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ConesDepth__rosidl_typesupport_introspection_c__get_function__ConeDepth__cones_depth(
  void * untyped_member, size_t index)
{
  eufs_msgs__msg__ConeDepth__Sequence * member =
    (eufs_msgs__msg__ConeDepth__Sequence *)(untyped_member);
  return &member->data[index];
}

bool ConesDepth__rosidl_typesupport_introspection_c__resize_function__ConeDepth__cones_depth(
  void * untyped_member, size_t size)
{
  eufs_msgs__msg__ConeDepth__Sequence * member =
    (eufs_msgs__msg__ConeDepth__Sequence *)(untyped_member);
  eufs_msgs__msg__ConeDepth__Sequence__fini(member);
  return eufs_msgs__msg__ConeDepth__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ConesDepth__rosidl_typesupport_introspection_c__ConesDepth_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(eufs_msgs__msg__ConesDepth, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "image_header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(eufs_msgs__msg__ConesDepth, image_header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cones_depth",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(eufs_msgs__msg__ConesDepth, cones_depth),  // bytes offset in struct
    NULL,  // default value
    ConesDepth__rosidl_typesupport_introspection_c__size_function__ConeDepth__cones_depth,  // size() function pointer
    ConesDepth__rosidl_typesupport_introspection_c__get_const_function__ConeDepth__cones_depth,  // get_const(index) function pointer
    ConesDepth__rosidl_typesupport_introspection_c__get_function__ConeDepth__cones_depth,  // get(index) function pointer
    ConesDepth__rosidl_typesupport_introspection_c__resize_function__ConeDepth__cones_depth  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ConesDepth__rosidl_typesupport_introspection_c__ConesDepth_message_members = {
  "eufs_msgs__msg",  // message namespace
  "ConesDepth",  // message name
  3,  // number of fields
  sizeof(eufs_msgs__msg__ConesDepth),
  ConesDepth__rosidl_typesupport_introspection_c__ConesDepth_message_member_array,  // message members
  ConesDepth__rosidl_typesupport_introspection_c__ConesDepth_init_function,  // function to initialize message memory (memory has to be allocated)
  ConesDepth__rosidl_typesupport_introspection_c__ConesDepth_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ConesDepth__rosidl_typesupport_introspection_c__ConesDepth_message_type_support_handle = {
  0,
  &ConesDepth__rosidl_typesupport_introspection_c__ConesDepth_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_eufs_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, eufs_msgs, msg, ConesDepth)() {
  ConesDepth__rosidl_typesupport_introspection_c__ConesDepth_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  ConesDepth__rosidl_typesupport_introspection_c__ConesDepth_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  ConesDepth__rosidl_typesupport_introspection_c__ConesDepth_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, eufs_msgs, msg, ConeDepth)();
  if (!ConesDepth__rosidl_typesupport_introspection_c__ConesDepth_message_type_support_handle.typesupport_identifier) {
    ConesDepth__rosidl_typesupport_introspection_c__ConesDepth_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ConesDepth__rosidl_typesupport_introspection_c__ConesDepth_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
