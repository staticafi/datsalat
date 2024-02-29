#include "./test_input_flow.h"

int main()
{
	unsigned short x = __VERIFIER_nondet_ushort();
	unsigned short y = __VERIFIER_nondet_ushort();
	_Bool z = x >= y;
	FLOW_COMPRISES_JOIN_EX(&z, sizeof(z), &x, sizeof(x));
	FLOW_COMPRISES_JOIN_EX(&z, sizeof(z), &y, sizeof(y));
	z = x >= 123;
	FLOW_COMPRISES_JOIN_EX(&z, sizeof(z), &x, sizeof(x));
	FLOW_NOT_COMPRISES_JOIN_EX(&z, sizeof(z), &y, sizeof(y));
	z = 123 >= y;
	FLOW_NOT_COMPRISES_JOIN_EX(&z, sizeof(z), &x, sizeof(x));
	FLOW_COMPRISES_JOIN_EX(&z, sizeof(z), &y, sizeof(y));
    return 0;
}
