// Host-side pin-state regression test; no Arduino hardware is used.
#include <cassert>
constexpr int HIGH = 1, LOW = 0, OUTPUT = 1;
int pins[14] = {};
void pinMode(int, int) {}
void delay(int) {}
void digitalWrite(int pin, int value) {
    pins[pin] = value;
    assert(!(pins[13] && pins[12]));
    assert(!(pins[11] && pins[10]));
}
struct SerialStub {
    char next = 0;
    void begin(int) {}
    bool available() { return next != 0; }
    char read() { char value = next; next = 0; return value; }
    void println(char) {}
} Serial;
#include "../we makers.cpp"
void command(char value, int lf, int lr, int rf, int rr) {
    Serial.next = value;
    loop();
    assert(pins[13] == lf && pins[12] == lr);
    assert(pins[11] == rf && pins[10] == rr);
}
int main() {
    setup();
    command('F', 1, 0, 1, 0);
    command('B', 0, 1, 0, 1);
    command('F', 1, 0, 1, 0);
    command('L', 0, 0, 1, 0);
    command('R', 1, 0, 0, 0);
    command('W', 1, 0, 0, 0);
    assert(pins[9] == HIGH);
    command('w', 1, 0, 0, 0);
    assert(pins[9] == LOW);
    command('S', 0, 0, 0, 0);
}
