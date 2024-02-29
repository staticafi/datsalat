#include "./test_interpretation.h"

int main()
{
    int16_t a = __VERIFIER_nondet_short();
    int16_t b = __VERIFIER_nondet_short();
    if (b == 0) CRASH(0);
    int16_t c = a / b;
    WRITE(s16, c);
    RET(0);
}
