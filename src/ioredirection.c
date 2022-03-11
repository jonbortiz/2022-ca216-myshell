#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "myshell.h"
#include "myshell.c"


// I/O REDIRECTION ATTEMPT
// NOT USED

int redirection(char **args, int inputSign, int outputSign)
{
    char *progName = args[0];
    char *inputFile = args[inputSign + 1];
    char *outputFile = args[outputSign + 1];
    pid_t pid;
    
    for (int i = inputSign; args[i]; i++) {
        args[i] = NULL;
    }
    for (int i = 1; args[i]; i++) {
        printf("%s\n", args[i]);
    }
    printf("%s\n", progName);
    printf("%s\n", inputFile);
    printf("%s\n", outputFile);

    pid = getpid();
    printf("before fork (redirect.): %d\n", pid);
    pid = fork();
    if (pid == -1)
    {
        printf("System failed to fork during I/O Redirection\n");
        return 0;
    }
    else if (pid == 0)
    {
        pid = getpid();
        printf("In Child (redirect.): %d\n", pid);
        freopen(inputFile, "r", stdin);
        freopen(outputFile, "w", stdout);
    }
    wait(NULL);

    pid = getpid();
    printf("After fork, back in main (redirect.) %d\n", pid);
    return 1;
}