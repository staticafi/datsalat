#include "./test_interpretation.h"

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "array-1.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    HIT();
    ERROR: {reach_error();ABORT();}
  }
  return;
}

int main()
{
  unsigned int SIZE=1;
  unsigned int j,k;
  int array[SIZE], menor;
  
  menor = __VERIFIER_nondet_int();

  for(j=0;j<SIZE;j++) {
       HIT();
       array[j] = __VERIFIER_nondet_int();
       
       if(array[j]<=menor)
       {
          HIT();
          menor = array[j];
       }                          
    }                       
    
    __VERIFIER_assert(array[0]>menor);    

    RET(0);
}

