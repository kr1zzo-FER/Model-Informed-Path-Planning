import launch
import launch_ros.actions

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

    save_file =  LaunchConfiguration('save_file_name', default=save_file_name)

    save_file_arg = DeclareLaunchArgument(
        'save_file',
        default_value=save_file_name,
        description='Name of the file to save the map'
    )

    map_maker_node = launch_ros.actions.Node(
        package='map_maker',
        executable='map_publisher',
        output='screen',
        emulate_tty=True,
        name='map_process_jadranovo',
        parameters=[{'save_file' : save_file_name}])
    
    return LaunchDescription([
        save_file_arg,
        map_maker_node
    ])



    