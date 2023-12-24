#include "stdio.h"
#include "string.h"
/* test signed/unsigned char size. test signed char strlen. */

int main()
{

    unsigned char c1;
    signed char c2;
    printf("sizeof(c1) = %ld\r\n", sizeof(c1));
    c1 = 0xff;
    printf("c1 = %d\r\n", c1);
    c1 = -5;
    printf("c1 = %d\r\n", c1);

    printf("\r\nsizeof(c2) = %ld\r\n", sizeof(c2));
    c2 = 0xff;
    printf("c2 = %d\r\n", c2);
    c2 = 0x7f;
    printf("c2 = %d\r\n", c2);
    c2 = 0x80;
    printf("c2 = %d\r\n", c2);
    c2 = 0x0;
    printf("c2 = %d\r\n", c2);
    c2 = 0x81;
    printf("c2 = %d\r\n", c2);

    printf("\r\nThis is a test\r\n");
    signed char a[1000];
    int i;
    for (i = 0; i < 1000; i++)
    {
        a[i] = -1 - i;
    }
    // [-128, 127]
    printf("len(a) = %ld\r\n", strlen(a));

    return 0;
}
