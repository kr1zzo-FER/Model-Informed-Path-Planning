import launch
import launch_ros.actions
from launch_ros.actions import Node

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, TimerAction
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration, PythonExpression


goal = [45.229050, 14.584951]

def generate_launch_description():

    start_value =  LaunchConfiguration('start')
    goal_value =  LaunchConfiguration('goal')

    goal_arg = DeclareLaunchArgument(
        'goal',
        default_value= f'{goal}',
    )

    pp_node = Node(
        package='path_planning_action',
        executable='start_goal_publisher',
        output='screen',
        name='manual_start_goal_publisher',
        parameters=[{
                     'goal': goal_value}]
    )


    
    return LaunchDescription([
        goal_arg,
        pp_node
    ])