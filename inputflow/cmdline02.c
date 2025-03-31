#include "./test_input_flow.h"
#include <string.h>

int main(int argc, char* argv[])
{   TAINT_ARGS("a.out");
    if (argc == 1)
    {
        int y = 0;
        for (int i = 0; argv[0][i] != '\0'; ++i)
            y += argv[0][i];
        FLOW_COMPRISES_JOIN_EX(&y, sizeof(y), argv[0], strlen(argv[0]));
    }
    return 0;
}
