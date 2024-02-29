#include <stdarg.h>
 
void foo(const char* fmt, ...)
{
    int i;
    char c;
    double d;
    va_list args;

    va_start(args, fmt);
    i = va_arg(args, int);
    c = va_arg(args, char);
    //d = va_arg(args, double);
    va_end(args);
}
 
int main(void)
{
    foo("icd", 1, 'A', 3.14); 
}
