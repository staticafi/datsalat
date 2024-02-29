#include <stdbool.h>

void zoo()
{
    _Bool b,c;
    b = b && c;
}

void zul()
{
    _Bool b;
    int i;
    b = (_Bool)i;
}

void zop()
{
    _Bool b,c;
    b = !c;
}

void hop()
{
    _Bool b,c,d;
    b = b && (c || !d);
}

void hoi()
{
    int i,j;
    switch (i)
    {
        case 0:
            j = 0;
            break;
        default:
            j = 1;
            break;
    }
}

void huh()
{
    int i,j;
    j = (i < j) ? i : j;
}

void bar()
{
    int i,j;
    _Bool b;
    b = i < j || j < i;
}

void foo()
{
    int i,j;
    if (i < j || j < i)
        i = j;
    else
        j = i;
}

int main()
{
    unsigned short int i,j;
    if (i < j)
        i = j;
    else
        j = i;
    return 0;
}
