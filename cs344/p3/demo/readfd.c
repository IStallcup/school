#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* path = "./file";
	int fd = open(path,O_RDONLY); //file open chekcing
	if(fd == -1)
	{
		fprintf(stderr,"Stuff\n");
		close(path);
		exit(1);
	}
	else if (dup2(fd,0) == -1)
		fprintf(stderr,"Stuff\n"); //redirects stdin to file @ "path"
	
	close(path);
	char buff[32];
	read(fd,buff,32);
	printf("%s",buff);

	fd = open(path,O_WRONLY);
	if(fd == -1)
	{
		fprintf(stderr,"Stuff\n");
		close(path);
		exit(1);
	}
	else if (dup2(fd,1) == -1)
		fprintf(stderr,"Stuff\n");
	char* output = "Output!\n";	
	close(path);
	char** command = malloc(sizeof(char*));
	command[0] = "ls";

	execvp(*command,command);

	write(fd,output,1);
	return 0;
}
