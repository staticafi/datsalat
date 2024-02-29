#include "./test_interpretation.h"

int main()
{
    int32_t a = __VERIFIER_nondet_int();
    int32_t b = __VERIFIER_nondet_int();
    if (b == 0) CRASH(0);
    int32_t c = a / b;
    WRITE(s32, c);
    RET(0);
}
