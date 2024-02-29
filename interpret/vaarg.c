#include "./test_interpretation.h"
#include <stdarg.h>
 
void foo(const char* fmt, ...)
{
    int i;
    char c;
    double d;
    va_list args;

    WRITE(s8, fmt[0]);
    WRITE(s8, fmt[1]);
    WRITE(s8, fmt[2]);

    va_start(args, fmt);
    i = va_arg(args, int);
    WRITE(s32, i);
    c = va_arg(args, char);
    WRITE(s8, c);
    d = va_arg(args, double);
    WRITE(f64, d);
    va_end(args);
}
 
int main(void)
{
    int i = __VERIFIER_nondet_int();
    char c = __VERIFIER_nondet_char();
    double d = __VERIFIER_nondet_double();
    foo("icd", i, c, d);
    RET(0);
}
