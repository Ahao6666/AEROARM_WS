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

// 饱和函数
void sat_my(double& x, double x_min, double x_max)
{
    if (x < x_min)
    {
        x = x_min;
    }
    if (x > x_max)
    {
        x = x_max;
    }
}

template <class T>
T setNAN2Zero(T var)
{
    if (isfinite(var))
    {
        return var;
    }
    else
    {
        return 0;
    }
}


clikRos::clikRos()
{

        // 【订阅】无人机当前状态 - 来自飞控
        //  本话题来自飞控(通过Mavros功能包 /plugins/sys_status.cpp)
        state_sub = nh.subscribe<mavros_msgs::State>("mavros/state", 10, &clikRos::state_obtain,this);

        // 【订阅】无人机当前位置 坐标系:ENU系 （此处注意，所有状态量在飞控中均为NED系，但在ros中mavros将其转换为ENU系处理。所以，在ROS中，所有和mavros交互的量都为ENU系）
        //  本话题来自飞控(通过Mavros功能包 /plugins/local_position.cpp读取), 对应Mavlink消息为LOCAL_POSITION_NED (#32), 对应的飞控中的uORB消息为vehicle_local_position.msg
        position_sub = nh.subscribe<geometry_msgs::PoseStamped>("mavros/local_position/pose", 10,  &clikRos::pos_obtain,this);

         // 【订阅】无人机当前速度 坐标系:ENU系 （此处注意，所有状态量在飞控中均为NED系，但在ros中mavros将其转换为ENU系处理。所以，在ROS中，所有和mavros交互的量都为ENU系）
        //  本话题来自飞控(通过Mavros功能包 /plugins/local_position.cpp读取), 对应Mavlink消息为LOCAL_POSITION_NED (#32), 对应的飞控中的uORB消息为vehicle_local_position.msg
        velocity_sub = nh.subscribe<geometry_msgs::TwistStamped>("mavros/local_position/velocity_local", 10,  &clikRos::vel_obtain,this);

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
        action_sub = nh.subscribe<clik::action>("navigator/vehicle_action",10,&clikRos::vehicle_action_callback,this); 
        // 【订阅】object的位置
        //  本话题来自于 vicon
        object_sub = nh.subscribe("vicon/Object/Object", 10, &clikRos::object_callback, this);


        // 【发布】机械臂末端位置指令
        Delta_pub = nh.advertise<clik::position_pub>("control_signal/pos_pub", 10);

        // 【发布】 飞行平台的轨迹指令和偏航指令 to 飞控
        local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>("online_target",10); // 这个接口用于调用off_mission的接口，但是这里有一点比较坑，就是这个航路点一旦结束，就不会再发了。

        // 【发布】串口指令
        write_pub = nh.advertise<std_msgs::String>("serial_write", 1000);

        // 【客户端】修改机械臂模式
        manipulator_client = nh.serviceClient<clik::manipulator_mode>("control_signal/command_mode");

        // // 【客户端】修改机械臂模式
        // gripper_client = nh.serviceClient<clik::gripper_mode>("control_signal/command_gripper_mode");

        //【客户端】 修改飞机飞行模式 发送给飞控
        set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("mavros/set_mode");

        // 【客户端】轨迹生成
        traj_solver_client  = nh.serviceClient<clik::traj_solver_msg>("trajectory_solver");
        // 【客户端】当前位置指令获取
        traj_out_client     = nh.serviceClient<clik::traj_out_msg>("trajectory_result");  
        // 【客户端】当前位置指令获取
        end_out_client     = nh.serviceClient<clik::traj_out_msg>("end_effector_result");      

        // 初始化机械臂工作状态
        manipulator_mode = mod_sleep;
        gripper_mode = mod_sleep;
        // 读取参数服务器
        nh.param<double>("/clik/yaw_offset",yaw_offset,-0.0751f);
        nh.param<double>("/clik/x_offset",dOffset(0),0.0111f);
        nh.param<double>("/clik/y_offset",dOffset(1),-0.0004f);
        nh.param<double>("/clik/z_offset",dOffset(2),0.2435f);
        rotation_delta_b << sin(yaw_offset), cos(yaw_offset), 0, cos(yaw_offset), sin(yaw_offset), 0, 0, 0, -1;

        nh.param<float>("/clik/x_min",xi_min[0],-4.0f);
        nh.param<float>("/clik/y_min",xi_min[1],-3.0f);
        nh.param<float>("/clik/z_min",xi_min[2],0.02f);
        nh.param<float>("/clik/delta_x_min",xi_min[3],-0.08f);
        nh.param<float>("/clik/delta_y_min",xi_min[4],-0.08f);
        nh.param<float>("/clik/delta_z_min",xi_min[5],-0.310f);

        nh.param<float>("/clik/x_max",xi_max[0],4.0f);
        nh.param<float>("/clik/y_max",xi_max[1],3.0f);
        nh.param<float>("/clik/z_max",xi_max[2],6.1f);
        nh.param<float>("/clik/delta_x_max",xi_max[3],0.08f);
        nh.param<float>("/clik/delta_y_max",xi_max[4],0.08f);
        nh.param<float>("/clik/delta_z_max",xi_max[5],-0.140f);

      
        nh.param<float>("/clik/vel_horizion_max",xi_dot_max[0],0.2f);
        xi_dot_max[1] = xi_dot_max[0];
        nh.param<float>("/clik/vel_vertical_max",xi_dot_max[2],0.2f);
        nh.param<float>("/clik/delta_vel",xi_dot_max[3],1.0f);
        xi_dot_max[4 ] = xi_dot_max[3];
        xi_dot_max[5 ] = xi_dot_max[3];
        for (int i = 0; i < 6; i++)
        {
            xi_dot_min[i] =  -xi_dot_max[i];
        }
    
        nh.param<float>("/clik/acc_horizion_max",xi_ddot_max[0],0.2f);
        xi_ddot_max[1] = xi_ddot_max[0];
        nh.param<float>("/clik/acc_vertical_max",xi_ddot_max[2],0.2f);
        nh.param<float>("/clik/delta_acc",xi_ddot_max[3],1.0f);
        xi_ddot_max[4 ] = xi_ddot_max[3];
        xi_ddot_max[5 ] = xi_ddot_max[3];
        for (int i = 0; i < 6; i++)
        {
            xi_ddot_min[i] =  -xi_ddot_max[i];
        }

        // 设置安全范围
        for (size_t i = 0; i < 3; i++)
        {
            flight_lower_bound_[i] = xi_min[i];
            flight_upper_bound_[i] = xi_max[i];
            delta_lower_bound_[i] = xi_min[i+3];
            delta_upper_bound_[i] = xi_max[i+3];
        }
        
        for (size_t i = 0; i < 6; i++)
        {
            CLIK_Obj.xi_min[i] = xi_min[i];
            CLIK_Obj.xi_max[i] = xi_max[i];
            CLIK_Obj.xi_dot_min[i] = xi_dot_min[i];
            CLIK_Obj.xi_dot_max[i] = xi_dot_max[i];
            CLIK_Obj.xi_ddot_min[i]= xi_ddot_min[i];
            CLIK_Obj.xi_ddot_max[i]= xi_ddot_max[i];
        }

         // 作业空间的中心点 机体坐标系
         point_wB[0]    = dOffset(0);
         point_wB[1]    = dOffset(1);
         point_wB[2]    = dOffset(2) + 0.225;

         

         // 初始化积分变量
         memset(Yout,0,sizeof(Yout));

         // 初始化积分变量
         memset(intePe,0,sizeof(intePe));

         // 初始化积分变量
         memset(intePeCmd,0,sizeof(intePeCmd));

        //  char path_file[200];

         now_time  = ros::Time::now();

         //  初始化运动学限制
        for (size_t i = 0; i < 6; i++)
        {
            CLIK_Obj.xi_min[i] = xi_min[i];
            CLIK_Obj.xi_max[i] = xi_max[i];
            CLIK_Obj.xi_dot_min[i] = xi_dot_min[i];
            CLIK_Obj.xi_dot_max[i] = xi_dot_max[i];
            CLIK_Obj.xi_ddot_min[i]= xi_ddot_min[i];
            CLIK_Obj.xi_ddot_max[i]= xi_ddot_max[i];
        }

        CLIK_Obj.getOffSetManipulator(yaw_offset,dOffset);
        
        char *buffer;
        //也可以将buffer作为输出参数
        if((buffer = getcwd(NULL, 0)) == NULL)
        {
            printf("getcwd error\n");
        }
        else
        {
            printf("%s\n", buffer);
            free(buffer);
        }
        //start log4z  
        zsummer::log4z::ILog4zManager::getRef().start();  

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
    // 【回调函数】 位置 ENU->NED 坐标系变换
    void  clikRos::pos_obtain(const geometry_msgs::PoseStamped::ConstPtr &msg)
    {
        current_local_pos = *msg;
        flightStateData.x = msg->pose.position.x;
        flightStateData.y = - msg->pose.position.y;
        flightStateData.z = - msg->pose.position.z;
    }
     void  clikRos::vel_obtain(const geometry_msgs::TwistStamped::ConstPtr &msg)
    {
        flightStateData.vx = msg->twist.linear.x;
        flightStateData.vy = - msg->twist.linear.y;
        flightStateData.vz = - msg->twist.linear.z;
    }
    // 【回调函数】 rcin
    void  clikRos::rcin_obtain(const mavros_msgs::RCIn::ConstPtr& msg)
    {
        std::lock_guard<std::mutex> lock(rc_mutex_);
        m_rcin_ = *msg;
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
void clikRos::vehicle_action_callback(const clik::action::ConstPtr& msg)
{
    cur_action = *msg;
}

// 【回调函数】
void clikRos::object_callback(const geometry_msgs::TransformStamped& message_holder)
{
    position_object(0) = message_holder.transform.translation.x;
    position_object(1) = - message_holder.transform.translation.y;
    position_object(2) = - message_holder.transform.translation.z;
}


bool clikRos::isManupulator(const mavros_msgs::RCIn& rcin)
{
    return ((rcin.channels.size()>=7) && (rcin.channels.at(9)>1500));//机械臂收放 通道10-SA
}

// bool clikRos::isGripper(const mavros_msgs::RCIn& rcin)
// {
//     return ((rcin.channels.size()>=7) && (rcin.channels.at(10)>1500));//机械爪收放，通道11-SG
// }

bool clikRos::isCoordinate(const mavros_msgs::RCIn& rcin)
{
    return (rcin.channels.size()>=7 && rcin.channels.at(8)>1500);//进入协同模式 通道9-SB
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
    // gripper_switch_ = false;
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
    Eigen::Vector3d dtemp = Eigen::Vector3d(pe[0],pe[1],pe[2]) - Eigen::Vector3d(flightStateData.x,flightStateData.y,flightStateData.z);
    Eigen::Vector3d euler;
    euler(0) = flightStateData.phi;
    euler(1) = flightStateData.theta;
    euler(2) = flightStateData.psi;

    Eigen::Matrix3d rotation  = Eigen::Matrix3d::Identity();
    euler_to_rotation(euler,rotation);
    Eigen::Vector3d peb = rotation.transpose() * dtemp;
    m_coordinate_contr_ini.xe = peb(0);
    m_coordinate_contr_ini.ye = peb(1);
    m_coordinate_contr_ini.ze = peb(2);

    m_coordinate_contr_ini.pe = Eigen::Vector3d(pe[0],pe[1],pe[2]) ;
    ROS_INFO("CLIK:INI_X=%f\tINI_Y=%f\tINI_Z=%f\t\n",m_coordinate_contr_ini.xe,m_coordinate_contr_ini.ye,m_coordinate_contr_ini.ze);
}

void clikRos::putDowndMnipulator()
{
    if (!on_off_manipulator_flag_ && !coordinate_flag_ && (manipulator_mode != mod_shrink))
    {
        /* 放下机械臂，不协调*/
        first_off_manipulator = true;
        last_off_manipulator =  ros::Time::now();
        manipulator_mode = mod_shrink;
    }
    if (first_off_manipulator && (ros::Time::now() - last_off_manipulator > ros::Duration(1.0)))
    {
       
        first_off_manipulator = false;
        Delta_mode.request.mode = 0;

        // 发送模式指令
        if (manipulator_client.call(Delta_mode)&&Delta_mode.response.result)
        {
            ROS_INFO("CLIK: Manipulator is off;");
        }
    }
}

void clikRos::putUpMnipulator()
{
    if (on_off_manipulator_flag_&&!coordinate_flag_ && !(manipulator_mode==mod_prepare) )
    {
        //收起机械臂， 不协调
        first_on_manipulator = true;
        last_on_manipulator =  ros::Time::now();
        manipulator_mode = mod_prepare; 
    }

    if (first_on_manipulator && (ros::Time::now() - last_on_manipulator > ros::Duration(1.0)))
    {
        first_on_manipulator = false;
        Delta_mode.request.mode = 1;
        
        // 发送模式指令
        if (manipulator_client.call(Delta_mode)&&Delta_mode.response.result)
        {
            ROS_INFO("CLIK: Manipulator is on;");
        }
    }
}

// void clikRos::Gripper_control()
// {
//     if (gripper_switch_ )
//     {
//         Gripper_mode.request.mode = 1;
//         // 发送模式指令
//         if (gripper_client.call(Gripper_mode) && Gripper_mode.response.result);
//         // {
            
//         //     ROS_INFO("CLIK: Gripper is true;");
//         // } 
//     }
//     else{
//         Gripper_mode.request.mode = 0;
//         // 发送模式指令
//         if (gripper_client.call(Gripper_mode) && Gripper_mode.response.result);
//         // {
//         //     ROS_INFO("CLIK: Gripper is false;");
//         // } 
//     }
// }

void clikRos::handlePainting()
{
   if (m_rcin_.channels.size()>=8 && m_rcin_.channels.at(7)>1600)
    {
        if (state_rc_1 == 0)
        {
            state_rc_1 = 1;
            state_rc_2 = 0;
            result_serial.data = "0001"; 
            write_pub.publish(result_serial); 
        }
    }
    else if ( m_rcin_.channels.size()>=8 && m_rcin_.channels.at(7) < 1600 &&  state_rc_2 == 0)
    {
        state_rc_1 = 0;
        state_rc_2 = 1;
        result_serial.data = "0000"; 
        write_pub.publish(result_serial);
    }

}
void clikRos::safeFlight(geometry_msgs::PoseStamped& pose_)
{
    if (pose_.pose.position.x < flight_lower_bound_[0])
    {
        pose_.pose.position.x = flight_lower_bound_[0];
    }
    if (pose_.pose.position.x > flight_upper_bound_[0])
    {
        pose_.pose.position.x = flight_upper_bound_[0];
    }
    if (pose_.pose.position.y < flight_lower_bound_[1])
    {
        pose_.pose.position.y = flight_lower_bound_[1];
    }
    if (pose_.pose.position.y > flight_upper_bound_[1])
    {
        pose_.pose.position.y = flight_upper_bound_[1];
    }
    if (pose_.pose.position.z < flight_lower_bound_[2])
    {
        pose_.pose.position.z = flight_lower_bound_[2];
    }
    if (pose_.pose.position.z > flight_upper_bound_[2])
    {
        pose_.pose.position.z = flight_upper_bound_[2];
    }
}

void clikRos::safeManipulator(clik::position_pub& delta_)
{
    if (delta_.X < delta_lower_bound_[0])
    {
        delta_.X = delta_lower_bound_[0];
    }
    if (delta_.X > delta_upper_bound_[0])
    {
        delta_.X = delta_upper_bound_[0];
    }
    if (delta_.Y < delta_lower_bound_[1])
    {
        delta_.Y = delta_lower_bound_[1];
    }
    if (delta_.Y > delta_upper_bound_[1])
    {
        delta_.Y = delta_upper_bound_[1];
    }
    if (delta_.Z < delta_lower_bound_[2])
    {
        delta_.Z = delta_lower_bound_[2];
    }
    if (delta_.Z > delta_upper_bound_[2])
    {
        delta_.Z = delta_upper_bound_[2];
    }
}

void clikRos::checkArmingState()
{
    if(!current_state.armed && !reset_CLIK_flag_)
    {
        reset_CLIK_flag_ = true;
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
    DCM_mani2body<< sin(yaw_offset),cos(yaw_offset),0.0,cos(yaw_offset),sin(yaw_offset),0.0,0.0,0.0,-1.0;
    std::cout << DCM_mani2body << std::endl;
    p_body = DCM_mani2body*p_mani + dOffset;
}

void  clikRos::coordinateBody2Manipulator(const Eigen::Vector3d& p_body , Eigen::Vector3d& p_mani )
{
    Eigen::Matrix3d DCM_mani2body;
    DCM_mani2body<< sin(yaw_offset),cos(yaw_offset),0.0,cos(yaw_offset),sin(yaw_offset),0.0,0.0,0.0,-1.0;
    p_mani = DCM_mani2body.transpose()*(p_body - dOffset);
}
void clikRos::handleCoordinate()
{
    Eigen::Vector3d  pb_end ;
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
        resetCoordinateIni();//在这里要改变起CLIK的初值
        //  设置协调状态
        coordinate_running_flag_ = true;
        last_time = ros::Time::now() ; // 初始化上一步计算时间
        now_time  = ros::Time::now() ; // 初始化这一步计算时间        ser.setPort("/dev/serial"); 
    
        test_begin = ros::Time::now() ;
        

        // 把 Delta机械臂放置在和合适的位置
        Delts_cont.time_stamp = now_time;
        Delts_cont.X =  0.0;
        Delts_cont.Y =  0.0;
        Delts_cont.Z = -0.14;
        // safeManipulator(Delts_cont); 
        Delta_pub.publish(Delts_cont);
        LOGFMTD("\t%s\t%f\t", "Peb_cmd_x", Delts_cont.X);
        LOGFMTD("\t%s\t%f\t", "Peb_cmd_y", Delts_cont.Y);
        LOGFMTD("\t%s\t%f\t", "Peb_cmd_z", Delts_cont.Z);
        CLIK_Obj.setIntergrate(Eigen::Vector3d(Delts_cont.X,Delts_cont.Y,Delts_cont.Z));
    }

    // if (1)
    if (coordinate_running_flag_)
    {

        // 轨迹生成的结果，按照时间调用 
        traj_out_srv.request.times = ros::Time::now();
        if (!traj_out_client.call(traj_out_srv))
        {
            ROS_INFO("Trajectory of quadcopter cannot be obtained.");// 
        }
        pose.pose.position.x = traj_out_srv.response.x;
        pose.pose.position.y =  - traj_out_srv.response.y;
        pose.pose.position.z =  - traj_out_srv.response.z;
        pose.pose.orientation.x = 0;
        pose.pose.orientation.y = 0;
        pose.pose.orientation.z = 0;
        pose.pose.orientation.w = 1;

        // // 安全限制
        safeFlight(pose);
        local_pos_pub.publish(pose);
        LOGFMTD("\t%s\t%f\t", "Pb_cmd_x", pose.pose.position.x);
        LOGFMTD("\t%s\t%f\t", "Pb_cmd_y", pose.pose.position.y);
        LOGFMTD("\t%s\t%f\t", "Pb_cmd_z", pose.pose.position.z);
        LOGFMTD("\t%s\t%f\t", "Pb_x", flightStateData.x);
        LOGFMTD("\t%s\t%f\t", "Pb_y", flightStateData.y);
        LOGFMTD("\t%s\t%f\t", "Pb_z", flightStateData.z); 

        end_out_srv.request.times = ros::Time::now();
        if (!end_out_client.call(end_out_srv))
        {
            ROS_INFO("Trajectory of end-effector cannot be obtained.");// 
        }

        // if(1)
        if(end_out_srv.response.flag_begin)
        {

            // 时间差
            now_time = ros::Time::now();
            double dt = now_time.toSec() - last_time.toSec();
            dt = dt > 0.05? 0.05:dt;
            CLIK_Obj.CLIK_U.dtime = dt;
            last_time = now_time;

            /* 协调*/
            // 处理算法的输入
            // double rr = 0.06;
            // double ttttt = now_time.toSec() - test_begin.toSec();
            // Eigen::Vector3d temp_n(rr*cos(ttttt),rr*sin(ttttt),0);
            CLIK_Obj.CLIK_U.point_e_des =  Eigen::Vector3d(end_out_srv.response.x, end_out_srv.response.y, end_out_srv.response.z);//m_coordinate_contr_ini.pe + temp_n;//
            CLIK_Obj.CLIK_U.point_e_des_dot =  Eigen::Vector3d(end_out_srv.response.dx, end_out_srv.response.dy, end_out_srv.response.dz);// Eigen::Vector3d(0,0,0);//
            CLIK_Obj.CLIK_U.angular_vel_base[0] = flightStateData.wx;
            CLIK_Obj.CLIK_U.angular_vel_base[1] = flightStateData.wy;
            CLIK_Obj.CLIK_U.angular_vel_base[2] = flightStateData.wz;
            // vicon环境下无法获取速度,使用速度指令 
            CLIK_Obj.CLIK_U.vel_base[0] =traj_out_srv.response.dx;//  
            CLIK_Obj.CLIK_U.vel_base[1] = traj_out_srv.response.dy;// 
            CLIK_Obj.CLIK_U.vel_base[2] = traj_out_srv.response.dz;// 
            Eigen::Vector3d pe_3d,pb_3d,peb_3d;
            pe_3d(0) = pe[0];
            pe_3d(1) = pe[1];
            pe_3d(2) = pe[2];
            peb_3d(0) = flightStateData.x;
            peb_3d(1) = flightStateData.y;
            peb_3d(2) = flightStateData.z;
            CLIK_Obj.CLIK_U.point_b = peb_3d;
            CLIK_Obj.CLIK_U.point_e = pe_3d;
            Eigen::Matrix3d rotation  = Eigen::Matrix3d::Identity();
            Eigen::Vector3d euler;
            euler(0) = flightStateData.phi;
            euler(1) = flightStateData.theta;
            euler(2) = flightStateData.psi;
            euler_to_rotation(euler,rotation);
            peb_3d = rotation.transpose()*(pe_3d-peb_3d);
            CLIK_Obj.CLIK_U.rotation = rotation;
            CLIK_Obj.CLIK_U.point_e_b = peb_3d;

            
            LOGFMTD("\t%s\t%f\t", "Pe_x", pe[0]);
            LOGFMTD("\t%s\t%f\t", "Pe_y", pe[1]);
            LOGFMTD("\t%s\t%f\t", "Pe_z", pe[2]);
            LOGFMTD("\t%s\t%f\t", "Pe_b_x", peb_3d[0]);
            LOGFMTD("\t%s\t%f\t", "Pe_b_y", peb_3d[1]);
            LOGFMTD("\t%s\t%f\t", "Pe_b_z", peb_3d[2]);
            Eigen::Vector3d ped_temp;
            coordinateBody2Manipulator(peb_3d, ped_temp);
            LOGFMTD("\t%s\t%f\t", "Pe_d_x", ped_temp[0]);
            LOGFMTD("\t%s\t%f\t", "Pe_d_y", ped_temp[1]);
            LOGFMTD("\t%s\t%f\t", "Pe_d_z", ped_temp[2]);

            

            LOGFMTD("\t%s\t%f\t", "Pe_cmd_x", CLIK_Obj.CLIK_U.point_e_des[0]);
            LOGFMTD("\t%s\t%f\t", "Pe_cmd_y", CLIK_Obj.CLIK_U.point_e_des[1]);
            LOGFMTD("\t%s\t%f\t", "Pe_cmd_z", CLIK_Obj.CLIK_U.point_e_des[2]);
  

            // 求解 
            CLIK_Obj.clik_solver();        
            
            LOGFMTD("\t%s\t%f\t", "Vb_x", CLIK_Obj.CLIK_U.vel_base[0]);
            LOGFMTD("\t%s\t%f\t", "Vb_y", CLIK_Obj.CLIK_U.vel_base[1]);
            LOGFMTD("\t%s\t%f\t", "Vb_z", CLIK_Obj.CLIK_U.vel_base[2]); 

            Eigen::Vector3d d3p_e_d_des;
            CLIK_Obj.getCLIKOut(d3p_e_d_des);
            // 安全限制
            
            Delts_cont.time_stamp = now_time;
            Delts_cont.X =  d3p_e_d_des(0);
            Delts_cont.Y =  d3p_e_d_des(1);
            Delts_cont.Z = d3p_e_d_des(2);
            safeManipulator(Delts_cont); 
            Delta_pub.publish(Delts_cont);
            LOGFMTD("\t%s\t%f\t", "Peb_cmd_x", Delts_cont.X);
            LOGFMTD("\t%s\t%f\t", "Peb_cmd_y", Delts_cont.Y);
            LOGFMTD("\t%s\t%f\t", "Peb_cmd_z", Delts_cont.Z);
        }
        else
        {
            // 把 Delta机械臂放置在和合适的位置
            Delts_cont.time_stamp = now_time;
            Delts_cont.X =  0.0;
            Delts_cont.Y =  0.0;
            Delts_cont.Z = -0.22;
            safeManipulator(Delts_cont); 
            Delta_pub.publish(Delts_cont);
            LOGFMTD("\t%s\t%f\t", "Peb_cmd_x", Delts_cont.X);
            LOGFMTD("\t%s\t%f\t", "Peb_cmd_y", Delts_cont.Y);
            LOGFMTD("\t%s\t%f\t", "Peb_cmd_z", Delts_cont.Z);
            CLIK_Obj.setIntergrate(Eigen::Vector3d(Delts_cont.X,Delts_cont.Y,Delts_cont.Z));
        }
        
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

    /*--------- 机械臂操作--------- */
    // 机械臂的收放
    // 这里有三种情况，不协调（放）、不协调（收）、协调
    // 放下机械臂 根据指令来执行
    putDowndMnipulator();
    // 收机械臂
    putUpMnipulator();
    // 修补剂操作
    handlePainting();
    // 机械爪收放判断
    // gripper_switch_ = isGripper(m_rcin_);
    // Gripper_control();
    /*--------- 协调控制--------- */
    // 协调控制开始
    if (coordinate_flag_  && (ros::Time::now() - last_coordinate > ros::Duration(1.0)))// 地面调试
    handleCoordinate();
}