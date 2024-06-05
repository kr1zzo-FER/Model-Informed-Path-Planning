import launch
import launch_ros.actions
from launch_ros.actions import Node

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, TimerAction
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration, PythonExpression

### User defined parameters ###

# Default name : procesed_map_{save_file_name} 
# in map_data folder
save_file_name = 'jadranovo'

###############################

def generate_launch_description():

    save_file =  LaunchConfiguration('save_file_name')

    save_file_arg = DeclareLaunchArgument(
        'save_file',
        default_value=save_file_name
    )

    map_maker_node = Node(
        package='map_maker',
        namespace = save_file,
        executable='map_publisher',
        output='screen',
        name='map_process'
    )

    get_name = ExecuteProcess(
        cmd=[[
            'ros2 param set',
            save_file,
        ]],
        shell=True,
    )
    
    return LaunchDescription([
        save_file_arg,
        map_maker_node
    ])