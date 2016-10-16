#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t spawnpid = fork();
	switch (spawnpid)
	{
		case -1: exit(1); break;
		case 0:printf("child: "); exit(0); break;
		default:printf("parent: "); break;
	}
	printf("XYZZY\n");
}
