NOTE: MAKEFILE NOT WORKING, CAN BE COMPILED AND RUN BY:
    gcc myshell.c -o myshell
    ./myshell <arguments>

NAME

    myshell

DESCRIPTION

    A simple command line shell written in the C programming language. This was given as continous assessment assignment for CA216.
    This shell can perform basic internal built-in commands listed below. These are the other functionalities of this C Shell:

        1. External Command Functionality
        2. Background execution
        3. Batchfile execution

BUILT-IN COMMANDS

    cd <directory> - change the current directory to the directory in the given argument. If the argument <directory>, is not present, reports the current working directory.
                     Also chanages the PWD environment variable to the new CWD.

    clr - clears the screen 

    dir - lists the contents of the current directory

    environ - lists all environment strings

    echo <string> - displays line of text that is passed as the argument <string>

    pause - pause operation of the shell until 'Enter' is pressed

    quit - quits the shell

ENVIRONMNET

    When the shell is initialised, variables from the environment it is executed in is set too. These variables depend on your personal configuration. These variables can be used to control the behaviour of shell scripts/other programs. You can also use these variables to change the user's environment. An example of this in the C Shell is in the use of the "cd" internal command. After the directory is changed, the PWD (Print Work Directory) Environment variable must be updated too. The C shell does this buy fetching the new CWD (Current Work Directory) and replacing it with the old PWD variable.

I/O REDIRECTION

    I/O (Input/Ouput) Redirection is the changing of streams for the input and output values given, or taken by the C Shell. Redirection allows the program to:

        Program input from stdin can be taken from external files, instead of user input (keyboard).

        Output for stdin can be sent to an external file/printer, instead of being sent to screen.
    
    When redirecting output to a file, if the file already exists, it is deleted and replaced with a new file. Alternativley, if the ouput is redirected using the ">>" symbol, and the given file exists. The program ouput is appeneded at the end of the file instead of being replaced.

PROCESSES

    When a programme is launched, it becomes a process. They are a special instance provided by the operating system that includes all the resources that are used by the running application. An example would be a running instance of the C Shell.

    A process can be split into two processes. This is called forking. The original process is called the parent, and the new forked process is the child.

BACKGROUND & FOREGROUND EXECUTION

