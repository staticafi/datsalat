#include "./test_interpretation.h"
#include <stdbool.h>

int main()
{
    char s[50];
    {
        short n;
        n = __VERIFIER_nondet_short();
        if (n <= 0)
            RET(-1);
        if (n >= sizeof(s) / sizeof(s[0]))
            RET(-2);
        for (short i = 0; i < n; ++i)
            s[i] = __VERIFIER_nondet_char();
        if (s[n-1] != '\0')
            RET(-3);
    }
    {
        int i = 0, k = 0;
        while (true)
        {
            if (s[i] == '\0')
            {
                WRITE(s32, i);
                break;
            }
            if (s[i] == 'A')
            {
                WRITE(s32, i);
                ++k;
            }
            ++i;
        }
        if (k == 5)
            RET(1);
        RET(0);
    }
}
