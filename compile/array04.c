#include <alloca.h>

extern int __VERIFIER_nondet_int(void);

int main() {
  int length = __VERIFIER_nondet_int();
  int *arr = alloca(length*sizeof(int));
  int z = __VERIFIER_nondet_int();
  arr[0] = z;
  return 0;
}
