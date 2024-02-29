#include "./test_interpretation.h"
#include <stdlib.h>


struct Link
{
    int data;
    struct Link* next;
    struct Link* prev;
};

struct List
{
    struct Link* head;
    struct Link* tail;
};


void create(struct List* const list)
{
    list->head = 0;
    list->tail = 0;
}


int empty(struct List* const list)
{
    return list->head == 0 ? 1 : 0;
}


int size(struct List* const list)
{
    int count = 0;
    for (struct Link* p = list->head; p != 0; p = p->next)
        ++count;
    WRITE(s32, count);
    return count;
}


int push_back(struct List* const list, int value)
{
    WRITE(s32, value);

    struct Link* const link = (struct Link*)malloc(sizeof(struct Link));
    if (link == 0)
    {
        HIT();
        return 0;
    }
    link->data = value;
    link->next = 0;
    link->prev = list->tail;
    if (list->tail == 0)
    {
        HIT();
        list->head = list->tail = link;
    }
    else
    {
        HIT();
        list->tail->next = link;
        list->tail = link;
    }
    return 1;
}


int pop_front(struct List* const list)
{
    struct Link* const link = list->head;
    int const data = link->data;
    if (list->tail == link)
    {
        HIT();
        list->head = list->tail = 0;
    }
    else
    {
        HIT();
        list->head = link->next;
        list->head->prev = 0;
    }
    free(link);

    WRITE(s32, data);

    return data;
}


void destroy(struct List* const list)
{
    while (!empty(list))
        pop_front(list);
}


int main()
{
    int n;
    struct List list;
    create(&list);
    n = __VERIFIER_nondet_int();
    if (n < 0 || n > 9)
    {
        HIT();
        CRASH(0);
        pop_front(&list);
    }
    for (int i = 0; i < n; ++i)
        push_back(&list, i);
    destroy(&list);
    RET(0);
}
