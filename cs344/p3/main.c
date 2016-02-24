#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{	
	printf("\n");
	printf("Welcome to smallsh, the smaller shell.\n");
	printf("\n");

	pid_t childPid;

	while (1)
	{
		printf(": ");
		fflush(stdout);
	
		/* changes directory to "demo" */
		chdir("./demo");

		char* argv[1];
		scanf("%s",*argv);
		
		if (strcmp(*argv,"exit") == 0)
			exit(0);
		

		printf(": ");
		fflush(stdout);
	
	
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
