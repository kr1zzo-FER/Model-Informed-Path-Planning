import launch
import launch_ros.actions

start = [45.237468, 14.575984]

goal = [45.228553, 14.585168]

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='path_planning_action',
            executable='start_goal_action',
            name='start_goal_action')
  ])
