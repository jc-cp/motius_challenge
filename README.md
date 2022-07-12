# Motius Challenge

The task is formulated openly, and there is not one correct answer. It basically consists of two ROS nodes, one in C++ and one in Python. One node sends at least one request of any kind to the other and the other node must respond. It is based on ROS services.


The python package is the "distance_service_server" which basically acts as a server waiting a request from the client, the C++ package "navigation_client". On the client package is also found a "launch" fodler which includes a launch-file that starts the necessary nodes. 

## Procedure
1. Turtlesim is initiated
2. The Server package is initiated (python), gets pose-information from the Turtlesim package
3. The Turtlesim_teleop package is initiated (in order to move the turtle via keyboard commands)
4. The Client package is initiated, sending a request to the server in order to get the traveled distance of the turtle 
5. The Server answers with a repsonse. 

## Commands

1. roscore
2. rosrun turtlesim turtlesim_node
3. rosrun distance_service_server getDistance_server.py
4. rosrun turtlesim turtle_teleop_key
5. rosrun navigation_client navigation_client_node
