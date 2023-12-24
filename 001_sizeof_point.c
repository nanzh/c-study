#include "stdio.h"

void fun(int b[100]){
    printf("void fun(int b[100]){\r\n");
	printf("sizeof(b) = %ld\r\n", sizeof(b));
    printf("}\r\n");
}


int main(){

	int *p = NULL;
	printf("int *p = NULL\r\n");
	printf("sizeof(p) = %ld\r\n", sizeof(p));
	printf("sizeof(*p) = %ld\r\n", sizeof(*p));

	int a[100];
	printf("\r\nint a[100]\r\n");
	printf("sizeof(a) = %ld\r\n", sizeof(a));
	printf("sizeof(a[0]) = %ld\r\n", sizeof(a[0]));
	printf("sizeof(a[100]) = %ld\r\n", sizeof(a[100]));
	printf("sizeof(&a) = %ld\r\n", sizeof(&a));
	printf("sizeof(&a[0]) = %ld\r\n", sizeof(&a[0]));

    int i = 0;
    printf("\r\nint i = 0\r\n");
    printf("sizeof(i) = %ld\r\n", sizeof(i));
    printf("sizeof(&i) = %ld\r\n", sizeof(&i));

	int b[100];
	printf("\r\nint b[100]\r\n");
    fun(b);

	return 0;
}
