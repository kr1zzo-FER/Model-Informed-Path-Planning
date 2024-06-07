import launch
import launch_ros.actions
from launch_ros.actions import Node

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, TimerAction
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration, PythonExpression

start = [45.236663, 14.575893]


def generate_launch_description():

    start_value =  LaunchConfiguration('start')
    goal_value =  LaunchConfiguration('goal')



    start_arg = DeclareLaunchArgument(
        'start',
        default_value=f'{start}',
    )

    pp_node = Node(
        package='path_planning_action',
        executable='start_goal_publisher',
        output='screen',
        name='manual_start_goal_publisher',
        parameters=[{'start': start_value
                     }]
    )


    
    return LaunchDescription([
        start_arg,
        pp_node
    ])