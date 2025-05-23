#include "./test_interpretation.h"


static void hash_combine(unsigned int* seed, char const  x)
{
    *seed ^= ((unsigned int)x * 977U) + 0x9e3779b9U + (*seed << 6) + (*seed >> 2);
}


int main()
{
    char x,y,z;
    unsigned int seed0, seed1;

    x = __VERIFIER_nondet_uint();
    y = __VERIFIER_nondet_uint();
    z = __VERIFIER_nondet_uint();

    seed0 = 73910U;
    hash_combine(&seed0, -24);
    hash_combine(&seed0, 56);
    hash_combine(&seed0, -120);
    WRITE(s32, seed0);

    seed1 = 73910U;
    hash_combine(&seed1, x);
    hash_combine(&seed1, y);
    hash_combine(&seed1, z);
    WRITE(s32, seed1);

    if (seed1 == seed0)
        RET(1);
    RET(0);
}
