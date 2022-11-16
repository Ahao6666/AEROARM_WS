#include "navigator.h"
#include <string>
#include <tf/transform_datatypes.h>

Navigator::Navigator():
wp_flag(false)
{
    /*subscriptions & publications*/

    action_sub = node_.subscribe<navigator::action>("navigator/vehicle_action",2,&Navigator::vehicle_action_callback,this); 
    state_sub = node_.subscribe<mavros_msgs::State>
            ("mavros/state", 10, &Navigator::state_cb,this);
    landstate_sub = node_.subscribe<mavros_msgs::ExtendedState>
            ("mavros/extended_state",5, &Navigator::extendedstate_cb,this);
    imu_sub = node_.subscribe<sensor_msgs::Imu>
            ("mavros/imu/data", 5, &Navigator::imu_cb,this);
    
    local_pose_sub = node_.subscribe<geometry_msgs::PoseStamped>
            ("mavros/local_position/pose", 10, &Navigator::local_pose_cb,this);

    global_position_sub = node_.subscribe<sensor_msgs::NavSatFix>
            ("mavros/global_position/global", 10, &Navigator::global_position_cb,this);

    // online_target_sub_ = node_.subscribe("online_target", 10,  &Navigator::onlineTarget_cb, this);
    pos_nav_sub_ = node_.subscribe("navigator/pos_nav", 10,  &Navigator::pos_nav_cb, this);
    
    local_pos_pub = node_.advertise<geometry_msgs::PoseStamped>("mavros/setpoint_position/local", 10);

    response_pub = node_.advertise<navigator::response>("navigator/vehicle_action_response", 5);

    set_mode_client = node_.serviceClient<mavros_msgs::SetMode>("mavros/set_mode");

    last_request = ros::Time::now();

}

Navigator::~Navigator()
{

}


void Navigator::mainLoop()
{

    switch (cur_action.behavior)
    {
        case IDLE:
            if(!init_switch_flags[IDLE])
            {
                ROS_INFO( "[Navigator] inside IDLE");
                init_switch_flags[IDLE] = true;
                clear_switch_flags_except(IDLE);
            }
            handle_idle();
        break;

        case TAKEOFF:
            if(!init_switch_flags[TAKEOFF])
            {
                ROS_INFO("[Navigator] inside TAKEOFF");            
                init_switch_flags[TAKEOFF] = true;
                clear_switch_flags_except(TAKEOFF);
            }
            handle_takeoff();
        break;

        case HOVER:
            if(!init_switch_flags[HOVER])
            {
                ROS_INFO("[Navigator] inside HOVER");               
                init_switch_flags[HOVER] = true;
                clear_switch_flags_except(HOVER);
            }
            handle_hover();
        break;

        case WAYPOINT_FLIGHT:
            if(!init_switch_flags[WAYPOINT_FLIGHT])
            {
                ROS_INFO( "[Navigator] inside WAYPOINT_FLIGHT");                
                init_switch_flags[WAYPOINT_FLIGHT] = true;
                clear_switch_flags_except(WAYPOINT_FLIGHT);
            }
            handle_waypoint_flight();
        break;

        case LAND:
            if(!init_switch_flags[LAND])
            {
                ROS_INFO("[Navigator] inside LAND");                
                init_switch_flags[LAND] = true;
                clear_switch_flags_except(LAND);
            }
            // handle_land();
            handle_land_auto();
        break;

        default:
             ROS_INFO("[navigator] unsupported behavior!");
        break;
    }
}

void Navigator::handle_idle()
{
//DO NOT CHANGE THE FUNCTION
    pose_ref.pose.position.x = 0;
    pose_ref.pose.position.y = 0;
    pose_ref.pose.position.z = 0;
    tf::Quaternion q = tf::createQuaternionFromYaw(0);
    tf::quaternionTFToMsg(q, pose_ref.pose.orientation);
    local_pos_pub.publish(pose_ref);

    if(!init_flags[IDLE])
    {

        init_flags[IDLE] = true;
        clear_flags_except(IDLE);

    }

}

void Navigator::handle_takeoff()
{
   
    if(!init_flags[TAKEOFF] )
    {
        
        pose_ref.pose.position.x = current_local_pos.pose.position.x;
        pose_ref.pose.position.y = current_local_pos.pose.position.y;
        pose_ref.pose.position.z = current_local_pos.pose.position.z + cur_action.params[0];
        pose_ref.pose.orientation = current_local_pos.pose.orientation;
        origin_local_pose_z = current_local_pos.pose.position.z;
        init_flags[TAKEOFF] = true;
       
        clear_flags_except(TAKEOFF);
        ROS_INFO("It is TAKEOFF");
        ROS_INFO(" current_local_pos %f,%f,%f,%f ",
                                        current_local_pos.pose.position.x,
                                        current_local_pos.pose.position.y,
                                        current_local_pos.pose.position.z,
                                        tf::getYaw(current_local_pos.pose.orientation));
        ROS_INFO(" pose_ref %f,%f,%f,%f ",
                                        pose_ref.pose.position.x,
                                        pose_ref.pose.position.y,
                                        pose_ref.pose.position.z,
                                        tf::getYaw(pose_ref.pose.orientation));
   
    }

    if (init_flags[TAKEOFF] && (fabs(pose_ref.pose.position.z - current_local_pos.pose.position.z) < 0.1))
    {
        ROS_INFO("this is current_local_pos z  %f, %f ",
        pose_ref.pose.position.z,current_local_pos.pose.position.z);
        report_task_finished(TAKEOFF);
        ROS_INFO(" TAKEOFF IS FINISHED");
        ROS_INFO("---------------");
    }

    local_pos_pub.publish(pose_ref);
    
}

void Navigator::handle_hover()
{
    
    if(!init_flags[HOVER])
    {
        pose_ref.pose.position.x = current_local_pos.pose.position.x;
        pose_ref.pose.position.y = current_local_pos.pose.position.y;
        pose_ref.pose.position.z = current_local_pos.pose.position.z;
        pose_ref.pose.orientation = current_local_pos.pose.orientation;
        init_flags[HOVER] = true;
        clear_flags_except(HOVER);
        report_task_finished(HOVER);
        ROS_INFO("IT IS HOVERING");
        ROS_INFO("at current_local_pos %f,%f,%f,%f ",
                                        current_local_pos.pose.position.x,
                                        current_local_pos.pose.position.y,
                                        current_local_pos.pose.position.z,
                                        tf::getYaw(current_local_pos.pose.orientation));
        ROS_INFO("---------------");

    }
    
    local_pos_pub.publish(pose_ref);
    
}

void Navigator::handle_waypoint_flight()
{
    if(!cur_action.onlineflag)
    {
        if(!init_flags[WAYPOINT_FLIGHT])
        {
            
            pose_ref.pose.position.x = pose_nav.pose.position.x;
            pose_ref.pose.position.y = pose_nav.pose.position.y;
            pose_ref.pose.position.z = pose_nav.pose.position.z;
            pose_ref.pose.orientation = pose_nav.pose.orientation;
            ROS_INFO("this is pose_ref x y z c  %f,%f,%f,%f ",pose_ref.pose.position.x,
                                                     pose_ref.pose.position.y,
                                                     pose_ref.pose.position.z,
                                                     tf::getYaw(pose_ref.pose.orientation));
            init_flags[WAYPOINT_FLIGHT] = true;
            wp_flag = false;
            clear_flags_except(WAYPOINT_FLIGHT);
            ROS_INFO("WAYPOINT_FLIGHT IS INITIALIZED");   
        } 

        local_pos_pub.publish(pose_ref);   
        updateWaypointIndex();
    }
    else
    {
        pose_ref.pose.position.x = pose_nav.pose.position.x;
        pose_ref.pose.position.y = pose_nav.pose.position.y;
        pose_ref.pose.position.z = pose_nav.pose.position.z;
        pose_ref.pose.orientation = pose_nav.pose.orientation;
        local_pos_pub.publish(pose_ref);
    }

    
    
}

void Navigator::handle_land()
{

    if(!init_flags[LAND])
    {
        pose_ref.pose.position.x = current_local_pos.pose.position.x;
        pose_ref.pose.position.y = current_local_pos.pose.position.y;
        pose_ref.pose.position.z = current_local_pos.pose.position.z - 200.0f;
        pose_ref.pose.orientation = current_local_pos.pose.orientation;

        ROS_INFO("IT IS LAND");
        ROS_INFO("this is current_local_pos %f,%f,%f,%f ",
        current_local_pos.pose.position.x,current_local_pos.pose.position.y,
        current_local_pos.pose.position.z,current_local_pos.pose.orientation);
        ROS_INFO("this is pose_ref %f,%f,%f,%f ",
        pose_ref.pose.position.x,pose_ref.pose.position.y,pose_ref.pose.position.z,pose_ref.pose.orientation);
            
        init_flags[LAND] = true;
        clear_flags_except(LAND);
    }
    
    local_pos_pub.publish(pose_ref);

    if (init_flags[LAND] && (fabs(current_local_pos.pose.position.z - origin_local_pose_z) < 0.1))
    {
        report_task_finished(LAND);
        ROS_INFO(" LAND IS FINISHED");
        ROS_INFO("---------------");

    }
  
}


void Navigator::handle_land_auto()
{

    if(!init_flags[LAND] || current_state.mode != "AUTO.LAND")
    {
        mavros_msgs::SetMode land_mode;
        land_mode.request.custom_mode = "AUTO.LAND"; // 
        if( ros::Time::now() - last_request > ros::Duration(0.5))
        {
           if( set_mode_client.call(land_mode) && land_mode.response.mode_sent)
           {
             init_flags[LAND] = true;
             clear_flags_except(LAND);
             ROS_INFO("AUTO.land_mode enabled");
           }
           last_request = ros::Time::now();
        }

        // ROS_INFO("IT IS Auto.LAND");   

        // dummy setpoint for switching back to Offboard again
        pose_ref.pose.position.x = current_local_pos.pose.position.x;
        pose_ref.pose.position.y = current_local_pos.pose.position.y;
        pose_ref.pose.position.z = current_local_pos.pose.position.z - 200.0f;
        pose_ref.pose.orientation = current_local_pos.pose.orientation;

    }
    
     local_pos_pub.publish(pose_ref);
    /*
    if (init_flags[LAND] && (fabs(current_local_pos.pose.position.z - origin_local_pose_z )< 0.1))
    {
        report_task_finished(LAND);
        ROS_INFO(" LAND IS FINISHED");
        ROS_INFO("---------------");

    }
    */
  
}

void Navigator::updateWaypointIndex()
{
    // index will be updated when the position is reached
    float dx = current_local_pos.pose.position.x - pose_nav.pose.position.x;
    float dy = current_local_pos.pose.position.y - pose_nav.pose.position.y;
    float dz = current_local_pos.pose.position.z - pose_nav.pose.position.z;
    float dtheta = tf::getYaw(current_local_pos.pose.orientation) - tf::getYaw(pose_nav.pose.orientation);
    float dist_sq = dx*dx+dy*dy+dz*dz; 
    if (sqrt(dist_sq) < cur_action.params[0] && dtheta < cur_action.params[1] && !wp_flag)
    {
        wp_flag = true;

        // init_flags[WAYPOINT_FLIGHT] = false;
        report_task_finished(WAYPOINT_FLIGHT);
        ROS_INFO("WAYPOINT_FLIGHT IS FINISED");
        ROS_INFO("---------------"); 
    }

}

void Navigator::clear_flags_except(int behavior)
{

    for(int i = 0 ; i < MAX_BEHAVIOR_NO ; i++ )
    {
        if (i != behavior)
        init_flags[i] = false;
    }

}

void Navigator::clear_switch_flags_except(int behavior)
{

    for(int i = 0 ; i < MAX_BEHAVIOR_NO ; i++ )
    {
        if (i != behavior)
        init_switch_flags[i] = false;
    }
}

void Navigator::report_task_finished(int behavior)
{
    cur_response.finished_behavior = behavior;
    cur_response.behavior_finished = true;
    cur_response.uav_id            = cur_action.uav_id;
    response_pub.publish(cur_response);
}



