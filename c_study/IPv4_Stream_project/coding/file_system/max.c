#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

// 生成空洞文件
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "usage...\n");
        exit(1);
    }
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd < 0)
    {
        perror("open");
        exit(1);
    }
    lseek(fd, 5L * 1024 * 1024 * 1024 - 1, SEEK_SET);
    write(fd, "", 1);
    close(fd);
    exit(0);
}