#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define STRSIZE 32

int main(void)
{
    char str[STRSIZE];
    // strcat();strcmp();strcpy();strncat();strncmp();strncpy();
    strncpy(str, "hello", STRSIZE);
    printf("len = %zd\n", strlen(str));
    printf("size = %zd\n", sizeof(str));
    exit(0);
}