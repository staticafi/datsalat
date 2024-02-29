#include "./test_input_flow.h"

int main()
{
	unsigned int x = __VERIFIER_nondet_uint();
	unsigned int y = __VERIFIER_nondet_uint();
	unsigned int z = x << y;
	FLOW_COMPRISES_JOIN(z, x);
	FLOW_COMPRISES_JOIN(z, y);
	z = y << 1;
	FLOW_NOT_COMPRISES_JOIN(z, x);
	FLOW_COMPRISES_JOIN(z, y);
    return 0;
}
