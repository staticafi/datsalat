#include "./test_interpretation.h"
extern void abort();

void foo(int cond)
{
    if (!cond)
        ABORT();
}

int main()
{
    int x;
    x = __VERIFIER_nondet_int();
    foo(x < 123);
    RET(0);
}
