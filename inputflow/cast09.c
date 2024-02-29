#include "./test_input_flow.h"

int main()
{
	int x = __VERIFIER_nondet_int();
	char* y = (char*)x;
	int z;
	short u,v;
	FLOW_COMPRISES_JOIN_EX(&y, sizeof(y), &x, sizeof(x));
	z = (int)y;
	FLOW_COMPRISES_JOIN_EX(&z, sizeof(z), &x, sizeof(x));
	u = (short)x;
	y = (char*)u;
	FLOW_COMPRISES_JOIN_EX(&y, sizeof(y), &x, sizeof(u));
	FLOW_NOT_COMPRISES_JOIN_EX(&y, sizeof(y), (short*)&x+1, sizeof(u));
	v = (short)y;
	FLOW_COMPRISES_JOIN_EX(&v, sizeof(v), &x, sizeof(u));
	FLOW_NOT_COMPRISES_JOIN_EX(&v, sizeof(v), (short*)&x+1, sizeof(u));

    return 0;
}
