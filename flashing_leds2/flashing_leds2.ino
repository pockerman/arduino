/**
 * This tutorial uses Arduino to flash a given number of LEDs
 */


 //array with the LDE pins. We use 3 LEDs
 int led_pins[]={8,10,12};

 //indicates some delay
 int time_delay = 75;

 
void setup() {
  //we need to set the mode before using any 
  //of the pins
  for(int i=0; i<3; ++i){
    pinMode(led_pins[i],OUTPUT);
  }

}

void loop() {

  //simply loop over the pins
  //and do some work
  for(int i=0; i<3; i++){
    digitalWrite(led_pins[i],HIGH);
    delay(time_delay);
    digitalWrite(led_pins[i], LOW);
    delay(time_delay);
  }

}
