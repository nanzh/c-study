#include <stdio.h>

void hello(void)
{
    fprintf(stderr, "hello!\n");
}

void func()
{
    void *buff[10];
    static int i;

    for (i = 0; i < 100; i++)
    {
        buff[i] = hello;
    }
}

int main(void)
{
    int buff[1000];
    func();

    return 0;
}