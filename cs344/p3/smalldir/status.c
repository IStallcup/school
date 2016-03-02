#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void print_status(int status)
{
	if(WIFEXITED(status))
		printf("exited with status %d\n",WEXITSTATUS(status));
	else printf("termsig = %d\n",WTERMSIG(status));
}

int main()
{	
	char** cmd = malloc(sizeof(char*));
	cmd[0] = "ls";

	int status;
	int iter = 0;
	pid_t cpid;

	while(iter < 2)
	{
		if (strcmp(cmd[0],"status") == 0)
			print_status(status);
	
		switch(cpid = fork())
		{
			case 0:
				printf("child\n");
				execvp(*cmd,cmd);
				break;
			default:
				printf("parent\n");
				cmd[0] = "status";
				waitpid(cpid,&status,0);
				printf("parent done waiting\n");
				break;
		}
		iter++;
	}
}
