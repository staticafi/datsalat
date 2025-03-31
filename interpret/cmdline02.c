#include "./test_interpretation.h"
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[])
{   WRITE_ARGS("a.out", "--help");
    if (argc != 2)
        RET(1);
    if (strcmp(argv[0], "a.out") != 0)
        RET(2);
    if (strcmp(argv[1], "--help") != 0)
        RET(3);
    RET(0);
}
