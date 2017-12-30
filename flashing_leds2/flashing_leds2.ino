/**
 * This tutorial uses Arduino to flash a given number of LEDs. It also
 * assumes that a button is used that is dealt via an interrupt
 */

volatile int state = LOW;

 //array with the LDE pins. We use 3 LEDs
 int led_pins[]={8,10,12};

 //indicates some delay
 int time_delay = 75;

 int pause = 500;

 
void setup() {
  //we need to set the mode before using any 
  //of the pins
  for(int i=0; i<3; ++i){
    pinMode(led_pins[i],OUTPUT);
  }

  //initialize the interrupt
  attachInterrupt(0, ledOnOff, RISING);

}

void loop() {

  //simply loop over the pins
  //and do some work
 if (state) {
    for (int i=0; i<3; i++){
      digitalWrite(led_pins[i], HIGH);
      delay(time_delay);
    }
  
    delay(pause);
  
    for (int i=0; i<3; i++){
      digitalWrite(led_pins[i], LOW);
      delay(time_delay);
    }

    delay(pause);
  }
}

void ledOnOff() {
  static unsigned long lastMillis = 0;
  unsigned long newMillis = millis();

  //perform Debounce check
  if (newMillis - lastMillis < 50){
  }
  else {
    state = !state;
    lastMillis = newMillis;
  }
}
