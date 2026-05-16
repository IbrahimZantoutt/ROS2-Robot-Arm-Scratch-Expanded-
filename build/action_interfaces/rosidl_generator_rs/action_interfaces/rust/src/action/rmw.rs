
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "action_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_Goal() -> *const std::ffi::c_void;
}

#[link(name = "action_interfaces__rosidl_generator_c")]
extern "C" {
    fn action_interfaces__action__MoveArm_Goal__init(msg: *mut MoveArm_Goal) -> bool;
    fn action_interfaces__action__MoveArm_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_Goal>, size: usize) -> bool;
    fn action_interfaces__action__MoveArm_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_Goal>);
    fn action_interfaces__action__MoveArm_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArm_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArm_Goal>) -> bool;
}

// Corresponds to action_interfaces__action__MoveArm_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArm_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub shoulder_angle_goal: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub elbow_angle_goal: f32,

}



impl Default for MoveArm_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !action_interfaces__action__MoveArm_Goal__init(&mut msg as *mut _) {
        panic!("Call to action_interfaces__action__MoveArm_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArm_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArm_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArm_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "action_interfaces/action/MoveArm_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_Goal() }
  }
}


#[link(name = "action_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_Result() -> *const std::ffi::c_void;
}

#[link(name = "action_interfaces__rosidl_generator_c")]
extern "C" {
    fn action_interfaces__action__MoveArm_Result__init(msg: *mut MoveArm_Result) -> bool;
    fn action_interfaces__action__MoveArm_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_Result>, size: usize) -> bool;
    fn action_interfaces__action__MoveArm_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_Result>);
    fn action_interfaces__action__MoveArm_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArm_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArm_Result>) -> bool;
}

// Corresponds to action_interfaces__action__MoveArm_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArm_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub shoulder_angle_rs: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub elbow_angle_rs: f32,

}



impl Default for MoveArm_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !action_interfaces__action__MoveArm_Result__init(&mut msg as *mut _) {
        panic!("Call to action_interfaces__action__MoveArm_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArm_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArm_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArm_Result where Self: Sized {
  const TYPE_NAME: &'static str = "action_interfaces/action/MoveArm_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_Result() }
  }
}


#[link(name = "action_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "action_interfaces__rosidl_generator_c")]
extern "C" {
    fn action_interfaces__action__MoveArm_Feedback__init(msg: *mut MoveArm_Feedback) -> bool;
    fn action_interfaces__action__MoveArm_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_Feedback>, size: usize) -> bool;
    fn action_interfaces__action__MoveArm_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_Feedback>);
    fn action_interfaces__action__MoveArm_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArm_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArm_Feedback>) -> bool;
}

// Corresponds to action_interfaces__action__MoveArm_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArm_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub shoulder_angle_fb: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub elbow_angle_fb: f32,

}



impl Default for MoveArm_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !action_interfaces__action__MoveArm_Feedback__init(&mut msg as *mut _) {
        panic!("Call to action_interfaces__action__MoveArm_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArm_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArm_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArm_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "action_interfaces/action/MoveArm_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_Feedback() }
  }
}


#[link(name = "action_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "action_interfaces__rosidl_generator_c")]
extern "C" {
    fn action_interfaces__action__MoveArm_FeedbackMessage__init(msg: *mut MoveArm_FeedbackMessage) -> bool;
    fn action_interfaces__action__MoveArm_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_FeedbackMessage>, size: usize) -> bool;
    fn action_interfaces__action__MoveArm_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_FeedbackMessage>);
    fn action_interfaces__action__MoveArm_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArm_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArm_FeedbackMessage>) -> bool;
}

// Corresponds to action_interfaces__action__MoveArm_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArm_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::MoveArm_Feedback,

}



impl Default for MoveArm_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !action_interfaces__action__MoveArm_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to action_interfaces__action__MoveArm_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArm_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArm_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArm_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "action_interfaces/action/MoveArm_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_FeedbackMessage() }
  }
}




#[link(name = "action_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "action_interfaces__rosidl_generator_c")]
extern "C" {
    fn action_interfaces__action__MoveArm_SendGoal_Request__init(msg: *mut MoveArm_SendGoal_Request) -> bool;
    fn action_interfaces__action__MoveArm_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_SendGoal_Request>, size: usize) -> bool;
    fn action_interfaces__action__MoveArm_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_SendGoal_Request>);
    fn action_interfaces__action__MoveArm_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArm_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArm_SendGoal_Request>) -> bool;
}

// Corresponds to action_interfaces__action__MoveArm_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArm_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::MoveArm_Goal,

}



impl Default for MoveArm_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !action_interfaces__action__MoveArm_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to action_interfaces__action__MoveArm_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArm_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArm_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArm_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "action_interfaces/action/MoveArm_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_SendGoal_Request() }
  }
}


#[link(name = "action_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "action_interfaces__rosidl_generator_c")]
extern "C" {
    fn action_interfaces__action__MoveArm_SendGoal_Response__init(msg: *mut MoveArm_SendGoal_Response) -> bool;
    fn action_interfaces__action__MoveArm_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_SendGoal_Response>, size: usize) -> bool;
    fn action_interfaces__action__MoveArm_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_SendGoal_Response>);
    fn action_interfaces__action__MoveArm_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArm_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArm_SendGoal_Response>) -> bool;
}

// Corresponds to action_interfaces__action__MoveArm_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArm_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for MoveArm_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !action_interfaces__action__MoveArm_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to action_interfaces__action__MoveArm_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArm_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArm_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArm_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "action_interfaces/action/MoveArm_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_SendGoal_Response() }
  }
}


#[link(name = "action_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "action_interfaces__rosidl_generator_c")]
extern "C" {
    fn action_interfaces__action__MoveArm_GetResult_Request__init(msg: *mut MoveArm_GetResult_Request) -> bool;
    fn action_interfaces__action__MoveArm_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_GetResult_Request>, size: usize) -> bool;
    fn action_interfaces__action__MoveArm_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_GetResult_Request>);
    fn action_interfaces__action__MoveArm_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArm_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArm_GetResult_Request>) -> bool;
}

// Corresponds to action_interfaces__action__MoveArm_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArm_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for MoveArm_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !action_interfaces__action__MoveArm_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to action_interfaces__action__MoveArm_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArm_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArm_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArm_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "action_interfaces/action/MoveArm_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_GetResult_Request() }
  }
}


#[link(name = "action_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "action_interfaces__rosidl_generator_c")]
extern "C" {
    fn action_interfaces__action__MoveArm_GetResult_Response__init(msg: *mut MoveArm_GetResult_Response) -> bool;
    fn action_interfaces__action__MoveArm_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_GetResult_Response>, size: usize) -> bool;
    fn action_interfaces__action__MoveArm_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoveArm_GetResult_Response>);
    fn action_interfaces__action__MoveArm_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoveArm_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<MoveArm_GetResult_Response>) -> bool;
}

// Corresponds to action_interfaces__action__MoveArm_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoveArm_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::MoveArm_Result,

}



impl Default for MoveArm_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !action_interfaces__action__MoveArm_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to action_interfaces__action__MoveArm_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoveArm_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__action__MoveArm_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoveArm_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoveArm_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "action_interfaces/action/MoveArm_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__action__MoveArm_GetResult_Response() }
  }
}






#[link(name = "action_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__action_interfaces__action__MoveArm_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to action_interfaces__action__MoveArm_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveArm_SendGoal;

impl rosidl_runtime_rs::Service for MoveArm_SendGoal {
    type Request = MoveArm_SendGoal_Request;
    type Response = MoveArm_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__action_interfaces__action__MoveArm_SendGoal() }
    }
}




#[link(name = "action_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__action_interfaces__action__MoveArm_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to action_interfaces__action__MoveArm_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct MoveArm_GetResult;

impl rosidl_runtime_rs::Service for MoveArm_GetResult {
    type Request = MoveArm_GetResult_Request;
    type Response = MoveArm_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__action_interfaces__action__MoveArm_GetResult() }
    }
}


