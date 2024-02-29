#include "./test_interpretation.h"

int main()
{
    switch (__VERIFIER_nondet_int())
    {
        case 0: RET(1);
        case 1: RET(10);
        case 2: RET(100);
        case 3: RET(1000);
        default: break;
    }
    RET(0);
}
