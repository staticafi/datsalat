struct A {
  char c;
  int i;
  short s;
};

union U {
  int X;
  struct A a;
  double Y;
};

int main()
{
  union U u;
  u.a.i = 1;
  u.Y = 1.2f;
  return 0;
}
