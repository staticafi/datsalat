#include "./test_interpretation.h"

int main()
{
    int x,y;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    if (x == y - 123456789)
        RET(1);
    RET(0);
}
