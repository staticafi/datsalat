void huh(int* p, short** q)
{
    q = (short**)p;
}

void buz(int* p, short* q)
{
    q = (short*)p;
}

void bar(short** p, float* q)
{
    *(int*)*p = *(int*)q;
}

void zoo(short** p, int* q)
{
    q = (int*)*p;
}

void foo(int* p, char c)
{
    *(char*)p = c;
}

int main()
{
    int* p;
    int i;
    short s;
    p = &i;
    *((short*)p + 1) = s;
    return 0;
}
