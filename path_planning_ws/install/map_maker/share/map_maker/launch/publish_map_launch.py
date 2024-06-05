import launch
import launch_ros.actions

### User defined parameters ###

# Default name : procesed_map_{save_file_name} 
# in map_data folder
save_file_name = 'jadranovo'

###############################

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='map_maker',
            executable='map_publisher',
            output='screen',
            emulate_tty=True,
            name='map_process_jadranovo',
            parameters=[{'save_file' : save_file_name}]),
  
  ])

