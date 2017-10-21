#include "two_motors_vehicle.h"

#include <Arduino.h>
#include <math.h>


TwoMotorsVehicle::TwoMotorsVehicle(int rdir1,int rdir2,int renable,
                                   int trig_pin,int echo_pin, int max_dist,
                                   int ldir1,int ldir2,int lenable,int max_speed)
:
r_(rdir1,rdir2,renable,max_speed),
l_(ldir1,ldir2,lenable,max_speed),
sensor_(trig_pin,echo_pin,max_dist),
MIN_DIST(2.0)
{
  enable();  
}


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
  //enable();
  r_.forward();
  l_.forward();
}

void
TwoMotorsVehicle::off(){
  r_.off();
  l_.off();
}

void 
TwoMotorsVehicle::execute(){

  float distance = sensor_.ping_cm();

  if(fabs(distance-MIN_DIST)<1.0e-5){

      //the sensor cannot sense anything
      //so stop the vehicle
      stop();  
  }
  else{

    
  }

}


