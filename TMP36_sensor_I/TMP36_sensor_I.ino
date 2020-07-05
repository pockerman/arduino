
/// Sketch for elementary use of 
/// a TMP36 temperature sensor

/// Analog reference voltage
const float AREF_V = 5.0;

/// the TMP36 analog pin
const int TEMP_PIN = A0;

/// the serial output rate
const unsigned int BAUD_RATE = 9600;


/// utility function to help in printing messages
void  do_print(const char*  text, float  value){

  Serial.print(text);
  Serial.print("\t");
  Serial.print(value);
  Serial.print("\n");
}

/// convert the given value to voltage
float to_voltage(int value){
  return AREF_V*value/1024;
}


/// convert the given voltage to temperature
/// measured in Celsius
float voltage_to_temp_C(float v){
  return (v*1000.0 -500)/10.0;
}

void setup() {
  Serial.begin(BAUD_RATE);
}

void loop() {

  // analog read
  const int output = analogRead(TEMP_PIN);
  float output_to_vol = to_voltage(output);
  float vol_to_temp = voltage_to_temp_C(output_to_vol);
  
  Serial.print("________________________\n");
  do_print("Output pf the sensor: ",output);
  do_print("Conversion to voltage: ",output_to_vol);
  do_print("Conversion to temperature: ",vol_to_temp);
  delay(1000);

}
