int foo(int a, float b)
{
    return a;
}

int bar()
{
    int y = foo(1, 2.3f);
    return y;
}

void zoo(int y)
{
    (void)foo(y, (float)y);
}

void huh()
{
    zoo(bar());
}

void hup()
{
    int (*ptr)();
    ptr = &bar;
    ptr = bar;
    (*ptr)();
}

int main()
{
    bar();
    return 0;
}
