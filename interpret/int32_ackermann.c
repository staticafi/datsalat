#include "./test_interpretation.h"


static int  ackermann(int const  x, int const  y)
{
    if (x == 0)
        return y + 1;
    if (y == 0)
        return ackermann(x - 1,1);
    return ackermann(x - 1,ackermann(x,y - 1));
}


int main()
{
    int x, y;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    if (x < 0)
        RET(1);
    if (x > 3)
        RET(2);
    if (y < 0)
        RET(3);
    if (y > 23)
        RET(4);

    int r = ackermann(x,y);
    WRITE(s32, r);

    if (x < 2)
        RET(5);
    if (r >= 4)
        RET(6);
    RET(0);
}
