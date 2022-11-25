首先保证所有程序都编译通过，ROS环境的要使用**catkin build**进行编译，PX4的代码要使用**make_sitl_default gazebo** 进行编译。

第一步，运行PX4的Gazebo仿真环境

- `cd PX4-Autopilot`
- `source Tools/setup_gazebo.bash $(pwd) $(pwd)/build/px4_sitl_default`
- `export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd):$(pwd)/Tools/sitl_gazebo`
- `roslaunch px4 posix_sitl.launch`

第二步，运行ROS环境下的开发程序

- `cd catkin_ws`
- `source devel/setup.bash`
- `roslaunch robot_connection.launch`

第三步，运行rviz_package(error)

- `cd catkin_ws/src/rviz_package`
- `roslaunch delta_rviz.launch`


# single-agent simulation

## start simulator
- `roslaunch px4 posix_sitl.launch`

## get connection
- `cd catkin_ws`
- `roslaunch robot_connection.launch`

## open QGC
- `cd Download`
- `./QGroundControl.AppImage `
there need to `arm the rotor` and `switch the mode to offboard`

## publish setpoint position (50 Hz)
- `rostopic pub -r 50 /mavros/setpoint_position/local geometry_msgs/PoseStamped "header: XXX`
or
- `rosrun off_mission single_agent_circle_mission`

# multi-agent simualtion
## start simulator
- `roslaunch px4 multi_uav_aeroarm.launch`

## open QGC
- `cd Download`
- `./QGroundControl.AppImage `

## start multi_agent_circle mission
- `rosrun off_mission multi_agent_circle_mission`
