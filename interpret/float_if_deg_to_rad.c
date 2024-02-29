#include "./test_interpretation.h"

#define PI 3.1415f

int main()
{
    float deg,rad,delta,x;
    deg = __VERIFIER_nondet_float();
    rad = PI * (deg / 180.0f);
    WRITE(f32, rad);
    delta = rad - PI / 2.0f;
    WRITE(f32, delta);
    x = delta < 0.0f ? -delta : delta;
    WRITE(f32, x);
    if (x < 0.001f)
        RET(1);
    RET(0);
}
