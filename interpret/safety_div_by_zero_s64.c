#include "./test_interpretation.h"

int main()
{
    int64_t a = __VERIFIER_nondet_longlong();
    int64_t b = __VERIFIER_nondet_longlong();
    if (b == 0) CRASH(0);
    int64_t c = a / b;
    WRITE(s64, c);
    RET(0);
}
