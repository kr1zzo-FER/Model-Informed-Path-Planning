import launch
import launch_ros.actions
from launch import LaunchDescription
from launch_ros.actions import Node
import os

save_file = 'jadranovo_map'

pkg_name = 'path_planning_client'

pkg_dir = os.popen('/bin/bash -c "source /usr/share/colcon_cd/function/colcon_cd.sh && \
        colcon_cd %s && pwd"' % pkg_name).read().strip()

def generate_launch_description():
    return launch.LaunchDescription([

        launch_ros.actions.Node(
            package='path_planning_client',
            executable='pointcloud_publisher',
            output='screen',
            emulate_tty=True,
            name='coast_pointcloud'
        ),

        launch_ros.actions.Node(
            package='path_planning_client',
            executable='rviz2_launch',
            output='screen',
            emulate_tty=True,
            name=f'map_visualization'
        ),

        launch_ros.actions.Node(
            package='path_planning_client',
            executable='start_goal_publisher',
            name='start_goal_publisher'
        ),
  
  ])
