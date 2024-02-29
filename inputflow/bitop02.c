#include "./test_input_flow.h"

int main()
{
	short x = __VERIFIER_nondet_short();
	short y = __VERIFIER_nondet_short();
	short z = x | y;
	FLOW_COMPRISES(z, x);
	FLOW_COMPRISES(z, y);
	z = y | 123;
	FLOW_NOT_COMPRISES(z, x);
	FLOW_COMPRISES(z, y);
    return 0;
}
