/*
 * Rotate a servo mechanism in the range [-90, 90] degrees 
 * 
 */

#include <Servo.h>

//The servo object to control
Servo servo;


// the servo PIN
const int SERVO_PIN = 9;

// Servo position delay default is 15ms
const int SERVO_POS_DELAY_TIME = 15;

// The servo position
int s_pos = 0;

void rotate_90(){

  for(s_pos = 0; s_pos <= 180; s_pos +=1){

    servo.write(s_pos);
    delay(SERVO_POS_DELAY_TIME);
  }
  
}

void rotate_back_90(){

  for(s_pos = 180; s_pos >= 0; s_pos -=1){

    servo.write(s_pos);
    delay(SERVO_POS_DELAY_TIME);
  }
  
}

void setup() {
  // put your setup code here, to run once:
  servo.attach(SERVO_PIN);

}

void loop() {
  // put your main code here, to run repeatedly:
  rotate_90();
  rotate_back_90();
  
}
