#include "./test_interpretation.h"

int main()
{
    uint8_t a = __VERIFIER_nondet_uchar();
    uint8_t b = __VERIFIER_nondet_uchar();
    if (b == 0) CRASH(0);
    uint8_t c = a / b;
    WRITE(u8, c);
    RET(0);
}
