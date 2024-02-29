#include "./test_input_flow.h"

int main()
{
	double x = __VERIFIER_nondet_double();
	float y = (float)x;
	FLOW_COMPRISES_JOIN_EX(&y, sizeof(y), &x, sizeof(x));
    return 0;
}
