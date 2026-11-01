# American-Spaces-Design-Challenge--Surkhet
This repository contains codes of the  team that took part in  American Spaces Design Challenge.
These are the code used by paticipants to run their arduino projects.

## Motor command regression check

The `we makers.cpp` sketch clears the previous motor direction before applying
F/B/L/R, preventing stale reverse or forward pins after direction changes.
Run the host-side pin simulation with a C++ compiler:

```sh
c++ -std=c++11 tests/motor_commands.cpp -o /tmp/motor-commands-test
/tmp/motor-commands-test
```

This checks command transitions and LED/stop behavior. It does not validate the
physical wiring, motor driver timing, or operation on an Arduino board.
