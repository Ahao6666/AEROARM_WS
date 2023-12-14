cmake_minimum_required(VERSION 3.10.0)
project(aerial_toolbox)
set(CMAKE_BUILD_TYPE RELWITHDEBINFO)

find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg sensor_msgs  
geometry_msgs tf message_generation)



add_message_files(
  FILES
  toolbox.msg
  toolbox_array.msg

)

generate_messages(
  DEPENDENCIES
  
  std_msgs
  sensor_msgs
)

#catkin_package( CATKIN_DEPENDS message_runtime std_msgs rospy )

## Use this on my computer
##target_link_libraries(offline_calculate  ${OpenCV_LIBS} ${catkin_LIBRARIES} )

##add_executable(cali_camera src/cali_camera.cc)
##target_link_libraries(cali_camera  ${catkin_LIBRARIES} realsense2::realsense2) #${OpenCV_LIBS}

include_directories(
  ${catkin_INCLUDE_DIRS}
  )
add_executable(realsense_sim src/realsense_sim.cpp)

## Use this on NUC
target_link_libraries(realsense_sim ${catkin_LIBRARIES}) #${OpenCV_LIBS}

## Use this on my computer
##target_link_libraries(realsense_sim ${OpenCV_LIBS} ${catkin_LIBRARIES}) #${OpenCV_LIBS}
