#include "navigation/navigation_client.hpp"
#include "distance_service_server/distance_srv.h"

using namespace motius;

Navigation_Client::Navigation_Client(ros::NodeHandle nh): nodeHandle{nh}
{

    ros::ServiceClient client = nodeHandle.serviceClient<distance_service_server::distance_srv>("/get_distance");
    
    distance_service_server::distance_srv srv;
    

    
    if (client.call(srv))
    {
      ROS_INFO_STREAM("Distance: " << srv.response.distance);
    }
    else
    {
      ROS_ERROR("Failed to get the distance.");
    }



    // The section below was only for testing purposes! A simple publisher with const values.

    // publisher_pose = nodeHandle.advertise<geometry_msgs::Pose>("/motius_challenge/robot_pose", 1000);
    // while(true)
    // {
    //   publish_pose();
    // }


}

void Navigation_Client::publish_pose(void)
{
  // TODO: maybe add a random number of the pose so that it is not always the same one
  geometry_msgs::Pose pose_msg;
  pose_msg.position.x = 1;
  pose_msg.position.y = 2;
  pose_msg.position.z = 3;

  pose_msg.orientation.w    = 1;
  pose_msg.orientation.x    = 0;
  pose_msg.orientation.y    = 0;
  pose_msg.orientation.z    = 0;
  publisher_pose.publish(pose_msg);
}