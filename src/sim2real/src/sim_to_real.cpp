#include "sim_to_real.h"

sim2realclass::sim2realclass()
{
    // 【订阅】机械臂末端位置 ENU
    //  本话题来自gazebo
    EndEffector_sub_ = nh.subscribe<nav_msgs::Odometry>("/ground_truth/position_end_effc", 10, &sim2realclass::endEffector_obtain,this);
    // 【订阅】遥控器指令 
    //  本话题来自joy_node
    RC_sub_ = nh.subscribe<sensor_msgs::Joy>("/joy", 10, &sim2realclass::rc_obtain, this);
    // 【发布】机械臂末端位置 ENU
    EndEffector_pub_ = nh.advertise<geometry_msgs::TransformStamped>("vicon/Delta/Delta", 10); 
    // 【发布】遥控器指令
    RC_pub_= nh.advertise<mavros_msgs::OverrideRCIn>("mavros/rc/override", 10); 
    //接收控上位机控制指令
    cmd_mod_sub_ = nh.advertiseService("control_signal/command_mode",  &sim2realclass::cmd_mode_Callback, this);
    // 接受上位机机械爪控制指令
    cmd_gripper_mod_sub_ = nh.subscribe("/chatter_tool", 10, &sim2realclass::cmd_gripper_Callback, this);  
   //接收位置指令
    cmd_pos_sub_ =nh.subscribe("/control_signal/pos_pub", 10,  &sim2realclass::cmd_pos_Callback, this); 
    // 发送末端位置指令
    endEffe_traj_pub_  = nh.advertise<geometry_msgs::Point>("/traj/rel_posi", 1); 
    // 发送gripper指令
    gripper_cmd_pub_  = nh.advertise<sim2real::gripper_cmd>("/gripper_cmd", 1);   //发布了但没有使用
  	joint_gripper_gazebo_pub1 = nh.advertise<std_msgs::Float32>("/joint/gripper1_1/position_cmd", 10);
  	joint_gripper_gazebo_pub2 = nh.advertise<std_msgs::Float32>("/joint/gripper1_2/position_cmd", 10);
    // 设置DELTA关节初始值
    traj_endEffe_.x = 0;
    traj_endEffe_.y = 0;
    traj_endEffe_.z = -0.35;
    endEffe_traj_pub_.publish(traj_endEffe_);
}

void sim2realclass::setInitJoint()
{
  traj_endEffe_.x = 0;
  traj_endEffe_.y = 0;
  traj_endEffe_.z = -0.35;
  endEffe_traj_pub_.publish(traj_endEffe_);
}

// 【回调函数】 机械臂末端位置 
void  sim2realclass::rc_obtain(const sensor_msgs::Joy::ConstPtr &msg)
{
  for(int i = 0;  i<7; i++)
  {
    uint16_t  uu = 1500 - msg->axes[i] *500;
    RC_Override_.channels.at(i) = uu;
  }
  for(int i = 0;  i<8; i++)
  {
    RC_Override_.channels[i+8] = 1400 + msg->buttons[i] *600;
  }
  RC_pub_.publish(RC_Override_);
}

// 【回调函数】 机械臂末端位置 
void  sim2realclass::endEffector_obtain(const nav_msgs::Odometry::ConstPtr &msg)
{
  endEffectorPosition_.transform.translation.x  = msg->pose.pose.position.x; 
  endEffectorPosition_.transform.translation.y  = msg->pose.pose.position.y; 
  endEffectorPosition_.transform.translation.z  = msg->pose.pose.position.z - 0.8; 
  endEffectorPosition_.transform.rotation  = msg->pose.pose.orientation; 
  EndEffector_pub_.publish(endEffectorPosition_);
}


//【回调函数】 接收上位机发送的控制指令->service
bool sim2realclass::cmd_mode_Callback(sim2real::cmd_mode::Request  &req,
         sim2real::cmd_mode::Response &res)
{
  if(req.mode==0 ||req.mode==1 || req.mode==2)
  {
    Mod_time_=ros::Time::now();
    res.result=1;
    Cmd_mode_=req.mode;
  }
  else
  {
    Mod_time_.sec=0;
    Mod_time_.nsec=0;
    Cmd_mode_=0;
    res.result=0;
  }
    switch(Cmd_mode_)
    {
      
      case mod_shrink:
        traj_endEffe_.x = 0;
        traj_endEffe_.y = 0;
        traj_endEffe_.z = -0.35;
        endEffe_traj_pub_.publish(traj_endEffe_);
        Cmd_mode_=mod_wait;
      break;
      case mod_prepare:
        traj_endEffe_.x = 0;
        traj_endEffe_.y = 0;
        traj_endEffe_.z = -0.18;
        endEffe_traj_pub_.publish(traj_endEffe_);
        Cmd_mode_=mod_wait;
        break;
      case mod_control:
        break;
      case mod_wait:
        break;
    }

  return true;
}


//【回调函数】 接受上位机机械爪控制指令
void sim2realclass::cmd_gripper_Callback(const std_msgs::String::ConstPtr & msg)
{
  ROS_INFO("接收到的数据：%s", msg->data.c_str());
  if(msg->data[3] == '1'){       //gripper is close
    gripper_cmd_.gripper_left = -0.02;
    gripper_cmd_.gripper_right = 0.02;
    gripper_cmd_pub_.publish(gripper_cmd_);
  }
  else if((msg->data[3] == '0')){    //gripper is open
    gripper_cmd_.gripper_left = 0.02;
    gripper_cmd_.gripper_right = -0.02;
    gripper_cmd_pub_.publish(gripper_cmd_);
  }
  else
    ROS_INFO("gripper_server no right case");

  gripper1_.data = gripper_cmd_.gripper_left;
  joint_gripper_gazebo_pub1.publish(gripper1_);
  gripper2_.data = gripper_cmd_.gripper_right;
  joint_gripper_gazebo_pub2.publish(gripper2_);
}

//【回调函数】 接收位置指令
void sim2realclass::cmd_pos_Callback(const sim2real::position_pub::ConstPtr& msg1)
{
  //工作空间限位 xmin,xmax,ymin,ymax,zmin,zmax
  float workspace[6]={-0.08,0.08,-0.08,0.08,-0.40,-0.120};
  traj_endEffe_.x=msg1->X<workspace[0]?workspace[0]:(msg1->X>workspace[1]?workspace[1]:msg1->X);
  traj_endEffe_.y=msg1->Y<workspace[2]?workspace[2]:(msg1->Y>workspace[3]?workspace[3]:msg1->Y);
  traj_endEffe_.z=msg1->Z<workspace[4]?workspace[4]:(msg1->Z>workspace[5]?workspace[5]:msg1->Z);
  endEffe_traj_pub_.publish(traj_endEffe_);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "sim2real");
    ros::NodeHandle sim_node;

    sim2realclass sim2real_obj;
    sim2real_obj.setInitJoint();

    ros::spin();
    return 0;
}