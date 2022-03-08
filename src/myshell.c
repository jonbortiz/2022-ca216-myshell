#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myshell.h"
#include "commands.c"
// #include "backgroundExecution.c"

void batch(char **argv, char ** args, char *buff, char ** arg)
{
    FILE *fptr;
    fptr = fopen(argv[1], "r");
    fgets(buff, MAX_BUFFER, fptr);
    while(!feof(fptr)) {
            if(fgets(buff, MAX_BUFFER, fptr)) {
                tokeniseInput(args, arg, buff);
                if(args[0]) {
                    if(findCMD(args)==0) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
            }
        fclose(fptr);
        }
}

void tokeniseInput(char ** args, char ** arg, char *buff)
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

    setShell();

    if(argc == 2) {
        batch(argv, args, buff, arg);
    }
    else {
        while(!feof(stdin))
        {
            getcwd(cwd, sizeof(cwd));
            fputs(cwd, stdout);
            fputs(prompt, stdout);

            if(fgets(buff, MAX_BUFFER, stdin)) {
                tokeniseInput(args, arg, buff);
                for(int i = 0; args[i]; i++) {
                    if(!strcmp(args[i], "&")) {
                        background_exec(argv, args, buff, arg);
                    }
                }
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
    }
    return 0;
}
