#include "./test_interpretation.h"

int main()
{
    uint32_t a = __VERIFIER_nondet_uint();
    uint32_t b = __VERIFIER_nondet_uint();
    if (b == 0) CRASH(0);
    uint32_t c = a / b;
    WRITE(u32, c);
    RET(0);
}
