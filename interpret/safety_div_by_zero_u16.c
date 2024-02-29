#include "./test_interpretation.h"

int main()
{
    uint16_t a = __VERIFIER_nondet_ushort();
    uint16_t b = __VERIFIER_nondet_ushort();
    if (b == 0) CRASH(0);
    uint16_t c = a / b;
    WRITE(u16, c);
    RET(0);
}
