#include "./test_interpretation.h"

int main()
{
    short x;
    x = __VERIFIER_nondet_short();
    if (x >= 12345)
        RET(1);
    RET(0);
}
