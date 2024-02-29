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
	struct Record* pr;
	char x;
	double d;
	int i;
	short s;

	pr = (struct Record*)malloc(sizeof(struct Record));

	pr->x = __VERIFIER_nondet_char();
	pr->d = __VERIFIER_nondet_double();
	pr->i = __VERIFIER_nondet_int();
	pr->s = __VERIFIER_nondet_short();

	x = pr->x;
	d = pr->d;
	i = pr->i;
	s = pr->s;

	FLOW_EQUAL(x, pr->x);
	FLOW_EQUAL(d, pr->d);
	FLOW_EQUAL(i, pr->i);
	FLOW_EQUAL(s, pr->s);

	FLOW_NOT_COMPRISES_JOIN_EX(&x, sizeof(x), &pr->d, sizeof(pr->d));
	FLOW_NOT_COMPRISES_JOIN_EX(&x, sizeof(x), &pr->i, sizeof(pr->i));
	FLOW_NOT_COMPRISES_JOIN_EX(&x, sizeof(x), &pr->s, sizeof(pr->s));

	FLOW_NOT_COMPRISES_JOIN_EX(&d, sizeof(d), &pr->x, sizeof(pr->x));
	FLOW_NOT_COMPRISES_JOIN_EX(&d, sizeof(d), &pr->i, sizeof(pr->i));
	FLOW_NOT_COMPRISES_JOIN_EX(&d, sizeof(d), &pr->s, sizeof(pr->s));

	FLOW_NOT_COMPRISES_JOIN_EX(&i, sizeof(i), &pr->d, sizeof(pr->d));
	FLOW_NOT_COMPRISES_JOIN_EX(&i, sizeof(i), &pr->x, sizeof(pr->x));
	FLOW_NOT_COMPRISES_JOIN_EX(&i, sizeof(i), &pr->s, sizeof(pr->s));

	FLOW_NOT_COMPRISES_JOIN_EX(&s, sizeof(s), &pr->d, sizeof(pr->d));
	FLOW_NOT_COMPRISES_JOIN_EX(&s, sizeof(s), &pr->i, sizeof(pr->i));
	FLOW_NOT_COMPRISES_JOIN_EX(&s, sizeof(s), &pr->x, sizeof(pr->x));

	free(pr);

	FLOW_NOT_COMPRISES_JOIN_EX(&x, sizeof(x), &d, sizeof(d));
	FLOW_NOT_COMPRISES_JOIN_EX(&x, sizeof(x), &i, sizeof(i));
	FLOW_NOT_COMPRISES_JOIN_EX(&x, sizeof(x), &s, sizeof(s));
	FLOW_NOT_COMPRISES_JOIN_EX(&d, sizeof(d), &x, sizeof(x));
	FLOW_NOT_COMPRISES_JOIN_EX(&d, sizeof(d), &i, sizeof(i));
	FLOW_NOT_COMPRISES_JOIN_EX(&d, sizeof(d), &s, sizeof(s));
	FLOW_NOT_COMPRISES_JOIN_EX(&i, sizeof(i), &d, sizeof(d));
	FLOW_NOT_COMPRISES_JOIN_EX(&i, sizeof(i), &x, sizeof(x));
	FLOW_NOT_COMPRISES_JOIN_EX(&i, sizeof(i), &s, sizeof(s));
	FLOW_NOT_COMPRISES_JOIN_EX(&s, sizeof(s), &d, sizeof(d));
	FLOW_NOT_COMPRISES_JOIN_EX(&s, sizeof(s), &i, sizeof(i));
	FLOW_NOT_COMPRISES_JOIN_EX(&s, sizeof(s), &x, sizeof(x));

    return 0;
}
