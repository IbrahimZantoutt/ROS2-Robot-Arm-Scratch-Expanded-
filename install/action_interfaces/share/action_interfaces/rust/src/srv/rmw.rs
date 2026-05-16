#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "action_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__srv__CheckLimits_Request() -> *const std::ffi::c_void;
}

#[link(name = "action_interfaces__rosidl_generator_c")]
extern "C" {
    fn action_interfaces__srv__CheckLimits_Request__init(msg: *mut CheckLimits_Request) -> bool;
    fn action_interfaces__srv__CheckLimits_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<CheckLimits_Request>, size: usize) -> bool;
    fn action_interfaces__srv__CheckLimits_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<CheckLimits_Request>);
    fn action_interfaces__srv__CheckLimits_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<CheckLimits_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<CheckLimits_Request>) -> bool;
}

// Corresponds to action_interfaces__srv__CheckLimits_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CheckLimits_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub shoulder_angle: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub elbow_angle: f32,

}



impl Default for CheckLimits_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !action_interfaces__srv__CheckLimits_Request__init(&mut msg as *mut _) {
        panic!("Call to action_interfaces__srv__CheckLimits_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for CheckLimits_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__srv__CheckLimits_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__srv__CheckLimits_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__srv__CheckLimits_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for CheckLimits_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for CheckLimits_Request where Self: Sized {
  const TYPE_NAME: &'static str = "action_interfaces/srv/CheckLimits_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__srv__CheckLimits_Request() }
  }
}


#[link(name = "action_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__srv__CheckLimits_Response() -> *const std::ffi::c_void;
}

#[link(name = "action_interfaces__rosidl_generator_c")]
extern "C" {
    fn action_interfaces__srv__CheckLimits_Response__init(msg: *mut CheckLimits_Response) -> bool;
    fn action_interfaces__srv__CheckLimits_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<CheckLimits_Response>, size: usize) -> bool;
    fn action_interfaces__srv__CheckLimits_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<CheckLimits_Response>);
    fn action_interfaces__srv__CheckLimits_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<CheckLimits_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<CheckLimits_Response>) -> bool;
}

// Corresponds to action_interfaces__srv__CheckLimits_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CheckLimits_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub is_safe: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for CheckLimits_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !action_interfaces__srv__CheckLimits_Response__init(&mut msg as *mut _) {
        panic!("Call to action_interfaces__srv__CheckLimits_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for CheckLimits_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__srv__CheckLimits_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__srv__CheckLimits_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { action_interfaces__srv__CheckLimits_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for CheckLimits_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for CheckLimits_Response where Self: Sized {
  const TYPE_NAME: &'static str = "action_interfaces/srv/CheckLimits_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__action_interfaces__srv__CheckLimits_Response() }
  }
}






#[link(name = "action_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__action_interfaces__srv__CheckLimits() -> *const std::ffi::c_void;
}

// Corresponds to action_interfaces__srv__CheckLimits
#[allow(missing_docs, non_camel_case_types)]
pub struct CheckLimits;

impl rosidl_runtime_rs::Service for CheckLimits {
    type Request = CheckLimits_Request;
    type Response = CheckLimits_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__action_interfaces__srv__CheckLimits() }
    }
}


