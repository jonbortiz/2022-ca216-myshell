#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signum)
{
	printf("signal interuppted, signal number: %d.\n", signum);
}

int main(int argc, char*argv[])
{
	int n = atoi(argv[1]);
	signal(SIGINT, signal_handler);
	for(int i = 0; i < n; i++)
	{
		pid_t getpid(void);
		printf("%d\n", getpid());
		sleep(5);
	}
	return 0;
}
