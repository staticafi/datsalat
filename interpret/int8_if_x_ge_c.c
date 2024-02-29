#include "./test_interpretation.h"

int main()
{
    char x;
    x = __VERIFIER_nondet_char();
    if (x >= 123)
        RET(1);
    RET(0);
}
