#include "./test_input_flow.h"

int main(int argc, char* argv[])
{   TAINT_ARGS("a.out");
    int x = argc;
	FLOW_EQUAL(x, argc);
	argc = 0;
	FLOW_NONE(argc);
    return 0;
}
