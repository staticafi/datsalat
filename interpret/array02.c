#include "./test_interpretation.h"
#include <alloca.h>

int main() {
    int length = __VERIFIER_nondet_int();
    int *arr = alloca(length*sizeof(int));
    int z = __VERIFIER_nondet_int();
    arr[length - 1] = z;
    WRITE(s32, arr[length - 1]);
    return 0;
}
