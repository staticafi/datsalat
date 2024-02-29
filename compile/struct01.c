struct Alignment
{
    char c;
    int i;
    short s;
};

struct Alignment AAA[2] = { { 'A', 1, 2 }, { 'B', 3, 4 } };
struct Alignment BBB[3];

struct Nested
{
    char str[10];
    float z;
};

struct Outer
{
    int i;
    struct Nested n;
    char c;
    float f;
};

void zoo()
{
    struct Outer a,b;
    a = b;
}

void zop()
{
    struct Outer a;
    struct Nested b;
    a.n = b;
}

void zor()
{
    struct Outer a;
    struct Nested b;
    b = a.n;
}

void huh()
{
    struct Outer a[3];
    char *p;
    p = &a[2].n.str[5];
}

void hux()
{
    struct Outer a[3];
    char c;
    c = a[2].n.str[5];
}

struct Nested fox(struct Outer o)
{
    return o.n;
}

struct Outer fov(struct Outer o)
{
    return o;
}

struct Nested foo(struct Outer o)
{
    struct Nested n;
    n = o.n;
    return n;
}

struct Nested* bar(struct Outer* o) {
    return &o->n;
}

void sad()
{
    struct Outer o;
    struct Nested n;
    n = foo(o);
}

struct Nested N;

int main()
{
    struct Outer o;
    N = *bar(&o);
    return 0;
}
