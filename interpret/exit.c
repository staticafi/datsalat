#include "./test_interpretation.h"


void foo()
{
    HIT();
}

void bar(int x)
{
    HIT();
}

int main()
{
    char x = READ(s8);

    atexit(&foo);

    if (x == 'a')
    {
        HIT();
        EXIT(1);
    }

    HIT();

    if (x == 'b')
    {
        HIT();
        ABORT();
    }

    HIT();

    if (x == 'c')
    {
        HIT();
        atexit((void(*)())&bar);
        EXIT(2);
    }

    RET(0);
}
