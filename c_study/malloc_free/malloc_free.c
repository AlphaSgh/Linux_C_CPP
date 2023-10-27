#include <stdio.h>
#include <stdlib.h>
/* 内存泄漏
void func(int *p, int size)
{
    p = malloc(size);
    if (p == NULL)
    {
        exit(0);
    }
    return;
}
*/
/* 解决方法1：返回指针p
void* func(int *p, int size)
{
    p = malloc(size);
    if (p == NULL)
    {
        exit(0);
    }
    return p;
}
*/
void func(int** p, int size)
{
    *p = malloc(size);
    if (*p = NULL)
    {
        exit(0);
    }
    return;
}
int main(void)
{
    // int num = 10;
    // int *p = NULL;

    // func(&p, num);
    // free(p);
    int* p = NULL;
    p = malloc(sizeof(int));
    *p = 10;
    printf("%p --> %d\n", p, *p);
    free(p);
    p = NULL;
    *p = 100;
    printf("%p --> %d\n", p, *p);
    exit(0);
    // int *p = NULL;
    // p = malloc(sizeof(int));
    // if (p == NULL)
    // {
    //     printf("malloc error\n");
    //     exit(0);
    // } else
    // {
    //     *p = 10;
    // }
    // printf("p = %d\n", *p);
    // free(p);
    // exit(0);
}