#include "./test_interpretation.h"

int main()
{
    float a = __VERIFIER_nondet_float();
    float b = __VERIFIER_nondet_float();
    if (b == 0) CRASHX(0);
    float c = a / b;
    WRITE(f32, c);
    RET(0);
}
