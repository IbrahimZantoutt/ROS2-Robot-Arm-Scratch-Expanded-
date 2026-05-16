from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import Command
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    pkg = get_package_share_directory('main_arm_package')

    urdf_path = os.path.join(pkg, 'urdf', 'arm.urdf')
    rviz_config = os.path.join(pkg, 'rviz', 'arm.rviz')

    return LaunchDescription([
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            parameters=[{
                'robot_description': Command(['xacro ', urdf_path])
            }]
        ),
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
        ),
        Node(
            package='rviz2',
            executable='rviz2',
            arguments=['-d', rviz_config],
        ),
    ])
