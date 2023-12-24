#include "stdio.h"
#include "string.h"
#include <limits.h> /* Used for UINT_MAX*/

int main()
{
    signed int a = -0;
    signed int b = +0;
    printf("&a = %p\r\n", &a);
    printf("a=%d\r\n", a);
    printf("&b = %p\r\n", &b);
    printf("b=%d\r\n", b);

    printf("=====test2======\r\n");
    int i = -20;
    unsigned j = 10;
    printf("i + j = %d\r\n", i + j);

    printf("=====test3=====\r\n");
#if 0
    unsigned t;
    for (t = 9; t >= 0; t--)
    {
        printf("%p\r\n", &t);
    }
#endif
    unsigned t;
    for (t = 9; t != UINT_MAX; t--)
    {
        printf("%p\r\n", &t);
    }

    return 0;
}
