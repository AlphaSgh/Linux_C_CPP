#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    // 标准IO和系统IO不可以混用
    putchar('a');
    int ret;
    ret = write(1, "b", 1);

    putchar('a');
    ret = write(1, "b", 1);

    putchar('a');
    ret = write(1, "b", 1);
    exit(0);
}