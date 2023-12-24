#include "stdio.h"
#include "stdarg.h"

void debug_write(char *fmt, ...);

#define DEBUG

#ifdef DEBUG
#define DEBUG_WRITE(arg) debug_write arg
#else
#define DEBUG_WRITE(arg)
#endif

#define SNAP_INT(arg) fprintf(stderr, #arg "...%d\n", arg)

void debug_write(char *fmt, ...){
    va_list ap;
    va_start(ap, fmt);

    vfprintf(stderr, fmt, ap);

    va_end(ap);

}


int main(){

    int hoge = 5;

    DEBUG_WRITE(("hoge...%d\n", hoge));
    // error: macro "DEBUG_WRITE" passed 2 arguments, but takes just 1
    // DEBUG_WRITE("hoge..%d\n", 5);

    SNAP_INT(hoge);
    SNAP_INT('a');

    return 0;
}