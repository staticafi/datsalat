#include "./test_input_flow.h"

int foo(int x)
{
	return x;
}

int main()
{
	int x = __VERIFIER_nondet_int();
	int y = foo(x);
	FLOW_EQUAL(y, x);
    return 0;
}
