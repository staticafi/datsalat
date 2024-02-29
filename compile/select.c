int foo(int* const p)
{
    return *p == 0 ? 1 : 0;
}

int main()
{
    return foo(0);
}
