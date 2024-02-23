// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from eufs_msgs:msg/ConeDepth.idl
// generated code does not contain a copyright notice
#include "eufs_msgs/msg/detail/cone_depth__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `color`
#include "rosidl_runtime_c/string_functions.h"

bool
eufs_msgs__msg__ConeDepth__init(eufs_msgs__msg__ConeDepth * msg)
{
  if (!msg) {
    return false;
  }
  // color
  if (!rosidl_runtime_c__String__init(&msg->color)) {
    eufs_msgs__msg__ConeDepth__fini(msg);
    return false;
  }
  // depth
  return true;
}

void
eufs_msgs__msg__ConeDepth__fini(eufs_msgs__msg__ConeDepth * msg)
{
  if (!msg) {
    return;
  }
  // color
  rosidl_runtime_c__String__fini(&msg->color);
  // depth
}

bool
eufs_msgs__msg__ConeDepth__are_equal(const eufs_msgs__msg__ConeDepth * lhs, const eufs_msgs__msg__ConeDepth * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // color
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->color), &(rhs->color)))
  {
    return false;
  }
  // depth
  if (lhs->depth != rhs->depth) {
    return false;
  }
  return true;
}

bool
eufs_msgs__msg__ConeDepth__copy(
  const eufs_msgs__msg__ConeDepth * input,
  eufs_msgs__msg__ConeDepth * output)
{
  if (!input || !output) {
    return false;
  }
  // color
  if (!rosidl_runtime_c__String__copy(
      &(input->color), &(output->color)))
  {
    return false;
  }
  // depth
  output->depth = input->depth;
  return true;
}

eufs_msgs__msg__ConeDepth *
eufs_msgs__msg__ConeDepth__create()
{
  eufs_msgs__msg__ConeDepth * msg = (eufs_msgs__msg__ConeDepth *)malloc(sizeof(eufs_msgs__msg__ConeDepth));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(eufs_msgs__msg__ConeDepth));
  bool success = eufs_msgs__msg__ConeDepth__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
eufs_msgs__msg__ConeDepth__destroy(eufs_msgs__msg__ConeDepth * msg)
{
  if (msg) {
    eufs_msgs__msg__ConeDepth__fini(msg);
  }
  free(msg);
}


bool
eufs_msgs__msg__ConeDepth__Sequence__init(eufs_msgs__msg__ConeDepth__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  eufs_msgs__msg__ConeDepth * data = NULL;
  if (size) {
    data = (eufs_msgs__msg__ConeDepth *)calloc(size, sizeof(eufs_msgs__msg__ConeDepth));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = eufs_msgs__msg__ConeDepth__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        eufs_msgs__msg__ConeDepth__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
eufs_msgs__msg__ConeDepth__Sequence__fini(eufs_msgs__msg__ConeDepth__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      eufs_msgs__msg__ConeDepth__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

eufs_msgs__msg__ConeDepth__Sequence *
eufs_msgs__msg__ConeDepth__Sequence__create(size_t size)
{
  eufs_msgs__msg__ConeDepth__Sequence * array = (eufs_msgs__msg__ConeDepth__Sequence *)malloc(sizeof(eufs_msgs__msg__ConeDepth__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = eufs_msgs__msg__ConeDepth__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
eufs_msgs__msg__ConeDepth__Sequence__destroy(eufs_msgs__msg__ConeDepth__Sequence * array)
{
  if (array) {
    eufs_msgs__msg__ConeDepth__Sequence__fini(array);
  }
  free(array);
}

bool
eufs_msgs__msg__ConeDepth__Sequence__are_equal(const eufs_msgs__msg__ConeDepth__Sequence * lhs, const eufs_msgs__msg__ConeDepth__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!eufs_msgs__msg__ConeDepth__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
eufs_msgs__msg__ConeDepth__Sequence__copy(
  const eufs_msgs__msg__ConeDepth__Sequence * input,
  eufs_msgs__msg__ConeDepth__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(eufs_msgs__msg__ConeDepth);
    eufs_msgs__msg__ConeDepth * data =
      (eufs_msgs__msg__ConeDepth *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!eufs_msgs__msg__ConeDepth__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          eufs_msgs__msg__ConeDepth__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!eufs_msgs__msg__ConeDepth__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
