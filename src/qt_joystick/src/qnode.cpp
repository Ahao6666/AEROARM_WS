/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/qt_joystick/qnode.hpp"
#include <mavros_msgs/RCIn.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qt_joystick {

  /*****************************************************************************
  ** Implementation
  *****************************************************************************/
  // Get vehicle state
  static mavros_msgs::State current_state;
  void QNode::state_cb(const mavros_msgs::State::ConstPtr& msg){
      current_state = *msg;
  }
  QNode::QNode(int argc, char** argv ) :
    init_argc(argc),
    init_argv(argv)
    {}

  QNode::~QNode() {
      if(ros::isStarted()) {
        ros::shutdown(); // explicitly needed since we use ros::start();
        ros::waitForShutdown();
      }
    wait();
  }

  bool QNode::init() {
    ros::init(init_argc,init_argv,"qt_joystick");
    if ( ! ros::master::check() ) {
      return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;
    // Add your ros communications here.
    joy_publisher = n.advertise<sensor_msgs::Joy>("joy", 1000);
    arming_client = n.serviceClient<mavros_msgs::CommandBool>("mavros/cmd/arming");
    state_sub = n.subscribe<mavros_msgs::State>("mavros/state", 10, QNode::state_cb);
    start();
    return true;
  }

  void QNode::run() {
    ros::Rate loop_rate(50);
    while ( ros::ok() ) {

      sensor_msgs::Joy joy_msg;
      joy_msg.header.stamp = ros::Time::now();
      joy_msg.header.frame_id = "dev/input/js0";
      joy_msg.axes.emplace_back(0);
      joy_msg.axes.emplace_back(0);
      joy_msg.axes.emplace_back(0);
      joy_msg.axes.emplace_back(0);
      joy_msg.axes.emplace_back(Send_data_[0]);
      joy_msg.axes.emplace_back(Send_data_[1]);
      joy_msg.axes.emplace_back(Send_data_[2]);
      joy_msg.buttons.emplace_back(Send_data_[3]);
      joy_msg.buttons.emplace_back(Send_data_[4]);
      joy_msg.buttons.emplace_back(Send_data_[5]);
      joy_publisher.publish(joy_msg);

      mavros_msgs::CommandBool arm_cmd;
      if( !current_state.armed && abs(Send_data_[5]) > 0.9){
          arm_cmd.request.value = true;
          arming_client.call(arm_cmd);
      }
//      if( current_state.armed && abs(Send_data_[5]) < 0.1){
//        arm_cmd.request.value = false;
//        arming_client.call(arm_cmd);
//      }

      ros::spinOnce();
      loop_rate.sleep();
    }
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
  }

  void QNode::Get_data(int *data){
    for(int i=0; i<6 ;i++)
      Send_data_[i] = data[i];
  }

}  // namespace qt_joystick
