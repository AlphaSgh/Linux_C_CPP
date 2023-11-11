## 静态库
libxx.a
xx 指代静态库ming

ar -cr libxx.a yyy.o

发布到
/usr/local/include
/usr/local/lib

gcc -L/usr/local/lib -o mian main.o -lxx
-l参数必须在最后，存在依赖关系

## 动态库 .so
libxx.so
xx 指代动态库名
gcc -shared -fpic -o libxx.so yyy.c

发布到
/usr/local/include
/usr/local/lib

在 /etc/ld.so.conf 中添加路径
/sbin/ldconfig 重读 /etc/ld.so.conf

gcc -I/usr/local/include -L/usr/local/lib -o ... -lxx
ldd - print shared library dependencies