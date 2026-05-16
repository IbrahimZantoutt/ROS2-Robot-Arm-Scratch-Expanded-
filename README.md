# ROS2 Robot Arm (From Scratch)

A 2-DOF simulated robot arm built from scratch in ROS2 using C++. The arm has a shoulder and elbow joint that can be commanded to target angles, with safety limit checking and real-time feedback. It's visualized in RViz using a URDF model.

This project was built as a learning exercise to get hands-on with the core ROS2 concepts. I'll be expanding it further in a separate repository.

---

## What it does

- Send a target shoulder and elbow angle to the arm
- The arm first checks whether those angles are within safe limits
- If safe, it incrementally moves toward the target (1 degree per step) while publishing feedback
- The arm state is continuously published and visualized in RViz

---

## Project Structure

```
src/
├── action_interfaces/       # Custom messages, services, and actions
│   ├── msg/
│   │   ├── ArmCommand.msg   # shoulder + elbow command angles
│   │   └── ArmState.msg     # current shoulder + elbow angles + status
│   ├── srv/
│   │   └── CheckLimits.srv  # request angles, response is_safe bool
│   └── action/
│       └── MoveArm.action   # goal, feedback, and result for arm movement
│
└── main_arm_package/        # Main nodes
    ├── src/
    │   ├── ArmController.cpp  # Publishes arm state and joint states
    │   ├── ArmMover.cpp       # Action server — moves arm to goal
    │   ├── ArmMonitor.cpp     # Watches state, serves limit checks
    │   └── ArmClient.cpp      # Checks limits then sends movement goal
    ├── urdf/arm.urdf          # Robot model for RViz
    └── launch/
        ├── launch.py          # Launch all nodes
        └── display.launch.py  # Launch with RViz
```

---

## Nodes

| Node | Role |
|---|---|
| `ArmController` | Subscribes to commands, publishes arm state and joint states for RViz |
| `ArmMover` | Action server — accepts a goal, steps the arm toward it, sends feedback |
| `ArmMonitor` | Watches arm state for limit violations, serves the `check_limits` service |
| `ArmClient` | Calls `check_limits` first, then sends an action goal if the angles are safe |

---

## ROS2 Concepts Covered

- **Topics** — publishing and subscribing (arm state, arm commands, joint states)
- **Services** — client/server pattern for the safety limit check (`CheckLimits`)
- **Actions** — full action client/server with goal, incremental feedback, and result (`MoveArm`)
- **Custom Interfaces** — defining your own `.msg`, `.srv`, and `.action` files in a separate package
- **Parameters** — declaring and reading node parameters at runtime (joint angle thresholds)
- **Timers** — periodic state publishing with `create_wall_timer`
- **Launch files** — launching multiple nodes together with Python launch files
- **URDF** — defining a robot model and visualizing it in RViz
- **rclcpp_action** — using the ROS2 action library in C++
- **Multi-threading** — detaching threads inside action execution to avoid blocking the executor

---

## Running It

Build the workspace:
```bash
colcon build
source install/setup.bash
```

Launch everything with RViz:
```bash
ros2 launch main_arm_package display.launch.py
```

Send a move command (shoulder 45°, elbow 90°):
```bash
ros2 run main_arm_package ArmClient 45.0 90.0
```

Joint limits enforced by `ArmMonitor`:
- Shoulder: -90° to 90°
- Elbow: 0° to 135°

---

## What's Next

This is the base version of the project. I'll be continuing development in a separate directory, adding things like more joints, better motion planning, and potentially hardware integration.
