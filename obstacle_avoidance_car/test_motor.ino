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
  
  Serial.begin(9600); 
}

void test1(){

  Serial.println("Running Test1");
  
  //MotorA spins forward and MotorB spins forward
  1
  
  A.forward(speed);
  B.forward(speed);

  //run the test for 2 seconds
  delay(2000);

  //finally stop the motors
  stop_motors();
  
}

void test2(){

  Serial.println("Running Test2");
  //MotorA spins forward and MotorB is stopped
  
  A.forward(speed);
  B.stop(); 

  //run the test for 2 seconds
  delay(2000);

  //finally stop the motors
  stop_motors();

}

void test3(){
  
  
  Serial.println("Running Test3");

  //MotorA spins backward and MotorB is stopped  
  

  A.backward(speed);
  B.stop();

  //run the test for 2 seconds
  delay(2000);

  //finally stop the motors
  stop_motors();

}


void test4(){
  
  Serial.println("Running Test4");

  //MotorA is stopped and MotorB spins forward  
  A.stop();
  B.forward(speed);

  //run the test for 2 seconds
  delay(2000);

  //finally stop the motors
  stop_motors();

}


void test5(){
  
  Serial.println("Running Test5");

  //MotorA is stopped and MotorB spins backward  
  A.stop();
  B.backward(speed);

  //run the test for 2 seconds
  delay(2000);

  //finally stop the motors
  stop_motors();

}

void test6(){
  
  Serial.println("Running Test6");

  //MotorA is stopped and MotorB is stopped 
  A.stop();
  B.stop();

  //run the test for 2 seconds
  delay(2000);

  //finally stop the motors
  stop_motors();
}

void test7(){
 
  Serial.println("Running Test7");

   //MotorA is spins backward and MotorB spins backward  
   A.backward(speed);
   B.backward(speed);

  //run the test for 2 seconds
  delay(2000);

  //finally stop the motors
  stop_motors();

}

void test8(){

  //accelerates both motors
  for(int i=0; i<256; i++){

    A.forward(i);
    B.forward(i);

    delay(20);
  }

  //decelerate from max to zero
  for(int i=255; i>=0; i--){

    A.forward(i);
    B.forward(i);

    delay(20);
  }

   //finally stop the motors
   stop_motors();
  
}



void loop() {

  //Serial.availabe will tell the board to look at the information
  //beign sent to it
  if (Serial.available() > 0){

    Serial.println("Serial input is available....");
    
    char cmd = Serial.read();
    

    //let's see what Arduino is receiving to be certain
    Serial.print("cmd received: ");
    Serial.println(cmd);
    

    switch(cmd)
    {
      
      case '1':
      {
        test1();
        delay(1000);
        break;
      }
      case '2':
      {
        test2();
        delay(1000);
        break;
      }
      
      case '3':
      {
        test3();
        delay(1000);
        break;
      }
      case '4':
      {
        test4();
        delay(1000);
        break;
      }
      case '5':
      {
        test5();
        delay(1000);
        break;
      }
      case '6':
      {
        test6();
        delay(1000);
        break;
      }
      case '7':
      {
        test7();
        delay(1000);
        break;
      }
      case '8':
      {
        test8();
        delay(1000);
        break;
      }
      default:
      {
        Serial.print("Invalid cmd given: ");
        Serial.println(cmd);
        Serial.println("Stopping the motors");
         
        stop_motors();
      }
    }

  }

}


