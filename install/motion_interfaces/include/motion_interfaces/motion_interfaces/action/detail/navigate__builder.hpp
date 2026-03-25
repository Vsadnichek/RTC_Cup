// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motion_interfaces:action/Navigate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "motion_interfaces/action/navigate.hpp"


#ifndef MOTION_INTERFACES__ACTION__DETAIL__NAVIGATE__BUILDER_HPP_
#define MOTION_INTERFACES__ACTION__DETAIL__NAVIGATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "motion_interfaces/action/detail/navigate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace motion_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_Goal_speed
{
public:
  explicit Init_Navigate_Goal_speed(::motion_interfaces::action::Navigate_Goal & msg)
  : msg_(msg)
  {}
  ::motion_interfaces::action::Navigate_Goal speed(::motion_interfaces::action::Navigate_Goal::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_Goal msg_;
};

class Init_Navigate_Goal_command
{
public:
  Init_Navigate_Goal_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_Goal_speed command(::motion_interfaces::action::Navigate_Goal::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_Navigate_Goal_speed(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_interfaces::action::Navigate_Goal>()
{
  return motion_interfaces::action::builder::Init_Navigate_Goal_command();
}

}  // namespace motion_interfaces


namespace motion_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_Result_message
{
public:
  explicit Init_Navigate_Result_message(::motion_interfaces::action::Navigate_Result & msg)
  : msg_(msg)
  {}
  ::motion_interfaces::action::Navigate_Result message(::motion_interfaces::action::Navigate_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_Result msg_;
};

class Init_Navigate_Result_success
{
public:
  Init_Navigate_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_Result_message success(::motion_interfaces::action::Navigate_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Navigate_Result_message(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_interfaces::action::Navigate_Result>()
{
  return motion_interfaces::action::builder::Init_Navigate_Result_success();
}

}  // namespace motion_interfaces


namespace motion_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_Feedback_progress
{
public:
  explicit Init_Navigate_Feedback_progress(::motion_interfaces::action::Navigate_Feedback & msg)
  : msg_(msg)
  {}
  ::motion_interfaces::action::Navigate_Feedback progress(::motion_interfaces::action::Navigate_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_Feedback msg_;
};

class Init_Navigate_Feedback_current_action
{
public:
  Init_Navigate_Feedback_current_action()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_Feedback_progress current_action(::motion_interfaces::action::Navigate_Feedback::_current_action_type arg)
  {
    msg_.current_action = std::move(arg);
    return Init_Navigate_Feedback_progress(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_interfaces::action::Navigate_Feedback>()
{
  return motion_interfaces::action::builder::Init_Navigate_Feedback_current_action();
}

}  // namespace motion_interfaces


namespace motion_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_SendGoal_Request_goal
{
public:
  explicit Init_Navigate_SendGoal_Request_goal(::motion_interfaces::action::Navigate_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::motion_interfaces::action::Navigate_SendGoal_Request goal(::motion_interfaces::action::Navigate_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_SendGoal_Request msg_;
};

class Init_Navigate_SendGoal_Request_goal_id
{
public:
  Init_Navigate_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_SendGoal_Request_goal goal_id(::motion_interfaces::action::Navigate_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Navigate_SendGoal_Request_goal(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_interfaces::action::Navigate_SendGoal_Request>()
{
  return motion_interfaces::action::builder::Init_Navigate_SendGoal_Request_goal_id();
}

}  // namespace motion_interfaces


namespace motion_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_SendGoal_Response_stamp
{
public:
  explicit Init_Navigate_SendGoal_Response_stamp(::motion_interfaces::action::Navigate_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::motion_interfaces::action::Navigate_SendGoal_Response stamp(::motion_interfaces::action::Navigate_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_SendGoal_Response msg_;
};

class Init_Navigate_SendGoal_Response_accepted
{
public:
  Init_Navigate_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_SendGoal_Response_stamp accepted(::motion_interfaces::action::Navigate_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Navigate_SendGoal_Response_stamp(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_interfaces::action::Navigate_SendGoal_Response>()
{
  return motion_interfaces::action::builder::Init_Navigate_SendGoal_Response_accepted();
}

}  // namespace motion_interfaces


namespace motion_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_SendGoal_Event_response
{
public:
  explicit Init_Navigate_SendGoal_Event_response(::motion_interfaces::action::Navigate_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::motion_interfaces::action::Navigate_SendGoal_Event response(::motion_interfaces::action::Navigate_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_SendGoal_Event msg_;
};

class Init_Navigate_SendGoal_Event_request
{
public:
  explicit Init_Navigate_SendGoal_Event_request(::motion_interfaces::action::Navigate_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_Navigate_SendGoal_Event_response request(::motion_interfaces::action::Navigate_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Navigate_SendGoal_Event_response(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_SendGoal_Event msg_;
};

class Init_Navigate_SendGoal_Event_info
{
public:
  Init_Navigate_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_SendGoal_Event_request info(::motion_interfaces::action::Navigate_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Navigate_SendGoal_Event_request(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_interfaces::action::Navigate_SendGoal_Event>()
{
  return motion_interfaces::action::builder::Init_Navigate_SendGoal_Event_info();
}

}  // namespace motion_interfaces


namespace motion_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_GetResult_Request_goal_id
{
public:
  Init_Navigate_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::motion_interfaces::action::Navigate_GetResult_Request goal_id(::motion_interfaces::action::Navigate_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_interfaces::action::Navigate_GetResult_Request>()
{
  return motion_interfaces::action::builder::Init_Navigate_GetResult_Request_goal_id();
}

}  // namespace motion_interfaces


namespace motion_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_GetResult_Response_result
{
public:
  explicit Init_Navigate_GetResult_Response_result(::motion_interfaces::action::Navigate_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::motion_interfaces::action::Navigate_GetResult_Response result(::motion_interfaces::action::Navigate_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_GetResult_Response msg_;
};

class Init_Navigate_GetResult_Response_status
{
public:
  Init_Navigate_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_GetResult_Response_result status(::motion_interfaces::action::Navigate_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Navigate_GetResult_Response_result(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_interfaces::action::Navigate_GetResult_Response>()
{
  return motion_interfaces::action::builder::Init_Navigate_GetResult_Response_status();
}

}  // namespace motion_interfaces


namespace motion_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_GetResult_Event_response
{
public:
  explicit Init_Navigate_GetResult_Event_response(::motion_interfaces::action::Navigate_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::motion_interfaces::action::Navigate_GetResult_Event response(::motion_interfaces::action::Navigate_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_GetResult_Event msg_;
};

class Init_Navigate_GetResult_Event_request
{
public:
  explicit Init_Navigate_GetResult_Event_request(::motion_interfaces::action::Navigate_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_Navigate_GetResult_Event_response request(::motion_interfaces::action::Navigate_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Navigate_GetResult_Event_response(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_GetResult_Event msg_;
};

class Init_Navigate_GetResult_Event_info
{
public:
  Init_Navigate_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_GetResult_Event_request info(::motion_interfaces::action::Navigate_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Navigate_GetResult_Event_request(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_interfaces::action::Navigate_GetResult_Event>()
{
  return motion_interfaces::action::builder::Init_Navigate_GetResult_Event_info();
}

}  // namespace motion_interfaces


namespace motion_interfaces
{

namespace action
{

namespace builder
{

class Init_Navigate_FeedbackMessage_feedback
{
public:
  explicit Init_Navigate_FeedbackMessage_feedback(::motion_interfaces::action::Navigate_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::motion_interfaces::action::Navigate_FeedbackMessage feedback(::motion_interfaces::action::Navigate_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_FeedbackMessage msg_;
};

class Init_Navigate_FeedbackMessage_goal_id
{
public:
  Init_Navigate_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Navigate_FeedbackMessage_feedback goal_id(::motion_interfaces::action::Navigate_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Navigate_FeedbackMessage_feedback(msg_);
  }

private:
  ::motion_interfaces::action::Navigate_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_interfaces::action::Navigate_FeedbackMessage>()
{
  return motion_interfaces::action::builder::Init_Navigate_FeedbackMessage_goal_id();
}

}  // namespace motion_interfaces

#endif  // MOTION_INTERFACES__ACTION__DETAIL__NAVIGATE__BUILDER_HPP_
