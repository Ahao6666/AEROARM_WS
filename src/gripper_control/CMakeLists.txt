cmake_minimum_required(VERSION 2.8.3)
project(gripper_control)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  sensor_msgs
)

catkin_package(

)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(gripper_control gripper_control.cpp)
target_link_libraries(gripper_control ${catkin_LIBRARIES})

