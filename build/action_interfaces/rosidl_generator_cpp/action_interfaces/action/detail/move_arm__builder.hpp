// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interfaces:action/MoveArm.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__ACTION__DETAIL__MOVE_ARM__BUILDER_HPP_
#define ACTION_INTERFACES__ACTION__DETAIL__MOVE_ARM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "action_interfaces/action/detail/move_arm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArm_Goal_wrist_angle_goal
{
public:
  explicit Init_MoveArm_Goal_wrist_angle_goal(::action_interfaces::action::MoveArm_Goal & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::MoveArm_Goal wrist_angle_goal(::action_interfaces::action::MoveArm_Goal::_wrist_angle_goal_type arg)
  {
    msg_.wrist_angle_goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_Goal msg_;
};

class Init_MoveArm_Goal_elbow_angle_goal
{
public:
  explicit Init_MoveArm_Goal_elbow_angle_goal(::action_interfaces::action::MoveArm_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveArm_Goal_wrist_angle_goal elbow_angle_goal(::action_interfaces::action::MoveArm_Goal::_elbow_angle_goal_type arg)
  {
    msg_.elbow_angle_goal = std::move(arg);
    return Init_MoveArm_Goal_wrist_angle_goal(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_Goal msg_;
};

class Init_MoveArm_Goal_shoulder_angle_goal
{
public:
  Init_MoveArm_Goal_shoulder_angle_goal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArm_Goal_elbow_angle_goal shoulder_angle_goal(::action_interfaces::action::MoveArm_Goal::_shoulder_angle_goal_type arg)
  {
    msg_.shoulder_angle_goal = std::move(arg);
    return Init_MoveArm_Goal_elbow_angle_goal(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveArm_Goal>()
{
  return action_interfaces::action::builder::Init_MoveArm_Goal_shoulder_angle_goal();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArm_Result_wrist_angle_rs
{
public:
  explicit Init_MoveArm_Result_wrist_angle_rs(::action_interfaces::action::MoveArm_Result & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::MoveArm_Result wrist_angle_rs(::action_interfaces::action::MoveArm_Result::_wrist_angle_rs_type arg)
  {
    msg_.wrist_angle_rs = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_Result msg_;
};

class Init_MoveArm_Result_elbow_angle_rs
{
public:
  explicit Init_MoveArm_Result_elbow_angle_rs(::action_interfaces::action::MoveArm_Result & msg)
  : msg_(msg)
  {}
  Init_MoveArm_Result_wrist_angle_rs elbow_angle_rs(::action_interfaces::action::MoveArm_Result::_elbow_angle_rs_type arg)
  {
    msg_.elbow_angle_rs = std::move(arg);
    return Init_MoveArm_Result_wrist_angle_rs(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_Result msg_;
};

class Init_MoveArm_Result_shoulder_angle_rs
{
public:
  Init_MoveArm_Result_shoulder_angle_rs()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArm_Result_elbow_angle_rs shoulder_angle_rs(::action_interfaces::action::MoveArm_Result::_shoulder_angle_rs_type arg)
  {
    msg_.shoulder_angle_rs = std::move(arg);
    return Init_MoveArm_Result_elbow_angle_rs(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveArm_Result>()
{
  return action_interfaces::action::builder::Init_MoveArm_Result_shoulder_angle_rs();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArm_Feedback_wrist_angle_fb
{
public:
  explicit Init_MoveArm_Feedback_wrist_angle_fb(::action_interfaces::action::MoveArm_Feedback & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::MoveArm_Feedback wrist_angle_fb(::action_interfaces::action::MoveArm_Feedback::_wrist_angle_fb_type arg)
  {
    msg_.wrist_angle_fb = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_Feedback msg_;
};

class Init_MoveArm_Feedback_elbow_angle_fb
{
public:
  explicit Init_MoveArm_Feedback_elbow_angle_fb(::action_interfaces::action::MoveArm_Feedback & msg)
  : msg_(msg)
  {}
  Init_MoveArm_Feedback_wrist_angle_fb elbow_angle_fb(::action_interfaces::action::MoveArm_Feedback::_elbow_angle_fb_type arg)
  {
    msg_.elbow_angle_fb = std::move(arg);
    return Init_MoveArm_Feedback_wrist_angle_fb(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_Feedback msg_;
};

class Init_MoveArm_Feedback_shoulder_angle_fb
{
public:
  Init_MoveArm_Feedback_shoulder_angle_fb()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArm_Feedback_elbow_angle_fb shoulder_angle_fb(::action_interfaces::action::MoveArm_Feedback::_shoulder_angle_fb_type arg)
  {
    msg_.shoulder_angle_fb = std::move(arg);
    return Init_MoveArm_Feedback_elbow_angle_fb(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveArm_Feedback>()
{
  return action_interfaces::action::builder::Init_MoveArm_Feedback_shoulder_angle_fb();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArm_SendGoal_Request_goal
{
public:
  explicit Init_MoveArm_SendGoal_Request_goal(::action_interfaces::action::MoveArm_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::MoveArm_SendGoal_Request goal(::action_interfaces::action::MoveArm_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_SendGoal_Request msg_;
};

class Init_MoveArm_SendGoal_Request_goal_id
{
public:
  Init_MoveArm_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArm_SendGoal_Request_goal goal_id(::action_interfaces::action::MoveArm_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveArm_SendGoal_Request_goal(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveArm_SendGoal_Request>()
{
  return action_interfaces::action::builder::Init_MoveArm_SendGoal_Request_goal_id();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArm_SendGoal_Response_stamp
{
public:
  explicit Init_MoveArm_SendGoal_Response_stamp(::action_interfaces::action::MoveArm_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::MoveArm_SendGoal_Response stamp(::action_interfaces::action::MoveArm_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_SendGoal_Response msg_;
};

class Init_MoveArm_SendGoal_Response_accepted
{
public:
  Init_MoveArm_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArm_SendGoal_Response_stamp accepted(::action_interfaces::action::MoveArm_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveArm_SendGoal_Response_stamp(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveArm_SendGoal_Response>()
{
  return action_interfaces::action::builder::Init_MoveArm_SendGoal_Response_accepted();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArm_GetResult_Request_goal_id
{
public:
  Init_MoveArm_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interfaces::action::MoveArm_GetResult_Request goal_id(::action_interfaces::action::MoveArm_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveArm_GetResult_Request>()
{
  return action_interfaces::action::builder::Init_MoveArm_GetResult_Request_goal_id();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArm_GetResult_Response_result
{
public:
  explicit Init_MoveArm_GetResult_Response_result(::action_interfaces::action::MoveArm_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::MoveArm_GetResult_Response result(::action_interfaces::action::MoveArm_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_GetResult_Response msg_;
};

class Init_MoveArm_GetResult_Response_status
{
public:
  Init_MoveArm_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArm_GetResult_Response_result status(::action_interfaces::action::MoveArm_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveArm_GetResult_Response_result(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveArm_GetResult_Response>()
{
  return action_interfaces::action::builder::Init_MoveArm_GetResult_Response_status();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveArm_FeedbackMessage_feedback
{
public:
  explicit Init_MoveArm_FeedbackMessage_feedback(::action_interfaces::action::MoveArm_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::MoveArm_FeedbackMessage feedback(::action_interfaces::action::MoveArm_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_FeedbackMessage msg_;
};

class Init_MoveArm_FeedbackMessage_goal_id
{
public:
  Init_MoveArm_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveArm_FeedbackMessage_feedback goal_id(::action_interfaces::action::MoveArm_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveArm_FeedbackMessage_feedback(msg_);
  }

private:
  ::action_interfaces::action::MoveArm_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::MoveArm_FeedbackMessage>()
{
  return action_interfaces::action::builder::Init_MoveArm_FeedbackMessage_goal_id();
}

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__ACTION__DETAIL__MOVE_ARM__BUILDER_HPP_
