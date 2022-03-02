#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "myshell.h"

extern char **environ;
char cwd[100];

void setShell() {
    getcwd(cwd, sizeof(cwd));
    setenv("SHELL", strcat(cwd, "/myshell"), 1);
}

void clr() {
    system("clear");
}

void pauseCMD() {
    printf("Shell is paused. Press Enter to continue...\n");
    while(getchar() != '\n') {
        getchar();
    }
}

void dir() {
    system("ls -al");
}

void environment() {
    for(int i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
}

void echo(char *argv[]) {
    for (int i = 1; argv[i]; i++)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");
}

void cd(char *argv[]) {
    getcwd(cwd, sizeof(cwd));
    if(chdir(argv[1]) != 0) {
        printf("%s\n", cwd);
        perror("Error: ");
    }
    else {
        getcwd(cwd, sizeof(cwd));
        setenv("PWD", cwd, 1);
    }
}
