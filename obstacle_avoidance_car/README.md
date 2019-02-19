# Obstacle Avoidance Car

Sketch for a differentual drive robot that uses an ultrasound sensor to avoid obstacles. Note that the sketch is elementary
and aims at getting you started. You will find four sketches:

- dev_sketches: where various tests with respect to the motion of the robot have been implemented
- forward_route_test: this is the first sketch to use with a powered chassis; simple straight line motion
- forward_route_optical_sensors: a move-straight-spin-left based on distance ticks powered chassis
- full_route_optical_and_us_sensors: a powered chassis that avoids (almost) obstacles

 
 in the You can simulate the robot using either ROS and the source code for <a href="#">Odisseus</a> or use <a href="https://github.com/UpperFrameworks/CubicEngine">CubicEngine</a> a C++ library for  robotics simulation. 

See the <a href="https://www.youtube.com/watch?v=oQQpAACa3ac"> Arduino Robot Car with Speed Sensors</a> video from <a href="https://dronebotworkshop.com/">DroneBot Workshop</a>  on how to assemble the robot base.

## Technical Requirements

1. Arduino UNO
2. L298N H bridge
3. HC-SR04 ultrasound sensor
4. 2 Optical source sensors
5. 2 6V motors
6. 6 cell battery holder
7. Small bread-board
8. 2 wheels
9. 2 wheel encoders
