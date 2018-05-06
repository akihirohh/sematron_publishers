#include "ros/ros.h"
#include <ros/package.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <std_msgs/String.h>
#include <std_msgs/Char.h>
#include <std_msgs/Int64.h>
#include <std_msgs/Int16MultiArray.h>
#include <std_msgs/Int32MultiArray.h>
#include <std_msgs/Int64MultiArray.h>
#include <sensor_msgs/BatteryState.h>
#include <control_msgs/JointTolerance.h>
#include <cmath>
#include "geometry_msgs/Twist.h"
#include <geometry_msgs/PolygonStamped.h>

#define MASTER_KEY 1993
#define MASTER_IP 172172118
#define PUBLISH_RATE 50

int main(int argc, char* argv[] )
{
  ros::init(argc, argv, "use_param");
  ros::NodeHandle node;
  ros::Publisher pub_red_line = node.advertise<std_msgs::Int32MultiArray>("unlock_me_if_you_can", 1);
  ros::Rate loop_rate(PUBLISH_RATE);


  //first subscriber
  ros::Publisher pub_first_publisher = node.advertise <std_msgs::String> ("/OOOstart_hereOOO",1);
  std_msgs::String msg_first_publisher;
  msg_first_publisher.data = "Step -1!# Next step a contains a std_msgs/Int64MultiArray message. Use $rostopic... The message is coded (just cast each number to char)!";

  //start_again
  ros::Publisher pub_start_again = node.advertise <std_msgs::Int64MultiArray> ("step0",1);
  std_msgs::Int64MultiArray msg_start_again;
  char buf0[] = "It was tutorial till now! #Step 0!# Just /start_again xP";
  for(int j = 0; j < sizeof(buf0)/sizeof(char); j++)
	{
		msg_start_again.data.push_back(buf0[j]);
	}

  //rostopic find
  ros::Publisher pub_rostopic_find = node.advertise <std_msgs::String> ("/start_again",1);
  std_msgs::String msg_rostopic_find;
  msg_rostopic_find.data = "Next step contains a control_msgs/JointTolerance message. #Step1!#";

  //rosnode info /more_numbers 
  ros::Publisher pub_rosnode_info = node.advertise<control_msgs::JointTolerance>("some_wrong_physics",1);
  control_msgs::JointTolerance msg_rosnode_info;
  msg_rosnode_info.velocity = 18;
  msg_rosnode_info.position = 14;
  msg_rosnode_info.acceleration = 2;
  msg_rosnode_info.name = "#Step2!# Learn about /more_numbers using $rosnode ...! Do you know what type of message it is? Then you can subscribe to it! The message is coded (You must add velocity to each number but don't forget to first subtract position and finally divide by acceleration).";

  //rostopic hz /even_more_numbers
  ros::Publisher pub_rostopic_hz = node.advertise<std_msgs::Int16MultiArray> ("/more_numbers",1);
  std_msgs::Int16MultiArray msg_rostopic_hz;  
  char buf[] = "#Step3!# Do you know what's the publishing rate of /even_more_numbers? You may want to use $rostopic... The closest integer to that rate multiplies every number of /even_more_numbers (originally just casting to char would do the job...)";
	for(int j = 0; j < sizeof(buf)/sizeof(char); j++)
	{
		msg_rostopic_hz.data.push_back(buf[j]*msg_rosnode_info.acceleration - msg_rosnode_info.velocity + msg_rosnode_info.position);
	}

  //rostopic find std_msgs/Int64
  //rostopic echo /hint
  //rostopic echo /mazana_matatu
  ros::Publisher pub_remember_status = node.advertise<std_msgs::Int64MultiArray>("/even_more_numbers",1);
  std_msgs::Int64MultiArray msg_remember_status;
  char buf1[] = "#Step4!# Don’t forget to publish your status! Seriously, it's really important. One of the std_msgs/Int64 topics has a hint. Translate it to chona and you'll know the name of next topic.";
	for(int j = 0; j < sizeof(buf1)/sizeof(char); j++)
	{
		msg_remember_status.data.push_back(buf1[j]*PUBLISH_RATE);
	}
  ros::Publisher pub_remember_status2 = node.advertise <std_msgs::Int64> ("/hint_here",1);
  std_msgs::Int64 msg_remember_status2; 
  msg_remember_status2.data = 300;

  //rostopic echo /not_a_selfie --no_arr
  ros::Publisher pub_rostopic_echo_no_arr = node.advertise <sensor_msgs::BatteryState> ("/mazana_matatu",1);
  sensor_msgs::BatteryState msg_rostopic_echo_no_arr;
  msg_rostopic_echo_no_arr.power_supply_status = 5;
  msg_rostopic_echo_no_arr.location = "Message fields are important. For instance, power_supply_status gives your current step (just in case you forgot) and serial_number has the hint for next step!";
  msg_rostopic_echo_no_arr.serial_number = "Sometimes you see a /not_a_selfie topic but you don't care about the array fields. Exclude them using --noarr argument with $rostopic echo!";

  //rostopic echo /not_a_selfie_for_sure --no_arr
  ros::Publisher pub_rostopic_echo_no_arr2 = node.advertise <sensor_msgs::Image> ("/not_a_selfie", 1);
  sensor_msgs::Image msg_rostopic_echo_no_arr2;
  msg_rostopic_echo_no_arr2.encoding = "#Step6!# I hope you used $rostopic echo /not_a_selfie --noarr to get here =] Just in case, try again with /not_a_selfie_for_sure.";
  for (int w = 0; w < 1024; w++)
  {
    for (int h = 0; h < 720; h++)
    {
      msg_rostopic_echo_no_arr2.data.push_back(w*255/1024 + h*255/720);
    }
  }

  //rosrun turtlesim turtlesim_node
  ros::Publisher pub_rosrun_turtlesim = node.advertise <sensor_msgs::Image> ("/not_a_selfie_for_sure", 1);
  sensor_msgs::Image msg_rosrun_turtlesim;
  msg_rosrun_turtlesim.encoding = "#Step7!# Now you're about to move your Crush. Make it personal changing the node name (add __name:=my_crush). Make it use the right topic (add turtle1/cmd_vel:=move_crush). All together: $rosrun turtlesim turtlesim_node __name:=my_crush turtle1/cmd_vel:=move_crush. The movement shape gives you the name for next topic! (P.S. you may need to translate to maori language).";
  for (int w = 0; w < 1024; w++)
  {
    for (int h = 0; h < 720; h++)
    {
      msg_rostopic_echo_no_arr2.data.push_back(w*255/1024 + h*255/720);
    }
  } 

  //args
  ros::Publisher pub_args = node.advertise <geometry_msgs::Twist> ("/move_crush",1);
  geometry_msgs::Twist msg_args;
  double angular[] = {0, M_PI/2 };
  double linear[] = {3, 0};
  int turtle_index = 0;

  //parameters
  ros::Publisher pub_param = node.advertise <geometry_msgs::PolygonStamped> ("/tapawha",1);
  geometry_msgs::PolygonStamped msg_param;
  msg_param.header.frame_id = "I bet you forgot to publish #Step8!# status. Anyway, now you need to publish #Step9!# Are you still changing the code and doing catkin_make every time? Why don't you try using arguments when you call $rosrun? You may have noticed the line int main(int argc, char* argv[]) in your nodes. argc gives you the number of arguments and argv gives you the arguments as strings. argv[0] gives you the path to the package but if you call $rosrun publish_my_status publish_my_status_node 9, then argv[1] = '9'. The function atoi conveniently converts string to int and you can publish it! ... ... ... It's not over yet! You'll learn something even more useful in /learn_parameters";

  // explore param
  ros::Publisher pub_explore_param = node.advertise <std_msgs::String> ("learn_parameters",1);
  std_msgs::String msg_explore_param;
  msg_explore_param.data = "Another way of changing variables inside node is ROS parameter. Explore $rosparam commands starting with tutorial# params";
  std::string tutorial1 = "If there's a param, you can get it inside node using node.getParam(<param_name>, var_to_store_param); Try printing /tutorial1 with ROS_INFO";
  std::string tutorial2 = "You can also set new values to params using command line. For example, if you want to use a param /myname_status (change myname to your name) to inform your status, you can use rosparam set /myname_status 10";
  std::string tutorial3 = "Or you can set the param inside your node: node.setParam(<param_name>, new_value). Time to collect some gifts o/";
  std::string small_gift = "You found a /key to unlock the publisher of a certain node. It may be obvious but just in case you don't find the node, search for Int32MultiArray messages";
  std::string medium_gift = "You must find the IP of the machine that's publishing all this stuff... rosnode may help you in your journey. Or you can find where's the master";
  std::string big_gift = "Your /key to unlock the publisher shall be the 10 numbers from master's IP without dots!!!";
  std::string monstrous_gift = "Remove 1993 from each element of the array and you will be able to cast it to char.";

  // image_view topic
  std_msgs::Int32MultiArray msg_red_line;
  int status = 0;
  char bufn[] = "Congrats! Now you have a grasp about rosparam.\tThe final topic is /red_line.\tRun rosrun image_view image_view image:=/red_line";
	;
	for(int j = 0; j <  sizeof(bufn)/sizeof(char); j++)
	{
		msg_red_line.data.push_back(bufn[j] + MASTER_KEY);
	}

  // End of the beginning
	image_transport::ImageTransport it(node);
	image_transport::Publisher pub_end = it.advertise("/red_line", 1);
	std::string fig_path = ros::package::getPath("sematron_publishers") + "/include/.dummy.png";
	cv::Mat image = cv::imread(fig_path, CV_LOAD_IMAGE_COLOR);
	sensor_msgs::ImagePtr msg_end = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();

  ros::Time previous_time = ros::Time::now(), current_time;

  while(ros::ok())
  {
    pub_first_publisher.publish(msg_first_publisher);
    pub_start_again.publish(msg_start_again);
    pub_rostopic_find.publish(msg_rostopic_find);
    pub_rosnode_info.publish(msg_rosnode_info);
    pub_rostopic_hz.publish(msg_rostopic_hz);
    pub_remember_status.publish(msg_remember_status);
    pub_remember_status2.publish(msg_remember_status2);
    pub_rostopic_echo_no_arr.publish(msg_rostopic_echo_no_arr);
    pub_rostopic_echo_no_arr2.publish(msg_rostopic_echo_no_arr2);
    pub_rosrun_turtlesim.publish(msg_rosrun_turtlesim);
    pub_explore_param.publish(msg_explore_param);

    current_time = ros::Time::now();
    if((current_time.toSec()-previous_time.toSec()) > 2)
    {
      previous_time = current_time;      
      msg_args.angular.z = angular[turtle_index];
      msg_args.linear.x = linear[turtle_index];
      turtle_index = (turtle_index == 0) ? 1: 0;
      pub_args.publish(msg_args);
    }

    node.setParam("/tutorial1", tutorial1);
    node.setParam("/tutorial2", tutorial2);
    node.setParam("/tutorial3", tutorial3);
    node.setParam("/small_gift", small_gift);
    node.setParam("/medium_gift", medium_gift);
    node.setParam("/big_gift", big_gift);
    node.setParam("/monstrous_gift", monstrous_gift);

    pub_param.publish(msg_param);
    node.getParam("/key", status);
    if(status == MASTER_IP)
    {
      pub_red_line.publish(msg_red_line);
      node.setParam("/key", 0);
    }
    pub_end.publish(msg_end);
    ros::spinOnce();
    loop_rate.sleep();
  }
}
