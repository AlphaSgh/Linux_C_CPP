#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
static off_t filesize(const char *fname)
{
    struct stat filestat;
    if (stat(fname, &filestat) < 0)
    {
        perror("stat()");
        exit(1);
    }
    return filestat.st_size;
}
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }
    off_t fsize = filesize(argv[1]);
    printf("file size = %ld\n", fsize);
    exit(0);
}