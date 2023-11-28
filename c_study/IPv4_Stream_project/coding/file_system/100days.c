#include <stdio.h>
#include <stdio.h>
#include <time.h>
#define TIMESTRSIZE 1024
int main(int argc, char const *argv[])
{
    time_t stamp;
    struct tm *tm;
    char timestr[TIMESTRSIZE];
    stamp = time(NULL);
    tm = localtime(&stamp);
    strftime(timestr, TIMESTRSIZE, "Now:%Y-%m-%d", tm);
    puts(timestr);
    tm->tm_mday += 100;
    mktime(tm);
    strftime(timestr, TIMESTRSIZE, "100days:%Y-%m-%d", tm);
    puts(timestr);
    return 0;
}
