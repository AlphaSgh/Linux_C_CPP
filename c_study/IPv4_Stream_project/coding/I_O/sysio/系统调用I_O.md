# 文件 IO 系统调用 IO

## fd 在文件 I/O 中贯穿始终

## 文件描述符的作用和概念(一个整型数（数组下标的位置，通过下标找到数组内的内容，里面存放的是 inode 结构体的地址指针，可以找到 inode）)

- Stream 流：标准输入，标准输出，标准出错
- fd：0，1，2,对应标准输入，标准输出，标准出错，文件描述符优先使用最小的可以使用的。
- inode 数组存在于当前的进程内，一个文件被打开多少次就会存在多少个对应的 inode 结构体
- inode 结构体内存在 pos 位置指针，count 表示打开次数

## 文件 IO 操作：open，close，read，write，lseek

```c
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
// 参数flag：读写权限是必需的，后面的是可加的，
// mode：是新创建的文件权限
// 上面两个open不是重载，下面的open是可变形参
O_CREATE,O_TRUNC
int openat(int dirfd, const char *pathname, int flags);
int openat(int dirfd, const char *pathname, int flags, mode_t mode);
```

```c
#include <unistd.h>
// 从 fd 中读取 size 大小的内容写到 buf 中
ssize_t read(int fd, void \*buf, size_t count);
// 从 buf 中度size大小内容写入到fd中
ssize_t write(int fd, const void *buf, size_t count);
```

- 标准 IO 与系统 IO 映射
- r -> O_RDONLY
- r+ -> O_RDWR
- w -> O_WRONLY | O_CREATE | O_TRUNC
- w+ -> O_RDWR | O_TRUNC | O_CREATE

## IO 的效率问题

## 文件 IO 和标准 IO 的区别

- 响应速度（文件 IO 快，标准 IO 满） 吞吐量（文件 IO 吞吐量小，标准 IO 大）
- 标准 IO 和文件 IO 不可以混合使用

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    // 标准IO和系统IO不可以混用
    putchar('a');
    write(1, "b", 1);

    putchar('a');
    write(1, "b", 1);

    putchar('a');
    write(1, "b", 1);
    exit(0);
}
```

- 对标准 IO 的写不一定直接写入到文件中，而是写到了缓冲区中 buffer 中。

```c
// 标准IO和文件IO相互转换
// 将一个FILE Stream流转化会 fd文件描述符
int fileno(FILE *stream);
// 将文件描述符fd转化为FILE Stream流
FILE *fdopen(int fd, const char *mode);
```

## 文件共享

## 原子操作

## 程序中的重定向：dup，dup2

## 同步：sync(); fsync(); fdatasync(); fctl(); ioctl();

## 虚目录：/dev/fd
