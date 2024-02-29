#include "./test_interpretation.h"

int main()
{
    short x,y;
    x = __VERIFIER_nondet_short();
    y = __VERIFIER_nondet_short();
    if (x == y - 12345)
        RET(1);
    RET(0);
}
