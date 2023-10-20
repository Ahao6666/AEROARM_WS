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

- `cd AEROARM_ws`
- `roslaunch robot_connection.launch`

## start task_plan

- `~/catkin_ws/src/task_plan/launch`
- `roslaunch task_plan.launch`

## open QGC

- `cd Download`
- `./QGroundControl.AppImage `
  there need to `arm the rotor` and `switch the mode to offboard`

## open qt_joystick
- `rosrun qt_joystick qt_joystick`
- 点击`connect`手动连接

## publish setpoint position (50 Hz)

- `rostopic pub -r 50 /mavros/setpoint_position/local geometry_msgs/PoseStamped "header: XXX`
  or
- `rosrun off_mission single_agent_circle_mission`

第一步：启动GAZEBO仿真后，在地面站手动电机解锁，SE开关在Takeoff and Hover模式下

第二步：SC拨杆分别为manual/position/offboard模式，切换至offboard模式，无人机上升随后悬停

第三步：SE拨杆至拨至Path档位下，进入online模式

第四步：在offboard+Online模式下，SB拨杆用于执行飞行任务，同时自主控制Detla机械臂

第五步：SA开关用于独立控制Delta机械臂

# multi-agent simualtion

## start simulator

- `roslaunch px4 multi_uav_aeroarm.launch`

## open QGC

- `cd Download`
- `./QGroundControl.AppImage `

## start multi_agent_circle mission

- `rosrun off_mission multi_agent_circle_mission`
