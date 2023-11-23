#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <glob.h>

#define PATHSIZE 1024

static int path_noloop(const char *pathname)
{
    char *pos;
    pos = strrchr(pathname, '/');
    if (pos == NULL)
    {
        exit(1);
    }
    if (strcmp(pos + 1, ".") == 0 || strcmp(pos + 1, "..") == 0)
    {
        return 0;
    }
    return 1;
}
static int64_t mydu(const char *pathname)
{
    // 如果一个变量自始至终没有进入递归中，则可以将该变量声明为static，存储在静态区，不占递归的栈空间
    // 如果一个变量在递归中使用到，则必须声明为auto类型。
    // path 为非目录文件
    static struct stat statres;
    static char nextpath[PATHSIZE];
    glob_t globres;
    if (lstat(pathname, &statres) < 0)
    {
        perror("lstat()");
        exit(1);
    }
    if (!(S_ISDIR(statres.st_mode)))
    {
        return statres.st_blocks;
    }
    strncpy(nextpath, pathname, PATHSIZE - 1);
    strncat(nextpath, "/*", PATHSIZE - 1);
    glob(nextpath, 0, NULL, &globres);

    strncpy(nextpath, pathname, PATHSIZE - 1);
    strncat(nextpath, "/.*", PATHSIZE - 1);
    glob(nextpath, GLOB_APPEND, NULL, &globres);

    int64_t sum = statres.st_blocks;
    for (size_t i = 0; i < globres.gl_pathc; i++)
    {
        if (path_noloop(globres.gl_pathv[i]) != 0)
        {
            sum += mydu(globres.gl_pathv[i]);
        }
    }
    globfree(&globres);
    return sum;
}
int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }
    int64_t res = mydu(argv[1]);
    printf("%ld\t%s\n", res / 2, argv[1]);
    return 0;
}
