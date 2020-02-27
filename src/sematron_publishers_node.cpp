// Tutorial produced by Vitor Akihiro Hisano Higuti
// for ROS minicourse (XIV SEMATRON)

#include "ros/ros.h"
#include "ros/network.h"
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
#include <diagnostic_msgs/DiagnosticStatus.h>
#include <control_msgs/JointTolerance.h>
#include <cmath>
#include "geometry_msgs/Twist.h"
#include <geometry_msgs/PolygonStamped.h>

#define MASTER_KEY 1993
#define PUBLISH_RATE 50

int main(int argc, char* argv[] )
{
  ros::init(argc, argv, "hint_here");
  ros::NodeHandle node;
  ros::Rate loop_rate(PUBLISH_RATE);
  std::string MASTER_IP = ros::network::getHost();

  ROS_INFO_STREAM("Instructions:");
  ROS_INFO_STREAM("1) When you see /blablabla, that's a topic");
  ROS_INFO_STREAM("2) When you see $ blablabla, that's a terminal command");
  ROS_INFO_STREAM("3) When in doubt, there's always $ rostopic echo ...");

  ROS_INFO_STREAM("Start with $ rostopic echo /000start_here000");
  
  //first subscriber
  ros::Publisher pub_first_publisher = node.advertise <std_msgs::String> ("/000start_here000",1);
  std_msgs::String msg_first_publisher;
  msg_first_publisher.data = "Step -1!# Next step contains a std_msgs/Int64MultiArray message. Use $rostopic echo /step0. The message is coded (just cast each number to char)! Hint: You can always use Internet... maybe an online int to char converters here? Hint 2: just in case you forgot, be aware that topics start are referred to with an / and terminal commands with $.";

  //start_again
  ros::Publisher pub_start_again = node.advertise <std_msgs::Int64MultiArray> ("step0",1);
  std_msgs::Int64MultiArray msg_start_again;
  char buf0[] = "Fools! It was tutorial till now! #Step 0!# Just /start_again xP";
  for(int j = 0; j < sizeof(buf0)/sizeof(char); j++)
	{
		msg_start_again.data.push_back(buf0[j]);
	}

  //rostopic find
  ros::Publisher pub_rostopic_find = node.advertise <std_msgs::String> ("/start_again",1);
  std_msgs::String msg_rostopic_find;
  msg_rostopic_find.data = "#Step1!# Use $rostopic info to find which topic has the control_msgs/JointTolerance message. Hint: do you know about the control_msgs/JointTolerance? Google it! Doesn't it remind you of physics?";

  //rosnode info /more_numbers 
  ros::Publisher pub_rostopic_info = node.advertise<control_msgs::JointTolerance>("/some_wrong_physics",1);
  control_msgs::JointTolerance msg_rostopic_info;
  msg_rostopic_info.velocity = 18;
  msg_rostopic_info.position = 14;
  msg_rostopic_info.acceleration = 2;
  msg_rostopic_info.name = "#Step2!# Learn more about /more_numbers! Do you know what type of message it uses? Then you can subscribe to it! The message is coded (You must add velocity to each number, divide by acceleration and finally subtract position). Don't be lazy and make a new package: On src directory, catkin_create_pkg <package_name> <dependency_0> ... <dependency_n>";

  //rostopic hz /even_more_numbers
  ros::Publisher pub_rostopic_hz = node.advertise<std_msgs::Int16MultiArray> ("/more_numbers",1);
  std_msgs::Int16MultiArray msg_rostopic_hz;  
  char buf[] = "#Step3!# Do you know what's the average publishing rate of /even_more_numbers? The closest integer to that rate multiplies every number of /even_more_numbers...";
	for(int j = 0; j < sizeof(buf)/sizeof(char); j++)
	{
		msg_rostopic_hz.data.push_back((buf[j]+ msg_rostopic_info.position)*msg_rostopic_info.acceleration - msg_rostopic_info.velocity );
	}

  //rostopic find std_msgs/Int64
  //rostopic echo /hint
  //rostopic echo /mazana_matatu
  ros::Publisher pub_remember_status = node.advertise<std_msgs::Int16MultiArray>("/even_more_numbers",1);
  std_msgs::Int16MultiArray msg_remember_status;
  char buf1[] = "#Step4!# Don't forget to publish your status! Seriously, it's really important. They're so important that one of the std_msgs/Int64 topics has a hint. Translate it to chona and you'll know the name of next topic.";
	for(int j = 0; j < sizeof(buf1)/sizeof(char); j++)
	{
		msg_remember_status.data.push_back(buf1[j]*PUBLISH_RATE);
	}
  ros::Publisher pub_remember_status2 = node.advertise <std_msgs::Int64> ("/hint_here",1);
  std_msgs::Int64 msg_remember_status2; 
  msg_remember_status2.data = 300;

  //rostopic echo /not_a_selfie --no_arr
  ros::Publisher pub_rostopic_echo_no_arr = node.advertise <diagnostic_msgs::DiagnosticStatus> ("/mazana_matatu",1);
  diagnostic_msgs::DiagnosticStatus msg_rostopic_echo_no_arr;
  msg_rostopic_echo_no_arr.level = 5;
  msg_rostopic_echo_no_arr.name = "Message fields are important. For example, level gives your current step (just in case you forgot) and hardware_id has the hint for next step!";
  msg_rostopic_echo_no_arr.hardware_id = "Sometimes you see a /not_a_selfie topic but you don't care about the array fields. Extra hint: $rostopic echo <topic> can have additional arguments!";
 
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
  msg_rosrun_turtlesim.encoding = "#Step7!# Now you're about to move your Crush. Make it personal changing the node name (add __name:=my_crush). Make it use the right topic as source of velocity commands (add turtle1/cmd_vel:=move_crush). All together: $rosrun turtlesim turtlesim_node __name:=my_crush turtle1/cmd_vel:=move_crush. The movement shape gives you the name for next topic! (P.S. you may need to translate to maori language).";
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
  msg_param.header.frame_id = "I bet you forgot to publish #Step7!# status. Anyway, now you need to publish #Step8!# Are you still changing the code and doing catkin_make every time? Why don't you try using arguments when you call $rosrun? You may have noticed the line int main(int argc, char* argv[]) in your nodes. argc gives you the number of arguments and argv gives you the arguments as strings. argv[0] gives you the path to the package. If you call $rosrun publish_my_status publish_my_status_node 8, then argv[1] = '8'. The function atoi conveniently converts string to int and you can publish it! ... ... ... It's not over yet! You'll learn something even more useful in /learn_parameters";

  // explore param
  ros::Publisher pub_explore_param = node.advertise <std_msgs::String> ("learn_parameters",1);
  std_msgs::String msg_explore_param;
  msg_explore_param.data = "#Step9!# Another way of changing variables inside node is ROS parameter. Explore $rosparam commands starting with /tutorial# params. Start with $ rosparam list.";
  std::string tutorial1 = "If there's a param, you can get it inside node using nodeHandle.getParam(<param_name>, var_to_store_param). Try printing /tutorial1 with ROS_INFO_STREAM";
  std::string tutorial2 = "You can also set new values to params using command line. For example, if you want to set the value of a param /myname_status (change myname to your name) to inform your status, you can use $ rosparam set /myname_status 9. Check its value with $ rosparam get!";
  std::string tutorial3 = "Or you can set the param inside your node: nodeHandle.setParam(<param_name>, new_value). Did you know isipho is gift in zulu? No? Do not waste more time! Collect your four isiphos disguised as params!";
  std::string small_gift = "Have you checked all tutorial params? Anyway, you just found an empty /key to unlock the publisher of a certain node. It may be obvious but just in case you don't find the node, search for std_msgs/Int32MultiArray messages. Keep echoing the topic until you set the /key =]";
  std::string medium_gift = "You must find the IP of the machine that's publishing all this stuff... rosnode may help you in your journey. Or you can find where's the master";
  std::string big_gift = "Your /key to unlock the publisher shall be the master's IP!!!";
  std::string monstrous_gift = "Remove 1993 from each element of the array and you will be able to cast it to char.";

  // image_view topic
  ros::Publisher pub_red_line = node.advertise<std_msgs::Int32MultiArray>("unlock_me_if_you_can", 1);
  std_msgs::Int32MultiArray msg_red_line;
  std::string status = "";
  char bufn[] = "\n#Step10!# Congrats! Now you have a grasp about rosparam. The final topic is /red_line. Run $ rqt_image_view /red_line ";
	;
	for(int j = 0; j <  sizeof(bufn)/sizeof(char); j++)
	{
		msg_red_line.data.push_back(bufn[j] + MASTER_KEY);
	}

  // End of the beginning
	image_transport::ImageTransport it(node);
	image_transport::Publisher pub_end = it.advertise("/red_line", 1);
	std::string fig_path = ros::package::getPath("sematron_publishers") + "/include/.end.png";
	cv::Mat image = cv::imread(fig_path, CV_LOAD_IMAGE_COLOR);
	sensor_msgs::ImagePtr msg_end = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();

  ros::Time previous_time = ros::Time::now(), current_time;

  while(ros::ok())
  {
    pub_first_publisher.publish(msg_first_publisher);
    pub_start_again.publish(msg_start_again);
    pub_rostopic_find.publish(msg_rostopic_find);
    pub_rostopic_info.publish(msg_rostopic_info);
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

    node.setParam("/000Check_tutorial_params", "###\nSeriously, start with tutorial params\n###");
    node.setParam("/tutorial1", tutorial1);
    node.setParam("/tutorial2", tutorial2);
    node.setParam("/tutorial3", tutorial3);
    node.setParam("/red_line/small_isipho", small_gift);
    node.setParam("/red_line/medium_isipho", medium_gift);
    node.setParam("/red_line/big_isipho", big_gift);
    node.setParam("/red_line/monstrous_isipho", monstrous_gift);

    pub_param.publish(msg_param);
    node.getParam("/key", status);
    if(strcmp(status.c_str(),MASTER_IP.c_str()) == 0)
    {
      pub_red_line.publish(msg_red_line);
      node.setParam("/key", "");
    }
    pub_end.publish(msg_end);
    ros::spinOnce();
    loop_rate.sleep();
  }
}
