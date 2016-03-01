#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void catch_arnold(int signo) //as in Schwarzenegger
{
	printf("found signterm\n");
}

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
			argv[argNum] = NULL;
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
			path = argv[argNum+1];
			/*printf("path=%s\n",path);
			printf("< detected\n");
			printf("stdin is now from file %s\n",argv[argNum-1]);*/
			fd_new = open(path,O_RDONLY);
			if(fd_new == -1)
			{
				fprintf(stderr, "smallsh: cannot open file for input\n");
				close(fd_new);
				return 1;
			}
			if (dup2(fd_new,fd_old) == -1)
			{
				fprintf(stderr,"Error in dup2\n");
				close(fd_new);
				return 1;
			}
			close(fd_new);
			argv[argNum] = NULL;
			argv[argNum+1] = NULL;

		}
		else if (fd_old == 1) //writing
		{
			path = argv[argNum+1];
			printf("path=%s\n",path);
			/*printf("> detected\n");
			printf("stdout is now to file %s\n",argv[argNum+1]);*/
			fd_new = open(path,O_WRONLY|O_CREAT|O_TRUNC,0777);
			if(fd_new == -1)
			{
				fprintf(stderr, "stdout redirect: error in file open\n");
				close(fd_new);
				return 1;
			}
			if (dup2(fd_new,fd_old) == -1)
			{
				fprintf(stderr,"Error in dup2\n");
				close(fd_new);
				return 1;
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
	
	int wpid;
	pid_t childPid;
	size_t max_size = 512;
	char** argv = malloc(sizeof(char*)*max_size);

	int status;
	struct sigaction termination;
	termination.sa_handler = catch_arnold;
	termination.sa_flags = 0;
	sigfillset(&(termination.sa_mask));
	sigaction(SIGTERM, &termination, NULL);
	int background;

	int *exitstatus;
	char* homedirec;
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
			homedirec = getenv("HOME");
			if(-1 == chdir(argv[1]))
				chdir(homedirec);	
		}


		   /*	if (strcmp(*argv,"cd") == 0)
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


		}*/
		//builtin: status
		//will require support of background processes first
		else if (strcmp(*argv,"status") == 0)
		{
			if(WIFEXITED(status))
				printf("exited with status %d\n",exitstatus);
			else printf("termsig = \n",WTERMSIG(status));
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
				if (1 == chgfd(argv,max_size))
					break;
				if (-1 == execvp(*argv,argv))
				{
					perror(*argv);
					exit(1);
				}
				break;
			default:
				//printf("parent\n");
				if (background != 0)
				{
					printf("bPid=%d\n",childPid);
					break;
				}
				else
				{
					//printf("not background process\n");
					do{
						waitpid(childPid,&status,WUNTRACED);
			//WUNTRACED gives status of stopped children 
					}
					while(!WIFEXITED(status) 
					   && !WIFSIGNALED(status));
				//may or may not be important?
					exitstatus = WEXITSTATUS(status);
				}
					//tracing
					if (WIFSIGNALED(status))
						printf("signalled\n");
					if (WTERMSIG(status))
						printf("terminated\n");
				break;
		}
		
		wpid = waitpid(-1,&status,WNOHANG);
		while(wpid > 0)
		{
			printf("backgroud process complete, pid=%d\n",wpid);
			if(WIFEXITED(status)) //exit status OK
				printf("exit status: %d\n",WIFEXITED(status));
			else //other signals are assumed to be terminating
				printf("terminating signal: %d\n",WTERMSIG(status));

			wpid = waitpid(-1,&status,WNOHANG);
		
		}
	}
	return 0;
}
