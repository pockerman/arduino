#ifndef TWO_MOTORS_VEHICLE_H
#define TWO_MOTORS_VEHICLE_H
#include "motor.h"
#include <NewPing.h>


class TwoMotorsVehicle
{

public:

  //Constructor
  TwoMotorsVehicle(int rdir1,int rdir2,int renable,
                   int ldir1,int ldir2,int lenable,
                   int trig_pin,int echo_pin, int max_dist,
                   int max_speed=Motor::default_max_speed());

  //move forward
  void move_forward(int speed=Motor::default_max_speed());

  void turn_left();

  void turn_right();

  //stops both motors
  void stop();

  void off();

  void enable();


  //execute the vehicle: sense obstacle-->decide what--->execute
  void execute();

private :

  //right motor
  Motor r_;

  //left motor
  Motor l_;

  //handles the sound sensor
  NewPing sensor_;

  //minimum distance the sensor cannot sense
  const float MIN_DIST;
};
#endif
