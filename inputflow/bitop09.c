#include "./test_input_flow.h"

int main()
{
	char x = __VERIFIER_nondet_uchar();
	char y = __VERIFIER_nondet_uchar();
	char z = x >> y;
	FLOW_COMPRISES_JOIN(z, x);
	FLOW_COMPRISES_JOIN(z, y);
	z = y >> 1;
	FLOW_NOT_COMPRISES_JOIN(z, x);
	FLOW_COMPRISES_JOIN(z, y);
    return 0;
}
