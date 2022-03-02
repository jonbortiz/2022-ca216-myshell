#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "myshell.h"
#include <dirent.h>

extern char **environ;

void tokeniseInput(char ** args, char ** arg, char buff[])
{
    arg = args;
    *arg++ = strtok(buff, SEPARATORS);
    while ((*arg++ = strtok(NULL, SEPARATORS)));
}

int command(char ** args)
{
    if (!strcmp(args[0],"clear")) { // "clear" command
        system("clear");
        return(1);
    } 
    else if (!strcmp(args[0],"quit")) {   // "quit" command
        return(0);                     // break out of 'while' loop
    }
    else if (!strcmp(args[0],"cd")) {
        char cwd[100];
        getcwd(cwd, sizeof(cwd));
        if(chdir(args[1]) != 0) {
            printf("%s\n", cwd);
            perror("Error: ");
        }
        else{
            getcwd(cwd, sizeof(cwd));
            setenv("PWD", cwd, 1);
        }
        return(1);
    }
}

int main(int argc, char ** argv)
{
    char buff[MAX_BUFFER];
    char * args[MAX_ARGS];
    char ** arg;
    char * prompt = "==>";

    while(!feof(stdin)) {

    fputs (prompt, stdout);

        if (fgets(buff, MAX_BUFFER, stdin))
        {
            tokeniseInput(args, arg, buff);

            if (args[0]) {                     // if there's anything there
                /* check for internal/external command */
                if(command(args) == 0){
                    break;
                }
                else{
                    continue;
                }
                /* else pass command onto OS (or in this instance, print them out) */
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