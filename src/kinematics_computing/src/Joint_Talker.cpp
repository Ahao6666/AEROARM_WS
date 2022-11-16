#include "InKinematics.h"

#define pi 3.14159265358979323846

int main(int argc, char **argv){
        ros::init(argc, argv, "joint_command_talker");
	Inverse_Kinematics_Talker talker(argc,argv);
  	ros::Rate loop_rate(updateRate);
	sensor_msgs::JointState stateMsg;
	std_msgs::Float32 msg;
  	while (ros::ok()){
		talker.inverse_kinematics();
		double theta_offset = 0.5*pi - 28.0*pi/180;
		msg.data= talker.getJointTheta().getX()-theta_offset;
    		talker.joint_gazebo_pub1.publish(msg);
		msg.data= talker.getJointTheta().getY()-theta_offset;
    		talker.joint_gazebo_pub2.publish(msg);
		msg.data=talker.getJointTheta().getZ()-theta_offset;
    		talker.joint_gazebo_pub3.publish(msg);
                stateMsg.header.stamp=ros::Time::now();
		stateMsg.name={"FlyingDeltaArmBase__link_0_JOINT_1", "FlyingDeltaArmBase__link_0_JOINT_2", "FlyingDeltaArmBase__link_0_JOINT_3"};
		stateMsg.position={talker.getJointTheta().getX()-1.1,talker.getJointTheta().getZ()-1.1,talker.getJointTheta().getY()-1.1};
		stateMsg.velocity={};
		stateMsg.effort={};
		talker.state_pub.publish(stateMsg);
    		ros::spinOnce();
    		loop_rate.sleep();
 	}
  	return 0;
}
