#include "./test_input_flow.h"

int main()
{
	float x = __VERIFIER_nondet_float();
	float y = -x;
	float z = 123.0f;
	FLOW_COMPRISES_JOIN(y, x);
	y = -z;
	FLOW_NONE(y);
    return 0;
}
