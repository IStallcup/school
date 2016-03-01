#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char** tokcmd(char** cmdline,size_t max_size)
{
	int argc = 0;
	char** argTok = malloc(sizeof(char*)*max_size);
	argTok[argc] = strtok(*cmdline," \n"); //name of command
	while (argTok[argc] != NULL)
	{
		argc++;
		argTok[argc] = strtok(NULL," \n"); //arguments
	}

	free(argTok);
	return argTok;
}

char** getcmd(char** argv, size_t max_size)
{
	fflush(stdin);
	getline(argv,&max_size,stdin);
	argv = tokcmd(argv,max_size);
	return argv;
}

int isbkgrnd(char** argv, char* amp, size_t max_size)
{
	int argNum;
	for(argNum = 0; argNum < max_size; argNum++)
	{
		if (argv[argNum] == NULL)
			break;
		if (strcmp(argv[argNum],amp) == 0)
		{
			//printf("%s = &\n",argv[argNum]);
			return 1;
		}
	}
	return 0;	
}

int redirectType(char* arg)
{
	
	if (strcmp(arg,"<") == 0) //READING
		return 0;
	else if (strcmp(arg,">") == 0) //WRITING
		return 1;
	else return -1; //no redirection
}

int chgfd(char** argv, size_t max_size)
{
	int argNum, fd_old, fd_new;
	char* arg;
	char* path;
	for (argNum = 0; argNum < max_size; ++argNum)
	{
		arg = argv[argNum];
		if(!arg)
			break;
		fd_old = redirectType(arg);
		//printf("rType = %d\n",fd_old);
		if(fd_old == 0)
		{
			path = argv[argNum-1];
			printf("path=%s\n",path);
			printf("< detected\n");
			printf("stdin is now from file %s\n",argv[argNum-1]);
			fd_new = open(path,O_RDONLY);
			if(fd_new == -1)
			{
				fprintf(stderr, "Error in file open\n");
				close(fd_new);
				exit(1);
			}
			else if (dup2(fd_new,fd_old) == -1)
			{
				fprintf(stderr,"Error in dup2\n");
				close(fd_new);
				exit(1);
			}
			close(fd_new);
			argv[argNum] = NULL;
			argv[argNum-1] = NULL;

		}
		else if (fd_old == 1)
		{
			path = argv[argNum+1];
			printf("path=%s\n",path);
			printf("> detected\n");
			printf("stdout is now to file %s\n",argv[argNum+1]);
			fd_new = open(path,O_WRONLY);
			if(fd_new == -1)
			{
				fprintf(stderr, "Error in file open\n");
				close(fd_new);
				exit(1);
			}
			else if (dup2(fd_new,fd_old) == -1)
			{
				fprintf(stderr,"Error in dup2\n");
				close(fd_new);
				exit(1);
			}
			close(fd_new);
			argv[argNum] = NULL;
			argv[argNum+1] = NULL;
		}
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
	int background;

	while(1)
	{
		background = 0;	

		fflush(stdout);
		printf(": ");
	
		argv = getcmd(argv, max_size);
		//find & at end of user's input
		background = isbkgrnd(argv,"&", max_size);
		

		//builtin: exit
		//exits program by breaking loop
		//needs work, as does not work with implementation of cd
		if (strcmp(*argv,"exit") == 0)
			break;
		//builtin: cd
		//changes directories
		//needs to appropriately kill child/parent processes
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
				fprintf(stderr,"smallsh: fork failed\n");
				exit(1);
				break;
			case 0:
				//need to edit args for background, redirections
				chgfd(argv,max_size);	
				if (-1 == execvp(*argv,argv))
				{
					perror(*argv);
					exit(2);
				}
				break;
			default:
				printf("parent\n");
				waitpid(childPid,&status,0);
				break;
		}
	}
	return 0;
}
