#include "motor.h"

Motor::Motor(int dir,int pwm,int max_speed=255)
:
dir_pin_(dir),
pwm_(pwm),
max_speed_(max_speed)
{
  pinMode(dir_pin_,OUTPUT);
  pinMode(pwm_,OUTPUT);
}
