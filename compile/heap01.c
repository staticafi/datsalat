#include <stdlib.h>

int* foo(size_t n)
{
    return (int*)malloc(n);
}

float* bar(size_t n, size_t s)
{
    return (float*)calloc(n, s);
}

float* huh(void* p, size_t n)
{
    return (float*)realloc(p, n);
}

void hup(int* pi)
{
    free(pi);
}

void hux(int* pi, size_t n)
{
    free_sized(pi, n);
}

void* zus(void* p, int c, size_t n)
{
    return memset(p,c,n); // returns d.
}

void* zup(void* d, void* s, size_t n)
{
    return memcpy(d,s,n); // returns d.
}

void* zul(void* d, void* s, size_t n)
{
    return memmove(d,s,n); // returns d.
}

void main() {}
