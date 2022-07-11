#pragma once

// ======= ROS =======
#include <ros/ros.h>
#include <ros/package.h>
#include <turtlesim/Pose.h>

//======= std libs =======
#include <string>
#include <cmath>

//======= Msgs =======
#include <geometry_msgs/Pose.h>

namespace motius
{
    class Navigation_Client
    {
        public:
            // ======= Constructor/Destructor =======
            Navigation_Client(ros::NodeHandle);

            // ============ Class variables ===========
                // EDIT
        private:
            // ============ General ===========
            ros::NodeHandle nodeHandle;
            ros::Publisher publisher_pose;

            // ============ Strings ===========
            const std::string kNodeName     = "navigation_node";
            const std::string kPrefix       = "[" + kNodeName + "]: ";

            //============ Functions ===========

            void publish_pose(void);

    };

} //namespace Motius