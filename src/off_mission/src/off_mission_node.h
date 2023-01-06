#ifndef OFF_MISSION_NODE_H
#define OFF_MISSION_NODE_H

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

#include "definitions.h"
#include <navigator/action.h>
#include <navigator/interface.h>//cg
#include <navigator/response.h>
#include <cmath>

#include <vector>
#define _USE_MATH_DEFINES

#include <mavros_msgs/SetMode.h>

class TaskManager
{

public:
    TaskManager();

    ~TaskManager();

    void mainLoop();
    mavros_msgs::State current_state;
private:
// public:
    ros::NodeHandle nh;

    ros::Subscriber m_rcin_sub_;
    ros::Subscriber state_sub;
    ros::Subscriber response_sub;
    ros::Subscriber local_pose_sub;
    ros::Subscriber online_target_sub_;
    
    ros::Publisher action_pub;
    ros::Publisher pos_nav_pub;
    ros::Publisher local_pos_pub;

    ros::ServiceClient set_mode_client;
    
    mavros_msgs::SetMode offb_set_mode;
    bool offboard_sent_flag_;
    ros::Time last_request;// = ros::Time::now();
    /*functions*/

    int _current_wpindex;//waypoint index starts from zero

    //vehicle states
    mavros_msgs::RCIn m_rcin_;
    mavros_msgs::RCIn m_rcin_prev_;
    
    geometry_msgs::PoseStamped current_local_pos;
    geometry_msgs::PoseStamped m_online_target_;
    geometry_msgs::PoseStamped pose_nav;

    std::vector<geometry_msgs::PoseStamped> waypoints;
    navigator::action cur_action;
    navigator::interface cur_interface;
    navigator::response cur_response;
    XmlRpc::XmlRpcValue wp_list;

    // bool test_flag;
    bool takeoff_finished_flag;
    bool init_switch_flags[MAX_BEHAVIOR_NO];
    bool takeoff_rc_flag; // vehicle should takeoff first
    bool m_online_offline_flag_;
    bool reset_off_mission_flag_;
    bool current_waypoint_published_flag_;
    std::mutex rc_mutex_;


    /*params*/
    int uav_id;
    double takeoff_height;
    double _nav_acc_radius;
    double _nav_acc_angle;

    // callbacks for subscriptions
    void state_cb(const mavros_msgs::State::ConstPtr& msg)
    {
        current_state = *msg;
    }

    void local_pose_cb(const geometry_msgs::PoseStamped::ConstPtr& msg)
    {
        current_local_pos = *msg;
    }

    void rcinCallback(const mavros_msgs::RCIn::ConstPtr& msg)
    {
            std::lock_guard<std::mutex> lock(rc_mutex_);
            m_rcin_ = *msg;
    }

    void response_cb(const navigator::response::ConstPtr& action_msg)
    {
        cur_response = *action_msg;
        // cur_response_state = cur_response.finished_behavior;
        //ROS_INFO_THROTTLE(5,"cur_response got msgs");
    }


    bool isSwitchLand(const mavros_msgs::RCIn& rcin)
    {
        return (rcin.channels.size()>=7 && rcin.channels.at(6)<1300);   //Land mode 通道7-SE
    }

    bool isSwitchTakeoffHover(const mavros_msgs::RCIn& rcin)
    {
        return (rcin.channels.size()>=7 && rcin.channels.at(6)>1300 && rcin.channels.at(6)<1700); //Takeoff and Hover mode 通道7-SE
    }

    bool isSwitchPath(const mavros_msgs::RCIn& rcin)
    {
        return (rcin.channels.size()>=7 && rcin.channels.at(6)>1800 && rcin.channels.at(6)<2100); //Path mode 通道7-SE
    }

    bool isAutoOffboardMode(const mavros_msgs::RCIn& rcin)
    {
        return (rcin.channels.size()>=7 &&
                rcin.channels.at(4)>1800 && rcin.channels.at(4)<2100 &&  //通道5-SC
                rcin.channels.at(5)>1800 && rcin.channels.at(5)<2100);  //通道6-SD
    }

    bool isAutoMode(const mavros_msgs::RCIn& rcin)
    {
        return (rcin.channels.size()>=7 &&
                rcin.channels.at(4)>1800 && rcin.channels.at(4)<2100);
    }

    bool isOffboardSwitchOn(const mavros_msgs::RCIn& rcin)
    {
    return (rcin.channels.size()>=7 &&
            rcin.channels.at(4)>900 && rcin.channels.at(4)<1200);//Offboard mdoe, 通道5-SC
    }
    
    
    bool checkEnterOffboardByRcSwitch()
    {
        if ( !isOffboardSwitchOn(m_rcin_prev_) && isOffboardSwitchOn(m_rcin_) ) {

            ROS_INFO("Entering Offboard by RC!\n");
            m_rcin_prev_ = m_rcin_;

            return true;
        }
    else
        {
            m_rcin_prev_ = m_rcin_;
            return false;
        }
    }
    
    void onlineTarget_cb(const geometry_msgs::PoseStamped::ConstPtr& msg);
    // init wp list from yaml file
    void initTagetVector(XmlRpc::XmlRpcValue &wp_list);
    void clear_switch_flags_except(int behavior);
    void handle_waypoint_flight();
    // update current waypoint index
    void updateWaypointIndex();
    void checkArmingState();
    void resetOffMission();

    // variable and functions related to RELATIVE ORIGIN
    int origin_counter;
    geometry_msgs::PoseStamped m_ref_origin_;
    bool ground_origin_position_initialized_flag_;

    bool all_waypoint_reached_flag_;
    
    void setOnGroundOrigin();
    void resetOnGroundOrigin();
    void addRefOrigin(geometry_msgs::PoseStamped  *ref);

    // behavior setting functions
    bool setBehaviorIDLE();
    bool setBehaviorTAKEOFF(double height); // relative hight wrt current position.z
    bool setBehaviorHOVER();
    bool setBehaviorPATH();
    bool setBehaviorLAND();
    void setBehaviorOnLine();

    void setOffboardMode();
    void handle_online_flight();
    ros::Time online_time_save;
    bool online_triger_flag;

};


#endif
