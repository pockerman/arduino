/**
 * Sketch to drive a differential drive robot
 * with optical sensors to sense motion and ultrasound
 * sound to sense obstacles
 */

#include <NewPing.h>

#include "motor.h"

//the speed at which the motors will spin during the test
const int MAX_SPEED = 100;

const int TURN_SPEED = 100;

//the number of slots the encoder has
//change here to match otherwise
const int N_SLOTS = 20;

//the diameter of the wheels in mm
const float DIAMETER = 66.10;

//the circumference of the wheel. This is
//the distance the wheel travel in one full
//rotation
const float CIRCUMFERENCE = DIAMETER*3.14;


//Trigger PIN for HC-SR04 sensor
const int TRIG_PIN = 10;

//Echo PIN for HC-SR04 sensor
const int ECHO_PIN = 13;

//Maximum distance that HC-SR04 has in cm
const float MAX_DIST = 400.0F;
NewPing sonar(TRIG_PIN,ECHO_PIN,MAX_DIST);

//the safety distance form the obstacle in cm
const float SAFETY_DISTANCE = 20.0F;

//current distance from sensed obstacle
float distance = 0.0F;

//helpful enumeration of the action space of the robot
enum Action{MOVE_FRWD, MOVE_BWRD, TURN_LEFT, TURN_RIGHT, STOP};

//the current action the robot undertakes
Action current_action = STOP;


// Integers for pulse counters
volatile unsigned int counter_A = 0;
volatile unsigned int counter_B = 0;


// Constants for Interrupt Pins
// Change values if not using Arduino Uno
 
const byte MOTOR_A = 2;  // Motor A Interrupt Pin  - Right Motor 
const byte MOTOR_B = 3;  // Motor B Interrupt Pin  - Left Motor

//The two motors we use for testing.
//The constructor of the motors::Motor object class
//
// pinMode(f_pin_,OUTPUT);
// pinMode(b_pin_,OUTPUT);
// pinMode(e_pin_,OUTPUT);
//Remark ENA and ENB pins must be PWM capable

//Motor A uses IN1 = 8, IN2 = 7 and ENA = 9
//this is also the assumed right motor in our assembly
motors::Motor A('A',8,7,9);

//Motor B uses IN4 = 4, IN3 = 5 ENB = 6
//this is also the assumed left motor in our assembly
motors::Motor B('B',4,5,6);

//helper to stop both motors after a test run
void stop_motors(){
  A.stop();
  B.stop();
}



// Motor A pulse count ISR
void isr_countA()  {
  counter_A++;  // increment Motor 1 counter value
  
} 

// Motor B pulse count ISR
void isr_countB()  {
  counter_B++;  // increment Motor A counter value
} 


// Function to convert from centimeters to steps
int cm_to_steps(float cm) {
 
  int result = 0;  // Final calculation result
  float circumference_cm = CIRCUMFERENCE / 10.; // Calculate wheel circumference in cm
  float cm_step = circumference_cm / N_SLOTS;  // CM per Step
  
  float f_result = cm / cm_step;  // Calculate result as a float
  result = static_cast<int>( f_result ); // Convert to an integer (note this is NOT rounded)
  
  return result;  // End and return result
 
}

void move_forward(float distance, int speed){

    counter_A = 0;  //  reset counter A to zero
    counter_B = 0;  //  reset counter B to zero

    int n_steps = cm_to_steps(distance);

    while (n_steps > counter_A && n_steps > counter_B){

        A.forward(speed);
        B.forward(speed);  
   }

   counter_A = 0;  //  reset counter A to zero
   counter_B = 0;  //  reset counter B to zero
}


void move_backward(float distance, int speed){

  counter_A = 0;  //  reset counter A to zero
  counter_B = 0;  //  reset counter B to zero

  int n_steps = cm_to_steps(distance);
  
  while (n_steps > counter_A && n_steps > counter_B){
    A.backward(speed);
    B.backward(speed);
  }

  counter_A = 0;  //  reset counter A to zero
  counter_B = 0;  //  reset counter B to zero
  
}

void turn_left(int speed){
  counter_A = 0;  //  reset counter A to zero
  counter_B = 0;  //  reset counter B to zero
  A.forward(speed);
  B.stop();
  counter_A = 0;  //  reset counter A to zero
  counter_B = 0;  //  reset counter B to zero
 
}


void turn_right(int speed){
  counter_A = 0;  //  reset counter A to zero
  counter_B = 0;  //  reset counter B to zero
  
  A.stop();
  B.forward(speed);
  counter_A = 0;  //  reset counter A to zero
  counter_B = 0;  //  reset counter B to zero
 
}

 
void setup() {

  //ENABLE FOR TESTING
  //Serial.begin(9600);
  
  // Attach the Interrupts to their ISR's
  attachInterrupt(digitalPinToInterrupt (MOTOR_A), isr_countA, RISING);  // Increase counter A when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt (MOTOR_B), isr_countB, RISING);  // Increase counter B when speed sensor pin goes Hig 

   sense();
}


void sense(){

  distance = sonar.ping_cm();
}

void think(){

  //decision is made based on distance
  
  if(distance-SAFETY_DISTANCE < 1.0e-3){

    current_action = MOVE_BWRD; 
  }
  else if(current_action == MOVE_BWRD){

    current_action = TURN_LEFT;
  }
  else if(current_action == TURN_LEFT){

    current_action = TURN_RIGHT;
  }
  else if(current_action == TURN_RIGHT){

    current_action = MOVE_FRWD;
     
  }
  else if(distance-SAFETY_DISTANCE > 10.){

    current_action = MOVE_FRWD;
    
  }
  
}


void act(){

  if(current_action == MOVE_FRWD){

    move_forward(10.0,MAX_SPEED);
  }
  else if(current_action == MOVE_BWRD){

    move_backward(10.0,MAX_SPEED);
  }
  else if(current_action == TURN_LEFT){

    turn_left(TURN_SPEED);
    
  }
  else if(current_action == TURN_RIGHT){

    turn_right(TURN_SPEED);
    
  }

  stop_motors();
  
}

void loop() {

    /*
     * ENABLE FOR TESTING
    if(current_action == MOVE_FRWD){

        Serial.print("Current distance:");
        Serial.println(distance);
        Serial.println("Action:  MOVE_FRWD");
        
    }
    else if(current_action == MOVE_BWRD){

      Serial.print("Current distance:");
      Serial.println(distance);
      Serial.println("Action:  MOVE_BWRD");
    }
    else if(current_action == TURN_LEFT){

      Serial.print("Current distance:");
      Serial.println(distance);
      Serial.println("Action:  TURN_LEFT");
    }
    else if(current_action == TURN_RIGHT){

      Serial.print("Current distance:");
      Serial.println(distance);
      Serial.println("Action:  TURN_RIGHT");
    
    }
    */

    sense();
    think();
    act();

}


