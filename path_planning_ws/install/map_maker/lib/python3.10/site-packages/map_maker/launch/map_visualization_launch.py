import launch
import launch_ros.actions
from launch_ros.actions import Node

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, TimerAction
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration, PythonExpression


def generate_launch_description():

    save_file_value =  LaunchConfiguration('save_file')

    save_file_arg = DeclareLaunchArgument(
        'save_file',
        default_value= 'jadranovo'
    )

    map_maker_node = Node(
        package='map_maker',
        executable='map_visualization',
        output='screen',
        name='map_process',
        parameters=[{'save_file': save_file_value}]
    )


    
    return LaunchDescription([
        save_file_arg,
        map_maker_node
    ])