#include "./test_interpretation.h"


int main()
{
    int x;
    x = __VERIFIER_nondet_int();
    if (-x*x+6*x-8 == 0)  // Roots are: 2 and 4.
        RET(1);
    RET(0);
}
