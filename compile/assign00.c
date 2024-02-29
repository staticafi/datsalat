void assign(int i, int j)
{
    i = j;
}


void assign_addr(int* p, int i)
{
    p = &i;
}


void assign_deref(int i, int* p)
{
    i = *p;
}


void deref_assign(int *p, int i)
{
    *p = i;
}


void deref_assign_deref(int *p, int* q)
{
    *p = *q;
}


int main()
{
    int *p;
    *p = 0;
    return 0;
}
