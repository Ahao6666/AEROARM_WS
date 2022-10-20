#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/JointState.h>
#include <geometry_msgs/Point.h>


class RvizPort{
	public:
		RvizPort(int,char**);
	  	ros::NodeHandle nh_;

		ros::Publisher jointState_pub;

	  	void odom_cb(const nav_msgs::Odometry& msg);
	  	void odom_position_only_cb(const nav_msgs::Odometry& msg);
	  	void endEffe_cb(const nav_msgs::Odometry& msg);
	  	void jointState_cb(const geometry_msgs::Point& msg);

	  	ros::Subscriber odom_sub;
		ros::Subscriber odom_position_only_sub;
		ros::Subscriber endEffe_sub;
		ros::Subscriber jointState_sub;

		geometry_msgs::TransformStamped odom_trans;
		geometry_msgs::TransformStamped odom_position_only_trans;
		geometry_msgs::TransformStamped endEffe_trans;
		sensor_msgs::JointState jointStatePub;
    		geometry_msgs::Point jointState;
	  	nav_msgs::Odometry odom;

		tf::TransformBroadcaster odom_broadcaster;
		tf::TransformBroadcaster odom_positon_only_broadcaster;
		tf::TransformBroadcaster endEffe_broadcaster;
};


RvizPort::RvizPort(int argc, char** argv){
	jointStatePub.name={"FlyingDeltaArmBase__link_0_JOINT_1", "FlyingDeltaArmBase__link_0_JOINT_2", "FlyingDeltaArmBase__link_0_JOINT_3"};

	//Subscribers Initialization
  	//odom_sub = nh_.subscribe("mavros/local_position/odom", 1, &RvizPort::odom_cb, this);
  	odom_sub = nh_.subscribe("/ground_truth/positon_uav_up", 1, &RvizPort::odom_cb, this);
  	odom_position_only_sub = nh_.subscribe("/ground_truth/positon_uav_up", 1, &RvizPort::odom_position_only_cb, this);

  	endEffe_sub = nh_.subscribe("ground_truth/relative_pos", 1, &RvizPort::endEffe_cb, this);
  	jointState_sub = nh_.subscribe("/joint/rviz_joint_pos", 1, &RvizPort::jointState_cb, this);

	//Publishers Initialization
	jointState_pub = nh_.advertise<sensor_msgs::JointState>("joint_states", 1000);


}
void RvizPort::odom_cb(const nav_msgs::Odometry& msg){
	odom=msg;
	odom.header.frame_id = "map";
    	odom_trans.transform.translation.x = msg.pose.pose.position.x;
    	odom_trans.transform.translation.y = msg.pose.pose.position.y;
    	odom_trans.transform.translation.z = msg.pose.pose.position.z;
    	odom_trans.transform.rotation = msg.pose.pose.orientation;
}

void RvizPort::odom_position_only_cb(const nav_msgs::Odometry& msg){


    	odom_position_only_trans.transform.translation.x = msg.pose.pose.position.x;
    	odom_position_only_trans.transform.translation.y = msg.pose.pose.position.y;
    	odom_position_only_trans.transform.translation.z = msg.pose.pose.position.z;
    	odom_position_only_trans.transform.rotation.x = 0;
    	odom_position_only_trans.transform.rotation.y = 0;
    	odom_position_only_trans.transform.rotation.z = 0;
    	odom_position_only_trans.transform.rotation.w = 1;
}




void RvizPort::endEffe_cb(const nav_msgs::Odometry& msg){
    	endEffe_trans.transform.translation.x = msg.pose.pose.position.x-0.008;
    	endEffe_trans.transform.translation.y = msg.pose.pose.position.y-0.0388;
    	endEffe_trans.transform.translation.z = msg.pose.pose.position.z;
    	endEffe_trans.transform.rotation = msg.pose.pose.orientation;
}

void RvizPort::jointState_cb(const geometry_msgs::Point& msg){
	jointState.x = msg.x;
	jointState.y = msg.y;
	jointState.z = msg.z;
}



int main(int argc, char** argv){
  	ros::init(argc, argv, "odometry_publisher");
  	RvizPort rvizPort(argc, argv);
  	ros::Rate r(200);
  	while(ros::ok()){
   	ros::spinOnce();              
    	rvizPort.odom_trans.header.stamp = ros::Time::now();
    	rvizPort.odom_trans.header.frame_id = "map";
    	rvizPort.odom_trans.child_frame_id = "base_link";
    	rvizPort.odom_broadcaster.sendTransform(rvizPort.odom_trans);
    	rvizPort.odom_position_only_trans.header.stamp = ros::Time::now();
    	rvizPort.odom_position_only_trans.header.frame_id = "map";
    	rvizPort.odom_position_only_trans.child_frame_id = "base_link_position";
    	rvizPort.odom_positon_only_broadcaster.sendTransform(rvizPort.odom_position_only_trans);

    	rvizPort.endEffe_trans.header.stamp = ros::Time::now();
   	rvizPort.endEffe_trans.header.frame_id = "base_link";
    	rvizPort.endEffe_trans.child_frame_id = "FlyingDeltaArmBase__low_base";
    	rvizPort.endEffe_broadcaster.sendTransform(rvizPort.endEffe_trans);
    	rvizPort.odom.header.stamp = ros::Time::now();


//        rvizPort.jointStatePub.header.stamp = ros::Time::now();
//	rvizPort.jointStatePub.position = {rvizPort.jointState.x,rvizPort.jointState.y,rvizPort.jointState.z};
//	rvizPort.jointStatePub.velocity = {};
//	rvizPort.jointStatePub.effort = {};
//	rvizPort.jointState_pub.publish(rvizPort.jointStatePub);
	
    	r.sleep();
  }
}
