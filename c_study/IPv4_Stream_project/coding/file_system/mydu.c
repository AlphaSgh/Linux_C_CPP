#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

static int64_t mydu(const char *pathname)
{ // path 为非目录文件
    struct stat result_stat;
    if (lstat(pathname, &result_stat) < 0)
    {
        perror("lstat()");
        exit(1);
    }
    if (!(S_ISDIR(result_stat.st_mode)))
    {
        return result_stat.st_blocks / 2;
    }

    // path 为目录文件
    return 0;
}
int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }
    int64_t res = mydu(argv[1]);
    printf("%ld\t%s\n", res, argv[1]);
    return 0;
}
