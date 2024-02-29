#include "./test_input_flow.h"

int main()
{
	int x = __VERIFIER_nondet_int();
	int y = x;
	FLOW_EQUAL(y, x);
	y = 0;
	FLOW_NONE(y);
    return 0;
}
