cmake_minimum_required(VERSION 2.8.3)
project(testPub)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  sensor_msgs
  tf
  nav_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES kinematicsComputing
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)




#target_link_libraries(InKinematics ${catkin_LIBRARIES})
#add_dependencies(InKinematics InKinematics_generate_messages_cpp)



#target_link_libraries(trajGeneration ${catkin_LIBRARIES})
#add_dependencies(trajGeneration trajGeneration_generate_messages_cpp)





add_executable(testRviz src/testRviz.cpp)
target_link_libraries(testRviz ${catkin_LIBRARIES})
add_dependencies(testRviz testRviz_generate_messages_cpp)

