int foo(int a, float b)
{
    return a;
}

int bar(int a, float b)
{
    return (int)b;
}

int main()
{
    int i;
    int (* fns[3])(int, float) = { &foo, &bar, &foo };
    return fns[i](1, 1.0f);
}
