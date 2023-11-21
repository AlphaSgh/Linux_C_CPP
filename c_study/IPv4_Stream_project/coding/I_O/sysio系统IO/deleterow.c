#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFSIZE 1024
int main(int argc, char **argv)
{

    int f1, f2;
    int ret, row = 0, rpos = 0, wpos = 0, pos = 0;
    char buf[BUFSIZE]; // 临时数组
    if (argc < 2)      // 如果传入参数不够，给出提示
    {
        fprintf(stderr, "用法错误 %d\n", argc);
        exit(1);
    }
    // 只读方式打开
    f1 = open(argv[1], O_RDONLY);
    if (-1 == f1)
    {

        perror("open()");
        exit(1);
    }
    // 以读写方式打开
    f2 = open(argv[1], O_RDWR);
    if (-1 == f2)
    {

        perror("open()");
        exit(1);
    }
    // 找到读取位置
    while (1)
    {
        if (row == 10)
        {
            rpos = lseek(f1, pos, SEEK_SET);
            break;
        }
        if (read(f1, buf, 1) <= 0)
            break;
        if (buf[0] == '\n')
            row++;

        pos++;
    }

    pos = 0;
    row = 0;

    // 找到写入位置
    while (1)
    {
        if (row == 9)
        {
            wpos = lseek(f2, pos, SEEK_SET);
            break;
        }
        if (read(f2, buf, 1) <= 0)
            break;
        if (buf[0] == '\n')
            row++;

        pos++;
    }

    // 读取数据写入文件
    while (1)
    {
        if (read(f1, buf, 1) <= 0)
            break;
        write(f2, buf, 1);
    }
    // 从写入位置开始截断
    ret = lseek(f2, 0, SEEK_CUR);
    // ftruncate(f2, rpos - wpos);
    close(f1); // 关闭文件
    close(f2);
    exit(0);
}