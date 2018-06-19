#include "two_motors_vehicle.h"

#include <Arduino.h>
#include <math.h>


TwoMotorsVehicle::TwoMotorsVehicle(int rdir1,int rdir2,int renable,
                                   int ldir1,int ldir2,int lenable,
                                   int trig_pin,int echo_pin, int max_dist,int max_speed)
:
sensor_(trig_pin,echo_pin,max_dist),
MIN_OBST_DIST(25.0)
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

//  r_.write(LOW,HIGH);
//  l_.write(HIGH,LOW);
}

void 
TwoMotorsVehicle::stop(){
  
}

void 
TwoMotorsVehicle::enable(){
  
}

void 
TwoMotorsVehicle::move_forward(int speed){
  
  
}

void
TwoMotorsVehicle::off(){
  
}

float 
TwoMotorsVehicle::sense_obstacle(){

  float dist = sensor_.ping_cm();
  return dist;
}

void 
TwoMotorsVehicle::execute(){

  float distance = sensor_.ping_cm();

  //if the calculated distance is less
  //than the minimum distance we spin around until
  //we find an unbstracted path
  if(fabs(distance-MIN_OBST_DIST)<1.0e-5){

      // turn until we find an obstacle free 
      //route
      turn_right();      
  }
  else{

    //move forward
    //move_forward();
  }

}


