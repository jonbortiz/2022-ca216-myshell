#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "myshell.c"
#include "myshell.h"


extern int errno;
void syserr(char* );

int background_exec(char **argv, char ** args, char *buff, char ** arg)
{
    pid_t pid;

    pid = getpid();
    printf("1Process ID before fork: %d\n", pid);
    pid = fork();

    if (pid == -1)
    {
        printf("System failed to fork\n");
        syserr("fork");
        return 0; 
    }
    else if (pid == 0)
    {
        pid = getpid();
        printf("2Process ID in child after fork: %d\n", pid);
        batch(argv, args, buff, arg);
        return 1;
        syserr("exec");
    }
}

void syserr(char * msg)
{
    fprintf(stderr, "%s: %s", strerror(errno), msg);
}