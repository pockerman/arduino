#ifndef MOTOR_H
#define MOTOR_H



class Motor
{

public:

  //default max speed
  static int default_max_speed(){return 255;}

  //Constructor
  Motor(int dir1,int dir2,int enable_pin,int max_speed=Motor::default_max_speed());

  //simulatneously write to the
  //direction and pwm pins
  //void write(int dp_status,int pwmp_status);

  //enable the motor
  void enable();

  //start the motor at the given speed
  //void start(int speed);

  //stop the motor
  void stop();

  //set the motor to off
  void off();

  //move forward
  void forward();


private:

  //the direction pin
  int dir1_;

  //PWM pin
  int dir2_;

  //enable pin
  int enable_pin_;

  //max speed of the motor
  int max_speed_;

  //flag indicating if the motor is stopped
  bool is_stopped_;
};

#endif
