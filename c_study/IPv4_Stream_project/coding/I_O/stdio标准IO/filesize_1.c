#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp;
    if (argc < 2)
    {
        fprintf(stderr, "usage...\n");
        exit(1);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        perror("fopen()");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    long count = ftell(fp);
    printf("the file: %s size is %ld\n", argv[1], count);
    fclose(fp);
    exit(0);
}