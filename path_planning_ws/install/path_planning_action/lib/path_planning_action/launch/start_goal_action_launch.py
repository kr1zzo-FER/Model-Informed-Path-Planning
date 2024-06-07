import launch
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='path_planning_action',
            executable='start_goal_action',
            name='start_goal_action')
  ])
