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

TwoMotorsVehicle vehicle(2,3,10,5,4,9);


//=========================================
//SENSOR

//the sensor
const unsigned int PING_SENSOR_IO_PIN = 7;

//echo pin
const int ECHO_PIN = 11;

//maximum distance of the sensor
const unsigned int MAX_DIST = 200;
NewPing sensor(PING_SENSOR_IO_PIN,ECHO_PIN,MAX_DIST);
//========================================

//========================================
//SERVO
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  vehicle.move_forward();

}


