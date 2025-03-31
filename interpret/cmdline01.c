#include "./test_interpretation.h"
#include <stdbool.h>

int main(int argc, char* argv[])
{   WRITE_ARGS("a.out");
    if (argc != 1)
        RET(1);
    RET(0);
}
