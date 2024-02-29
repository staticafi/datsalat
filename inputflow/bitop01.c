#include "./test_input_flow.h"

int main()
{
	int x = __VERIFIER_nondet_int();
	int y = __VERIFIER_nondet_int();
	int z = x & y;
	FLOW_COMPRISES(z, x);
	FLOW_COMPRISES(z, y);
	z = y & 123;
	FLOW_NOT_COMPRISES(z, x);
	FLOW_COMPRISES(z, y);
    return 0;
}
