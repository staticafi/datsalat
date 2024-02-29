#include "./test_interpretation.h"

int main()
{
    uint32_t mem;
    int i = __VERIFIER_nondet_int();
    char c = *((char*)&mem + i);
    RET(0);
}
