#include "./test_input_flow.h"

int main()
{
	int x = __VERIFIER_nondet_int();
	short y = x;
	FLOW_COMPRISES_EX(&y, &x, sizeof(y));
	FLOW_NOT_COMPRISES_JOIN_EX(&y, sizeof(y), (short*)&x+1, sizeof(y));
    return 0;
}
