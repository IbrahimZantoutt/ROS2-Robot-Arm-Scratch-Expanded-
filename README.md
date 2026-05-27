# ROS2 Robot Arm — Expanded

A 4-DOF simulated robot arm built in ROS2 (C++) and Gazebo, capable of autonomous pick-and-place. This is an expansion of an [earlier 2-DOF project](https://github.com/IbrahimZantoutt/ROS2-Robot-Arm-Scratch-Limited-) — the starting point was a simple angle-commanded arm in RViz; this version adds two more joints, a gripper, inverse kinematics, Gazebo physics simulation, contact sensors, and a task planner that sequences a full pick-and-place operation.

---

## What it does

1. A `TaskPlanner` node tells the arm to pick up a box at a target XYZ world position and drop it at another
2. `ArmMover` solves inverse kinematics from the XYZ goal → joint angles, then steps the arm incrementally toward those angles while publishing feedback
3. `ArmController` drives the joints in both RViz (via `/joint_states`) and Gazebo (via `ros2_control` position commands)
4. The gripper closes slowly until both contact sensors detect the box, then squeezes 4mm past contact to generate friction force sufficient to carry it
5. `ArmMonitor` watches all joint angles against configurable limits and serves a `check_limits` service that gates every IK solution before execution

---

## Architecture

```
src/
├── action_interfaces/              # Custom ROS2 interface definitions
│   ├── msg/
│   │   ├── ArmCommand.msg          # 4-joint angle commands (shoulder, elbow, wrist, spin)
│   │   ├── ArmState.msg            # Current 4-joint angles + status
│   │   └── GripCommand.msg         # "open" / "close" grip command
│   ├── srv/
│   │   └── CheckLimits.srv         # Request joint angles → response is_safe bool
│   └── action/
│       └── MoveArm.action          # Goal: XYZ + elbow config | Feedback: live angles | Result: final angles
│
└── main_arm_package/
    ├── src/
    │   ├── ArmController.cpp        # Joint state publisher + Gazebo position controller driver
    │   ├── ArmMover.cpp             # Action server: IK solver + incremental joint stepping
    │   ├── ArmMonitor.cpp           # Limit checker service + real-time safety watchdog
    │   ├── ArmClient.cpp            # One-shot move client (send XYZ from terminal)
    │   └── TaskPlanner.cpp          # Pick-and-place sequencer using a phase state machine
    ├── urdf/arm.urdf                # Full robot model with Gazebo physics + ros2_control tags
    ├── config/controllers.yaml      # ros2_control: JointGroupPositionController config
    ├── worlds/my_world.sdf          # Custom Gazebo world with pickup and drop boxes
    └── launch/
        ├── gazebo.launch.py         # Gazebo + RViz + all nodes + controllers
        ├── display.launch.py        # RViz-only (no physics)
        └── launch.py               # Nodes only (no visualizers)
```

---

## Nodes

| Node | Role |
|---|---|
| `TaskPlanner` | Phase state machine: moves to pick → closes grip → moves to drop → opens grip |
| `ArmMover` | Action server — solves IK from XYZ target, steps joints to solution, aborts if unreachable or out of limits |
| `ArmController` | Publishes `/joint_states` for RViz and `arm_position_controller/commands` for Gazebo; drives the gripper with contact-sensor feedback |
| `ArmMonitor` | Subscribes to arm state and warns on limit violations; serves `check_limits` for pre-motion safety gating |
| `ArmClient` | Terminal utility — send a single XYZ move command with optional elbow config flag |

---

## What I learned / what's new vs the previous version

### Robot structure
- Went from 2 joints (shoulder + elbow) to 4 active joints: **spin** (base rotation), **shoulder**, **elbow**, **wrist**
- Added a **parallel gripper** with two prismatic finger joints
- Calculated proper inertia tensors for every link so Gazebo physics doesn't blow up

### Inverse kinematics
- The previous version took raw joint angles as input. This one takes **world XYZ coordinates** and solves IK in `ArmMover::solveIK()`
- Used the standard 2-link planar IK formula (law of cosines) in the arm's vertical plane, then extracted spin from `atan2(y, x)`
- Handled the coordinate frame mismatch between IK convention (angle from horizontal) and the URDF joints (angle from vertical)
- Exposed **elbow-up vs elbow-down** as a configuration choice (two valid IK solutions for the same XYZ)

### Gazebo simulation
- Integrated `gazebo_ros2_control` — the URDF has a `<ros2_control>` hardware interface block, and `controllers.yaml` configures a `JointGroupPositionController`
- The arm is driven by publishing a `Float64MultiArray` to `arm_position_controller/commands`, which Gazebo's controller manager executes
- Used `TimerAction` in the launch file to stagger gazebo server start → robot spawn → controller load (timing matters)
- Built a custom SDF world with a pickup box on a pedestal and a drop pedestal

### Contact sensors and gripper grasping
- Added Gazebo contact sensor plugins (`libgazebo_ros_bumper.so`) on both finger links, remapped to `/gripper_left_contact` and `/gripper_right_contact`
- The gripper closes incrementally (1mm steps) and monitors both contact flags — stops early if both fingers detect contact, then squeezes 4mm past contact to generate normal force for friction
- Used a separate `CallbackGroup` (`MutuallyExclusive`) and a `MultiThreadedExecutor` for the contact subscriptions so they don't block the main publish loop

### Concurrency
- `ArmMover` runs the action execution in a detached thread (`std::thread{...}.detach()`) so the executor stays responsive
- Used `std::mutex` to protect the shared current-angle state between the arm state subscriber and the execution thread
- Used `std::atomic<bool>` for contact flags shared between the contact callbacks and the gripper close loop
- Used `std::promise` / `std::future` to bridge the async `check_limits` service call synchronously inside the IK check

### Task planning
- `TaskPlanner` implements a simple phase-based state machine (`enum class Phase`) driven by action result callbacks
- Phase transitions: `MOVING_TO_PICK` → (result callback) → close grip → `MOVING_TO_DROP` → (result callback) → open grip → `DONE`
- This is the pattern for sequencing multi-step robot tasks without blocking

---

## Joint limits

Enforced by `ArmMonitor` (configurable via ROS2 parameters):

| Joint | Range |
|---|---|
| Spin | -180° to 180° |
| Shoulder | -90° to 90° |
| Elbow | -135° to 135° |
| Wrist | -120° to 120° |

---

## Running it

Build:
```bash
colcon build
source install/setup.bash
```

Launch Gazebo + RViz + all nodes:
```bash
ros2 launch main_arm_package gazebo.launch.py
```

Then start the task planner (pick box1 at `(0.8, 0, 0.265)`, drop on box3 at `(-0.8, 0, 0.28)`):
```bash
ros2 run main_arm_package TaskPlanner
```

Or send a one-shot XYZ move from the terminal:
```bash
# Move to x=0.5, y=0.3, z=0.3 with elbow-up configuration
ros2 run main_arm_package ArmClient 0.5 0.3 0.3 U
```

RViz only (no Gazebo physics):
```bash
ros2 launch main_arm_package display.launch.py
```

---

## ROS2 concepts covered (cumulative)

| Concept | Where |
|---|---|
| Topics — pub/sub | `ArmController` → arm state, joint states, position commands |
| Services — client/server | `ArmMonitor` serves `check_limits`; `ArmMover` calls it synchronously via promise/future |
| Actions — goal / feedback / result | `MoveArm` action with XYZ goal, per-step angle feedback, final angle result |
| Custom interfaces | `.msg`, `.srv`, `.action` files in `action_interfaces` package |
| Parameters | Joint limit thresholds declared and read at runtime in `ArmMonitor` |
| Timers | 50ms publish loop in `ArmController` |
| Launch files | Python launch files with `TimerAction` for staggered startup |
| URDF | Full robot model with collision, inertia, revolute + prismatic joints |
| ros2_control | Hardware interface tags in URDF + `JointGroupPositionController` via `controllers.yaml` |
| Gazebo simulation | `gazebo_ros2_control` plugin, contact sensors, friction/physics tuning |
| Inverse kinematics | Analytic 2-link planar IK with spin + elbow-up/down configuration |
| Multi-threaded executor | `MultiThreadedExecutor` + `CallbackGroup` in `ArmController` |
| Thread safety | `std::mutex`, `std::atomic<bool>`, `std::promise/future` |
| State machines | Phase-based pick-and-place sequencing in `TaskPlanner` |
