enum E {
  E0,
  E1,
  E2
};

int main()
{
  int i;
  enum E e = E0;
  i = E1;
  i = e;
  e = (enum E)i;
  return 0;
}
