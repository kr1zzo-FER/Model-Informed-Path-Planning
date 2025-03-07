import launch
import launch_ros.actions
from launch_ros.actions import Node

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, TimerAction
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration, PythonExpression

start = [0.0,0.0]   

goal = [0.0,0.0]

def generate_launch_description():

    start_value =  LaunchConfiguration('start')
    goal_value =  LaunchConfiguration('goal')



    start_arg = DeclareLaunchArgument(
        'start',
        default_value=f'{start}',
    )

    goal_arg = DeclareLaunchArgument(
        'goal',
        default_value= f'{goal}',
    )

    pp_node = Node(
        package='path_planning_client',
        executable='start_goal_update',
        output='screen',
        name='manual_start_goal_publisher',
        parameters=[{'start': start_value,
                     'goal': goal_value}]
    )
    
    return LaunchDescription([
        start_arg,
        goal_arg,
        pp_node
    ])