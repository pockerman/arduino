/**
 * This sketch controls a signle LED
 */

#define PIN_ID 12
int time_delay = 75;
void setup() {

  //we need to set the mode before using any 
  //of the pins
  pinMode(PIN_ID,OUTPUT);
  
}

void loop() {
  digitalWrite(PIN_ID,HIGH);
  delay(time_delay);
  digitalWrite(PIN_ID, LOW);
  delay(time_delay);

}
