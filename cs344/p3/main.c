#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
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
	printf("argc=%d\n",argc);
	//testing area
	int i;
	for (i = 0; i < argc; i++)
	{
		printf("argTok[%d]=%s\n",i,argTok[i]);
	}
	return argTok;
}

char** getcmd(char** argv)
{
	size_t max_size = 512;
	char** cmdline = malloc(sizeof(char*)*max_size);
	getline(argv,&max_size,stdin);
	argv =  tokcmd(argv,max_size);
	int i;
	for (i = 0; i < max_size; i++)
	{
		if (argv[i])
			printf("argv[%d]=%s\n",i,argv[i]);
		else break;
	}
	return argv;
}

int main()
{	
	printf("\n");
	printf("Welcome to smallsh, the smaller shell.\n");
	printf("\n");
	printf(": ");
	pid_t childPid;

	char** argv = malloc(sizeof(char*)*512);

	argv = getcmd(argv);

	switch(childPid = fork())
	{
		case -1:
			perror("Error in forking to child after input.\n");
			exit(-1);
			break;
		case 0:
			if (-1 == execvp(*argv,argv))
			{
				perror("Error in execvp.\n");
				exit(-1);
			} //re-enable when input parsing works
			break;
		default:
			waitpid(childPid);
			break;
	}
	return 0;
}
