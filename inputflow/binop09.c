#include "./test_input_flow.h"

int main()
{
	float x = __VERIFIER_nondet_float();
	float y = __VERIFIER_nondet_float();
	float z = x / y;
	FLOW_COMPRISES_JOIN(z, x);
	FLOW_COMPRISES_JOIN(z, y);
	z = y / 123.0f;
	FLOW_NOT_COMPRISES_JOIN(z, x);
	FLOW_COMPRISES_JOIN(z, y);
    return 0;
}
