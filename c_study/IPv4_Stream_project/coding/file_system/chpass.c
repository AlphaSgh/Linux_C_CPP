#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <shadow.h>
#include <crypt.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "usage...\n");
        exit(1);
    }
    // getpass 隐藏终端输入
    char *input_passwd;
    char *crypt_passwd;
    struct spwd *shadowline;
    input_passwd = getpass("PASSWD:");

    shadowline = getspnam(argv[1]);
    crypt_passwd = crypt(input_passwd, shadowline->sp_pwdp);
    if (strcmp(shadowline->sp_pwdp, crypt_passwd) == 0)
    {
        printf("success\n");
    }
    else
    {
        printf("error");
    }

    return 0;
}
