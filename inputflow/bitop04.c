#include "./test_input_flow.h"

int main()
{
	char x = __VERIFIER_nondet_char();
	char y = ~x;
	char z = 42;
	FLOW_COMPRISES(y, x);
	y = ~z;
	FLOW_NONE(y);
    return 0;
}
