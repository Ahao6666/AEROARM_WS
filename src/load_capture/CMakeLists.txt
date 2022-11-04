cmake_minimum_required(VERSION 2.8.3)
project(load_capture)


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

add_executable(load_capture_gripper1 load_capture_gripper1.cpp)
target_link_libraries(load_capture_gripper1 ${catkin_LIBRARIES})

add_executable(load_capture_gripper3 load_capture_gripper3.cpp)
target_link_libraries(load_capture_gripper3 ${catkin_LIBRARIES})

add_executable(load_capture_gripper2 load_capture_gripper2.cpp)
target_link_libraries(load_capture_gripper2 ${catkin_LIBRARIES})

