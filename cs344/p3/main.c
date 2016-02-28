#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char** tokcmd(char** cmdline,size_t max_size)
{
	int argNum;
	int argc = 0;
	char** argTok = malloc(sizeof(char*)*max_size);
	argTok[argc] = strtok(*cmdline," \n"); //name of command
	while (argTok[argc] != NULL)
	{
		argc++;
		argTok[argc] = strtok(NULL," \n"); //arguments
	}

	//testing area
	/*printf("argc=%d\n",argc);
	int i;
	for (i = 0; i < argc; i++)
	{
		printf("argTok[%d]=%s\n",i,argTok[i]);
	}*/


	free(argTok);
	return argTok;
}

char** getcmd(char** argv)
{
	size_t max_size = 512;
	getline(argv,&max_size,stdin);
	argv = tokcmd(argv,max_size);
	int i;
	/*for (i = 0; i < max_size; i++)
	{
		if (argv[i])
			printf("argv[%d]=%s\n",i,argv[i]);
		else break;
	}
	fflush(stdout);*/
	return argv;
}

int main()
{	
	printf("\n");
	printf("Welcome to smallsh, the smaller shell.\n");
	printf("\n");
	
	pid_t childPid;

	char** argv = malloc(sizeof(char*)*512);

	int status;

	while(1)
	{
			
		fflush(stdout);
		printf(": ");
	
		argv = getcmd(argv);

		if (strcmp(*argv,"exit") == 0)
				break;

		switch(childPid = fork())
		{
			case -1:
				perror("Error in forking to child after input.\n");
				exit(-1);
				break;
			case 0:
				if (-1 == execvp(*argv,argv))
				{
					perror("Command failed.\nsmallsh:");
					exit(-1);
				}
				fflush(stdout);
				break;
			default:
				waitpid(childPid,&status,0);
				break;
		}
	}
	free(*argv);
	return 0;
}
