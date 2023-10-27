#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    short x;
    // 类型参数：
    printf("sizeof(float)          = %zu\n", sizeof(float));
    printf("sizeof(void(*)(void))  = %zu\n", sizeof(void(*)(void)));
    printf("sizeof(char[10])       = %zu\n", sizeof(char[10]));
//  printf("sizeof(void(void))     = %zu\n", sizeof(void(void))); // 错误：函数类型
//  printf("sizeof(char[])         = %zu\n", sizeof(char[])); // 错误：不完整类型
 
    // 表达式参数：
    printf("sizeof 'a'             = %zu\n", sizeof 'a'); // 'a' 的类型为 int
    // printf("sizeof main            = %zu\n", sizeof main); // 错误：函数类型
    printf("sizeof &main           = %zu\n", sizeof &main);
    printf("sizeof \"hello\"         = %zu\n", sizeof "hello"); // 类型为 char[6]
    printf("sizeof x               = %zu\n", sizeof x);   // x 的类型为 short
    printf("sizeof (x+1)           = %zu\n", sizeof(x+1)); // x+1 的类型为 int
    exit(0);
}