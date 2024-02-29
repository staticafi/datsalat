#include "./test_interpretation.h"
#include <stdlib.h>

int main()
{
    void* p = malloc(10);
    int i = __VERIFIER_nondet_int();
    free(p);
    if (i == 123)
    {
        CRASH(0);
        free(p);
    }
    RET(0);
}
