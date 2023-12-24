#include <stdio.h>

extern int extern_test_i;
// warning: type defaults to ‘int’ in declaration of ‘extern_test_i’ [-Wimplicit-int]
// extern extern_test_i;

// /usr/bin/ld: /tmp/ccoIvn9E.o:(.data+0x0): multiple definition of `extern_test_i'; /tmp/ccV15fGF.o:(.data+0x0): first defined here
// extern int extern_test_i = 10;

// extern_test_j 类型不一致，为什么会编译通过呢
extern double extern_test_j;

extern void extern_test_fun(void);
// warning: type defaults to ‘int’ in declaration of ‘extern_test_fun’ [-Wimplicit-int]
// extern extern_test_fun();

int main(){

    printf("i = %d\r\n", extern_test_i);
    extern_test_j = 2.0;
    printf("j = %lf\r\n", extern_test_j);
    extern_test_fun();
    return 0;
}