#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	char *argv[64];
	printf("parent pid=%d\n",getpid());
	pid_t childPid;
	if ((childPid = fork()) < 0)
	{
		printf("fatal error in fork.\n");
		exit(-1);
	}
	waitpid(childPid);
	if (childPid == 0)
	{
		printf("pid=%d\n",getpid());
		printf("try execvp\n");
		char* argv[2];
		argv[0] = "./hello";
		argv[1] = "1";
		if (-1 == execvp(*argv,argv))
			printf("execvp fucked up\n");
	}
	else
	{
		printf("childPid=%d\n",childPid);
	}
	printf("process %d dying :(\n",getpid());
	return 0;
}
