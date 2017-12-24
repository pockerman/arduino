/**
 * Simple program that flashes on and off Arduino's embedded LED
 */


void setup() {

  //we need to set the mode of the pin before
  //using it. Arduino's embedded LED is connected
  //to pin 13
  pinMode(13,OUTPUT);

}

void loop() {

  digitalWrite(13,HIGH);
  delay(1000); // delay 1000 milliseconds
  digitalWrite(13,LOW);
  delay(1000);

}
