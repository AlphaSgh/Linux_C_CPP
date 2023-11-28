#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "usage...\n");
        exit(1);
    }
    struct passwd *pwdline;
    pwdline = getpwuid(atoi(argv[1]));
    puts(pwdline->pw_name);
    return 0;
}
