#ifndef TWO_MOTORS_VEHICLE_H
#define TWO_MOTORS_VEHICLE_H
#include "motor.h"

class TwoMotorsVehicle
{

public:

  //Constructor
  TwoMotorsVehicle(int rdir1,int rdir2,int renable,
                   int ldir1,int ldir2,int lenable,int max_speed=Motor::default_max_speed());

  //move forward
  void move_forward(int speed=Motor::default_max_speed());

  void turn_left();

  void turn_right();

  //stops both motors
  void stop();

  void off();

  void enable();
  //void set();

private :

  //right motor
  Motor r_;

  //left motor
  Motor l_;
};
#endif
