#include "./test_input_flow.h"

int main()
{
	float x = __VERIFIER_nondet_float();
	double y = (double)x;
	FLOW_COMPRISES_JOIN_EX(&y, sizeof(y), &x, sizeof(x));
    return 0;
}
