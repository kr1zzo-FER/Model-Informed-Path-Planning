import launch
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='path_planning_action',
            executable='map_process',
            output='screen',
            emulate_tty=True,
            name='map_process_jadranovo',
            parameters=[{'save_file' : 'jadranovo_map',
                        'grid_size' : 10,
                        'locations' : ["sv_marko", "voz", "lokvisce"]}]),
  
  ])

