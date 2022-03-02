#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myshell.h"
#include "commands.c"
#include "batchexec.c"

void tokeniseInput(char ** args, char ** arg, char buff[])
{
    arg = args;
    *arg++ = strtok(buff, SEPARATORS);
    while ((*arg++ = strtok(NULL, SEPARATORS)));
}

int main(int argc, char **argv)
{
    char buff[MAX_BUFFER];
    char * args[MAX_ARGS];
    char ** arg;
    char * prompt = "==>";
    char cwd[100];
    int batchFlag = 0;

    setShell();

    if(!strcmp(argv[1],"batchfile")) {
        
    }

    while(!feof(stdin))
    {
        getcwd(cwd, sizeof(cwd));
        fputs(cwd, stdout);
        fputs(prompt, stdout);

        if(fgets(buff, MAX_BUFFER, stdin)) {
            tokeniseInput(args, arg, buff);

            if(args[0]) {
                if(findCMD(args)==0) {
                    break;
                }
                else {
                    continue;
                }

                arg = args;
                while (*arg) {
                    fprintf(stdout,"%s ",*arg++);
                    fputs ("\n", stdout);

                }
            }
        }
    }
    return 0;
}
