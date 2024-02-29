#include "./test_interpretation.h"
extern void abort(void);

void reach_error(void) {
  ABORT();
}

void __VERIFIER_assert(int cond) {
  if (!cond) {
    reach_error();
  }
}

int main() {
  int x = __VERIFIER_nondet_int();
  int y = __VERIFIER_nondet_int();
  int z = __VERIFIER_nondet_int();
  if (!(x == y && x >= 0 && x+y+z==0))
    RET(1);
  while (x > 0) {
    x--;
    y--;
    z++;
    z++;
  }
  __VERIFIER_assert(z<=0);
  RET(0);
}
