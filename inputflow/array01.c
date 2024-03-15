#include "./test_input_flow.h"
#include <alloca.h>

int main() {
    int length = __VERIFIER_nondet_int();
    int *arr = alloca(length*sizeof(int));
    int z = __VERIFIER_nondet_int();
    int h;
    arr[length - 1] = z;
    FLOW_EQUAL(arr[length - 1], z);
    h = arr[length - 1];
    FLOW_EQUAL(h, z);
	FLOW_NONE(arr[0]);
    return 0;
}
