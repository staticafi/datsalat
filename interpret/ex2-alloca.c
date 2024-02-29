#include "./test_interpretation.h"
#include <stdlib.h>
#include <alloca.h>

int test_fun(int x, int y, int z, int flag)
{
    HIT();
    int* x_ref = alloca(sizeof(int));
    int* y_ref = alloca(sizeof(int));
    int* z_ref = alloca(sizeof(int));
    int* flag_ref = alloca(sizeof(int));
    int* c = alloca(sizeof(int));
    flag = 1;
    *x_ref = x;
    *y_ref = y;
    *z_ref = z;
    *flag_ref = flag;
    *c = 0;
    while ((*y_ref < *z_ref) && (*flag_ref > 0)) {
        HIT();
        if ((*y_ref > 0) && (*x_ref > 1)) {
            HIT();
            *y_ref = (*x_ref) * (*y_ref);
        } else {
            HIT();
            if ((*y_ref > 0) && (*x_ref < -1)) {
                HIT();
                *y_ref = -(*x_ref) * (*y_ref);
            } else {
                HIT();
                *flag_ref = 0;
            }
        }
        *c = *c + 1;
    }
    HIT();
    return *c;
}

int main() {
    RET(test_fun(__VERIFIER_nondet_int(),__VERIFIER_nondet_int(),__VERIFIER_nondet_int(),__VERIFIER_nondet_int()));
}
