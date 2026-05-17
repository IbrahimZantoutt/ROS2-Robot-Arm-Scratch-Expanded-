#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to action_interfaces__msg__ArmState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    pub wrist_angle: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub status: std::string::String,

}



impl Default for ArmState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ArmState::default())
  }
}

impl rosidl_runtime_rs::Message for ArmState {
  type RmwMsg = super::msg::rmw::ArmState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        shoulder_angle: msg.shoulder_angle,
        elbow_angle: msg.elbow_angle,
        wrist_angle: msg.wrist_angle,
        status: msg.status.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      shoulder_angle: msg.shoulder_angle,
      elbow_angle: msg.elbow_angle,
      wrist_angle: msg.wrist_angle,
        status: msg.status.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      shoulder_angle: msg.shoulder_angle,
      elbow_angle: msg.elbow_angle,
      wrist_angle: msg.wrist_angle,
      status: msg.status.to_string(),
    }
  }
}


// Corresponds to action_interfaces__msg__ArmCommand

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ArmCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub shoulder_angle_cmd: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub elbow_angle_cmd: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub wrist_angle_cmd: f32,

}



impl Default for ArmCommand {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ArmCommand::default())
  }
}

impl rosidl_runtime_rs::Message for ArmCommand {
  type RmwMsg = super::msg::rmw::ArmCommand;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        shoulder_angle_cmd: msg.shoulder_angle_cmd,
        elbow_angle_cmd: msg.elbow_angle_cmd,
        wrist_angle_cmd: msg.wrist_angle_cmd,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      shoulder_angle_cmd: msg.shoulder_angle_cmd,
      elbow_angle_cmd: msg.elbow_angle_cmd,
      wrist_angle_cmd: msg.wrist_angle_cmd,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      shoulder_angle_cmd: msg.shoulder_angle_cmd,
      elbow_angle_cmd: msg.elbow_angle_cmd,
      wrist_angle_cmd: msg.wrist_angle_cmd,
    }
  }
}


