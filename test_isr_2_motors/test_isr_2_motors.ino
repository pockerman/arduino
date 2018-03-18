

/**
 * Test ISR for two motors. The sketch has been taken from
 * the following YouTub tutorial:
 * 
 * https://www.youtube.com/watch?v=oQQpAACa3ac&t=2s
 */

//Use TimerOne library to work with the internal timers 
#include "TimerOne.h"

const byte MTR1 = 2; //Motor 1 interrupt pin INT 0
const byte MTR2 = 3; //Motor 2 interrupt pin INT 1

//pulse counters
unsigned int counter1 = 0;
unsigned int counter2 = 0;

//this denotes the number of slots in encoder disk
//ADAPT APPROPRIATELY
float diskslots = 20.0;

//ISRs

void ISR_count1()
{

  counter1++;
}

void ISR_count2()
{

  counter2++;
}

//TimerOne ISR
void ISR_timerone()
{

  //stop the timer because we want to use
  //the Serial.print
  Timer1.detachInterrupt();

  Serial.print("Motor Speed 1: ");

  //calculate RPMs for Motor1
  float rotation1 = (counter1 / diskslots) * 60.0;

  Serial.print(rotation1);
  Serial.print("RPM - ");
  counter1 = 0;

  float rotation2 = (counter2 / diskslots) * 60.0;
  Serial.print(rotation2);
  Serial.print("RPM - ");
  counter2 = 0;

  //enable the timer
  Timer1.attachInterrupt(ISR_timerone);
  
}


void setup() 
{

  Serial.begin(9600);

  //set timer for 1 sec
  Timer1.initialize(1000000);

  //increase counter 1 when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt (MTR1), ISR_count1, RISING);

  //increase counter 2 when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt (MTR2), ISR_count2, RISING);

  //enable the timer
  Timer1.attachInterrupt(ISR_timerone);
}

void loop() 
{

  //Nothing to do in the loop

}
