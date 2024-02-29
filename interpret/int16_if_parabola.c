#include "./test_interpretation.h"

int main()
{
    short x;
    x = __VERIFIER_nondet_short();
    if (-x*x+(short)6*x-(short)8 == (short)0)  // Roots are: 2 and 4.
        RET(1);
    RET(0);
}
