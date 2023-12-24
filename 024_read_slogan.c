/* 可变长数组的数组 */
/* 实现一个程序，管理周一到周日，每天输出不同的标语 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void read_slogan(FILE *fp, char **slogan)
{

    char buf[1024];
    int i;
    for (i = 0; i < 7; i++)
    {
        fgets(buf, 1024, fp);
        /* 删除换行字符 */
        buf[strlen(buf) - 1] = '\0';
        /* 分配保存一个标语的内存空间 */
        slogan[i] = malloc(sizeof(char) * (strlen(buf) + 1));
        strcpy(slogan[i], buf);
    }
}

int main()
{
    char *slogan[7];
    int i;
    read_slogan(stdin, slogan);

    for (i = 0; i < 7; i++)
    {
        printf("%s\n", slogan[i]);
    }

    return 0;
}