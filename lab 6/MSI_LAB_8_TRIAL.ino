void setup() {
  Serial.begin(9600);
  const int analogPin = A0;
}

void loop() {
  int sensor = analogRead(A0);
  float temp = sensor;
  Serial.println(temp);
  delay(1000);

}
