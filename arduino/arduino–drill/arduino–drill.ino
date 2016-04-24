// these constants won't change:

const int gun = A0; // the piezo is connected to analog pin 0

// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin

void setup() {
  Serial.begin(9600);       // use the serial port
}

void loop() {
  sensorReading = 0;
  sensorReading = analogRead(gun);
//  sensorReading = map(sensorReading, 1023,0,0, 100);
  if (sensorReading < 450) {
    sensorReading = 400;
  }
  sensorReading = map(sensorReading, 400,1023,0, 130);
  Serial.write(sensorReading);
//  Serial.println(sensorReading);
  delay(100);  // delay to avoid overloading the serial port buffer
}
