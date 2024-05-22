import launch
import launch_ros.actions
from launch import LaunchDescription
from launch_ros.actions import Node
import os

save_file = 'jadranovo_map'

start = [45.237468, 14.575984]

goal = [45.228553, 14.585168]

pkg_name = 'path_planning_action'

pkg_dir = os.popen('/bin/bash -c "source /usr/share/colcon_cd/function/colcon_cd.sh && \
        colcon_cd %s && pwd"' % pkg_name).read().strip()

def generate_launch_description():
    return launch.LaunchDescription([

        launch_ros.actions.Node(
            package='path_planning_action',
            executable='pointcloud_publisher',
            output='screen',
            emulate_tty=True,
            name='coast_pointcloud',
            parameters=[{'save_file' : save_file,
                          'start' : start,
                          'goal' : goal}]
        ),

        launch_ros.actions.Node(
            package='path_planning_action',
            executable='rviz2_launch',
            output='screen',
            emulate_tty=True,
            name=f'map_visualization',
            parameters=[{'save_file' : save_file }]
        ),
  
  ])
