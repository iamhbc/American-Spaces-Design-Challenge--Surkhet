# American Spaces Design Challenge - Surkhet

This repository contains three Arduino project sketches submitted by participants in the American Spaces Design Challenge.

The native regression test for the Bluetooth motor-control sketch can be run with a C++ compiler:

```sh
c++ -std=c++11 -Wall -Wextra -Werror tests/test_we_makers.cpp -o /tmp/test_we_makers
/tmp/test_we_makers
```

The remaining sketches require an Arduino toolchain and the `Servo` library for `We designers.cpp`. This repository does not specify a target board or provide Arduino build scripts.
