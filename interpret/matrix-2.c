#include "./test_interpretation.h"
extern void abort(void);

void __VERIFIER_assert(int cond) {
  HIT();
  if (!(cond)) {
    ERROR: {ABORT();}
  }
  return;
}

int main()
{
  unsigned int N_LIN=__VERIFIER_nondet_uint();
  unsigned int N_COL=__VERIFIER_nondet_uint();
  unsigned int j,k;
  int matriz[N_COL][N_LIN], maior;
  
  maior = __VERIFIER_nondet_int();
  for(j=0;j<N_COL;j++)
  {
    HIT();
    for(k=0;k<N_LIN;k++)
    {       
       HIT();
       matriz[j][k] = __VERIFIER_nondet_int();
       
       if(matriz[j][k]>maior)
       {
          HIT();
          maior = matriz[j][k];                          
       }
    }                       
  } 
  for(j=0;j<N_COL;j++)
    for(k=0;k<N_LIN;k++)
      __VERIFIER_assert(matriz[j][k]<maior);    
  RET(0);
}

