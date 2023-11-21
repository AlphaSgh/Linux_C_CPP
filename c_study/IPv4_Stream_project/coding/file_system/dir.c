#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

#define PAT "/etc"

int main(int argc, char const *argv[])
{
    DIR *dp;
    struct dirent *cur;
    dp = opendir(PAT);
    if (dp == NULL)
    {
        perror("opendir()");
        exit(1);
    }
    int count = 0;
    while ((cur = readdir(dp)) != NULL)
    {
        count++;
        puts(cur->d_name);
    }
    printf("count = %d\n", count);
    closedir(dp);
    return 0;
}
