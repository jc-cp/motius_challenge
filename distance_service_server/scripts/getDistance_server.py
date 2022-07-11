#!/usr/bin/env python3

from __future__ import print_function
import rospy
import sys, os
from geometry_msgs.msg import Point
from turtlesim.msg import Pose
# sys.path.insert(0, 'motius_challenge/distance_service_server/')
# os.chdir(os.path.dirname(os.getcwd()))
from distance_service_server.srv import distance_srv, distance_srvResponse
import math

class DistanceCalculator:
    def __init__(self):
        self.pose_subscriber = rospy.Subscriber('/turtle1/pose', Pose, self.compute_euclidean_distance)
        self.first_pose = True
        self.total_distance = 0.0
        self.last_position = Point()
        self.position = Pose()
        self.srv = rospy.Service('/get_distance', distance_srv, self.handler_getDistance)
        rospy.loginfo('Service is running')


    def compute_euclidean_distance(self, data):
        self.position = data
        self.position.x = round(self.position.x, 3)
        self.position.y = round(self.position.y, 3)

        if self.first_pose:
            self.first_pose = False
            self.last_position = self.position

        euclidean_distance = math.sqrt((self.position.x - self.last_position.x)* (self.position.x - self.last_position.x) + (self.position.y - self.last_position.y)*(self.position.y - self.last_position.y))
        self.total_distance = self.total_distance + euclidean_distance
        self.last_position = self.position


    def handler_getDistance(self, request):
        # This acts basically as the callback for the service, similar to the topic-callbacks
        
        distance = self.total_distance

        # conversion from sea miles to meters of the turtle
        if request.units == 'sea_miles':
            distance = distance * 0.000539
        
        response = distance_srvResponse()
        response.distance = distance

        return response


if __name__ == "__main__":
    rospy.init_node('getDistance_server')
    # Instance of the class
    d = DistanceCalculator()
    print("Ready to get distance from Turtlesim!")
    rospy.spin()
    