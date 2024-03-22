#include "./test_interpretation.h"

int main()
{
    float a = __VERIFIER_nondet_float();
    float b = __VERIFIER_nondet_float();
    float c = a / b;
    WRITE(f32, c);
    RET(0);
}
