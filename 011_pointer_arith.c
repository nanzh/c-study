#include "stdio.h"

int main(void){

    int hoge;
    int *hoge_p;

    hoge_p = &hoge;
    printf("hoge_p..%p\n", hoge_p);
    hoge_p++;
    printf("hoge_p..%p\n", hoge_p);
    printf("hoge_p+3..%p\n", hoge_p+3);

    char str[256];
    str[0] = 'a';
    str[1] = 'b';
    printf("%s\n", str);

    return 0;
}