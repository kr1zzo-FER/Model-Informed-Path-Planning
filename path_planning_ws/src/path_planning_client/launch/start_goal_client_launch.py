import launch
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='path_planning_client',
            executable='start_goal_client',
            name='start_goal_client')
  ])
