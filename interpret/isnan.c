#include "./test_interpretation.h"
#include <math.h>
#include <float.h>


int main()
{
  double d = __VERIFIER_nondet_double();

  if(!(isnormal(FLT_MAX))) RET(1);
  if(!(isinf(HUGE_VAL))) RET(2);
  if(!(isinf(HUGE_VALF))) RET(3);
//  if(!(isinf(HUGE_VALL))) RET(4);
  if(!(isinf(INFINITY))) RET(5);
  if(!(isnan(NAN))) RET(6);

  if(!(isinf(INFINITY+INFINITY))) RET(7);
  if(!(isnan(-INFINITY+INFINITY))) RET(8);
  if(!(INFINITY+INFINITY>0)) RET(9);
  if(!(isnan(NAN+d))) RET(10);
  if(!(isnan(NAN+INFINITY))) RET(11);

  if(!(isnan(INFINITY-INFINITY))) RET(12);
  if(!(isinf(-INFINITY-INFINITY))) RET(13);
  if(!(-INFINITY-INFINITY<0)) RET(14);
  if(!(isnan(NAN-d))) RET(15);
  if(!(isnan(NAN-INFINITY))) RET(16);

  if(!(isinf(INFINITY*INFINITY))) RET(17);
  if(!(isinf(-INFINITY*INFINITY))) RET(18);
  if(!(INFINITY*INFINITY>0)) RET(19);
  if(!(-INFINITY*INFINITY<0)) RET(20);
  if(!(isnan(NAN*d))) RET(21);
  if(!(isnan(NAN*INFINITY))) RET(22);
  if(!(isnan(INFINITY*0))) RET(23);
  if(!(signbit(1.0*-0.0))) RET(24);
  if(!(!signbit(1.0*0.0))) RET(25);

  if(!(isnan(INFINITY/INFINITY))) RET(26);
  if(!(isnan(-INFINITY/INFINITY))) RET(27);

  int zero=0;
  if(!(isinf(INFINITY/zero))) RET(28);
  if(!(0.0/INFINITY==0)) RET(29);
  if(!(1.0/INFINITY==0)) RET(30);
  if(!(signbit(-1.0/INFINITY))) RET(31);
  if(!(signbit(1.0/-INFINITY))) RET(32);
  if(!(INFINITY/-2<0)) RET(33);
  if(!(isinf(1.0/0.0))) RET(34);
  if(!(isinf(INFINITY/2))) RET(35);
  if(!(isnan(0.0/0.0))) RET(36);
  if(!(isnan(NAN/d))) RET(37);
  if(!(isnan(NAN/INFINITY))) RET(38);
  if(!(signbit(-0.0/1))) RET(39);

  RET(0);
}
