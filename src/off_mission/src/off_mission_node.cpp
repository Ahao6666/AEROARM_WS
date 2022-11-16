
#include "off_mission_node.h"

TaskManager::TaskManager()
{
    /* subscriptions and publications */
    m_rcin_sub_ = nh.subscribe<mavros_msgs::RCIn>("/mavros/rc/in", 10,&TaskManager::rcinCallback,this);
    state_sub = nh.subscribe<mavros_msgs::State>("mavros/state", 10, &TaskManager::state_cb,this);
    //ros::Subscriber local_vel_sub  = nh.subscribe("mavros/local_position/velocity", 10, local_vel_cb);
    response_sub  = nh.subscribe("navigator/vehicle_action_response", 5,&TaskManager::response_cb,this);
    local_pose_sub = nh.subscribe<geometry_msgs::PoseStamped>
            ("mavros/local_position/pose", 10, &TaskManager::local_pose_cb,this);
    online_target_sub_ = nh.subscribe("online_target", 10, &TaskManager::onlineTarget_cb, this);  // 这是飞虎那边给的在线跟踪的接口，可以直接通过这个来给

    action_pub = nh.advertise<navigator::action>("navigator/vehicle_action",2);
    pos_nav_pub = nh.advertise<geometry_msgs::PoseStamped>("navigator/pos_nav",2);
    local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>("mavros/setpoint_position/local", 10);
    set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("mavros/set_mode");
    offb_set_mode.request.custom_mode = "OFFBOARD"; // AUTO.LAND
    offboard_sent_flag_ = false ;
    last_request = ros::Time::now();

    /*params*/
    ros::NodeHandle private_nh("~");
    private_nh.param("takeoff_height", takeoff_height, 1.0);
    
    private_nh.param("nav_acc_radius", _nav_acc_radius, 0.5);
    private_nh.param("nav_acc_angle", _nav_acc_angle, 0.1);
    private_nh.param("uav_id", uav_id, 1);

    // load yaml files
    private_nh.getParam("waypoints",wp_list);
    
    resetOffMission();
    initTagetVector(wp_list);

    // test_flag = true;
    online_triger_flag = 0;
}

TaskManager::~TaskManager()
{

}
void TaskManager::checkArmingState()
{
    if(!current_state.armed && !reset_off_mission_flag_)
    {
        reset_off_mission_flag_ = true;
        ROS_INFO("Disarmed! Will restart the mission next time armed!\n");
    }
    if(current_state.armed && reset_off_mission_flag_)
    {
        reset_off_mission_flag_ = false;
        ROS_INFO("First time to Arm");
        resetOffMission();
    }
}

void TaskManager::resetOffMission()
{

  _current_wpindex = 0;
  m_online_offline_flag_ = 0;
  current_waypoint_published_flag_ = false;
  takeoff_finished_flag = false;
  takeoff_rc_flag = false;

  all_waypoint_reached_flag_ = false; 
  resetOnGroundOrigin();
}

void TaskManager::mainLoop()
{
    // If first time arm, reset whole mission
    checkArmingState();
    // Set relative origin, taking local position drift into account
    if(!ground_origin_position_initialized_flag_ )
    // if(!test_flag )
    {
        setOnGroundOrigin();
        return;
    }

    setOffboardMode();

    /********IDLE, TAKEOFF, HOVE, PATH, LAND ************/

    // Case IDLE: while no OFFBOARD RC INPUT
    if (!isOffboardSwitchOn(m_rcin_) || cur_response.finished_behavior == LAND) 
    // if(!test_flag )
    {   
        if ( setBehaviorIDLE() )     
            offboard_sent_flag_ = false;
    }    
    
    // Case TAKEOFF & HOVER: First Time is TAKEOFF, the rest is HOVER
    if (isOffboardSwitchOn(m_rcin_) && isSwitchTakeoffHover(m_rcin_)) 
    // if(!test_flag )
    {
      if (!takeoff_rc_flag) 
      {
        if ( setBehaviorTAKEOFF(takeoff_height) ) 
        {
          takeoff_rc_flag = true;
        }
      }
      if (cur_response.finished_behavior == TAKEOFF && !takeoff_finished_flag) 
      {
        takeoff_finished_flag = true;
      }
      if (takeoff_finished_flag && takeoff_rc_flag) 
      {
        setBehaviorHOVER();
      }
    }

    // Case: PATH: online or offline waypoint
    if(/*takeoff_finished_flag && */isOffboardSwitchOn(m_rcin_) && isSwitchPath(m_rcin_) && takeoff_rc_flag)
    // if(test_flag )
    {  
        setBehaviorOnLine();
        if (online_triger_flag)
        {
            handle_online_flight();
        }
        else if ( !all_waypoint_reached_flag_ )
        {
            if( setBehaviorPATH() )
            {
            	takeoff_finished_flag = true; // Once switched to PATH, change TAKEOFF to HOVER
            }
            handle_waypoint_flight();
        }
        else
        {

        }
    }

    // Case: LAND
    if (/*takeoff_finished_flag && */isOffboardSwitchOn(m_rcin_) && isSwitchLand(m_rcin_) && takeoff_rc_flag)
    // if(!test_flag )
    {
        if ( setBehaviorLAND() )
        {
          takeoff_finished_flag = true; // enable hover once go to land position once
          offboard_sent_flag_   = false; // indicate offboard not sent 
        }
    }

}

void TaskManager::initTagetVector(XmlRpc::XmlRpcValue &wp_list)
{
    waypoints.clear();
    geometry_msgs::PoseStamped tempPose;

    for (size_t i = 0; i < wp_list.size(); i++)
    {
        tempPose.header.seq = i;
        XmlRpc::XmlRpcValue data_list(wp_list[i]);

        // get position
        tempPose.pose.position.x = data_list[0];
        tempPose.pose.position.y = data_list[1];
        tempPose.pose.position.z = data_list[2];

        // get orientation
        tf::Quaternion q = tf::createQuaternionFromYaw(data_list[3]);

        tf::quaternionTFToMsg(q, tempPose.pose.orientation);
        waypoints.push_back(tempPose);
        // ROS_INFO("tempPose.pose.position.x  %f ", tempPose.pose.position.x);
        ROS_INFO("waypoints x y z c  %f %f %f %f ",waypoints.at(i).pose.position.x,
                                                   waypoints.at(i).pose.position.y,
                                                   waypoints.at(i).pose.position.z,
                                                   tf::getYaw(waypoints.at(i).pose.orientation));

    }

     ROS_INFO("Loaded waypoint size is %d ", (int)waypoints.size());
}

void TaskManager::onlineTarget_cb(const geometry_msgs::PoseStamped::ConstPtr& msg)
{
    
    m_online_target_ = *msg;
    m_online_offline_flag_ = 1; 
    online_time_save = ros::Time::now();
} 
void TaskManager::handle_online_flight()
{
    // float current_yaw;
    // float new_online_target_x;
    // float new_online_target_y;
    // current_yaw = tf::getYaw(current_local_pos.pose.orientation);
    // new_online_target_x = m_online_target_.pose.position.x * cos(current_yaw) - m_online_target_.pose.position.y * sin(current_yaw);
    // new_online_target_y = m_online_target_.pose.position.x * sin(current_yaw) + m_online_target_.pose.position.y * cos(current_yaw);
    // pose_nav.pose.position.x  = current_local_pos.pose.position.x + new_online_target_x;
    // pose_nav.pose.position.y  = current_local_pos.pose.position.y + new_online_target_y;
    // pose_nav.pose.position.z  = current_local_pos.pose.position.z;
    // pose_nav.pose.orientation = current_local_pos.pose.orientation;
    // // pose_nav.pose.position.x = current_local_pos.pose.position.x + m_online_target_.pose.position.x;
    // // pose_nav.pose.position.y = current_local_pos.pose.position.y + m_online_target_.pose.position.y;
    pos_nav_pub.publish(m_online_target_);
}

void TaskManager::handle_waypoint_flight()
{
    
    if( !online_triger_flag) 
    {
        if( _current_wpindex < waypoints.size() ) 
        {    
            if(!current_waypoint_published_flag_ )
            {    
                pose_nav.pose.position.x = waypoints.at(_current_wpindex).pose.position.x;
                pose_nav.pose.position.y = waypoints.at(_current_wpindex).pose.position.y;
                pose_nav.pose.position.z = waypoints.at(_current_wpindex).pose.position.z;
                pose_nav.pose.orientation = waypoints.at(_current_wpindex).pose.orientation;
                
                // addRefOrigin(&pose_nav);  // add origin bias for position drift
                pos_nav_pub.publish(pose_nav);
                current_waypoint_published_flag_ = true;
            }
        
            if(cur_response.finished_behavior == WAYPOINT_FLIGHT && cur_response.behavior_finished)
            {
                cur_response.behavior_finished = false;
                _current_wpindex++;
                current_waypoint_published_flag_ = false;
                ROS_INFO("_current_wpindex++ is %d ", _current_wpindex);
            }
        }
        else
        {
            all_waypoint_reached_flag_ = true; 
        }
    }   
}


void TaskManager::clear_switch_flags_except(int behavior)
{

    for(int i = 0 ; i < MAX_BEHAVIOR_NO ; i++ )
    {
        if (i != behavior)
        init_switch_flags[i] = false;
        
    }
}


void TaskManager::setOnGroundOrigin()
{
     m_ref_origin_.pose.position.x = current_local_pos.pose.position.x;
     m_ref_origin_.pose.position.y = current_local_pos.pose.position.y;
     m_ref_origin_.pose.position.z = current_local_pos.pose.position.z;
     ground_origin_position_initialized_flag_ = true;
     ROS_INFO("refernce origin set at position x  %f y  %f z %f " , m_ref_origin_.pose.position.x , 
                                                                       m_ref_origin_.pose.position.y , 
                                                                       m_ref_origin_.pose.position.z);
}

void TaskManager::resetOnGroundOrigin()
{
    ground_origin_position_initialized_flag_ = false;
    origin_counter  = 0;
    m_ref_origin_.pose.position.x = 0;
    m_ref_origin_.pose.position.y = 0;
    m_ref_origin_.pose.position.z = 0;
}

void TaskManager::addRefOrigin(geometry_msgs::PoseStamped  *ref)
{
    ref->pose.position.x = ref->pose.position.x + m_ref_origin_.pose.position.x;
    ref->pose.position.y = ref->pose.position.y + m_ref_origin_.pose.position.y;
    ref->pose.position.z = ref->pose.position.z + m_ref_origin_.pose.position.z;
}

/********************** Behavior related functions **********************/

bool TaskManager::setBehaviorIDLE()
{
  if (!init_switch_flags[IDLE]) 
  {
    cur_action.behavior = IDLE;
    cur_action.uav_id = uav_id;
    cur_action.params.clear();
    action_pub.publish(cur_action);
    init_switch_flags[IDLE] = true;
    ROS_INFO("IT'S IDLE");
    ROS_INFO("---------------");
    clear_switch_flags_except(IDLE);
    return true;
  }
  else
    return false;
}

bool TaskManager::setBehaviorTAKEOFF(double height)
{
  if (!init_switch_flags[TAKEOFF]) 
  {
    cur_action.behavior = TAKEOFF;
    cur_action.params.clear();
    cur_action.params.push_back(height);
    action_pub.publish(cur_action);
    init_switch_flags[TAKEOFF] = true;
    ROS_INFO("IT'S TAKEOFF");
    ROS_INFO("---------------");
    clear_switch_flags_except(TAKEOFF);
    return true;
  }
  else
    return false;
}

bool TaskManager::setBehaviorHOVER() 
{
  if (!init_switch_flags[HOVER]) 
  {
    cur_action.behavior = HOVER;
    cur_action.params.clear();
    action_pub.publish(cur_action);
    init_switch_flags[HOVER] = true;
    ROS_INFO("IT'S HOVER");
    ROS_INFO("---------------");
    clear_switch_flags_except(HOVER);
    return true;
  }
  else 
    return false;
}

bool TaskManager::setBehaviorLAND() 
{
  if (!init_switch_flags[LAND]) 
  {
    cur_action.behavior = LAND;
    cur_action.params.clear();
    action_pub.publish(cur_action);
    init_switch_flags[LAND] = true;
    ROS_INFO("IT'S LAND");
    ROS_INFO("---------------");
    clear_switch_flags_except(LAND);
    return true;
  }
  else
    return false;
}
void TaskManager::setBehaviorOnLine() {
    if (!online_triger_flag && m_online_offline_flag_ && ((ros::Time::now() - online_time_save)<ros::Duration(1)))
    { 
        ROS_INFO("XXXX11\n");
        cur_action.behavior = WAYPOINT_FLIGHT;
        cur_action.params.clear();
        cur_action.onlineflag = m_online_offline_flag_;
        cur_action.params.push_back(_nav_acc_radius);
        cur_action.params.push_back(_nav_acc_angle);
        current_waypoint_published_flag_ = false;
        action_pub.publish(cur_action);   
        online_triger_flag = true;
    }
    if (online_triger_flag && m_online_offline_flag_ && ((ros::Time::now() - online_time_save)>ros::Duration(1)))
    {
        ROS_INFO("XXXXX22\n");
        online_triger_flag = false;
        cur_action.behavior = WAYPOINT_FLIGHT;
        cur_action.params.clear();
        cur_action.onlineflag = 0;
        cur_action.params.push_back(_nav_acc_radius);
        cur_action.params.push_back(_nav_acc_angle);
        current_waypoint_published_flag_ = false;
        action_pub.publish(cur_action);
        init_switch_flags[WAYPOINT_FLIGHT] = true;
        clear_switch_flags_except(WAYPOINT_FLIGHT); 
        all_waypoint_reached_flag_ = false; 
        _current_wpindex = 1;
    }
}


bool TaskManager::setBehaviorPATH() 
{
  if (!init_switch_flags[WAYPOINT_FLIGHT]) 
  {
    cur_action.behavior = WAYPOINT_FLIGHT;
    cur_action.params.clear();
    cur_action.onlineflag = 0;
    cur_action.params.push_back(_nav_acc_radius);
    cur_action.params.push_back(_nav_acc_angle);
    current_waypoint_published_flag_ = false;
    //initTagetVector(wp_list);
    action_pub.publish(cur_action);
    init_switch_flags[WAYPOINT_FLIGHT] = true;
    clear_switch_flags_except(WAYPOINT_FLIGHT);

    ROS_INFO("IT'S WAYPOINT_FLIGHT");
    ROS_INFO("Current waypoint index %d", _current_wpindex);
    ROS_INFO("---------------");

    return true;
  }
  else
    return false;
}

/* set offboard in any of the two conditions
* 1. first enter offboard by rc;
* 2. switch from AUTO.LAND to Offboard while landing
*/ 
void TaskManager::setOffboardMode()
{
    if ( checkEnterOffboardByRcSwitch() ||
            (isOffboardSwitchOn(m_rcin_) && !isSwitchLand(m_rcin_) && !offboard_sent_flag_ ) )
    {
      if( set_mode_client.call(offb_set_mode) && offb_set_mode.response.mode_sent)
       {
          ROS_INFO("First Time Offboard enabled by SetMode");
          offboard_sent_flag_ = true;
       }
       last_request = ros::Time::now();            
    }

    if (current_state.mode != "OFFBOARD" 
            && ros::Time::now() - last_request > ros::Duration(5.0) 
            && !isSwitchLand(m_rcin_)
            && isOffboardSwitchOn(m_rcin_)
            && !all_waypoint_reached_flag_)
    {
       if( set_mode_client.call(offb_set_mode) && offb_set_mode.response.mode_sent)
        {
             ROS_INFO("Offboard enabled by SetMode");
        }
        last_request = ros::Time::now();
    }
}
