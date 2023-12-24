#include "stdio.h"
#include "stdlib.h"
#include "read_any_line.h"
#define TEST_COUNT 5

int main(){
    char **text_data;
    int line_num;
    int i;

    text_data = read_file(stdin, &line_num, TEST_COUNT);
    for(i=0; i<line_num; i++){
        printf("%s\n", text_data[i]);
    }

    free_buff();
    free(text_data);
    return 0;

}