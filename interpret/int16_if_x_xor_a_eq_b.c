#include "./test_interpretation.h"

int main()
{
    short x;
    x = __VERIFIER_nondet_short();
    if ((x ^ (short)41853) == 12345) // (short)41853 == -23683; Without the cast the TRUE branch is UNREACHABLE!!!
        RET(1);
    RET(0);
}
