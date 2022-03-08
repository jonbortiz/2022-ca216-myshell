#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

extern int errno;        // system error number 
void syserr(char* );     // error report and abort routine 

int main(int argc, char *argv[])
{
   pid_t pid;            // process ID
   int rc;               // return code

   pid = getpid();       // get our own pid
   printf("Process ID before fork: %d\n", (int)pid);

   switch (fork()) {
      case -1:
         syserr("fork");
      case 0:             // execution in child process 
         pid = getpid();  // get child pid
         printf("Process ID in child after fork: %d\n", pid);
         execlp("./sleepy", "sleepy", "10",NULL);
         syserr("execl"); // error if return from exec
   }

// continued execution in parent process

   pid = getpid();        // reget our pid
   printf("Process ID in parent after fork: %d\n", pid);

   exit(0);
}

void syserr(char * msg)   // report error code and abort
{
   fprintf(stderr,"%s: %s", strerror(errno), msg);
   abort();
}

int backgr_exe(char **args)
{
    // a char array of the possible internal commands a user can give
    char *internal_cmds[] = {
        "quit",
        "clr",
        "mkdir",
        "help",
        "dir",
        "echo",
        "environ",
        "cd"
    };
    

    // array of command's functions
    int (*commands[]) (char **) = {
        &quit,
        &clear,
        &makedir,
        &help,
        &dir,
        &echo,
        &enviro,
        &cd,
    };

    int foundInt=0;

    if(args[0] == NULL) // check if user has given a command
    {
        // user entered no command i.e. an empty command input
        return 1;
    }
    else
    {

        pid_t pid = fork(); // creates a child process

        for(int i=0; i<(sizeof(internal_cmds) / sizeof(char *)); i++) // loops through array of internal commands
        {
            if(!strcmp(args[0], internal_cmds[i])) // finds the command that matches the user's input
            {
                if(pid == -1)
                {
                    printf("Error: fork failed.");
                }
                else if(pid == 0)
                {
                    return (*commands[i])(args); // executes the given command
                }
            }
        }

    }
}