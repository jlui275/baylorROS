#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc, char**argv) {
//initialize ros set up node
ros::init(argc,argv,"random_husky_commands");
ros::Handle nh;

//create a publisher, publish to the husky_velocity_controller/cmd_vel topic, with queue of 100

ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("husky_velocity_ontroller/cmd_vel",100);

//set up randm generatr
srand(time(0));

//setup the Loop to pblish t a rate f 10Z
ros:Rate rate(10);

while (ros::ok()){
	//Declear the message to be sent
	geometry_msgs:Twist msg;
	//Random  x value between-2 and 2
	msg.linear.x=4*double(rand())/double(RAND_MAX)-2;
	//random z value between -3 and 3
	msg.angular.y=6*double(rand())/double(RAND_MAX)-3;
	//pblish the message
	pub.publish(msg);
	//dela until next message
	rate.sleep();
	}
}
