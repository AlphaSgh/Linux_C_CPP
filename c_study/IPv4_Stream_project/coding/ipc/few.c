#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    puts("begin");
    fflush(NULL);
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        perror("fork()");
        exit(1);
    }
    if (pid == 0)
    {
        execl("/usr/bin/ls", "-l", NULL);
        perror("execl()");
        exit(1);
    }
    wait(NULL);
    puts("end");
    return 0;
}
