#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
int main()
{
    int count = 0;
    FILE *fp;
    while (1)
    {
        fp = fopen("tmp", "w");
        if (fp == NULL)
        {
            // fprintf(stderr, "fopen() failed errno = %d\n", errno); // 打印错误errno
            perror("fopen()"); // 打印错误信息
            // fprintf(stderr, "fopen(): %s\n", strerror(errno)); // 打印错误信息
            break;
        }
        count++;
    }
    printf("count = %d\n", count);
    exit(0);
}