void foo(void (*f)(void))
{
}
 
void bar(void)
{
}
 
int main(void)
{
    foo(&bar); 
}
