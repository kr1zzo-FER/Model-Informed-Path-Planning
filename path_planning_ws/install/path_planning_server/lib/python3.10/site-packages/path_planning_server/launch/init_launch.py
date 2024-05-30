import launch
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='path_planning_server',
            executable='planning_server',
            name='talker'),
  ])
