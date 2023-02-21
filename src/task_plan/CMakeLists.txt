cmake_minimum_required(VERSION 3.0.2)
project(task_plan)

## Compile as C++11, supported in ROS Kinetic and newer
 add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  message_generation roscpp std_msgs geometry_msgs 
)



## Generate messages in the 'msg' folder
add_message_files(
  FILES
  corner.msg
)

## Generate services in the 'srv' folder
add_service_files(FILES
  traj_out_msg.srv
  traj_solver_msg.srv
)

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
generate_messages(DEPENDENCIES
  std_msgs
  geometry_msgs
)

catkin_package(
  CATKIN_DEPENDS
  roscpp std_msgs message_runtime
  )

  include_directories(
  include ${catkin_INCLUDE_DIRS}
)


link_directories(
 lib
  ${catkin_LIB_DIRS}
)

add_executable(traj_gen
  src/bezier_base.cpp
  src/trajectory_generator.cpp
)
add_dependencies(traj_gen ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(traj_gen
  ${catkin_LIBRARIES}
  osqp  # library name
)


#uncomment the following 4 lines to use the Eigen library
find_package(cmake_modules REQUIRED)
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
add_definitions(${EIGEN_DEFINITIONS})

add_executable(pathfinder
  src/pathfinder.cpp
  src/a_star.cpp
)
add_dependencies(pathfinder ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(pathfinder
  ${catkin_LIBRARIES}
)


add_executable(traj_solver
 src/bezier_base.cpp
 src/trajectory_solver.cpp
 src/log4z.cpp
 src/end_effector_planning.cpp
 src/auto_pick.cpp
)
add_dependencies(traj_solver ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(traj_solver
 ${catkin_LIBRARIES}
 osqp  # library name
)

add_executable(box_pose_pub src/box_pose_pub.cpp)
add_dependencies(box_pose_pub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(box_pose_pub ${GAZEBO_LIBRARIES} ${catkin_LIBRARIES})
