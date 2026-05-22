import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import ExecuteProcess, TimerAction
from launch.substitutions import Command, FindExecutable
from launch_ros.actions import Node


def generate_launch_description():
    pkg_share = get_package_share_directory('main_arm_package')
    urdf_path = os.path.join(pkg_share, 'urdf', 'arm.urdf')
    world_path = os.path.join(pkg_share, 'worlds', 'my_world.sdf')
    rviz_config = os.path.join(pkg_share, 'rviz', 'arm.rviz')

    robot_description = {
        'robot_description': Command([FindExecutable(name='xacro'), ' ', urdf_path])
    }

    # Start Gazebo — explicitly load the factory and init plugins so /spawn_entity is available
    gazebo = ExecuteProcess(
        cmd=['gazebo', '--verbose',
             '-s', 'libgazebo_ros_init.so',
             '-s', 'libgazebo_ros_factory.so',
             world_path],
        output='screen'
    )

    # Publish robot TF — joint_state_broadcaster feeds /joint_states in Gazebo mode
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[robot_description]
    )

    # Spawn the robot — delayed slightly to let gzserver finish loading plugins
    spawn_entity = TimerAction(
        period=5.0,
        actions=[Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=['-topic', 'robot_description', '-entity', 'arm_robot'],
            output='screen'
        )]
    )

    # Load controllers — delayed further so the Gazebo ros2_control plugin has time to start
    joint_state_broadcaster_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_state_broadcaster'],
    )

    arm_position_controller_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['arm_position_controller'],
    )

    arm_controller = Node(
        package='main_arm_package',
        executable='ArmController',
        name='arm_controller_node',
    )

    arm_mover = Node(
        package='main_arm_package',
        executable='ArmMover',
        name='arm_mover_node'
    )

    arm_monitor = Node(
        package='main_arm_package',
        executable='ArmMonitor',
        name='arm_monitor_node'
    )

    rviz = Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', rviz_config],
        output='screen'
    )

    return LaunchDescription([
        gazebo,
        robot_state_publisher,
        spawn_entity,
        TimerAction(period=10.0, actions=[joint_state_broadcaster_spawner]),
        TimerAction(period=11.0, actions=[arm_position_controller_spawner]),
        arm_controller,
        arm_mover,
        arm_monitor,
        rviz,
    ])
