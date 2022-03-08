#include <string.h>
#include "internal.c"
#include "external.c"
#include "ioredirection.c"

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
        setShell();
        return 1;
    }
    else {
        for (int i = 0; args[i]; i++) {
            if (!strcmp(args[i], ">") || !strcmp(args[i], "<")) {
                redirection(args);
                return 1;
            }
        }
        if (external(args)==0) {
            return 0;
        } else {
            return 1;
        }
    }
}