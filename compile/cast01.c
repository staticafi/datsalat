void huh()
{
    short s=1;
    unsigned short us=1;
    float f=1.2f;
    f = (float)s;
    f = (float)us;
    s = (short)f;
    us = (unsigned short)f;
}

void buz()
{
    float f=1.2f;
    double d=1.2f;
    f = (float)d;
    d = (double)f;
}

void bar()
{
    int i=1;
    unsigned int ui=1;
    float f=1.2f;
    f = (float)i;
    f = (float)ui;
    i = (int)f;
    ui = (unsigned int)f;
}

void zoo()
{
    int i=1;
    unsigned int ui=1;
    short s=2;
    unsigned short us=2;
    i = (int)ui;
    i = (int)s;
    i = (int)us;
    ui = (unsigned int)i;
    ui = (unsigned int)s;
    ui = (unsigned int)us;
    s = (short)i;
    s = (short)ui;
    s = (short)us;
    us = (unsigned short)i;
    us = (unsigned short)ui;
    us = (unsigned short)s;
}

void foo()
{
    unsigned int ui=1;
    unsigned short us=2;
    ui = (unsigned int)us;
    us = (unsigned short)ui;
}

int main()
{
    int i=1;
    short s=2;
    i = (int)s;
    s = (short)i;
    return 0;
}
