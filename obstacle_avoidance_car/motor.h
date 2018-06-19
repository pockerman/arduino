#ifndef MOTOR_H
#define MOTOR_H

namespace motors
{



  /**
   * class Motor models an electric motor controlled
   * via an L298N bridge. 
   */
  class Motor
  {
  
  public:
  
    /**
     * The default max speed the motor can reach
     */
    static int default_max_speed(){return 255;}
  
    /*
     * Constructor: Create a motor by passing the forward and backward pins as well
     * as the enable pin. Note that the enable pin must be PWM capable. Finally
     * there is also an option to set the maximum speed of the motor
     */
    Motor(const char* name, int f_pin,int b_pin,int e_pin,int max_speed=Motor::default_max_speed());
  
    
  
    /**
     * Enables the motor
     */
    void enable();
  
    /**
     * Disables the motor. Sets the e_pin_ to LOW
     */
     void disable();
  
    /**
     * Stops the motor
     */
    void stop();
  
   
  
    /**
     * Move the motor in the forward direction. This function simply sets the f_pin_ to HIGH and the b_pin_ to LOW
     */
    void forward(int speed);
  
    /**
     * Move the motor in the reverse direction. This function simply sets the f_pin_ to LOW and the b_pin_ to HIGH 
     */
     void backward(int speed);
  
    /**
     * Returns the id of the forward pin
     */
     int get_f_pin()const{return f_pin_;}
  
     /**
      * Returns the id of the backward pin
      */
      int get_b_pin()const{return b_pin_;}
  
  
  private:
  
    /**
     * The name of the motor
     */
    const char* name_;
  
    /**
     * The forward pin
     */
    int f_pin_;
  
    /**
     * The backward pin that is the pin for moving the motor
     * in the reverse direction than f_pin_
     */
    int b_pin_;
  
    /**
     * The enable pin. It must be PWM capable
     */
    int e_pin_;
  
    /**
     * The max speed  the motor is capable of
     */
    int max_speed_;
  
    //flag indicating if the motor is stopped
    bool is_stopped_;
  };
  
}//motors

#endif
