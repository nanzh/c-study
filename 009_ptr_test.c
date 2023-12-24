#include <stdio.h>

int main(){

    int a[5] = {1,2,3,4,5};
    int *ptr1 = (int *)(&a+1);
    printf("%x\r\n", ptr1[-1]);
    // int *ptr2 = (int *)((int)a+1);
    // printf("%x,%x\r\n", ptr1[-1], *ptr2);

    return 0;
}