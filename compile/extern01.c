#include <stdbool.h>

extern char __VERIFIER_nondet_char();
extern short __VERIFIER_nondet_short();
extern short HULA;

int main()
{
    char c;
    short n;
    c = __VERIFIER_nondet_char();
    n = HULA;
    HULA = __VERIFIER_nondet_short();
    return 0;
}
