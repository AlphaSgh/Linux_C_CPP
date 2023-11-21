#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>

#define PAT "/home/hello/.*" // 查看隐藏文件
// #define PAT "/home/hello/*" // 查看当前所有文件排除隐藏文件

int __errfunc(const char *errpath, int eerrno)
{
    puts(errpath);
    fprintf(stderr, "Error msg: %s\n", strerror(eerrno));
    return 0;
}
int main(int argc, char const *argv[])
{
    glob_t globres;
    int err = glob(PAT, 0, NULL, &globres);
    if (err)
    {
        printf("Error code = %d\n", err);
        exit(1);
    }
    for (size_t i = 0; i < globres.gl_pathc; i++)
    {
        puts(globres.gl_pathv[i]);
    }
    globfree(&globres);
    return 0;
}
