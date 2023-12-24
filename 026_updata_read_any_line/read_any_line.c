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

static ReadLineStatus add_character(int ch)
{
    /* 此函数每次被调用，st_current_buffer_size都必定会增加1，正常情况下，下面的断言肯定不会出错 */
    assert(st_current_buffer_size >= st_current_used_size);

    if (st_current_buffer_size == st_current_used_size)
    {
        char *temp;
        temp = realloc(st_line_buffer, (st_current_buffer_size + ALLOC_SIZE * sizeof(char)));
        if (temp == NULL)
        {
            return READ_LINE_OUT_OF_MEMORY;
        }
        st_line_buffer = temp;
        st_current_buffer_size += ALLOC_SIZE;
    }
    st_line_buffer[st_current_used_size] = ch;
    st_current_used_size++;
    return READ_LINE_SUCCESS;
}

/* 如果想成为通用函数，就需要对返回值做检查，并且能向调用方返回函数的处理状态
 * 以下几种可能，使用枚举类型ReadLineStatus:
 * 正常读取了一行
 * 读到了文件的末尾
 * 内存不足都导致处理失败
 */

ReadLineStatus read_line(FILE *fp, char **line)
{
    int ch;
    ReadLineStatus status = READ_LINE_SUCCESS;

    st_current_used_size = 0;
    while ((ch = getc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            status = add_character('\0');
            if (status != READ_LINE_SUCCESS)
            {
                goto FUNC_END;
            }

            break;
        }
        status = add_character(ch);
        if (status != READ_LINE_SUCCESS)
        {
            goto FUNC_END;
        }
    }
    if (ch == EOF)
    {
        if (st_current_used_size > 0)
        {
            status = add_character('\0');
            if (status != READ_LINE_SUCCESS)
            {
                goto FUNC_END;
            }
        }
        else
        {
            status = READ_LINE_EOF;
            goto FUNC_END;
        }
    }
    *line = malloc(sizeof(char) * (st_current_used_size));
    if (*line == NULL)
    {
        status = READ_LINE_OUT_OF_MEMORY;
        goto FUNC_END;
    }
    strcpy(*line, st_line_buffer);

FUNC_END:
    if (status != READ_LINE_SUCCESS && status != READ_LINE_EOF)
    {
        free(*line);
        free_buff();
    }
    return status;
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
    ReadLineStatus ret;

    while (cnt < test_cnt)
    {
        if ((ret = read_line(fp, &line)) != READ_LINE_SUCCESS)
        {
            printf("read line error, ret is %d\r\n", ret);
            break;
        }
        text_data = add_line(text_data, line, &line_alloc_num, &line_num);
        cnt++;
    }
    /* 将text_data缩小到实际需要的大小 */
    text_data = realloc(text_data, line_num * sizeof(char *));
    *line_num_p = line_num;
    return text_data;
}
