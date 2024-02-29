#include "./test_interpretation.h"
#include <stdlib.h>

int main()
{
    char* A = (char*)malloc(10);
    int i = __VERIFIER_nondet_int();
    char c = A[i];
    RET(0);
}
