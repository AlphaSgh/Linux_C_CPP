#include <stdio.h>
#include <stdlib.h>
/**
 * 缓冲器的作用：
 *      大多数情况下是好事，合并系统调用
 * 1.行缓冲：换行的时候刷新，缓冲区满进行刷新，强制刷新（标准输出，应为是终端设备）
 *
 * 2.全缓冲：缓冲器满进行缓冲，强制刷新（默认，只要不是终端设备）
 *
 * 3.立即输出，stderr，立即输出错误
 *
 * setvbuf()修改缓冲器模式
 */
int main(int argc, char **argv)
{
    int i;
    printf("before while()");
    fflush(stdout);
    while (1)
    {
        /* code */
    }
    printf("after while()");
    exit(0);
}