/**
 * Sketch for simple radar. Simple radar uses an ultrasound
 * sensor mounted on top of a servomotor and reporst to the Serial window
 * the distance of an object. It uses the Servo library to control the servo.
 * It uses the NewPing library to control the ultrasound sensor
 */
#include <Servo.h>
#include <NewPing.h>



//create the object that represents the servomotor
Servo servo;

// variable to store the servo position
int pos = 0;



int TRIGPIN = 7;
int ECHOPIN = 11;
int MAX_DIST = 40; //cm 
NewPing sensor(TRIGPIN,ECHOPIN,MAX_DIST);

//the time to delay the rotation. Depending on the servomotor
//load you may have to adjust this value
int time_delay = 15;    

void setup() {

  //attaches the servo on pin 9 to the servo object
  //pinMode is handled by the attach function
  servo.attach(9);

  //we need to set the pin modes for
  //the NewPing library
  pinMode(ECHOPIN,INPUT);
  pinMode(TRIGPIN,OUTPUT);
  Serial.begin(9600);

}

void rotate(){

  // goes from 0 degrees to 180 degrees in steps of 1 degree
  for (pos = 0; pos <= 180; pos += 1) { 

    // tell servo to go to position in variable 'pos'
    // waits 15ms for the servo to reach the position
    servo.write(pos);    
    delay(time_delay);                       
  }

  // goes from 180 degrees to 0 degrees
  for (pos = 180; pos >= 0; pos -= 1) { 
    servo.write(pos);              
    delay(time_delay);                       
  }

  
}

void sense(){

  float distance = sensor.ping_cm();
  Serial.print(distance);
  Serial.print(" cm\n");
  
}

void loop() {
 
  sense();
  rotate();
}
