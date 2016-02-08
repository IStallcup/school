#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/* remember you cannot determine if a process will complete when you create it (except logically) */

int main()
{
	int exitMethod;

	pid_t spawnpid = -5;


	int ten = 10;

	spawnpid = fork(); /*not created in any order!! which switch will execute first? nobody knows. */

	/* wait(); */

	/* wait() waits until ANY ONE child process completes; returns PID of child */
	/* ceases execution of current process instantly until wait's conditions are met */

	/* waitpid(spawnid); */

	/* waitpid() waits for SPECIFIC PID'd process to end */
	/* ceases execution similarly to wait() */

	pid_t currentpid = getpid();
	printf("pid=%ld\n",currentpid); /* remember pids of children are not always numerically greater */
	switch(spawnpid)
	{
		case -1:
			perror("oh shit"); /*what does perror do?*/
		   	/*interprets variable errorno (specific to each process) as an error message, outputs to stderr */
			exit(1); /*returns 1 to stderror? */
			break;
		case 0:
			ten += 1;
			printf("child; ten = %d\n",ten);
			break;
		default:
			ten -= 1;
			printf("parent; ten = %d\n",ten);
			break;
	}
	printf("exec by both\n");
	return 0;
}
