#include <stdbool.h>

void huh()
{
    unsigned long long int i,j;
    _Bool b;
    b = i < j;
    b = i <= j;
    b = i >= j;
    b = i > j;
    b = i == j;
    b = i != j;
}

void baz()
{
    double i,j;
    _Bool b;
    b = i < j;
    b = i <= j;
    b = i >= j;
    b = i > j;
    b = i == j;
    b = i != j;
}

void bar()
{
    float i,j;
    _Bool b;
    b = i < j;
    b = i <= j;
    b = i >= j;
    b = i > j;
    b = i == j;
    b = i != j;
}

void foo()
{
    unsigned short i,j;
    _Bool b;
    b = i < j;
    b = i <= j;
    b = i >= j;
    b = i > j;
    b = i == j;
    b = i != j;
}

int main()
{
    int i,j;
    _Bool b;
    b = i < j;
    b = i <= j;
    b = i >= j;
    b = i > j;
    b = i == j;
    b = i != j;
    return 0;
}
