#include <ros/ros.h>
#include <stdint.h>
// 遥控器指令
#include <mavros_msgs/OverrideRCIn.h>
#include <sensor_msgs/Joy.h>

// 末端位置
#include <geometry_msgs/TransformStamped.h>
#include <nav_msgs/Odometry.h>

// 机械臂指令
#include "std_msgs/String.h"
#include "sim2real/position_pub.h"
#include "sim2real/cmd_mode.h"
//girpper command
#include "sim2real/gripper_cmd.h"



enum COM_MODE { mod_shrink = 0, mod_prepare = 1, mod_control = 2 ,mod_wait =3};

class sim2realclass
{
public:
    sim2realclass();
    ~sim2realclass(){};
    void setInitJoint();
private:
    ros::NodeHandle nh;
    ros::Subscriber EndEffector_sub_;        // 【订阅】机械臂的末端位置 - Gazebo ENU 地面绝对坐标系
    ros::Subscriber RC_sub_;        // 【订阅】遥控器指令
    ros::Publisher EndEffector_pub_;        // 【发布】机械臂的末端位置 - 来自vicon 坐标系 地面绝对坐标系（vicon）
    ros::Publisher RC_pub_;        // 【发布】遥控器指令
    geometry_msgs::TransformStamped endEffectorPosition_; 
    ros::Publisher endEffe_traj_pub_;        // 【发布】机械臂的末端位置指令
    ros::Publisher gripper_cmd_pub_;        // 【发布】gripper的末端位置指令

    geometry_msgs::Point traj_endEffe_;
    sim2real::gripper_cmd gripper_cmd_;

  //接收控上位机控制指令
  ros::ServiceServer cmd_mod_sub_;
  // ros::ServiceServer cmd_gripper_mod_sub_;

  //接收位置指令
  ros::Subscriber cmd_pos_sub_; 
  ros::Subscriber cmd_gripper_mod_sub_;

    mavros_msgs::OverrideRCIn RC_Override_;
    int Cmd_mode_=0;
    ros::Time Mod_time_;
    bool cmd_mode_Callback(sim2real::cmd_mode::Request  &req, sim2real::cmd_mode::Response &res);
    void cmd_gripper_Callback(const std_msgs::String::ConstPtr & msg);
    // bool cmd_gripper_mode_Callback(sim2real::cmd_mode::Request  &req, sim2real::cmd_mode::Response &res);
    void  endEffector_obtain(const nav_msgs::Odometry::ConstPtr &msg);
    void cmd_pos_Callback(const sim2real::position_pub::ConstPtr& msg1);
    void  rc_obtain(const sensor_msgs::Joy::ConstPtr &msg);
};