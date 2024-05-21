import launch
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='path_planning_action',
            executable='coast_pointcloud',
            output='screen',
            emulate_tty=True,
            name='coast_pointcloud',
            parameters=[{'save_file' : 'jadranovo_map'}]),
  
  ])

