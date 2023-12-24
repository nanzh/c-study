#include "stdio.h"
#include "stdlib.h"

int global_variable;
static int file_static_variable;

void func1(void)
{
    int func1_variable;
    static int func1_static_varibale;
    printf("&func1_variable..%p\n", &func1_variable);
    printf("&func1_static_variable..%p\n", &func1_static_varibale);
}

void func2(void)
{
    int func2_variable;
    printf("&func2_variable..%p\n", &func2_variable);
}

int main()
{
    int *p;

    /* 输出指向函数的指针 */
    printf("&func1..%p\n", func1);
    printf("&func2..%p\n", func2);

    /* 输出字符串常量的地址 */
    printf("string literal..%p\n", "abc");

    /* 输出全局变量 */
    printf("&global_variable..%p\n", &global_variable);

    /* 输出文件内的static变量的地址 */
    printf("&file_static_varibale..%p\n", &file_static_variable);

    /* 输出局部变量 */
    func1();
    func2();

    /* 通过malloc申请的内存区域的地址 */
    p = malloc(sizeof(int));
    printf("malloc address..%p\n", p);
    free(p);

    return 0;
}

/* gcc (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0 result */
/*        地址                内容
 * 0x55a2cdf731a9       函数func1()的地址
 * 0x55a2cdf7320b       函数func2()的地址
 * 0x55a2cdf74062       字符串常量

 * 0x55a2cdf76014       文件内static变量
 * 0x55a2cdf76018       func1()中的static变量
 * 0x55a2cdf7601c       全局变量

 * 0x55a2ce1946b0       利用malloc分配的内存区域

 * 0x7fff5722ee24       func1()中的自动变量
 * 0x7fff5722ee24       func2()中的自动变量
 *
 * */