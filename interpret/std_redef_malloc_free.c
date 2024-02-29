#include "./test_interpretation.h"

static char mem[100];
static int idx = 0;
char* zzmalloc(int n) 
{
    char* ptr;
    ptr = mem + idx;
    idx += n;
    WRITE(s32, idx);
    return ptr;
}

void zzfree(void* p)
{
    // nothing to do.
}

int main()
{
    char* ptr;
    int n;
    n = __VERIFIER_nondet_int();
    if (n < 1 || n > 1000) // Intentionally larger limit than maximum.
        RET(-1);
    ptr = zzmalloc(n);
    zzfree(ptr);
    RET(0);
}
