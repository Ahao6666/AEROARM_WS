# Simulation process

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

第三步，运行航路点设定

- `roslaunch navigator navigator.launch`
- `roslaunch off_mission off_mission.launch`

第四步，UI joysiyck control

- `rosrun qt_joystick qt_joystick`

  Click on the `connect` button

# Joy stick control process

第一步：启动GAZEBO仿真后，在地面站手动电机解锁

第二步：SC拨杆分别为manual/position/offboard模式，切换至offboard模式

第三步：SE拨杆至2档位，进入Online模式

第四步：在offboard+Online模式下，SB拨杆用于执行飞行任务，同时自主控制Detla机械臂

第五步：SA开关用于独立控制Delta机械臂
