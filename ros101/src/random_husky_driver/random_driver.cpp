#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc, char**argv) {
//initialize ros set up node
ros::init(argc,argv,"random_husky_commands");
ros::NodeHandle nh;

//create a publisher, publish to the husky_velocity_controller/cmd_vel topic, with queue of 100

ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("husky_velocity_controller/cmd_vel",100);


//setup the Loop to pblish t a rate f 10Z
ros::Rate rate(10);
int count = 0;
while (ros::ok()){
	//Declear the message to be sent
	geometry_msgs::Twist msg;
	// x value set to 0.5
	if (count < 50 )
	{
	   msg.linear.x= 0.1;
	   count ++;
	}
	else {
	   msg.linear.x= 0;
	}
	
	//pblish the message
	pub.publish(msg);
	//dela until next message
	rate.sleep();
	}
}
