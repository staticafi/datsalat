#include "./test_interpretation.h"

int main()
{
    float x;
    x = __VERIFIER_nondet_float();
    if (1.23f*x*x-4.56f*x-7.89f == 0) // Roots:~ -1.284921407699584961, 4.992...
        RET(1);
    RET(0);
}
