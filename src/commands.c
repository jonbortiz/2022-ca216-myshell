#include <string.h>
#include "internal.c"
#include "external.c"
#include "internal.h"
#include "commands.h"
// #include "ioredirection.c"
char cwd[100];

int findCMD(char ** args)
{
    if(!strcmp(args[0],"clear")) {
        clr();
        return 1;
    }
    else if (!strcmp(args[0],"dir")) {
        dir();
        return 1;
    }
    else if (!strcmp(args[0],"quit")) {
        return 0;
    }
    else if (!strcmp(args[0],"cd")) {
        cd(args);
        return 1;
    }
    else if (!strcmp(args[0],"echo")) {
        echo(args);
        return 1;
    }
    else if(!strcmp(args[0],"environ")) {
        environment(args);
        return 1;
    }
    else if(!strcmp(args[0],"pause")) {
        pauseCMD();
        return 1;
    }
    else if(!strcmp(args[0], "setShell")) {
        getcwd(cwd, sizeof(cwd));
        setenv("SHELL", strcat(cwd, "/myshell"), 1);
        return 1;
    }
    else if(!strcmp(args[0], "help")) {
        help();
        return 1;
    }
    else {
        // int inputSign = 0, outputSign = 0, redirectionFlag = 0;
        // for (int i = 0; args[i]; i++) {
        //     if (!strcmp(args[i], "<") || !strcmp(args[i], "<<")) {
        //         redirectionFlag = 1;
        //         inputSign = i;
        //     }
        //     else if (!strcmp(args[i], ">") || !strcmp(args[i], ">>")) {
        //         redirectionFlag = 1;
        //         outputSign = i;
        //     }
        // }
        // if (redirectionFlag = 1) {
        //     if (redirection(args, inputSign, outputSign)==0) {
        //         return 0;
        //     } else {
        //         return 1;
        //     }
        // }
        if (external(args)==0) {
            return 0;
        } else {
            return 1;
        }
    }
}