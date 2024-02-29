#include "./test_input_flow.h"

int main()
{
	short x = __VERIFIER_nondet_short();
	int y = x;
	FLOW_COMPRISES_EX(&y, &x, sizeof(x));
	FLOW_NOT_COMPRISES_JOIN_EX((short*)&y+1, sizeof(x), &x, 1);
	FLOW_COMPRISES_JOIN_EX((short*)&y+1, sizeof(x), (char*)&x+1, 1);
    return 0;
}
