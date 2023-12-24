#include "stdio.h"

/* 从标准输入读取一个整数，然后在循环里打印这个整数值，
 * 每次输出后等待用户输入一个字符，然后将整数加1
 */

/* 测试同时打开两个窗口运行，输出的hoge地址相同? */
int main(){

    int hoge;
    char buff[256];

    printf("&hoge..%p\n", &hoge);

    printf("Input initial value.\n");
    fgets(buff,sizeof(buff), stdin);
    sscanf(buff, "%d", &hoge);

    for(;;){
        printf("hoge..%d\n", hoge);
        getchar();
        hoge++;

    }

    return 0;
}