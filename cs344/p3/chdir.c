#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t childPid;
	pid_t grandChild;
	size_t max_size = 512;
	int status;
	char** command = malloc(sizeof(char*)*max_size);
	command[0] = "cd";
	command[1] = "demo";
	switch(childPid = fork())
	{
		case -1:
			perror("smallsh");
			exit(1);
			break;
		case 0:
			printf("child here. changing directory\n");
			kill(getppid(),SIGTERM);
			execvp(*command,command);
			break;
		default:
			printf("parent here.\n");
			waitpid(childPid,&status,0);
			break;
	}
	return 0;
}
