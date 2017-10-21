#include <Servo.h>
#include <NewPing.h>
#include "two_motors_vehicle.h"


//==========================================
//the vehicle. We use the following pins
//Arduino----L298 H-Bridge
//right motor: 10----ENA, 2----IN1, 3----IN2, 
//left motor:  9----ENB, 4----IN3, 5----IN4 
// make a small switch so that IN4 for the left 
//motor is equivelant to IN1 for the right motor
//i.e corresponding to dir1 as in right motor 

//NewPing sensor handling
//TRIG PIN 7
//ECHO PIN 11
//MAX DIST in 400 cm 

TwoMotorsVehicle vehicle(2,3,10,5,4,9,7,11,400);



//========================================
//SERVO
//Servo servo;

void setup() {
  
  Serial.begin(9600);
}

void loop() {
  vehicle.execute();

}


