#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int r, pipeFDs[2];
	char message[512];
	pid_t spawnpid;
	
	pipe(pipeFDs);
	spawnpid = fork();
	
	switch (spawnpid)
	{
	 case 0:
	 close(pipeFDs[0]); // close the input file descriptor
	 write(pipeFDs[1], "hi process, this is the STUFF!!", 21);
	 break;
	
	 default:
	 close(pipeFDs[1]); // close output file descriptor
	 r = read(pipeFDs[0], message, sizeof(message));
	 printf("Message received from other: %s\n", message);
	 break;
	}
}
