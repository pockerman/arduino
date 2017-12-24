#include "motor.h"
#include <Arduino.h>
#include <math.h>


Motor::Motor(int dir1,int dir2,int enable_pin,int max_speed)
:
dir1_(dir1),
dir2_(dir2),
enable_pin_(enable_pin),
max_speed_(max_speed),
is_stopped_(true)
{
  pinMode(dir1_,OUTPUT);
  pinMode(dir2_,OUTPUT);
  pinMode(enable_pin_,OUTPUT);
}

/*void 
Motor::write(int dp_status,int pwmp_status){
  digitalWrite(dir_pin_, dp_status);
  digitalWrite(pwm_, pwmp_status);
}*/

void 
Motor::stop(){

  digitalWrite(dir1_,LOW);
  digitalWrite(dir2_,LOW);
  is_stopped_ = true;
}

void 
Motor::enable(){
  digitalWrite(enable_pin_,HIGH);
}

void 
Motor::off(){
  digitalWrite(enable_pin_,LOW);
}

/*void 
Motor::start(int speed){

  int type = HIGH;

  

  //speed should be in the range [0,max_speed]
  speed = abs(speed % (max_speed_+1));

  digitalWrite(dir_pin_,type);
  analogWrite(pwm_,speed);
}*/

void 
Motor::forward(){
  digitalWrite(dir1_,HIGH);
  digitalWrite(dir2_,LOW);
}

