#include "./test_interpretation.h"

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct list_head list = { &list, &list };

int main(void)
{
    if (list.next == &list)
        HIT();
    if (list.prev == &list)
        HIT();
    RET(0);
}
