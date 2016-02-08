#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int main()
{
	char [6] pid = getpid();
	int ppid = getppid();
	printf("pid=%s ppid=%d\n",pid,ppid);
	char [21] PATH;
		

	return 0;
}
