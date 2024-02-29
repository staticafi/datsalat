#include "./test_input_flow.h"

int main()
{
	unsigned short n = __VERIFIER_nondet_ushort();
	int A[n];
	int i,j,x;
	i = __VERIFIER_nondet_int();
	j = __VERIFIER_nondet_int();
	A[i] = __VERIFIER_nondet_int();
	A[j] = A[i];
	x = A[j];
	FLOW_EQUAL(x, A[i]);
	FLOW_EQUAL(A[j], A[i]);

    return 0;
}
