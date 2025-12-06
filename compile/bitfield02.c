typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned long long int uint64_t;
struct A
{
    uint16_t raw;
    uint8_t pt : 8;
    uint64_t owner : 40;
};

void foo(struct A* a, unsigned long long int x)
{
    a->owner = x;
}

int main(void)
{
    return 0;
}