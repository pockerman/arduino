#ifndef TWO_MOTORS_VEHICLE_H
#define TWO_MOTORS_VEHICLE_H
#include "motor.h"

class TwoMotorsVehicle
{

public:

  //Constructor
  TwoMotorsVehicle(int rdirpin,int rpwmpin,int ldirpin,int lpwmpin,int max_speed=255);


  //void set();

private :

  //right motor
  Motor r_;

  //left motor
  Motor r_;
};
#endif
