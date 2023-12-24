#include "stdlib.h"
#include "word_manage_p.h"

void dump_word(FILE *fp){
    int i;
    printf("num_of_word = %d\r\n", num_of_word);
    for(i = 0; i<num_of_word; i++){
        fprintf(fp, "%-20s%5d\n", word_array[i].name, word_array[i].count);
    }

}