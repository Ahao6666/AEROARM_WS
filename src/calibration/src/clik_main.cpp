#include "clik_main.h"

// 四元素转欧拉角
Eigen::Vector3d quaternion_to_euler(const Eigen::Quaterniond &q)
{
    float quat[4];
    quat[0] = q.w();
    quat[1] = q.x();
    quat[2] = q.y();
    quat[3] = q.z();

    Eigen::Vector3d ans;
    ans[0] = atan2(2.0 * (quat[3] * quat[2] + quat[0] * quat[1]), 1.0 - 2.0 * (quat[1] * quat[1] + quat[2] * quat[2]));
    ans[1] = asin(2.0 * (quat[2] * quat[0] - quat[3] * quat[1]));
    ans[2] = atan2(2.0 * (quat[3] * quat[0] + quat[1] * quat[2]), 1.0 - 2.0 * (quat[2] * quat[2] + quat[3] * quat[3]));
    return ans;
}

clikRos::clikRos()
{

        // 【订阅】无人机当前状态 - 来自飞控
        //  本话题来自飞控(通过Mavros功能包 /plugins/sys_status.cpp)
        state_sub = nh.subscribe<mavros_msgs::State>("mavros/state", 10, &clikRos::state_obtain,this);

        // 【订阅】无人机当前位置 坐标系:ENU系 （此处注意，所有状态量在飞控中均为NED系，但在ros中mavros将其转换为ENU系处理。所以，在ROS中，所有和mavros交互的量都为ENU系）
        //  本话题来自飞控(通过Mavros功能包 /plugins/local_position.cpp读取), 对应Mavlink消息为LOCAL_POSITION_NED (#32), 对应的飞控中的uORB消息为vehicle_local_position.msg
        position_sub = nh.subscribe<geometry_msgs::PoseStamped>("mavros/local_position/pose", 10,  &clikRos::pos_obtain,this);

        // 【订阅】无人机当前欧拉角 坐标系:ENU系
        //  本话题来自飞控(通过Mavros功能包 /plugins/imu.cpp读取), 对应Mavlink消息为ATTITUDE (#30), 对应的飞控中的uORB消息为vehicle_attitude.msg
        attitude_sub = nh.subscribe<sensor_msgs::Imu>("mavros/imu/data", 10,  &clikRos::att_obtain,this);
        // 【订阅】无人机的期望姿态角
        //  本话题来自飞控(通过Mavros功能包 /plugins/imu.cpp读取), 对应Mavlink消息为ATTITUDE (#30), 对应的飞控中的uORB消息为vehicle_attitude.msg
        attitude_sp_sub = nh.subscribe<geometry_msgs::PoseStamped>("mavros/setpoint_attitude/attitude", 10,  &clikRos::att_sp_obtain,this);
        

        // 【订阅】遥控器的操纵 
        //  本话题来自飞控(通过Mavros功能包 /plugins/manulcontrol.cpp读取), 对应Mavlink消息为ATTITUDE (#30), 对应的飞控中的uORB消息为vehicle_attitude.msg
        rcin_sub = nh.subscribe<mavros_msgs::RCIn>("mavros/rc/in", 10, &clikRos::rcin_obtain,this); 
        
        // 【订阅】机械臂的末端位置 - 来自vicon 坐标系 地面绝对坐标系（vicon）
        // 本话题来自vicon_bridge
        Delta_sub = nh.subscribe("vicon/Delta/Delta", 10, &clikRos::delta_obtain, this);

        // 【订阅】无人机的导航状态
        //  本话题来自于 off_mission
        action_sub = nh.subscribe<calibration::action>("navigator/vehicle_action",10,&clikRos::vehicle_action_callback,this); 


        // 【发布】机械臂末端位置指令
        Delta_pub = nh.advertise<calibration::position_pub>("control_signal/pos_pub", 10);

        // 【发布】 飞行平台的轨迹指令和偏航指令 to 飞控
        local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>("online_target",10); // 这个接口用于调用off_mission的接口，但是这里有一点比较坑，就是这个航路点一旦结束，就不会再发了。

        // 【发布】串口指令
        write_pub = nh.advertise<std_msgs::String>("serial_write", 1000);

        // 【客户端】修改机械臂模式
        manipulator_client = nh.serviceClient<calibration::manipulator_mode>("control_signal/command_mode");

        //【客户端】 修改飞机飞行模式 发送给飞控
        set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("mavros/set_mode");

        // 初始化机械臂工作状态
        manipulator_mode = mod_sleep;

        now_time  = ros::Time::now();
        p1_e_delta_des << 0.0, 0.0, -0.220;
        p2_e_delta_des << 0.0, 0.04, -0.220;
}

    // 欧拉角转旋转矩阵
void clikRos::euler_to_rotation(const Eigen::Vector3d& euler, Eigen::Matrix3d& rotation)
{
    rotation(0,0) = cos(euler(1))*cos(euler(2));
    rotation(0,1) = sin(euler(1))*sin(euler(0))*cos(euler(2))-cos(euler(0))*sin(euler(2));
    rotation(0,2) = sin(euler(1))*cos(euler(0))*cos(euler(2))+sin(euler(0))*sin(euler(2));
    rotation(1,0) = cos(euler(1))*sin(euler(2));
    rotation(1,1) = sin(euler(1))*sin(euler(0))*sin(euler(2))+cos(euler(0))*cos(euler(2));
    rotation(1,2) = -sin(euler(0))*cos(euler(2))+cos(euler(0))*sin(euler(1))*sin(euler(2));
    rotation(2,0) = -sin(euler(1));
    rotation(2,1) = -sin(euler(0))*cos(euler(1));
    rotation(2,2) = cos(euler(0))*cos(euler(1));
}



 // 【回调函数】 飞机状态 
    void  clikRos::state_obtain(const mavros_msgs::State::ConstPtr &msg)
    {
        current_state = *msg;
    }
    // 【回调函数】 位置 ENU->NED
    void  clikRos::pos_obtain(const geometry_msgs::PoseStamped::ConstPtr &msg)
    {
        current_local_pos = *msg;
        flightStateData.x = msg->pose.position.x;
        flightStateData.y = - msg->pose.position.y;
        flightStateData.z = - msg->pose.position.z;
    }

    // 【回调函数】 rcin
    void  clikRos::rcin_obtain(const mavros_msgs::RCIn::ConstPtr& msg)
    {
        std::lock_guard<std::mutex> lock(rc_mutex_);
        m_rcin_ = *msg;
        //ROS_INFO("CLIK:1111");
        //ROS_INFO("RC_IN chanlle = %u\n",m_rcin_.channels.at(9));
    }


    // 【回调函数】 姿态角&角速度 ENU->NED
void  clikRos::att_obtain(const sensor_msgs::Imu::ConstPtr& msg)
{
    Eigen::Quaterniond q_fcu = Eigen::Quaterniond(msg->orientation.w, msg->orientation.x, msg->orientation.y, msg->orientation.z);
    //Transform the Quaternion to euler Angles
    Eigen::Vector3d euler_fcu = quaternion_to_euler(q_fcu);
    flightStateData.phi    = euler_fcu[0];
    flightStateData.theta  = - euler_fcu[1];
    flightStateData.psi    = - euler_fcu[2] ;
    
    double x = msg->orientation.x;
    double y = msg->orientation.y;
    double z = msg->orientation.z;

    flightStateData.wx = msg->angular_velocity.x;
    flightStateData.wy = - msg->angular_velocity.y;
    flightStateData.wz = - msg->angular_velocity.z;
}
// 【回调函数】 期望的姿态角
void clikRos::att_sp_obtain(const geometry_msgs::PoseStamped::ConstPtr &msg)
{
    Eigen::Quaterniond q_fcu = Eigen::Quaterniond(msg->pose.orientation.w, msg->pose.orientation.x, msg->pose.orientation.y, msg->pose.orientation.z);
    //Transform the Quaternion to euler Angles
    attitude_sp = quaternion_to_euler(q_fcu);
}

// 【回调函数】机械臂的末端位置 - 来自vicon 坐标系 地面绝对坐标系（vicon）
void clikRos::delta_obtain(const geometry_msgs::TransformStamped& message_holder)
{
//   pose = message_holder;
   pe[0] = message_holder.transform.translation.x;
   pe[1] = -message_holder.transform.translation.y;
   pe[2] = -message_holder.transform.translation.z;
}

// 【回调函数】
void clikRos::vehicle_action_callback(const calibration::action::ConstPtr& msg)
{
    cur_action = *msg;
}


bool clikRos::isManupulator(const mavros_msgs::RCIn& rcin)
{
    return ((rcin.channels.size()>=7) && (rcin.channels.at(9)>1500));//机械臂收放 通道10
}

bool clikRos::isCoordinate(const mavros_msgs::RCIn& rcin)
{
    return (rcin.channels.size()>=7 && rcin.channels.at(8)>1500);//进入协同模式 通道待定
}

void clikRos::setOnGroundOrigin()
{
     m_ref_origin_.pose.position.x = current_local_pos.pose.position.x;
     m_ref_origin_.pose.position.y = current_local_pos.pose.position.y;
     m_ref_origin_.pose.position.z = current_local_pos.pose.position.z;
     ground_origin_position_initialized_flag_ = true;
     ROS_INFO("refernce origin set at position x  %f y  %f z %f " , m_ref_origin_.pose.position.x , 
                                                                       m_ref_origin_.pose.position.y , 
                                                                      m_ref_origin_.pose.position.z);
}
void clikRos::resetCLIK()
{
    on_off_manipulator_flag_ = false;// false：摆臂垂直 true：摆臂水平
    resetOnGroundOrigin();
}
void clikRos::resetOnGroundOrigin()
{
    ground_origin_position_initialized_flag_ = false;
    origin_counter  = 0;
    m_ref_origin_.pose.position.x = 0;
    m_ref_origin_.pose.position.y = 0;
    m_ref_origin_.pose.position.z = 0;
}
void clikRos::resetCoordinateIni()
{
    m_coordinate_contr_ini.x = flightStateData.x;
    m_coordinate_contr_ini.y = flightStateData.y;
    m_coordinate_contr_ini.z = flightStateData.z;
    m_coordinate_contr_ini.psi = flightStateData.psi;
    double dtemp[3];
    dtemp[0] = pe[0]- flightStateData.x;
    dtemp[1] = pe[1]- flightStateData.y;
    dtemp[2] = pe[2]- flightStateData.z;
    Eigen::Vector3d euler;
    euler(0) = flightStateData.phi;
    euler(1) = flightStateData.theta;
    euler(2) = flightStateData.psi;

    Eigen::Matrix3d rotation  = Eigen::Matrix3d::Identity();
    euler_to_rotation(euler,rotation);

    m_coordinate_contr_ini.xe = rotation(0,0)*dtemp[0]+rotation(1,0)*dtemp[1]+rotation(2,0)*dtemp[2];
    m_coordinate_contr_ini.ye = rotation(0,1)*dtemp[0]+rotation(1,1)*dtemp[1]+rotation(2,1)*dtemp[2];
    m_coordinate_contr_ini.ze = rotation(0,2)*dtemp[0]+rotation(1,2)*dtemp[1]+rotation(2,2)*dtemp[2];
    ROS_INFO("CLIK:INI_X=%f\tINI_Y=%f\tINI_Z=%f\t\n",m_coordinate_contr_ini.xe,m_coordinate_contr_ini.ye,m_coordinate_contr_ini.ze);
}

void clikRos::checkArmingState()
{
    if(!current_state.armed && !reset_CLIK_flag_)
    {
        reset_CLIK_flag_ = true;
        ROS_INFO("-----------------------------------------------");
        ROS_INFO("Disarmed! Will restart the mission next time armed!\n");
    }
    if(current_state.armed && reset_CLIK_flag_)
    {
        reset_CLIK_flag_ = false;
        ROS_INFO("First time to Arm");
        resetCLIK();
    }
}

// 
    void clikRos::checkCoordinateState()
{
    if(!coordinate_flag_ && !reset_coordinate_flag_)
    {
        reset_coordinate_flag_ = true;
        ROS_INFO("-----------------------------------------------");
        ROS_INFO("Discoordinated! Will restart the mission next time coordinated!\n");
    }
    if( coordinate_flag_ && reset_coordinate_flag_)
    {
        reset_coordinate_flag_ = false;
        ROS_INFO("First time to Coordinate");
        resetCoordinateIni();//在这里要改变起CLIK的初值
        last_coordinate = ros::Time::now();
    }
}

void  clikRos::coordinateManipulator2Body(const  Eigen::Vector3d& p_mani, Eigen::Vector3d& p_body)
{
    Eigen::Matrix3d DCM_mani2body;
    DCM_mani2body<< -sin(yaw_offset),cos(yaw_offset),0.0,cos(yaw_offset),sin(yaw_offset),0.0,0.0,0.0,-1.0;
    p_body = DCM_mani2body*p_mani + dOffset;
}

void  clikRos::coordinateBody2Manipulator(const Eigen::Vector3d& p_body , Eigen::Vector3d& p_mani )
{
    Eigen::Matrix3d DCM_mani2body;
    DCM_mani2body<< -sin(yaw_offset),cos(yaw_offset),0.0,cos(yaw_offset),sin(yaw_offset),0.0,0.0,0.0,-1.0;
    p_mani = DCM_mani2body.transpose()*(p_body - dOffset);
}
void clikRos::handleCoordinate()
{
    if (!(manipulator_mode==mod_control))
    {
        /* code for True */
        manipulator_mode = mod_control;
        Delta_mode.request.mode = 2;
        if (manipulator_client.call(Delta_mode)&&Delta_mode.response.result)
        {
            
            ROS_INFO("CLIK: Manipulator is coordinated;");
        }
        // 在这里已经默认进入offboard模式了
        
        coordinate_running_flag_ = true;
        
         memset(Yout,0,sizeof(Yout));

        last_time = ros::Time::now() ; // 初始化上一步计算时间
        now_time  = ros::Time::now() ; // 初始化这一步计算时间        ser.setPort("/dev/serial"); 

        test_begin = ros::Time::now() ;
        resetCoordinateIni();//在这里要改变起CLIK的初值
    }
    if (coordinate_running_flag_)
    {
        now_time  = ros::Time::now() ;
        double time_from_begin =  now_time.toSec() - test_begin.toSec();
        if (time_from_begin < 15)
        {
            Delts_cont.time_stamp = ros::Time::now();
            Delts_cont.X  = p1_e_delta_des(0);
            Delts_cont.Y  = p1_e_delta_des(1) ;
            Delts_cont.Z  = p1_e_delta_des(2);
        }

        if( time_from_begin>13 && time_from_begin <14)
        {
            p1_e << pe[0], pe[1], pe[2];
            p1_b << flightStateData.x, flightStateData.y, flightStateData.z;
            Eigen::Vector3d euler_temp(flightStateData.phi, flightStateData.theta, flightStateData.psi);
            euler_to_rotation(euler_temp, ratation1_b2i);
        }

        if (time_from_begin >= 15)
        {
            Delts_cont.time_stamp = ros::Time::now();
            Delts_cont.X  = p2_e_delta_des(0);
            Delts_cont.Y  = p2_e_delta_des(1) ;
            Delts_cont.Z  = p2_e_delta_des(2);
        }

        if( time_from_begin>23 && time_from_begin <24)
        {
            p2_e << pe[0], pe[1], pe[2];
            p2_b << flightStateData.x, flightStateData.y, flightStateData.z;
            Eigen::Vector3d euler_temp(flightStateData.phi, flightStateData.theta, flightStateData.psi);
            euler_to_rotation(euler_temp, ratation2_b2i);
        }

        if (time_from_begin>28 && time_from_begin<29 && !flag_calibrate)
        {
            Eigen::Vector3d  pe_b_1 = ratation1_b2i.transpose() * (p1_e - p1_b);
            Eigen::Vector3d  pe_b_2 = ratation2_b2i.transpose() * (p2_e - p2_b);
            Eigen::Vector3d  pbbb = pe_b_2 - pe_b_1;
            double off_yaw_out  = acos(pbbb(0)/pbbb.norm());
            off_yaw_out = (pbbb(1)>0)? off_yaw_out: -off_yaw_out;
            Eigen::Matrix3d rotation_delta_b;
            rotation_delta_b << sin(off_yaw_out), cos(off_yaw_out), 0, cos(off_yaw_out), sin(off_yaw_out), 0, 0, 0, -1;
            Eigen::Vector3d off_dist = pe_b_1 - rotation_delta_b*p1_e_delta_des;
            ROS_INFO("yaw offset = %f rad", off_yaw_out);
            ROS_INFO("distant offset =[ %f, %f, %f]  m", off_dist(0),off_dist(1),off_dist(2));
            ROS_INFO("cheack");
            Eigen::Vector3d off_dist_chec = pe_b_2 - rotation_delta_b*p2_e_delta_des;
            ROS_INFO("distant offset =[ %f, %f, %f]  m", off_dist_chec(0),off_dist_chec(1),off_dist_chec(2));
            
            Eigen::Vector3d ped_test = rotation_delta_b.transpose()*(pe_b_1 - off_dist);
            ROS_INFO("first cmd =[ %f, %f, %f]  m", ped_test(0),ped_test(1),ped_test(2));

            ped_test = rotation_delta_b.transpose()*(pe_b_2 - off_dist_chec);
            ROS_INFO("second cmd =[ %f, %f, %f]  m", ped_test(0),ped_test(1),ped_test(2));
            
            flag_calibrate = true;
        }
        


        Delta_pub.publish(Delts_cont);
    }
}


void clikRos::mainLoop()
{
    /*--------- 初始检查--------- */
    // If first time arm, reset whole mission
    checkArmingState();
    // Set relative origin, taking local position drift into account
    if(!ground_origin_position_initialized_flag_ )
    {
        setOnGroundOrigin();
        return;
    } 
    coordinate_flag_ = isCoordinate(m_rcin_);
    on_off_manipulator_flag_ = isManupulator(m_rcin_);
    if (!coordinate_flag_ && last_coordinate_flag_)
    {
        coordinate_off_flag_ = true;
    }
    last_coordinate_flag_ = coordinate_flag_;

    if ( !(cur_action.behavior == WAYPOINT_FLIGHT))
    {
        coordinate_off_flag_ = false;
    }
    
    // 检查是否协调控制
    checkCoordinateState();
    
    if (coordinate_flag_  && (ros::Time::now() - last_coordinate > ros::Duration(1.0)))// 地面调试
    handleCoordinate();
    
}
