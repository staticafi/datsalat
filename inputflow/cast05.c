#include "./test_input_flow.h"

int main()
{
	short x = __VERIFIER_nondet_short();
	float y = (float)x;
	FLOW_COMPRISES_JOIN_EX(&y, sizeof(y), &x, sizeof(x));
    return 0;
}
