#include "./test_interpretation.h"
#include <stdbool.h>

int main()
{
    short x1, y1, x2, y2;
    bool cond_1, cond_2;
    x1 = __VERIFIER_nondet_short();
    y1 = __VERIFIER_nondet_short();
    x2 = __VERIFIER_nondet_short();
    y2 = __VERIFIER_nondet_short();

    if (x1 == y1 + 123)
    {
        HIT();
        cond_1 = true;
    }
    else
    {
        HIT();
        cond_1 = false;
    }
    
    if (x2 != y2 + 123)
    {
        HIT();
        cond_2 = true;
    }
    else
    {
        HIT();
        cond_2 = false;
    }

    if (cond_1 == true)
    {
        HIT();
        if (cond_2 == true)
            RET(1);
    }

    RET(0);
}
