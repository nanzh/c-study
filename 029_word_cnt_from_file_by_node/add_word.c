#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "word_manage_p.h"


/* 复制字符串 */
static char *my_strdup(char *src)
{
    char *dest;
    dest = malloc(sizeof(char) * (strlen(src) + 1));
    strcpy(dest, src);
    return dest;
}

static Word *create_word(char *name){
    Word *new_word;
    new_word = malloc(sizeof(Word));

    new_word->name = my_strdup(name);
    new_word->count = 1;
    new_word->next = NULL;

    return new_word;

}

/* 追加单词 */
void add_word(char *word)
{
    printf("word is %s\r\n", word);

    Word *pos;
    Word *prev;
    Word *new_word;
    int result;

    prev = NULL;
    for(pos = word_header; pos != NULL; pos = pos->next){
        result = strcmp(pos->name, word);
        if(result >= 0){
            break;
        }
        prev = pos;
    }
    if(word_header != NULL && result == 0){
        pos->count++;
    }
    else{
        new_word = create_word(word);
        if(prev == NULL){
            /* 插到初始位置 */
            new_word->next = word_header;
            word_header = new_word;
        }
        else{
            new_word->next = pos;
            prev->next = new_word;

        }
    }
  
}