#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("external program + %d\n", atoi(argv[1]));
    return 0;
}
