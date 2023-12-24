#include "stdio.h"
#include "stdlib.h"

int main()
{

    int *int_p;
    int_p = malloc(sizeof(int));

    *int_p = 12345;
    printf("*int_p..%d\n", *int_p);

    free(int_p);
    /* 根据书里的说法，调用free之后，对应的内存内容不会被马上破坏，但我运行的结果变成了0 */

    printf("*int_p..%d\n", *int_p);

    return 0;
}