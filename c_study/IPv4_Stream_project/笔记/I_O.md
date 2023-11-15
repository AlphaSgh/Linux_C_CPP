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

- fgetc();
- fputc();
- fgets();
- fgets(char \*, SIZE, FILE_Stream), 正常结束情况：1. 读到了 size - 1 个字符，2. 读到了 '\n';
- fputs();
- fputs(const char *, FILE *stream),

- fread();
- fread(buf, size, nmemb, fp); 从 fp 读取 nmemb 个大小为 size 的对象到 buf 中，返回值为成功读取的对象个数，如果读取的字节数小于 size 则无法进行读取
- fwrite();

- printf(const char \*format, ...);
- fprintf(FILE *stream, const char *format, ...);
- sprintf(char *str, const char *format, ...);
- snprintf(char *str, size_t size, const char *format, ...);放入 n 个字节，防止缓冲器溢出
- atoi(const char \*strnum); 讲一个字符串转换为数字
- scanf(const char \*format, ...);
- fscanf(FILE \*stream, const char \*format, ...);
- sscanf(const char *str, const char *format, ...)

文件位指针，文件的读写发生在当前位置。

- fseek(\*stream, offset, whence); 可以实现空洞文件
- ftell(\*stream); 返回文件指针所在位置
- rewind(); == (void) fseek(stream, 0L, SEEK_SET)
- fseeko();
- ftello();

- fflush(); 刷新缓冲器

- getline(char \**lineptr, size_t *n, FILE *stream); 从 stream 中获取一整行的内容放入 *lineptr。
- 临时文件：1.如何不冲突，2.及时销毁，3.常用函数：创建临时名字 char *tmpnam(char *s); 创建临时文件 FILE \*tmpfile(void);
