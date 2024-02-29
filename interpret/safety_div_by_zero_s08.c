#include "./test_interpretation.h"

int main()
{
    int8_t a = __VERIFIER_nondet_char();
    int8_t b = __VERIFIER_nondet_char();
    if (b == 0) CRASH(0);
    int8_t c = a / b;
    WRITE(s8, c);
    RET(0);
}
