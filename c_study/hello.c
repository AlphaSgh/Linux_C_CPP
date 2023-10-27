#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    bool flag = true;
    printf("true = %d\n", flag);
    printf("%c, %c, %c\n", '\047', '\x7f', 'X');
    printf("hello\n");
    exit(0);
}