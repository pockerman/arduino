
/**
 * Sketch for elementary use of a TMP36 
 * temperature sensor
 */

void  mprint(const char*  text, float  value);

void setup() {
  Serial.begin(9600);
}

void loop() {

  //analog read
  const int output = analogRead(A3);
  float output_to_vol = 5.0*(output/1024.0);
  float vol_to_temp = 100.0*(output_to_vol -0.5);
  
  Serial.print("________________________\n");
  mprint("Output pf the sensor: ",output);
  mprint("Conversion to voltage: ",output_to_vol);
  mprint("Conversion to temperature: ",vol_to_temp);
  delay(1000);

}

void  mprint(const char*  text, float  value){

  Serial.print(text);
  Serial.print("\t");
  Serial.print(value);
  Serial.print("\n");
}

