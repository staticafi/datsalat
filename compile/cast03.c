void zol()
{
    int** p;
    int* q;
    p = &q;
}

void hup()
{
    int** p;
    int* q;
    q = (int*)p;
}

void baz()
{
    int** p;
    int* q;
    p = (int**)q;
}

void zoo()
{
    int* p;
    int q;
    p = &q;
}

void huh()
{
    int* p;
    int q;
    q = (int)p;
}

void bar()
{
    int* p;
    int q;
    p = (int*)q;
}

int main(void)
{
    int**p = 0;
    return 0;
}
