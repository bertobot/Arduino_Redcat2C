#ifndef __Redcat2C_h_
#define __Redcat2C_h_

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#include <Servo.h>

class Redcat2C {
private:
    Servo mMotor, mSteer;
    int mMin, mMax;

public:
    Redcat2C(int mpin, int spin, int tmin=1000, int tmax=2000);
    virtual ~Redcat2C();

    void arm(int dur=3100);
    void throttle(int p);
    void throttlef(float percent);
    void turn(int angle);
    void move(int p, int a);
    void move(float p, int a);
};

#endif

