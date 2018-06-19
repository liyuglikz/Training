#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void slot_func(int sig)
{
	printf("\ngot signal:%d\n", sig);
	printf("Exit\n");
	exit(0);
}

int main(int argc, char *argv[])
{
	signal( SIGINT, slot_func);// "ctrl + c"
	while(1)
	{
		sleep(1);
	}
	return 0;
}
