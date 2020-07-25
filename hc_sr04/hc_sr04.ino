///
/// This sketch shows how to use the HC-SR04 sensor
///

 
const int TRIG_PIN = 10;
const int ECHO_PIN = 13;
float duration = 0.0f;
float distance = 0.0f;

void setup() {

  Serial.begin(9600);


  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);

}

void loop() {

  /// write a pulse to the HC-SR04 trigger pin
  /// effectively creates a 10 microsecond pulse
  digitalWrite(TRIG_PIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN,LOW);

  /// Measure the response from the HC-SR04 echo pin
  /// measure how long the pulse stays high
  duration = pulseIn(ECHO_PIN,HIGH);

  /// Determine distance from duration. Use 343 meters 
  /// per second as speed of sound. Duration is divided by two 
  /// as the signal also includes the return trip time
   
  distance = (duration*0.5)*0.0343;

  /// use the serial monitor to print the results
  Serial.print("Distance is = ");

  /// the sensor has maximum 400 cm and minimum 2 cm
  /// anything outside this range is invalid
  if(distance >= 400. || distance <= 2.0){

      Serial.print("Out of range");
  }
  else{
    
    Serial.print(distance);
    Serial.print(" cm");
    
  }

}
