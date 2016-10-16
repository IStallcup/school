#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void catchchild(int signo)
{
	fflush(stdout);
	printf("FOUND YOU FUCKER!!\n");
	
}

void catchint(int signo)
{
	printf("interrupt signal found\n");
}

int main()
{
	int status;

	struct sigaction see_child;
	see_child.sa_handler = catchchild;
	see_child.sa_flags = 0;	
	sigfillset(&(see_child.sa_mask));
	sigaction(SIGCHLD, &see_child, NULL);
	
	struct sigaction interrupt;
	interrupt.sa_handler = catchint;;
	interrupt.sa_flags = 0;
	sigfillset(&(interrupt.sa_mask));
	sigaction(SIGINT, &interrupt, NULL);
	pid_t myPid = getpid();
	pid_t childPid;
	char** command = malloc(sizeof(char*)*2);
	*command = "ls";
	switch(childPid = fork())
	{
		case 0:
			kill(myPid,SIGINT);		
			printf("child\n");
			execvp(*command,command);		
			break;
		default:
			waitpid(childPid,&status,0);
			if (WIFSTOPPED(status))
				printf("stopped\n");
			else if (WIFSIGNALED(status))
				printf("signalled\n");
			else if (WIFEXITED(status))
				printf("exited\n");
			printf("after wait\n");
			break;
	}

	return 0;
}
