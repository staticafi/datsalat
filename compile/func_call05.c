int foo(char c)
{
    return (int)c;
}

void bar(void)
{
}

void hux()
{
    int x;
    int (*fn)(char);
    fn = &foo;
    x = (*fn)('A');    
}

void huh()
{
    int x;
    int (*fn)(char);
    fn = (int (*)(char))&bar;
    x = (*fn)('A');
}
