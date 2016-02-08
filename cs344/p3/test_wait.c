#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/* remember you cannot determine if a process will complete when you create it (except logically) */

int main()
{
	int exitMethod;

	pid_t spawnpid = -5;

	spawnpid = fork(); /*not created in any order!! which switch will execute first? nobody knows. */

	if (spawnpid == 0)
	{
		printf("child sleeping\n");
		wait(5);
	}

	/* rest of prog on slides; demo of wait/waitpid */	

	return 0;
}
