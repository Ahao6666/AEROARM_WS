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

add_executable(load_capture load_capture.cpp)
target_link_libraries(load_capture ${catkin_LIBRARIES})

