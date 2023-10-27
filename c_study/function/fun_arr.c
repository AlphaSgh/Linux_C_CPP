#include <stdio.h>
#include <stdlib.h>

void print_arr_p(int* p, int n)
{
    printf("%s:%zd\n", __FUNCTION__, sizeof(p));
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");
}
void print_arr(int p[], int n)
{
    printf("%s:%zd\n", __FUNCTION__, sizeof(p));
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
}
void print_darr1(int *p, int length)
{
    printf("sizeof(p) = %zd\n", sizeof(p));
    for (size_t i = 0; i < length; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");
}
void print_darr2(int (*p)[4], int m, int n) 
{
    printf("sizeof(p) == %zd\n", sizeof(p));
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
    
}
void print_darr3(int **p, int m, int n) 
{
    printf("sizeof(p) == %zd\n", sizeof(p));
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            printf("%d ", *((int *)p + i * n +j));
        }
        printf("\n");
    }
    
}
int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    // printf("%s:%zd\n", __FUNCTION__, sizeof(a));
    // print_arr(a, sizeof(a) / sizeof(*a));
    // print_arr_p(a, sizeof(a) / sizeof(*a));

    int b[3][4] = {1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2, 1};
    print_darr1(*b, 3 * 4);
    print_darr2(&b[0], 3, 4);
    print_darr3((int **)b, 3, 4);
    exit(0);
}