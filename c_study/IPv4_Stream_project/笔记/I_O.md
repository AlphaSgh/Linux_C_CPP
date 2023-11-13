## I/O input & output，一切实现的基础

当标准 I/O 和系统 I/O 均可以使用的时候，优选标准 I/O；
系统调用 I/O 是接口，标准 I/O 是接口的实现。

## 系统调用 I/O，sysio

## 标准 I/O， stdio

- 标准 I/O 依赖于系统调用 I/O
- FILE 类型贯穿始终
- fopen(const char *path, const char *mode); fopen 函数返回的 FILE \* 放在堆上。
- fopen 打开文件的上限
- 程序运行之后会自动打开 3 个流，标准输入-stdin,标准输出-stdout,标准错误-stderr
- 新文件的权限计算 0666 & ~umask
- path:文件路径，mode：打开权限 r, r+, w, w+, a, a+,
- fclose();

fgetc();
fputc();
fgets();
- fgets(char *, SIZE, FILE_Stream), 正常结束情况：1. 读到了 size - 1 个字符，2. 读到了 '\n';
fputs();
- fputs(const char *, FILE *stream),
fread();
fwrite();

printf();
scanf();

fseek();
ftell();
fewind();

fflush();
