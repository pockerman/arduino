

#ifndef TWO_MOTORS_VEHICLE_H
#define TWO_MOTORS_VEHICLE_H
#include <Arduino.h>
#include "motor.h"
#include <NewPing.h>




class TwoMotorsVehicle
{

public:

  //Constructor
  TwoMotorsVehicle(int rdir1,int rdir2,int renable,
                   int ldir1,int ldir2,int lenable,
                   int trig_pin,int echo_pin, int max_dist,
                   int max_speed);

  //move forward
  void move_forward(int speed);

  //turn the vehicle to the left
  void turn_left();

  //turn the vehicle to the right
  void turn_right();

  //stops both motors
  void stop();

  // set motors to off
  void off();

  //enable the motors
  void enable();


  //execute the vehicle: sense obstacle-->decide what--->execute
  void execute();

  //senses obstacle and returns the distance from it
  float sense_obstacle();

private :

  

  //handles the sound sensor
  NewPing sensor_;

  //minimum distance for obstacle closeness
  //by default it is set to 25 cm
  const float  MIN_OBST_DIST;
};
#endif
