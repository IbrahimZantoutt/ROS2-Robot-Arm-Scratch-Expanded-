#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to action_interfaces__srv__CheckLimits_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CheckLimits_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub shoulder_angle: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub elbow_angle: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub wrist_angle: f32,

}



impl Default for CheckLimits_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::CheckLimits_Request::default())
  }
}

impl rosidl_runtime_rs::Message for CheckLimits_Request {
  type RmwMsg = super::srv::rmw::CheckLimits_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        shoulder_angle: msg.shoulder_angle,
        elbow_angle: msg.elbow_angle,
        wrist_angle: msg.wrist_angle,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      shoulder_angle: msg.shoulder_angle,
      elbow_angle: msg.elbow_angle,
      wrist_angle: msg.wrist_angle,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      shoulder_angle: msg.shoulder_angle,
      elbow_angle: msg.elbow_angle,
      wrist_angle: msg.wrist_angle,
    }
  }
}


// Corresponds to action_interfaces__srv__CheckLimits_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CheckLimits_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub is_safe: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for CheckLimits_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::CheckLimits_Response::default())
  }
}

impl rosidl_runtime_rs::Message for CheckLimits_Response {
  type RmwMsg = super::srv::rmw::CheckLimits_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        is_safe: msg.is_safe,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      is_safe: msg.is_safe,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      is_safe: msg.is_safe,
      message: msg.message.to_string(),
    }
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


