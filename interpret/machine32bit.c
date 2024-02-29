#include "./test_interpretation.h"

struct list_head
{
    struct list_head *next ;
    struct list_head *prev ;
};

struct node
{
    int value ;
    struct list_head linkage ;
    struct list_head nested ;
};

int main(void) 
{
    int a,b,c,x;
    a = sizeof(int);
    b = sizeof(struct node);
    c = sizeof(struct list_head *);
    x = __VERIFIER_nondet_int();

    if (a != 4)
        RET(10);
    if (b != 20)
        RET(20);
    if (c != 4)
        RET(30);
    RET(x == 123);
}
