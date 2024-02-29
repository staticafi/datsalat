#include "./test_interpretation.h"
#include <math.h>

int main()
{
    float x;
    x = __VERIFIER_nondet_float();
    if (x == (float)cos(x)) // solution: 0.7390851378440856934
        RET(1);
    RET(0);
}
