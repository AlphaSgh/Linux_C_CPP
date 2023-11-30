#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#define FMTSTRSIZE 1024
#define TIMESTRSIZE 1024
/**
 * -y: year
 * -m: month
 * -d: day
 * -H: hour
 * -M: minute
 * -S: second
 */
int main(int argc, char **argv)
{
    FILE *fp = stdout;
    time_t stamp;
    struct tm *tm;
    char timestr[TIMESTRSIZE];
    char fmtstr[FMTSTRSIZE];
    int c;

    fmtstr[0] = '\0';

    stamp = time(NULL);
    tm = localtime(&stamp);

    while (1)
    {
        c = getopt(argc, argv, "-H:MSy:md"); // 如果选项后面加了：则可以通过optarg获取参数; 前面加 ‘-’表示存在非选项传参
        if (c < 0)
        {
            break;
        }
        switch (c)
        {
        case 1:
            fp = fopen(argv[optind - 1], "a+");
            if (fp == NULL)
            {
                perror("fopen()");
                fp = stdout;
            }
            break;
        case 'H':
            if (strcmp(optarg, "12") == 0)
            {
                strncat(fmtstr, "%I(%P) ", FMTSTRSIZE);
            }
            else if (strcmp(optarg, "24") == 0)
            {
                strncat(fmtstr, "%H ", FMTSTRSIZE);
            }
            else
            {
                fprintf(stderr, "invalid argument -H!\n");
            }
            break;
        case 'M':
            strncat(fmtstr, "%M ", FMTSTRSIZE);
            break;
        case 'S':
            strncat(fmtstr, "%S ", FMTSTRSIZE);
            break;
        case 'y':
            if (strcmp(optarg, "2") == 0)
            {
                strncat(fmtstr, "%y ", FMTSTRSIZE);
            }
            else if (strcmp(optarg, "4") == 0)
            {
                strncat(fmtstr, "%Y ", FMTSTRSIZE);
            }
            else
            {
                fprintf(stderr, "invalid argument -y!\n");
            }
            break;
        case 'm':
            strncat(fmtstr, "%m ", FMTSTRSIZE);
            break;
        case 'd':
            strncat(fmtstr, "%d ", FMTSTRSIZE);
            break;
        default:
            break;
        }
    }
    // puts(fmtstr);
    strncat(fmtstr, "\n", FMTSTRSIZE);
    strftime(timestr, TIMESTRSIZE, fmtstr, tm);
    fputs(timestr, fp);
    if (fp != stdout)
    {
        fclose(fp);
    }
    return 0;
}
