#include "./test_interpretation.h"

int main()
{
    int x;
    x = __VERIFIER_nondet_int();
    if (x >= 123456789)
        RET(1);
    RET(0);
}
