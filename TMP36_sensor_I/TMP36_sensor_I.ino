
/**
 * Sketch for elementary use of a TMP36 
 * temperature sensor
 */

void  do_print(const char*  text, float  value);

float to_voltage(int value){

  return 5.0*(value/1024.0);
}

float voltage_to_temp_C(float V){

  return 100.0*(V -0.5);
}

void setup() {
  Serial.begin(9600);
}

void loop() {

  //analog read
  const int output = analogRead(A3);
  float output_to_vol = to_voltage(output);
  float vol_to_temp = voltage_to_temp_C(output_to_vol);
  
  Serial.print("________________________\n");
  do_print("Output pf the sensor: ",output);
  do_print("Conversion to voltage: ",output_to_vol);
  do_print("Conversion to temperature: ",vol_to_temp);
  delay(1000);

}

void  do_print(const char*  text, float  value){

  Serial.print(text);
  Serial.print("\t");
  Serial.print(value);
  Serial.print("\n");
}

