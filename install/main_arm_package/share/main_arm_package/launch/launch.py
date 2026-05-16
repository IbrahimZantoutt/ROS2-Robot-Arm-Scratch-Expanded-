from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='main_arm_package',
            executable='ArmController',
            name='arm_controller_node'
        ),
        Node(
            package='main_arm_package',
            executable='ArmMonitor',
            name='arm_monitor_node'
        ),
        Node(
            package='main_arm_package',
            executable='ArmMover',
            name='arm_mover_node'
        )
    ])