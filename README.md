# Redcat Everest 10 via Arduino
This repo is an Arduino interface for any 2-Channel RC car.  I created this to interface with a Redcat Everest 10 Crawler.

## Synopsis

```c++
#include <Redcat2C.h>

Redcat2C *car;

void setup() {
    car = new Redcat2C(9, 10);  // connect motor to pin 9, steer to pin 10
    car->arm();                // arms the ESC, will wait for 3s

    delay(1000);

    // turn the wheel left and right
    car->turn(60);      // left
    delay(1000);
    car->turn(120);   // right
    delay(1000);
    car->turn(90);    // center

    delay(3000);
}

void loop() {
    // forward, backward movement
    car->throttle(100); // full speed ahead
    car->throttle(0);   // full reverse
    car->throttle(50);  // stop

    // turning
    car->turn(80);      // turn 10 degrees left
    car->turn(100);     // turn 10 degrees right

    // move and turn
    car->move(85, 90);  // forward 85%, center steer
    car->move(85, 80);  // forward 85%, turning left 10 degrees
    car->move(85, 100); // forward 85%, turning right 10 degrees

    delay(100);
}
```
