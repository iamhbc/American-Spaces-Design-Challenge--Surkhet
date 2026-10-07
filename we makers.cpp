void setMotorOutputs(bool leftForward, bool leftReverse, bool rightForward, bool rightReverse) {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  if (leftForward) digitalWrite(13, HIGH);
  if (leftReverse) digitalWrite(12, HIGH);
  if (rightForward) digitalWrite(11, HIGH);
  if (rightReverse) digitalWrite(10, HIGH);
}

void setup() {
  pinMode(13, OUTPUT);  // left motors forward
  pinMode(12, OUTPUT);  // left motors reverse
  pinMode(11, OUTPUT);  // right motors forward
  pinMode(10, OUTPUT);  // right motors reverse
  pinMode(9, OUTPUT);   // LED
  setMotorOutputs(false, false, false, false);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    Serial.println(command);

    if (command == 'F') {
      setMotorOutputs(true, false, true, false);
    } else if (command == 'B') {
      setMotorOutputs(false, true, false, true);
    } else if (command == 'L') {
      setMotorOutputs(false, false, true, false);
    } else if (command == 'R') {
      setMotorOutputs(true, false, false, false);
    } else if (command == 'S') {
      setMotorOutputs(false, false, false, false);
    } else if (command == 'W') {
      digitalWrite(9, HIGH);
    } else if (command == 'w') {
      digitalWrite(9, LOW);
    }
  }
  delay(100);
}
