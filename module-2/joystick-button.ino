int xyzPins[] = {27, 26, 2};   //x,y,z pins
void setup() {
  Serial.begin(115200);
  // pinMode(xyzPins[2], INPUT_PULLUP);  //z axis is a button.
  pinMode(22, INPUT_PULLUP);  //button.
}
void loop() {
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);
  Serial.printf("X,Y,Z: %d,\t%d,\t%d\n", xVal, yVal, zVal);
  // Serial.printf(zVal);
  int buttonVal = digitalRead(22);
  Serial.print(buttonVal);
  Serial.print('\n');
  delay(500);
}
