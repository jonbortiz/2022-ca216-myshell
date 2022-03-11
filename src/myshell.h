#define MAX_BUFFER 1024 // max line buffers
#define MAX_ARGS 64 // max number of args
#define SEPARATORS " \t\n" // tokens will be separated by white spaces

void tokeniseInput(char ** args, char ** arg, char *buff);
void batch(char **argv, char ** args, char *buff, char ** arg);

