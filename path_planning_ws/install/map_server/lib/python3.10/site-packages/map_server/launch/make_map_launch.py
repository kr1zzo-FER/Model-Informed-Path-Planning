import launch
import launch_ros.actions

save_file = 'jadranovo_map'
grid_size = 10
locations = ["sv_marko", "voz", "lokvisce"]

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='map_server',
            executable='map_process',
            output='screen',
            emulate_tty=True,
            name='map_process',
            parameters=[{'save_file' : save_file,
                        'grid_size' : grid_size,
                        'locations' : locations}]),
  
  ])

