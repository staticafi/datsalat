struct A
{
    char c;
    int i;
    double d;
};

char zul(int p)
{
    int i;
    return zul(i);
}
 
char* foo(int* p)
{
    int i;
    return foo(&i);
}
 
int* baz(int a[])
{
    int z[3];
    return baz(&z[2]);
}
 
int* bar(int a[])
{
    int z[3];
    return bar(z);
}
 
struct A* buz(struct A* p)
{
    struct A a;
    return buz(&a);
}
 
struct A huh(struct A p)
{
    struct A a;
    return huh(a);
}
 
int main(void)
{
    int i;
    i = *bar(&i);
    return 0;
}
