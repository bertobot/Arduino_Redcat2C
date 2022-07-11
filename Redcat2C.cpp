#include "Redcat2C.h"

Redcat2C::Redcat2C(int mpin, int spin, int tmin, int tmax) {
    mMotor.attach(mpin);
    mSteer.attach(spin);

    mMin = tmin;
    mMax = tmax;
}

Redcat2C::~Redcat2C() {
    mMotor.detach();
    mSteer.detach();
}

void Redcat2C::arm(int dur) {
    throttle(50);
    delay(dur);
}

void Redcat2C::throttle(int p) {
    mMotor.writeMicroseconds(map(p, 0, 100, mMin, mMax));
}

void Redcat2C::throttlef(float percent) {
    int v = int((mMin + (mMax - mMin)) * percent);
    throttle(v);
}

void Redcat2C::turn(int angle) {
    mSteer.write(map(angle, 0, 180, 0, 180));
}

void Redcat2C::move(int p, int a) {
    throttle(p);
    turn(a);
}

void Redcat2C::move(float p, int a) {
    throttlef(p);
    turn(a);
}

