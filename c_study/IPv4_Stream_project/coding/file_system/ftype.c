#define _BSD_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <sys/sysmacros.h>
#include <fcntl.h>

static int ftype(const char *fname)
{
    struct stat filestat;
    if (stat(fname, &filestat) < 0)
    {
        perror("stat()");
        exit(1);
    }
    /*
    S_ISREG(m)  is it a regular file?

    S_ISDIR(m)  directory?

    S_ISCHR(m)  character device?

    S_ISBLK(m)  block device?

    S_ISFIFO(m) FIFO (named pipe)?

    S_ISLNK(m)  symbolic link?  (Not in POSIX.1-1996.)

    S_ISSOCK(m) socket?  (Not in POSIX.1-1996.)
    */
    switch (filestat.st_mode & S_IFMT)
    {
        // dcb-lsp
    case S_IFBLK:
        return 'b';
        break;
    case S_IFCHR:
        return 'c';
        break;
    case S_IFDIR:
        return 'd';
        break;
    case S_IFIFO:
        return 'p';
        break;
    case S_IFLNK:
        return 'l';
        break;
    case S_IFREG:
        return '-';
        break;
    case S_IFSOCK:
        return 's';
        break;
    default:
        return '?';
        break;
    }
}
int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "usage...\n");
        exit(1);
    }
    int ch = ftype(argv[1]);
    printf("%s is %c\n", argv[1], ch);
    return 0;
}
