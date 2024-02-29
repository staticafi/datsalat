#include "./test_interpretation.h"
#include <stdbool.h>

static int  parse_int(char const* const  c_string, char const  which, char const  terminal, int*  result)
{
    int idx = 0, sign = 1, end = 0, i = 0, exp = 1;
    if (c_string[idx] == '\0')
    {
        HIT();
        return -1;
    }
    if (c_string[idx] != which)
    {
        HIT();
        return -1;
    }
    ++idx;
    if (c_string[idx] == '\0')
    {
        HIT();
        return -1;
    }
    if (c_string[idx] != '=')
    {
        HIT();
        return -1;
    }
    ++idx;
    if (c_string[idx] == '\0')
    {
        HIT();
        return -1;
    }
    if (c_string[idx] == '-')
    {
        HIT();
        sign = -1;
        ++idx;
    }
    else
    {
        HIT();
        if (c_string[idx] == '+')
        {
            HIT();
            ++idx;
        }
    }
    end = idx;
    while (true)
    {
        if (c_string[idx] == terminal)
        {
            HIT();
            break;
        }
        if (c_string[idx] == '\0')
        {
            HIT();
            return -1;
        }
        if (c_string[idx] < '0')
        {
            HIT();
            return -1;
        }
        if (c_string[idx] > '9')
        {
            HIT();
            return -1;
        }
        ++idx;
        if (idx - end > 3)
        {
            HIT();
            return -1;
        }
    }
    if (idx == end)
    {
        HIT();
        return -1;
    }
    *result = 0;
    i = idx;
    while (true)
    {
        if (i == end)
        {
            HIT();
            *result *= sign;
            return idx;
        }
        --i;
        *result += (c_string[i] - '0') * exp;
        exp *= 10;
    }
}


static bool  mut(char const* const  c_string)
{
    int  idx = 0, idx_tmp, x, y;
    idx_tmp = parse_int(c_string + idx, 'x', ';', &x);
    if (idx_tmp == -1)
    {
        HIT();
        return false;
    }
    idx += idx_tmp + 1;
    idx_tmp = parse_int(c_string + idx, 'y', '.', &y);
    if (idx_tmp == -1)
    {
        HIT();
        return false;
    }
    return true;
}


int main()
{
    short n;
    char s[50];
    n = __VERIFIER_nondet_short();
    if (n <= 0)
        RET(-1);
    if (n >= sizeof(s) / sizeof(s[0]))
        RET(-2);
    for (short i = 0; i < n; ++i)
        s[i] = __VERIFIER_nondet_char();
    if (s[n-1] != '\0')
        RET(-3);

    RET((int)mut(s));
}
