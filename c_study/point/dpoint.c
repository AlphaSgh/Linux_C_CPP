#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[2][3] = {1, 2, 3, 4, 5, 6};
    int* p = *a;
    int (*q)[3] = a; // 数组指针
    printf("%p -- > %d\n", q, **q);
    printf("%p -- > %d\n", q + 1, **(q + 1));
    // a[i][j] = *(*(a + i) + j)
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%p --> a[%zd][%zd] == %d ",&a[i][j], i, j, a[i][j]);
        }
        printf("\n");
    }
    exit(0);
}