/**
 * 变量与地址 int* p = &i; i 是变量，&i 取地址。
 * 指针与指针变量（指针是地址，指针变量就是一个变量，这个变量中存放一个地址（指针））
 * 直接访问与间接访问
 * 空指针与野指针，指针赋为空NULL是为了防止野指针的情况，没有指向任何内容的指针成为野指针
 * 空类型 void* 可以和任何其他类型的指针进行赋值
 * 指针定义与初始化的书写规则
 * 指针运算
 * 指针与数组
 * const 与指针
 *      常量指针：本质是指针，指针指向的内容不可以改变，但是指针的指向可以改变。 int const *p; const int *p;
 *      指针常量：指针的指向不可以改变，只能指向定义的地址，但是地址中的内容可以改变。int* const p;
 * 指针数组与数组指针:
 *      指针数组，本质上是个数组，数组里面存储的是指针， int* p[3];
 *      数组指针，本质上是个指针，指向一个数组的指针 int (*p)[3] ==> int[3] (*p);
 * 多级指针
 * 函数指针和指针函数
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int sum[] = {1, 3, 4};
    int* str[3] = {"hello", "world", "ls"};
    int i = 1;
    int* p = &i;
    printf("i = %d\n", i);
    printf("&i = %p\n", &i);
    printf("p = %p\n", p);
    printf("&p = %p\n", &p);
    printf("*p = %d\n", *p);
    printf("sizeof(p) = %zd\n", sizeof(p)); // 所有指针的大小都是8字节
    exit(0);
}