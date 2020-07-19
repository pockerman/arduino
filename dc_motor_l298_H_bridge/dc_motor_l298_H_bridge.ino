
const int IN1 = 8;
const int IN2 = 7;

// enable pin must be able to use PWM
const int ENA = 9;
const int speed = 200;

void setup() {

  // these are comming out of the
  // UNO board and into the L298N module
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  Serial.println("Forward...");

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed);

  //run the test for 2 seconds
  delay(2000);

  Serial.println("Backward...");

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speed);

  //run the test for 2 seconds
  delay(2000);

  // stop the motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, LOW);

}
