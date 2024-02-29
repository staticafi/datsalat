const int h = 5;
int i = 3*h + 2;

int gi;
int* gpi = &gi;

struct AA {
  char c;
  int i;
};

struct AA gaa;
int* gpiaa = &gaa.i;

struct A {
  char c;
  short s;
  int a[3];
  char x;
};
struct A ga;
int* gpaa = ga.a + 2;

struct B {
  int *p;
  float x;
  char *q;
};

struct A aaa[2];
struct B bbb[2] = {
  { &aaa[1].a[1], 1.0f, &aaa[0].x }
};

int main()
{
  struct A a;
  a = aaa[1];
  return 0;
}
