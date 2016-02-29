#include <fcntl.h>
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

int isRedirect(char* arg)
{
	if (strcmp(arg,"|") == 0)
		return 1;
	else if (strcmp(arg,"<") == 0)
		return 2;
	else if (strcmp(arg,">") == 0)
		return 3;
	else return 0;
}

int fdchg(char** argv, size_t max_size)
{
	int argNum,redType;
	printf("start fdchg\n");
	for (argNum = 0; argNum < max_size; ++argNum)
	{
		redType = isRedirect(argv[argNum]);
		printf("Look@%s\n",argv[argNum]);
		if (redType == 0)
			printf("not a redirection character:%s\n",argv[argNum]);
		else printf("%s is a redirection character\n",argv[argNum]);
	}
	return 0;
}

int main()
{	
	printf("\n");
	printf("Welcome to smallsh, the smaller shell.\n");
	printf("\n");
	
	pid_t childPid;
	size_t max_size = 512;
	char** argv = malloc(sizeof(char*)*max_size);

	int status;

	while(1)
	{
			
		fflush(stdout);
		printf(": ");
	
		argv = getcmd(argv);


		//replace this with a function? we'll see

		//builtin: exit
		//exits program by breaking loop
		if (strcmp(*argv,"exit") == 0)
				break;
		//builtin: cd
		//changes directories
		else if (strcmp(*argv,"cd") == 0)
		{
			switch(childPid = fork())
			{
				case -1:
					perror("smallsh: fork failed\n");
					exit(1);
					break;
				case 0:
					if (-1 == chdir(argv[1]))
					{
						exit(2);
					}
					break;
				default:
					waitpid(childPid,&status,0);
					if (WIFEXITED(status))
					{
						printf("smallsh: cd failed with status %d\n"
								,WEXITSTATUS(status));
					}
			}


		}
		//builtin: status
		//will require support of background processes first
		else if (strcmp(*argv,"status") == 0)
		{
			printf("smallsh:status is go\n");
		}
		else
		switch(childPid = fork())
		{
			case -1:
				perror("smallsh: fork failed\n");
				exit(1);
				break;
			case 0:
				if (-1 == execvp(*argv,argv))
				{
					perror("smallsh");
					exit(2);
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
