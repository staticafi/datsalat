#include "./test_input_flow.h"
#include <stdarg.h>
 
void foo(const char* fmt, int xi, char xc, double xd, ...)
{
    int i;
    char c;
    double d;
    va_list args;

    FLOW_NONE_EX(fmt, 3);

    va_start(args, fmt);
    i = va_arg(args, int);
    FLOW_EQUAL(i, xi);

    c = va_arg(args, char);
    FLOW_EQUAL(c, xc);

    d = va_arg(args, double);
    FLOW_EQUAL(d, xd);

    va_end(args);
}
 
int main(void)
{
    int i = __VERIFIER_nondet_int();
    char c = __VERIFIER_nondet_char();
    double d = __VERIFIER_nondet_double();
    foo("icd", i, c, d, i, c, d);

    return 0;
}
