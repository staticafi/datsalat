extern void exit(int exit_code);
extern int atexit(void (*func)(void));
extern void abort(void);

void foo() {}

int main()
{
    char x = 'x';

    atexit(&foo);

    if (x == 'a')
        exit(1);
    if (x == 'b')
        abort();

    return(0);
}
