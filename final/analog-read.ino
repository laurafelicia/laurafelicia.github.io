int xyzPins[] = {12, 15, 21, 36}; //x,y,z pins

void setup() {
  Serial.begin(115200);
  pinMode(xyzPins[0], INPUT_PULLUP); //x axis controls pitch.
  pinMode(xyzPins[1], INPUT_PULLUP); //y axis controls volume (not working)
  pinMode(xyzPins[2], INPUT_PULLUP); //z axis is a button to repeat song.
  pinMode(xyzPins[3], INPUT_PULLUP); //button to pause and play
}
void loop() {

  //For joystick
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);

  Serial.print(xVal, DEC);
  Serial.print(",");
  Serial.print(yVal, DEC);
  Serial.print(",");
  Serial.print(zVal, DEC);
  Serial.print(",");
  Serial.print('\n');
  delay(100);
  
}