#include <stdio.h>
#include <stdlib.h>
#define BUFFERSIZE 32
int main(int argc, char **argv)
{
    FILE *fps, *fpd;
    char buf[BUFFERSIZE];
    int ch;
    if (argc < 3)
    {
        fprintf(stderr, "Usage:%s <src_file> <dest_file>\n", argv[0]);
        exit(1);
    }

    fps = fopen(argv[1], "r");
    if (fps == NULL)
    {
        fclose(fps);
        perror("fopen()");
        exit(1);
    }
    fpd = fopen(argv[2], "w");
    if (fpd == NULL)
    {
        perror("fopen()");
        exit(1);
    }
    int n;
    while ((n = fread(buf, 1, BUFFERSIZE, fps)) > 0)
    {
        fwrite(buf, 1, n, fpd);
    }

    fclose(fpd);
    fclose(fps);

    exit(0);
}