#include "./test_interpretation.h"

int main()
{
    double a = __VERIFIER_nondet_double();
    double b = __VERIFIER_nondet_double();
    if (b == 0) CRASHX(0);
    double c = a / b;
    WRITE(f64, c);
    RET(0);
}
