#include "./test_input_flow.h"
#include <stdlib.h>

struct Record
{
	char x;
	double d;
	int i;
	short s;
};

int main()
{
	int n;
	int i;
	struct Record r,s,t;
	struct Record* pr;

	r.x = __VERIFIER_nondet_char();
	r.d = __VERIFIER_nondet_double();
	r.i = __VERIFIER_nondet_int();
	r.s = __VERIFIER_nondet_short();

	n = __VERIFIER_nondet_int();
	i = __VERIFIER_nondet_int();

	pr = (struct Record*)malloc(n * sizeof(struct Record));
	pr[i] = r;
	s = pr[i];
	pr[i] = pr[0];
	t = pr[i];

	free(pr);

	FLOW_EQUAL(s.x, r.x);
	FLOW_EQUAL(s.d, r.d);
	FLOW_EQUAL(s.i, r.i);
	FLOW_EQUAL(s.s, r.s);

	FLOW_NOT_COMPRISES_JOIN_EX(&s.x, sizeof(s.x), &r.d, sizeof(r.d));
	FLOW_NOT_COMPRISES_JOIN_EX(&s.x, sizeof(s.x), &r.i, sizeof(r.i));
	FLOW_NOT_COMPRISES_JOIN_EX(&s.x, sizeof(s.x), &r.s, sizeof(r.s));

	FLOW_NOT_COMPRISES_JOIN_EX(&s.d, sizeof(s.d), &r.x, sizeof(r.x));
	FLOW_NOT_COMPRISES_JOIN_EX(&s.d, sizeof(s.d), &r.i, sizeof(r.i));
	FLOW_NOT_COMPRISES_JOIN_EX(&s.d, sizeof(s.d), &r.s, sizeof(r.s));

	FLOW_NOT_COMPRISES_JOIN_EX(&s.i, sizeof(s.i), &r.d, sizeof(r.d));
	FLOW_NOT_COMPRISES_JOIN_EX(&s.i, sizeof(s.i), &r.x, sizeof(r.x));
	FLOW_NOT_COMPRISES_JOIN_EX(&s.i, sizeof(s.i), &r.s, sizeof(r.s));

	FLOW_NOT_COMPRISES_JOIN_EX(&s.s, sizeof(s.s), &r.d, sizeof(r.d));
	FLOW_NOT_COMPRISES_JOIN_EX(&s.s, sizeof(s.s), &r.i, sizeof(r.i));
	FLOW_NOT_COMPRISES_JOIN_EX(&s.s, sizeof(s.s), &r.x, sizeof(r.x));

	if (i == 0)
	{
		FLOW_EQUAL(s.x, t.x);
		FLOW_EQUAL(s.d, t.d);
		FLOW_EQUAL(s.i, t.i);
		FLOW_EQUAL(s.s, t.s);
	}
	else
	{
		FLOW_NONE(t.x);
		FLOW_NONE(t.d);
		FLOW_NONE(t.i);
		FLOW_NONE(t.s);
	}

    return 0;
}
