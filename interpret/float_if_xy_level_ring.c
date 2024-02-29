#include "./test_interpretation.h"
#include <math.h>

int main()
{
    float x,y,z;
    x = __VERIFIER_nondet_float();
    y = __VERIFIER_nondet_float();
    z = x*x + y*y;
    WRITE(f32, z);
    if (123.25f < z && z < 123.75f)
        RET(1);
    RET(0);
}
