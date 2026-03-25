// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from motion_interfaces:action/Navigate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "motion_interfaces/action/navigate.h"


#ifndef MOTION_INTERFACES__ACTION__DETAIL__NAVIGATE__STRUCT_H_
#define MOTION_INTERFACES__ACTION__DETAIL__NAVIGATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'command'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Navigate in the package motion_interfaces.
typedef struct motion_interfaces__action__Navigate_Goal
{
  /// команда движения
  rosidl_runtime_c__String command;
  /// максимальная скорость движения
  float speed;
} motion_interfaces__action__Navigate_Goal;

// Struct for a sequence of motion_interfaces__action__Navigate_Goal.
typedef struct motion_interfaces__action__Navigate_Goal__Sequence
{
  motion_interfaces__action__Navigate_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motion_interfaces__action__Navigate_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Navigate in the package motion_interfaces.
typedef struct motion_interfaces__action__Navigate_Result
{
  /// успешно ли выполнилось
  bool success;
  /// сообщение об ошибке или статус
  rosidl_runtime_c__String message;
} motion_interfaces__action__Navigate_Result;

// Struct for a sequence of motion_interfaces__action__Navigate_Result.
typedef struct motion_interfaces__action__Navigate_Result__Sequence
{
  motion_interfaces__action__Navigate_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motion_interfaces__action__Navigate_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'current_action'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Navigate in the package motion_interfaces.
typedef struct motion_interfaces__action__Navigate_Feedback
{
  /// что сейчас делаем ("moving", "turning", "stopping")
  rosidl_runtime_c__String current_action;
  /// прогресс выполнения 0.0 - 1.0
  float progress;
} motion_interfaces__action__Navigate_Feedback;

// Struct for a sequence of motion_interfaces__action__Navigate_Feedback.
typedef struct motion_interfaces__action__Navigate_Feedback__Sequence
{
  motion_interfaces__action__Navigate_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motion_interfaces__action__Navigate_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "motion_interfaces/action/detail/navigate__struct.h"

/// Struct defined in action/Navigate in the package motion_interfaces.
typedef struct motion_interfaces__action__Navigate_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  motion_interfaces__action__Navigate_Goal goal;
} motion_interfaces__action__Navigate_SendGoal_Request;

// Struct for a sequence of motion_interfaces__action__Navigate_SendGoal_Request.
typedef struct motion_interfaces__action__Navigate_SendGoal_Request__Sequence
{
  motion_interfaces__action__Navigate_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motion_interfaces__action__Navigate_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Navigate in the package motion_interfaces.
typedef struct motion_interfaces__action__Navigate_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} motion_interfaces__action__Navigate_SendGoal_Response;

// Struct for a sequence of motion_interfaces__action__Navigate_SendGoal_Response.
typedef struct motion_interfaces__action__Navigate_SendGoal_Response__Sequence
{
  motion_interfaces__action__Navigate_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motion_interfaces__action__Navigate_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  motion_interfaces__action__Navigate_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  motion_interfaces__action__Navigate_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Navigate in the package motion_interfaces.
typedef struct motion_interfaces__action__Navigate_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  motion_interfaces__action__Navigate_SendGoal_Request__Sequence request;
  motion_interfaces__action__Navigate_SendGoal_Response__Sequence response;
} motion_interfaces__action__Navigate_SendGoal_Event;

// Struct for a sequence of motion_interfaces__action__Navigate_SendGoal_Event.
typedef struct motion_interfaces__action__Navigate_SendGoal_Event__Sequence
{
  motion_interfaces__action__Navigate_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motion_interfaces__action__Navigate_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Navigate in the package motion_interfaces.
typedef struct motion_interfaces__action__Navigate_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} motion_interfaces__action__Navigate_GetResult_Request;

// Struct for a sequence of motion_interfaces__action__Navigate_GetResult_Request.
typedef struct motion_interfaces__action__Navigate_GetResult_Request__Sequence
{
  motion_interfaces__action__Navigate_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motion_interfaces__action__Navigate_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "motion_interfaces/action/detail/navigate__struct.h"

/// Struct defined in action/Navigate in the package motion_interfaces.
typedef struct motion_interfaces__action__Navigate_GetResult_Response
{
  int8_t status;
  motion_interfaces__action__Navigate_Result result;
} motion_interfaces__action__Navigate_GetResult_Response;

// Struct for a sequence of motion_interfaces__action__Navigate_GetResult_Response.
typedef struct motion_interfaces__action__Navigate_GetResult_Response__Sequence
{
  motion_interfaces__action__Navigate_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motion_interfaces__action__Navigate_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  motion_interfaces__action__Navigate_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  motion_interfaces__action__Navigate_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Navigate in the package motion_interfaces.
typedef struct motion_interfaces__action__Navigate_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  motion_interfaces__action__Navigate_GetResult_Request__Sequence request;
  motion_interfaces__action__Navigate_GetResult_Response__Sequence response;
} motion_interfaces__action__Navigate_GetResult_Event;

// Struct for a sequence of motion_interfaces__action__Navigate_GetResult_Event.
typedef struct motion_interfaces__action__Navigate_GetResult_Event__Sequence
{
  motion_interfaces__action__Navigate_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motion_interfaces__action__Navigate_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "motion_interfaces/action/detail/navigate__struct.h"

/// Struct defined in action/Navigate in the package motion_interfaces.
typedef struct motion_interfaces__action__Navigate_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  motion_interfaces__action__Navigate_Feedback feedback;
} motion_interfaces__action__Navigate_FeedbackMessage;

// Struct for a sequence of motion_interfaces__action__Navigate_FeedbackMessage.
typedef struct motion_interfaces__action__Navigate_FeedbackMessage__Sequence
{
  motion_interfaces__action__Navigate_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motion_interfaces__action__Navigate_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOTION_INTERFACES__ACTION__DETAIL__NAVIGATE__STRUCT_H_
