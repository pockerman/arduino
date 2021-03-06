#include <Servo.h>
#include <NewPing.h>

// Include the TimerOne Library from Paul Stoffregen
#include "TimerOne.h"

#include "motor.h"

//the speed at which the motors will spin during the test
const int MAX_SPEED = 100;

//the number of slots the encoder has
//change here to match otherwise
const int N_SLOTS = 20;

//the diameter of the wheels in mm
const float DIAMETER = 66.10;

//the circumference of the wheel. This is
//the distance the wheel travel in one full
//rotation
const float CIRCUMFERENCE = DIAMETER*3.14;


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

    //counter_A = 0;  //  reset counter A to zero
    //counter_B = 0;  //  reset counter B to zero

    //move forward at the given speed for the specified number of steps
    int n_steps = cm_to_steps(distance);

    //A.forward(speed);
   // B.forward(speed);

    // Go forward until step value is reached
    while (n_steps > counter_A && n_steps > counter_B){

      if(n_steps > counter_A){
        A.forward(speed);
      }
      else{
  
        A.stop();
      }

      if(n_steps > counter_B){
        B.forward(speed);
      }
      else{
  
        B.stop();
      }
     
   }

  //finally stop the motors
  stop_motors();

  counter_A = 0;  //  reset counter A to zero
  counter_B = 0;  //  reset counter B to zero
  
}

void turn_left(){
  
  counter_A = 0;  //  reset counter A to zero
  counter_B = 0;  //  reset counter B to zero
  
  A.forward(MAX_SPEED);
  B.stop();

  counter_A = 0;  //  reset counter A to zero
  counter_B = 0;  //  reset counter B to zero
  
}
 


void execute(){

   move_forward(50.0,MAX_SPEED);
  
   //wait for 0.5 seconds
  delay(500);

  //now turn left
  turn_left();

  //wait for 0.5 seconds
  delay(1500);

  //move forward
  move_forward(50.0,MAX_SPEED);

  //wait for 0.5 seconds
  delay(500);
  
}


void setup() {
  
  // Attach the Interrupts to their ISR's
  attachInterrupt(digitalPinToInterrupt (MOTOR_A), isr_countA, RISING);  // Increase counter A when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt (MOTOR_B), isr_countB, RISING);  // Increase counter B when speed sensor pin goes Hig


  //execute();
  
}

void loop() {

  //Serial.availabe will tell the board to look at the information
  //beign sent to it

  //delay(1000);

  //move_forward(50.0,MAX_SPEED);
  execute();
 
}


