/**
 * Sketch for simple radar. Simple radar uses an ultrasound
 * sensor mounted on top of a servomotor and reporst to the Serial window
 * the distance of an object. It uses the Servo library to control the servo
 */
#include <Servo.h>

//create the object that represents the servomotor
Servo servo;

// variable to store the servo position
int pos = 0;    

void setup() {

  //attaches the servo on pin 9 to the servo object
  //pinMode is handled by the attach function
  servo.attach(9);

}

void rotate(){

  // goes from 0 degrees to 180 degrees in steps of 1 degree
  for (pos = 0; pos <= 180; pos += 1) { 

    // tell servo to go to position in variable 'pos'
    // waits 15ms for the servo to reach the position
    servo.write(pos);    
    delay(15);                       
  }

  // goes from 180 degrees to 0 degrees
  for (pos = 180; pos >= 0; pos -= 1) { 
    servo.write(pos);              
    delay(15);                       
  }

  
}

void loop() {
  rotate();
}
