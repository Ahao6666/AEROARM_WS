cmake_minimum_required(VERSION 2.8.3)
project(Gazebo_RL)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  catkin_simple
  roscpp
  rospy
  rosbag
  std_msgs
)
find_package(Eigen3 REQUIRED)
find_package(gazebo REQUIRED)

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   kpkv_msg.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   traj.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs  # Or other packages containing msgs
# )

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES Gazebo_RL
#  CATKIN_DEPENDS actionlib catkin_simple roscpp
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIRS}
  ${GAZEBO_INCLUDE_DIRS}
)
link_directories(${GAZEBO_LIBRARY_DIRS})
## Declare a C++ library
# add_library(Gazebo_RL
#   src/${PROJECT_NAME}/Gazebo_RL.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(Gazebo_RL ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable

add_executable(floating_platform src/floating_platform.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(Gazebo_RL_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(floating_platform ${${Gazebo_RL}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(floating_platform ${catkin_LIBRARIES})
