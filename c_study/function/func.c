#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("argc == %d\n", argc);
    for (size_t i = 0; i < argc; i++)
    {
        printf("argv[%zd] == %s\n", i, argv[i]);
    }
    
    exit(0);
}