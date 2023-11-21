#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define FNAME "./out"

int main()
{
    /*
        int fd;
        close(1);
        fd = open(FNAME, O_WRONLY | O_CREAT | O_TRUNC, 0600);
        if (fd < 0)
        {
            perror("open()");
            exit(1);
        }
    */

#if 0
    int fd;
    fd = open(FNAME, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd < 0)
    {
        perror("open()");
        exit(1);
    }
    // close(1) 和 dup(fd) 不是原则操作，多线程环境下会出现 关闭 1后被其他线程抢占的情况。
    close(1);  // 关闭1号文件描述符
    dup(fd);   // 将 文件描述符 fd 复制到 1 号
    close(fd); // 关闭原来的 fd
#endif
    int fd;
    fd = open(FNAME, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd < 0)
    {
        perror("open()");
        exit(1);
    }
    dup2(fd, 1); // 将上面的close(1) 和 dup(fd)合并为原子操作，关闭1号，复制fd到1号
    if (fd != 1)
    {
        close(fd);
    }

    /***********************************/
    printf("Hello world\n");
    exit(0);
}