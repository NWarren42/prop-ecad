//analog pin to read
#define TC_PIN A0

//amplifier constants
float bias = 1;
float gain = 1 + (461.7)/(2.01);

//linear seeback coefficient
float seeback_coeff = 40e-6;

float volt = 0;
float temp = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //read analog pin
  volt = analogRead(TC_PIN) * (5.0 / 1023.0);
  
  //convert to temperature
  temp = (volt - bias) / (gain * seeback_coeff);

  Serial.print("Raw Voltage: ");
  Serial.println(volt, 5);

  Serial.print("Temperature (C): ");
  Serial.println(temp, 4);
  Serial.println();

  delay(1000);
}
