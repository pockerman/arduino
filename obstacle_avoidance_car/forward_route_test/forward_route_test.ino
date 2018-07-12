#include <Servo.h>
#include <NewPing.h>


#include "motor.h"

//the test speed at which the motors will spin during the tests
const int speed = 200;

//The two motors we use for testing.
//The constructor of the motors::Motor object class
//
// pinMode(f_pin_,OUTPUT);
// pinMode(b_pin_,OUTPUT);
// pinMode(e_pin_,OUTPUT);
//Remark ENA and ENB pins must be PWM capable

//Motor A uses IN1 = 8, IN2 = 7 and ENA = 9
motors::Motor A('A',8,7,9);

//Motor B uses IN4 = 4, IN3 = 5 ENB = 3
motors::Motor B('B',4,5,3);

//helper to stop both motors after a test run
void stop_motors(){
  A.stop();
  B.stop();
}


void setup() {
  
  //nothing to do here
}

void loop() {

  //Serial.availabe will tell the board to look at the information
  //beign sent to it

  delay(1000);

  A.forward(speed);
  B.forward(speed);

   //run the test for 2 seconds
  delay(20000);

  //finally stop the motors
  stop_motors();
 
}


