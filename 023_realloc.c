#include "stdio.h"
#include "stdlib.h"

#define TEST_COUNT 5

int main()
{

    int *variable_array = NULL;
    int size = 0;
    char buf[256];
    int i;

    while (fgets(buf, 256, stdin) != NULL)
    {
        size++;
        if(size >= TEST_COUNT){
            break;
        }
        variable_array = realloc(variable_array, sizeof(int) * size);
        sscanf(buf, "%d", &variable_array[size - 1]);
    }

    for (i = 0; i < size; i++)
    {
        printf("variable_array[%d]..%d\r\n", i, variable_array[i]);
    }

    return 0;
}