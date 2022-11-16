#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <ros/ros.h>
#include <iostream>
#include <mutex>
#include <geometry_msgs/PoseStamped.h>

#include <mavros_msgs/RCIn.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/ExtendedState.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/NavSatFix.h>
#include <tf/transform_datatypes.h>
#include <mavros_msgs/SetMode.h>

#include <cmath>
#include "definitions.h"
#include "navigator/action.h"
#include "navigator/response.h"



class Navigator
{

public:
    Navigator();

    ~Navigator();

    void mainLoop();

private:
    /*variables*/
    ros::NodeHandle node_;

    //uav state & pp
    //std::vector <geometry_msgs::PoseStamped> waypoints;

    //publications and subscriptions
    
    ros::Publisher response_pub;
    ros::Publisher local_pos_pub;

    ros::Subscriber action_sub;
    ros::Subscriber imu_sub;
    ros::Subscriber state_sub;
    ros::Subscriber landstate_sub;
    ros::Subscriber local_pose_sub;
    ros::Subscriber global_position_sub;
    ros::Subscriber online_target_sub_;
    ros::Subscriber pos_nav_sub_;
    //services

    ros::ServiceClient set_mode_client;// = nh.serviceClient<mavros_msgs::SetMode> ("mavros/set_mode");
    ros::Time last_request;

    navigator::response cur_response;
    navigator::action cur_action;
    geometry_msgs::PoseStamped pose_ref;

    //waypoint index starts from zero
    // float _nav_acc_radius = 0.0f;
    sensor_msgs::NavSatFix current_global_pos;
    mavros_msgs::State current_state;
    sensor_msgs::Imu current_imu_data;
    mavros_msgs::ExtendedState current_extendedstate;
    geometry_msgs::PoseStamped current_local_pos;
    geometry_msgs::PoseStamped pose_nav;
    
    int  m_online_offline_flag_;
    bool init_flags[MAX_BEHAVIOR_NO];
    bool init_switch_flags[MAX_BEHAVIOR_NO];
    bool wp_flag;
    float origin_local_pose_z;


    /*functions*/

    /*callback functions*/
    void vehicle_action_callback(const navigator::action::ConstPtr& msg)
    {
        cur_action = *msg;
    //   ROS_INFO("cur_action.uav_waypoint.pose.position.x %f ", cur_action.uav_waypoint.at(0).pose.position.x);
    //    ROS_INFO("cur_action.uav_waypoint.pose.orientation %f ", cur_action.uav_waypoint.at(0).pose.orientation);
    }
    void state_cb(const mavros_msgs::State::ConstPtr& msg)
    {
        current_state = *msg;
    }
    void extendedstate_cb(const mavros_msgs::ExtendedState::ConstPtr& msg)
    {
        current_extendedstate = *msg;
    }

    void imu_cb(const sensor_msgs::Imu::ConstPtr& msg)
    {
        current_imu_data = *msg;
    }
        
    // vehicle local position
    void local_pose_cb(const geometry_msgs::PoseStamped::ConstPtr& msg)
    {
        current_local_pos = *msg;
    }
    void global_position_cb(const sensor_msgs::NavSatFix::ConstPtr& msg)
    {
        current_global_pos = *msg;
    }

    void pos_nav_cb(const geometry_msgs::PoseStamped::ConstPtr& msg)
    {
        pose_nav = *msg;
        init_flags[WAYPOINT_FLIGHT] = false;
    }

    /*behavior handlers*/
    void handle_idle();
    void handle_land();
    void handle_takeoff();
    void handle_hover();
    void handle_waypoint_flight();

    void handle_land_auto();

    /*supplementary functions*/
    void clear_flags_except(int behavior);
    void report_task_finished(int behavior);
    void clear_switch_flags_except(int behavior);
    void updateWaypointIndex();

};


#endif

