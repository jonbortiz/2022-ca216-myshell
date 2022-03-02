#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

extern int errno;
void syserr(char* );

int external(char ** args)
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
        execvp(args[0], args);
        syserr("exec");
    }
    wait(NULL);

    pid = getpid();
    printf("3Process ID in parent after fork: %d\n", pid);
    return 1;
}

void syserr(char * msg)
{
    fprintf(stderr, "%s: %s", strerror(errno), msg);
}