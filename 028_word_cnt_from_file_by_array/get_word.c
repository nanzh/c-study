#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"

int get_word(char *buff, int buff_size, FILE *fp)
{

    int len;
    int ch;

    /* 跳过读取空白字符 */
    while ((ch = getc(fp)) != EOF && !(isalnum(ch)))
        ;
    if (ch == EOF)
    {
        return EOF;
    }

    /* ch中保存了单词的初始字符 */
    len = 0;
    do
    {
        buff[len] = ch;
        len++;
        if (len >= buff_size - 1)
        {
            fprintf(stderr, "word too long.\n");
            exit(1);
        }

    } while ((ch = getc(fp)) != EOF && isalnum(ch));

    buff[len] = '\0';
    return len;
}
