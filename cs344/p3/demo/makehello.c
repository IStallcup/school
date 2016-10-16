#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	char* argv[1];
	argv[0] = "./hello";	
	pid_t childPid;
	if ((childPid = fork()) == 0)
	{
		printf("this is child\n");
		fflush(stdout);
		exit(execvp(*argv,argv)); /* does this work? */
		if (-1 == execvp(*argv,argv))
			printf("exec failed\n");
		exit(-1);
	}
	else
	{
		printf("this is parent\n");
	}
	fflush(stdout);
	return 0;
}
