#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define FNAME "/tmp/out"
#define BUFFSIZE 1024
int main(int argc, char const *argv[])
{
    FILE *fp;
    char buf[BUFFSIZE];
    int count = 0;
    time_t stamp;
    struct tm *tm;
    fp = fopen(FNAME, "a+");
    if (fp == NULL)
    {
        perror("fopen()");
        exit(1);
    }
    while (fgets(buf, BUFFSIZE, fp) != NULL)
    {
        count++;
    }

    while (1)
    {
        time(&stamp);
        tm = localtime(&stamp);
        fprintf(fp, "%-4d%d-%d-%d %d:%d:%d\n", ++count, tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
        fflush(fp);
        sleep(1);
    }

    fclose(fp);
    return 0;
}