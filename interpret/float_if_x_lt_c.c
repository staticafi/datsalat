#include "./test_interpretation.h"

int main()
{
    float x;
    x = __VERIFIER_nondet_float();
    if (x < -123.4567f)
        RET(1);
    RET(0);
}
