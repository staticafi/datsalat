void zoo()
{
    int i=1;
    unsigned short j=2;
    short k=2;
    i = i & j;
    j = i | k;
    i = ~j;
    j = i ^ k;
}

void baz()
{
    int i=1;
    unsigned int j=1;
    short k=2;
    i = i << j;
    i = j << k;
    j = j >> i;
    j = i >> i;
    j = i >> k;
}

void bar()
{
    float i=1,j=2,k;
    ++i;
    j--;
    k = -i;
    k = i + 3.0f;
    k = i - j;
    k = i * j;
    k = i / j;
    k -= 1.0f;
    k += i;
}

void foo()
{
    unsigned int i=1,j=2,k;
    ++i;
    j--;
    k = -i;
    k = i + 3;
    k = i - j;
    k = i * j;
    k = i / j;
    k = i % j;
    k -= 1;
    k += i;
}

int main()
{
    int i=1,j=2,k;
    ++i;
    j--;
    k = -i;
    k = i + 3;
    k = i - j;
    k = i * j;
    k = i / j;
    k = i % j;
    k -= 1;
    k += i;
    return 0;
}
