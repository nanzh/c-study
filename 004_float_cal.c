#include "stdio.h"

int main(){
    /* 结果不太符合预期 */
    float a = 10000000000.00;
    float b = 0.00000000001;
    printf("%lf\n", a+b);

    return 0;
}