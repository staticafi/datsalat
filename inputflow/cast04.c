#include "./test_input_flow.h"

int main()
{
	unsigned short x = __VERIFIER_nondet_ushort();
	unsigned int y = x;
	FLOW_COMPRISES_EX(&y, &x, sizeof(x));
	FLOW_NONE_EX((short*)&y+1, sizeof(x));
    return 0;
}
