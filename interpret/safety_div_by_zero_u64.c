#include "./test_interpretation.h"

int main()
{
    uint64_t a = __VERIFIER_nondet_ulonglong();
    uint64_t b = __VERIFIER_nondet_ulonglong();
    if (b == 0) CRASH(0);
    uint64_t c = a / b;
    WRITE(u64, c);
    RET(0);
}
