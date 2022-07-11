#include "navigation/navigation_client.hpp"
#include <string>
#include <ros/ros.h>

const std::string kNodeName     = "navigation";
const std::string kPrefix       = "[" + kNodeName + "]: ";


int main(int argc, char** argv)
{
  ros::init(argc, argv, kNodeName);
  // ROS_INFO("Starting " + kPrefix + ".");
  ros::NodeHandle nh("~");

  motius::Navigation_Client navigation_client(nh);

  // ros::spin();

  return EXIT_SUCCESS;
}