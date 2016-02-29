#include <fcntl.h>
#include <stdio.h>

int main()
{
	char* path = "./file";
	int fd = open(path,O_RDONLY);
	printf("fd for %s is %d\n",path,fd);
	dup2(3,0); //redirects stdin to file @ "path"
	close(path);
	char buff[32];
	read(3,buff,32);
	printf("%s",buff);
	return 0;
}
