struct B {
  int a : 1;
  int   : 2;
  int b : 3;
  int c : 2;
  int   : 4;
  int d : 4;
};

struct B bbb = { 1, 3, 2 };

int zoo(struct B* b)
{
  return (int)b->c;
}

struct B bar(struct B b)
{
  return b;
}

void foo()
{
  struct B b;
  b = bbb;
}

int main()
{
  ++bbb.b;
  return 0;
}
