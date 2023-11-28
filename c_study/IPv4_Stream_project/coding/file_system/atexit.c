#include <stdlib.h>
#include <stdio.h>

static void fun1(void)
{
    puts("fun1 is working\n");
}
static void fun2(void)
{
    puts("fun2 is working\n");
}
static void fun3(void)
{
    puts("fun3 is working\n");
}
int main(int argc, char const *argv[])
{
    puts("begin\n");

    atexit(fun1);
    atexit(fun2);
    atexit(fun3);
    puts("end\n");
    return 0;
}
