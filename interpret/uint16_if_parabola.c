#include "./test_interpretation.h"

int main()
{
    unsigned short x;
    x = __VERIFIER_nondet_ushort();
    if (-x*x+(unsigned short)6*x-(unsigned short)8 == (unsigned short)0)  // Roots are: 2 and 4.
        RET(1);
    RET(0);
}
