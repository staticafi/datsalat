#include "./test_input_flow.h"

int main()
{
	float x = __VERIFIER_nondet_float();
	float y = x;
	FLOW_EQUAL(y, x);
	y = 0.0f;
	FLOW_NONE(y);
    return 0;
}
