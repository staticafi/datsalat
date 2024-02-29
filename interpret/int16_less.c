#include "./test_interpretation.h"

int main()
{
    short x, y;
    x = __VERIFIER_nondet_short();
    y = __VERIFIER_nondet_short();
    if (x < -10)
        RET(1);
    if (x > -1)
        RET(2);
    if (x >= y)
        RET(3);
    if (x + 50 > 2*y)
        RET(4);
    RET(0);
}
