#include <stdio.h>
#include "string.h"

void Fun(char *p){
    //p="hello";
    strcpy(p,"hello");
}

int Fun1(void){
    int a = 5;
    return a;
}

/* 函数内返回局部变量出错 */
char * Fun2(void){
    char str[30];
    return str;
}

int main()
{
    char q[10];
    Fun(q);
    printf("%s\n",q);

    int i;
    i = Fun1();
    printf("%d\n",i);

    char *ret;
    ret = Fun2();
    printf("%s\n",ret);
    return 0;
}

/* chatgpt 给的修改方式 */
/* 
#include <stdlib.h>
#include <string.h>

int Fun1(void) {
    int a = 5;
    return a;
}

char* Fun2(void) {
    char* str = (char*)malloc(30 * sizeof(char));
    strcpy(str, "Hello, World!");
    return str;
}

int main() {
    int result1 = Fun1();
    printf("%d\n", result1);
    
    char* result2 = Fun2();
    printf("%s\n", result2);
    free(result2);  // 释放动态分配的内存

    return 0;
}
*/