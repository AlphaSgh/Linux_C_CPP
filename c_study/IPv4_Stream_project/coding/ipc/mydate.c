#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    puts("Begin");
    fflush(NULL);
    execl("/bin/date", "date", "+%s", NULL);
    perror("execl()");
    exit(1);
    puts("end");
    exit(0);
}
