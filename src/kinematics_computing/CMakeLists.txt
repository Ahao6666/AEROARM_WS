cmake_minimum_required(VERSION 2.8.3)
project(kinematics_computing)


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

add_executable(Joint_Talker src/Joint_Talker.cpp src/InKinematics.cpp)
target_link_libraries(Joint_Talker ${catkin_LIBRARIES})
add_dependencies(Joint_Talker Joint_Talker_generate_messages_cpp)
