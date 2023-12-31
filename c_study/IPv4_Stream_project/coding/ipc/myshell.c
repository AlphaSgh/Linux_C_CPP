#include <glob.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DELIMS " \t\n"

typedef struct cmd_st
{
    glob_t globres;
} cmd_st;

static void prompt(void) { printf("mysh-o.1$ "); }
static void parse(char *line, cmd_st *cmd)
{
    char *tok;
    int i = 0;
    while (1)
    {
        tok = strsep(&line, DELIMS);
        if (tok == NULL)
        {
            break;
        }
        if (tok[0] == '\0')
        {
            continue;
        }
        glob(tok, GLOB_NOCHECK | GLOB_APPEND * i, NULL, &cmd->globres);
        i = 1;
    }
}
int main(int argc, char const *argv[])
{
    char *linebuf = NULL;
    size_t linebuf_zize = 0;
    cmd_st cmd;
    pid_t pid;
    while (1)
    {
        prompt();
        if (getline(&linebuf, &linebuf_zize, stdin) < 0)
        {
            break;
        }
        parse(linebuf, &cmd);
        if (0)
        { // 内部命令
          // todo:
        }
        else
        {
            pid = fork();
            if (pid < 0)
            {
                perror("fork()");
                exit(1);
            }
            if (pid == 0)
            {
                execvp(cmd.globres.gl_pathv[0], cmd.globres.gl_pathv);
                perror("execvp()");
                exit(1);
            }
            else
            {
                wait(NULL);
            }
        }
    }

    return 0;
}
