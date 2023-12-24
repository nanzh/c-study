#include <stdio.h>
#include <stdlib.h>

struct student
{

} stu;

typedef struct st_type
{
    int i;
    int a[];
} type_a;

int main()
{

    printf("struct size is %ld\r\n", sizeof(stu));
    printf("type_a size is %ld\r\n", sizeof(type_a));

    type_a p0;
    printf("type_a p size is %ld\r\n", sizeof(p0));

    // 柔性数组不占空间
    type_a *p = (type_a *)malloc(sizeof(type_a) + 100 * sizeof(int));
    printf("type_a p size is %ld\r\n", sizeof(*p));
    free(p);

    return 0;
}