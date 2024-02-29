#include "./test_interpretation.h"

int main()
{
    int x, y;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    if (x < 0)
        RET(1);
    if (x > 3)
        RET(2);
    if (y < 0)
        RET(3);
    if (y > 23)
        RET(4);
    RET(0);
}
