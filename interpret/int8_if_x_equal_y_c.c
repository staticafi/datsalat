#include "./test_interpretation.h"

int main()
{
    char x,y;
    x = __VERIFIER_nondet_char();
    y = __VERIFIER_nondet_char();
    if (x == y-123)
        RET(1);
    RET(0);
}
