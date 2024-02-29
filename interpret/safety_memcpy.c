#include "./test_interpretation.h"
#include <string.h>

int main()
{
    char A[10];
    int n = __VERIFIER_nondet_int();
    if (n > 5) CRASHX(0);
    memcpy(&A[10-n], &A[0], n);
    RET(0);
}
