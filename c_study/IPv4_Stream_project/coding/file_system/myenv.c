#include <stdio.h>
#include <stdlib.h>
extern char **environ;
int main(int argc, char **argv)
{
    for (size_t i = 0; environ[i] != NULL; i++)
    {
        puts(environ[i]);
    }
    printf("%p\n", getenv("SHELL"));
    setenv("SHELL", "/BIN/BASH", 1);
    printf("%p\n", getenv("SHELL"));
    getchar();
    puts(getenv("SHELL"));
    exit(0);
}