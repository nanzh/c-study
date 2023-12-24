#ifndef READ_LINE_H_INCLUDED
#define READ_LINE_H_INCLUDED

#include <stdio.h>

char *read_line(FILE *fp);
void free_buff(void);
char **add_line(char **text_data, char *line, int *line_alloc_num, int *line_num);
char **read_file(FILE *fp, int *line_num_p, int test_cnt);

#endif