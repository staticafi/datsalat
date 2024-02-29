#include "./test_interpretation.h"

int main()
{
    char  data[4];
    data[0] = __VERIFIER_nondet_char();
    data[1] = __VERIFIER_nondet_char();
    data[2] = __VERIFIER_nondet_char();
    data[3] = __VERIFIER_nondet_char();

    if (data[0] == 'b')
    {
        HIT();
        if (data[1] == 'a')
        {
            HIT();
            if (data[2] == 'd')
            {
                HIT();
                if (data[3] == '!')
                    RET(1);
            }
        }
    }
    RET(0);
}
