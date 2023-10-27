#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char* strs[3] = {"hello", "world", "c!"};
    for (size_t i = 0; i < sizeof(strs) / sizeof(strs[0]); i++)
    {
        printf("%s\n", strs[i]);
    }
    
    int a[3];
    int* p = a;
    for (size_t i = 0; i < sizeof(a) / sizeof(*a); i++)
    {
        printf("%p -- > %d\n", &a[i], a[i]);
    }
    
    for (size_t i = 0; i < sizeof(a) / sizeof(*a); i++)
    {
        scanf("%d", p + i);
    }
    for (size_t i = 0; i < sizeof(a) / sizeof(*a); i++)
    {
        printf("%p -- > %d\n", p + i, *(p + i));
    }
    
    
    #if 0
    int a[3] = {1, 2, 3};
    int i;
    int* p = a; // a是常亮， p是变量 p++正确，a++出错
    // value = a[i] = *(a + i) = *(p + i) = p[i]
    // &a[i] = a + i = p + i = &p[i]
    // 一维数组大小 == sizeof(a) / sizeof(*a)  *a == *(a + 0) == a[0]
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("%p --> %d\n", a + i, a[i]);
        printf("%p --> %d\n", p + i, *(p + i));
        printf("%p --> %d\n", p + i, p[i]);

    }
    #endif
    exit(0);
}