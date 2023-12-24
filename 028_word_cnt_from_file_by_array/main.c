#include "stdio.h"
#include "stdlib.h"
#include "get_word.h"
#include "word_manage.h"

#define WORD_LEN_MAX (1024)

int main(int argc, char **argv)
{
    char buf[WORD_LEN_MAX];
    FILE *fp;

    if (argc == 1)
    {
        fp = stdin;
    }
    else
    {
        fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            fprintf(stderr, "%s: %s can not open\r\n", argv[0], argv[1]);
            exit(1);
        }
    }

    printf("word initialize\r\n");
    word_initialize();

    while (get_word(buf, WORD_LEN_MAX, fp) != EOF)
    {
        add_word(buf);
    }

    printf("dump word\r\n");
    dump_word(stdout);

    int word_cnt = get_word_count("hello");
    printf("Total hello count is %d\r\n", word_cnt);

    word_finalize();
    printf("end\r\n");

    return 0;
}