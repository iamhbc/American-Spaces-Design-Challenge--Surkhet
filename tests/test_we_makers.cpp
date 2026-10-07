#include <cassert>

const int LOW = 0;
const int HIGH = 1;
const int OUTPUT = 1;

int pinValues[14] = {};

void pinMode(int, int) {}
void digitalWrite(int pin, int value) {
  pinValues[pin] = value;
  assert(!(pinValues[13] && pinValues[12]));
  assert(!(pinValues[11] && pinValues[10]));
}
void delay(int) {}

struct FakeSerial {
  int pending = -1;

  void begin(long) {}
  int available() { return pending >= 0; }
  char read() {
    char command = static_cast<char>(pending);
    pending = -1;
    return command;
  }
  void println(char) {}
};

FakeSerial Serial;

#include "../we makers.cpp"

void sendCommand(char command) {
  Serial.pending = command;
  loop();
}

void assertMotorState(int leftForward, int leftReverse, int rightForward, int rightReverse) {
  assert(pinValues[13] == leftForward);
  assert(pinValues[12] == leftReverse);
  assert(pinValues[11] == rightForward);
  assert(pinValues[10] == rightReverse);
}

int main() {
  setup();
  assertMotorState(LOW, LOW, LOW, LOW);

  sendCommand('F');
  assertMotorState(HIGH, LOW, HIGH, LOW);
  sendCommand('B');
  assertMotorState(LOW, HIGH, LOW, HIGH);
  sendCommand('F');
  assertMotorState(HIGH, LOW, HIGH, LOW);
  sendCommand('L');
  assertMotorState(LOW, LOW, HIGH, LOW);
  sendCommand('R');
  assertMotorState(HIGH, LOW, LOW, LOW);
  sendCommand('S');
  assertMotorState(LOW, LOW, LOW, LOW);

  sendCommand('F');
  loop();
  assertMotorState(HIGH, LOW, HIGH, LOW);
  sendCommand('W');
  assert(pinValues[9] == HIGH);
  assertMotorState(HIGH, LOW, HIGH, LOW);
  sendCommand('w');
  assert(pinValues[9] == LOW);
}
