#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "action_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__msg__ArmState() -> *const std::ffi::c_void;
}

#[link(name = "action_interfaces__rosidl_generator_c")]
extern "C" {
    fn action_interfaces__msg__ArmState__init(msg: *mut ArmState) -> bool;
    fn action_interfaces__msg__ArmState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ArmState>, size: usize) -> bool;
    fn action_interfaces__msg__ArmState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ArmState>);
    fn action_interfaces__msg__ArmState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ArmState>, out_seq: *mut rosidl_runtime_rs::Sequence<ArmState>) -> bool;
}

// Corresponds to action_interfaces__msg__ArmState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ArmState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub shoulder_angle: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub elbow_angle: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub status: rosidl_runtime_rs::String,

}



impl Default for ArmState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !action_interfaces__msg__ArmState__init(&mut msg as *mut _) {
        panic!("Call to action_interfaces__msg__ArmState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ArmState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__msg__ArmState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__msg__ArmState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__msg__ArmState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ArmState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ArmState where Self: Sized {
  const TYPE_NAME: &'static str = "action_interfaces/msg/ArmState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__msg__ArmState() }
  }
}


#[link(name = "action_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__msg__ArmCommand() -> *const std::ffi::c_void;
}

#[link(name = "action_interfaces__rosidl_generator_c")]
extern "C" {
    fn action_interfaces__msg__ArmCommand__init(msg: *mut ArmCommand) -> bool;
    fn action_interfaces__msg__ArmCommand__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ArmCommand>, size: usize) -> bool;
    fn action_interfaces__msg__ArmCommand__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ArmCommand>);
    fn action_interfaces__msg__ArmCommand__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ArmCommand>, out_seq: *mut rosidl_runtime_rs::Sequence<ArmCommand>) -> bool;
}

// Corresponds to action_interfaces__msg__ArmCommand
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ArmCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub shoulder_angle_cmd: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub elbow_angle_cmd: f32,

}



impl Default for ArmCommand {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !action_interfaces__msg__ArmCommand__init(&mut msg as *mut _) {
        panic!("Call to action_interfaces__msg__ArmCommand__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ArmCommand {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__msg__ArmCommand__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__msg__ArmCommand__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__msg__ArmCommand__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ArmCommand {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ArmCommand where Self: Sized {
  const TYPE_NAME: &'static str = "action_interfaces/msg/ArmCommand";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__msg__ArmCommand() }
  }
}


