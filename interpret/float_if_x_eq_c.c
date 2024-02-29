#include "./test_interpretation.h"

int main()
{
    float x;
    x = __VERIFIER_nondet_float();
    if (x == -123.4567f) // -123.4567f = 0xC2F6E9D5 hex = 1100 0010 1111 0110 1110 1001 1101 0101 bin
        RET(1);
    RET(0);
}
