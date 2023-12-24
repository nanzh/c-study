/* 实现可以读取任意长度的行的例程 */
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "string.h"
#define ALLOC_SIZE (256)

#include "read_any_line.h"

/* 读取行的缓冲，必要时进行扩展，但是区域不会被缩小。调用free_buffer()释放 */
static char *st_line_buffer = NULL;

/* 在st_line_buff前方被分配的内存区域的大小 */
static int st_current_buffer_size = 0;

/* st_line_buffer中现在保存的字符的大小 */
static int st_current_used_size = 0;

static void add_character(int ch)
{
    /* 此函数每次被调用，st_current_buffer_size都必定会增加1，正常情况下，下面的断言肯定不会出错 */
    assert(st_current_buffer_size >= st_current_used_size);

    if (st_current_buffer_size == st_current_used_size)
    {
        st_line_buffer = realloc(st_line_buffer, (st_current_buffer_size + ALLOC_SIZE * sizeof(char)));
        st_current_buffer_size += ALLOC_SIZE;
    }
    st_line_buffer[st_current_used_size] = ch;
    st_current_used_size++;
}

/* 从fp读取一行字符，一旦读到文件末尾，就返回NULL */
char *read_line(FILE *fp)
{
    int ch;
    char *ret = NULL;

    st_current_used_size = 0;
    while ((ch = getc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            add_character('\0');
            break;
        }
        add_character(ch);
    }
    if (ch == EOF)
    {
        if (st_current_used_size > 0)
        {
            add_character('\0');
        }
        else
        {
            return NULL;
        }
    }
    ret = malloc(sizeof(char) * (st_current_used_size));
    strcpy(ret, st_line_buffer);
    return ret;
}

void free_buff(void)
{
    free(st_line_buffer);
    st_line_buffer = NULL;
    st_current_buffer_size = 0;
    st_current_used_size = 0;
}

char **add_line(char **text_data, char *line, int *line_alloc_num, int *line_num)
{
    assert(*line_alloc_num >= *line_num);
    if (*line_alloc_num == *line_num)
    {
        text_data = realloc(text_data, (*line_alloc_num + ALLOC_SIZE) * sizeof(char *));
        *line_alloc_num += ALLOC_SIZE;
    }
    text_data[*line_num] = line;
    (*line_num)++;
    return text_data;
}

char **read_file(FILE *fp, int *line_num_p, int test_cnt)
{
    char **text_data = NULL;
    int line_num = 0;
    int line_alloc_num = 0;
    char *line;
    int cnt = 0;

    while ((cnt < test_cnt) && ((line = read_line(fp)) != NULL))
    {
        text_data = add_line(text_data, line, &line_alloc_num, &line_num);
        cnt++;
    }
    /* 将text_data缩小到实际需要的大小 */
    text_data = realloc(text_data, line_num * sizeof(char *));
    *line_num_p = line_num;
    return text_data;
}
