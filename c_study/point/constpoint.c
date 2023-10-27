#include <stdlib.h>
#include <stdio.h>

/**
 * const 将变量常量化
 * const int a; int const a; 常量
 * 
 * 常量指针
 * const int *p
 * int const *p
 * 指针常量
 * int* const p;
 * 
 * const int* const p;
*/
int main(void)
{
    const int i = 10;
    const int j = 100;
    const int* const p = &i; // 指针的指向和指针指向的内容均不可发生改变
    // p = &j; // error 
    // *p = j; // error

#if 0
    const int i = 10;
    const int j = 100;
    int* const p = &i; // 指针常量
    // p = &j; //error 常量指针，指针的指向不可以被改变
    *p = j; // 指针指向的内容可以进行修改
#endif

#if 0
    const int i = 10;
    const int j = 100;
    const int* p = &i; // 常量指针
    p = &j; // 可以修改指向
    // *p = j; // 不可以修改指针指向的内容
#endif
    exit(0);
}