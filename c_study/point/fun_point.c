/**
 * 函数与指针
 * 指针函数
 *      返回值 * 函数名（形参）==》int* fun(int i)本质为一个函数，返回值为一个指针
 * 函数指针
 *      本质上是一个指针，这个指针指向一个函数  类型 (*指针名) （形参） int（*p）(int, int); 指针p指向一个函数【int add(int a, int b){}, p = &add】
 * 函数指针数组
 *      本质上是一个数组，数组里面存放的是函数指针 数组arr中存放的是指针，每一个指针都指向一个函数 int add(int a, int b){}, p = &add】
 * 
 * 指向指针函数的函数指针数组
 *      int* (*funcp[N]) (int)
*/
#include <stdio.h>
#include <stdlib.h>

// 指针函数
// 返回值 * 函数名（形参）==》int* fun(int i)本质为一个函数，返回值为一个指针
int* point_fun(int (*p)[5], int i)
{
    return *(p + i);
}

// 函数指针
// 本质上是一个指针，这个指针指向一个函数  类型 (*指针名) （形参） int（*p）(int, int); 指针p指向一个函数【int add(int a, int b){}, p = &add】
int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
// 函数指针数组
// 本质上是一个数组，数组里面存放的是函数指针 int(*arr[n]) (int, int); 数组arr中存放的是指针，每一个指针都指向一个函数 int add(int a, int b){}, p = &add】

int main(void)
{
    int res;
    int a = 2, b = 8;
    // 函数指针数组
    int (*arr[2]) (int, int);
    arr[0] = &add;
    arr[1] = &sub;
    for (size_t i = 0; i < 2; i++)
    {
        res = arr[i](a, b);
        printf("res = %d\n", res);
    }
    

/*
函数指针
本质上是一个指针，这个指针指向一个函数  类型 (*指针名) （形参） int（*p）(int, int); 指针p指向一个函数【int add(int a, int b){}, p = &add】
    int res;
    int a = 2, b = 8;
    int (*p) (int, int);
    p = &add;
    res = p(a, b);
    printf("res = %d\n", res);
    p = &sub;
    res = p(a, b);
    printf("res = %d\n", res);

*/


/*
指针函数
    const int M = 2, N = 5;
    int arr[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int* res;
    res = point_fun(arr, 0);
    for (size_t i = 0; i < N; i++)
    {
        printf("%d ", *(res + i));
    }
*/

    exit(0);
}