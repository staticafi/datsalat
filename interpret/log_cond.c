#include "./test_interpretation.h"
#include <stdbool.h>

int main()
{
    char a,b;
    bool z;
    a = __VERIFIER_nondet_char();
    b = __VERIFIER_nondet_char();
    z = (a == 12 || !(b == 21 && a != 123));
    RET((int)z);
}
