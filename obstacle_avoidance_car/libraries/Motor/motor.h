#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor
{

public:

  //Constructor
  Motor(int dir,int pwm,int max_speed=255);


private:

  //the direction pin
  int dir_pin_;

  //PWM pin
  int pwm_;

  //max speed of the motor
  int max_speed_;
};

#endif
