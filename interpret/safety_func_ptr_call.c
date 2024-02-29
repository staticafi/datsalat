#include "./test_interpretation.h"

int foo(char c)
{
    return (int)c;
}

void bar(int x)
{
}

int main()
{
    int x;
    int (*fn)(char);
    int n = __VERIFIER_nondet_int();
    if (n == 123)
    {
        HIT();
        fn = (int (*)(char))&bar;
    }
    else
    {
        HIT();
        fn = &foo;
    }
    if ((void*)fn == (void*)&bar)
        CRASHX(0);
    x = (*fn)('A');
    WRITE(s32, x);
    RET(0);
}
