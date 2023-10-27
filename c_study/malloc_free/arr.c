#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int num = 5;
    int *p = NULL;
    p = malloc(sizeof(int) * num);
    for (size_t i = 0; i < num; i++)
    {
        scanf("%d", &p[i]);
    }
    for (size_t i = 0; i < num; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");
    free(p);
    exit(0);
}