#include <stdio.h>

union {
    int i;
    char a[2];
}*p, u;

void check_system(){
    union check{
        int i;
        char ch;
    }u_check;
    u_check.i = 1;
    if(u_check.ch==1){
        printf("this is little-endian\r\n");
    }
    else{
        printf("this is big-endian\r\n");
    }


}

int main(){
    p = &u;
    p->a[0] = 0x39;
    p->a[1] = 0x38;
    printf("p->i = %x\r\n", p->i);

    check_system();
    return 0;
}