#ifndef CLIK_MAIN_H
#define CLIK_MAIN_H


#include <ros/ros.h>
#include "mavros_msgs/ActuatorControl.h"
#include <mavros_msgs/State.h>
#include <mavros_msgs/RCIn.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/TwistStamped.h>
#include <mavros_msgs/SetMode.h>
#include <sensor_msgs/Imu.h>
#include <stddef.h>
#include <stdio.h>                // This ert_main.c example uses printf/fflush
#include <mutex>
#include <Eigen/Eigen>
#include <math.h>
#include <clik/position_pub.h>
#include <clik/manipulator_mode.h>
#include <clik/gripper_mode.h>
#include "clik/traj_out_msg.h"
#include "clik/traj_solver_msg.h"
#include <string.h>
#include "clik_cplus.h"
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>
#include "log4z.h"
#include "clik/action.h"
#include <fstream>

#define _USE_MATH_DEFINES

#include <mavros_msgs/SetMode.h>

//#include <std_msgs/Int32.h>

//#include "math_utils.h"

enum m_behavior {IDLE, WAYPOINT_FLIGHT,LAND, HOVER,TAKEOFF,FORWARD,BACKWARD,RIGHT,LEFT,UP,DOWN};


typedef struct {
  double x    = 0;                   
  double y    = 0;                      
  double z    = 0;    
  double vx  = 0;
  double vy  = 0;
  double vz  = 0;                         
  double phi  =0;                    
  double theta = 0;                
  double psi  = 0;                    
  double wx   = 0;                 
  double wy   = 0;                    
  double wz   = 0;                     
} flightStateStruct;


typedef struct {
  double x = 0;                   
  double y = 0;                      
  double z = 0;                                           
  double psi = 0;                    
  double xe  = 0;                 
  double ye  = 0;                    
  double ze  = 0;    
  Eigen::Vector3d pe = Eigen::Vector3d(0,0,0);                 
} coordinateIni;

// 机械臂的模式：0 放下， 1 收起， 2 协调。
enum COM_MODE { mod_shrink = 0, mod_prepare = 1, mod_control = 2 ,mod_sleep =3,mod_wait =4,mod_read=5};



class clikRos
{
public:
    clikRos();
    ~clikRos(){};

    void mainLoop();

    flightStateStruct flightStateData;
    coordinateIni m_coordinate_contr_ini;

    mavros_msgs::RCIn m_rcin_;
    mavros_msgs::RCIn m_rcin_prev_;
 
    mavros_msgs::State current_state;
    COM_MODE manipulator_mode;
    COM_MODE gripper_mode;

private:

    clik_c_ CLIK_Obj;
    ros::NodeHandle nh;
    ros::Subscriber state_sub ;       // 【订阅】无人机当前状态 - 来自飞控
    ros::Subscriber position_sub;     // 【订阅】无人机当前位置 坐标系:ENU系
    ros::Subscriber velocity_sub;     // 【订阅】无人机当sudu 坐标系:ENU系
    ros::Subscriber attitude_sub;     // 【订阅】无人机当前欧拉角 坐标系:ENU系
    ros::Subscriber attitude_sp_sub;  // 【订阅】无人机的期望姿态
    ros::Subscriber rcin_sub;         // 【订阅】遥控器的操纵 
    ros::Subscriber Delta_sub;        // 【订阅】机械臂的末端位置 - 来自vicon 坐标系 地面绝对坐标系（vicon）
    ros::Subscriber action_sub;       // 【订阅】off_mission 无人机的导航状态
    ros::Subscriber object_sub;       // 【订阅】object的位置
    
    ros::ServiceClient traj_solver_client; // 【客户端】轨迹生成
    ros::ServiceClient traj_out_client;    // 【客户端】轨迹输出
    ros::ServiceClient end_out_client;    // 【客户端】轨迹输出
    
    ros::Publisher Delta_pub;//【发布】 Delta的位置指令
    ros::Publisher local_pos_pub;// 【发布】 飞机的轨迹指令
    ros::Publisher write_pub;// 【发布】 串口指令

    ros::ServiceClient manipulator_client; // 客户端修改模式
    ros::ServiceClient set_mode_client; // 客户端 修改飞机的模式
    // ros::ServiceClient gripper_client; // 客户端修改gripper模式

    bool reset_CLIK_flag_;
    bool on_off_manipulator_flag_; // 机械臂收放状态：false放，true收
    bool ground_origin_position_initialized_flag_ ;
    bool coordinate_flag_;// 协调控制状态：false不协调，true协调
    bool reset_coordinate_flag_;// 协调控制状态保存 
    bool stall_manipulater_flag_;// 保持机械臂的模式指令
    bool first_off_manipulator;// 首次进入放机械臂状态
    bool first_on_manipulator;// 首次收sho进入机械臂状态
    bool first_on_gripper;// 首次收sho进入gripper
    bool coordinate_running_flag_;// 协调控制已经进入
    // bool gripper_switch_;     //机械爪收放判断

    ros::Time last_off_manipulator; // 首次进入放机械臂状态时间
    ros::Time last_on_manipulator; // 首次进入放机械臂状态时间
    ros::Time last_on_gripper; 
    ros::Time last_coordinate; // 首次进入协同模式时间
    ros::Time last_time; // 上一步计算时间
    ros::Time now_time; // 这一步计算时间
    ros::Time test_begin;// 测试开始时间
    std::mutex rc_mutex_;
    std_msgs::String result_serial; 

    double Yout[6];

    clik::traj_out_msg    traj_out_srv;
    clik::traj_out_msg    end_out_srv;
    clik::traj_solver_msg traj_solver_srv;
    

    int origin_counter;
    double pe[3];//机械臂在地面坐标系（绝对坐标系）上的位置，从vicon上订阅
    Eigen::Vector3d dOffset;//机械臂的1状态移动平台相对于飞机的误差
    double yaw_offset;//机械臂相对机体x正方向的误差，该误差与vicon的标定直接相关
    Eigen::Matrix3d rotation_delta_b;
    
    geometry_msgs::PoseStamped m_ref_origin_; //起飞点信息（地面坐标系原点）
    geometry_msgs::PoseStamped current_local_pos; //当前位置信息
    clik::position_pub Delts_cont; // 发布delta机械臂的位置指令 
    clik::manipulator_mode Delta_mode; //发布机械臂模式
    clik::gripper_mode Gripper_mode; //发布gripper模式
    mavros_msgs::SetMode offb_set_mode; // 飞机的飞行模式，这里要把飞机的模式修改位off-board模式
    geometry_msgs::PoseStamped pose; // 储存飞机的位置和偏航指令
    Eigen::Vector3d attitude_sp; // 储存期望的姿态
    clik::action cur_action;

    //回调函数
    void state_obtain(const mavros_msgs::State::ConstPtr &msg);
    void pos_obtain(const geometry_msgs::PoseStamped::ConstPtr &msg);
    void  vel_obtain(const geometry_msgs::TwistStamped::ConstPtr &msg);
    void rcin_obtain(const mavros_msgs::RCIn::ConstPtr& msg);
    void att_obtain(const sensor_msgs::Imu::ConstPtr& msg);
    void delta_obtain(const geometry_msgs::TransformStamped& message_holder);
    void vehicle_action_callback(const clik::action::ConstPtr& msg);
    void att_sp_obtain(const geometry_msgs::PoseStamped::ConstPtr &msg);
    void object_callback(const geometry_msgs::TransformStamped& message_holder);
   

    bool isManupulator(const mavros_msgs::RCIn& rcin);
    // bool isGripper(const mavros_msgs::RCIn& rcin);
    bool isCoordinate(const mavros_msgs::RCIn& rcin);
    void coordinateManipulator2Body(const  Eigen::Vector3d& p_mani, Eigen::Vector3d& p_body);
    void  coordinateBody2Manipulator(const Eigen::Vector3d& p_body , Eigen::Vector3d& p_mani );



    // 检查是否解锁
    void checkArmingState();
    // 检查是否协调，并初始化
    void checkCoordinateState();

    void resetCLIK();
    void resetCoordinateIni();
    void setOnGroundOrigin();
    void resetOnGroundOrigin();
    void rt_OneStep(void);

    // 修补剂控制
    void handlePainting();
    // 放下机械臂
    void putDowndMnipulator();
    // 收上机械臂
    void putUpMnipulator();
    // 机械爪控制
    // void Gripper_control();
    // 协调控制
    void handleCoordinate();
    // 无人机安全飞行限制
    void safeFlight(geometry_msgs::PoseStamped& pose_);
    // 机械臂安全工作空间
    void safeManipulator(clik::position_pub& delta_);


    double  intePe[3];
    double  intePeCmd[3];
    void euler_to_rotation(const Eigen::Vector3d& euler, Eigen::Matrix3d& rotation);
    Eigen::Vector3d point_wB;
    Eigen::Vector3d point_b_desire;
    Eigen::Vector3d point_e_desire;
    Eigen::Vector3d point_e_b_desire;
    Eigen::Vector3d position_object;
    bool last_coordinate_flag_ = false;
    bool coordinate_off_flag_ = false;
    double start_coordinate_point_[3];
    int state_rc_1  = 0; 
    int state_rc_2  = 0;
    double flight_lower_bound_[3]={-2,-2, 0.1};
    double flight_upper_bound_[3]={ 2, 2, 2.1};
    double delta_lower_bound_[3] = {-0.08,-0.08,-0.310};
    double delta_upper_bound_[3] = { 0.08, 0.08,-0.140};
    float xi_min[6];
    float xi_max[6];
    float xi_dot_min[6];
    float xi_dot_max[6];
    float xi_ddot_min[6];
    float xi_ddot_max[6];
};

#endif
