#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{	
	printf("\n");
	printf("Welcome to smallsh, the smaller shell.\n");
	printf("\n");

	while (1)
	{
	
	printf(": ");
	fflush(stdout);

	char* argv[1];
	scanf("%s",*argv);

	printf(": ");
	fflush(stdout);

	pid_t childPid;

	switch(childPid = fork())
	{
		case -1:
			perror("Error in forking to child after input.\n");
			exit(-1);
			break;
		case 0:
			if (-1 == execvp(*argv,argv))
				printf("error\n");
			break;
		default:
			waitpid(childPid);
			break;
	}
	}
	return 0;
}
