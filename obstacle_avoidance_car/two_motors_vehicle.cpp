#include "two_motors_vehicle.h"
#include <Arduino.h>
TwoMotorsVehicle::TwoMotorsVehicle(int rdir1,int rdir2,int renable,
                                   int ldir1,int ldir2,int lenable,int max_speed)
:
r_(rdir1,rdir2,renable,max_speed),
l_(ldir1,ldir2,lenable,max_speed)
{}


void 
TwoMotorsVehicle::turn_left(){

  //r_.write(HIGH,LOW);
  //l_.write(LOW,HIGH);
}

void 
TwoMotorsVehicle::turn_right(){

  //r_.write(LOW,HIGH);
  //l_.write(HIGH,LOW);
}

void 
TwoMotorsVehicle::stop(){
  r_.stop();
  l_.stop();
}

void 
TwoMotorsVehicle::enable(){
  r_.enable();
  l_.enable();
}

void 
TwoMotorsVehicle::move_forward(int speed){
  enable();
  r_.forward();
  l_.forward();
}

void
TwoMotorsVehicle::off(){
  r_.off();
  l_.off();
}

