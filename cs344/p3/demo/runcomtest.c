#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int isRedirect(char* arg)
{
	if (strcmp(arg,"|") == 0)
		return 1;
	else if (strcmp(arg,"<") == 0)
		return 2;
	else if (strcmp(arg,">") == 0)
		return 3;
	else return 0;
}

int fdchg(char** argv, size_t max_size)
{
	int argNum,redType,fd_new,fd_old;
	int redType_f = 0;
	printf("start fdchg\n");
	for (argNum = 0; argNum < max_size; ++argNum)
	{
		if (!argv[argNum])
			break;
		redType = isRedirect(argv[argNum]);
		printf("redType of %s is %d\n",argv[argNum],redType);
		printf("Look@%s\n",argv[argNum]);
		if (redType != 0)
		{
			printf("redirection character:%s\n",argv[argNum]);
			redType_f = redType;
		}
	}
	printf("postloop argNum=%d\n",argNum);
	printf("file involved in redirection is %s\n",argv[argNum-1]);
	if (redType_f == 1)
	{
		fd_new = open(argv[argNum-1],O_RDONLY);
		fd_old = 0;
		dup2(fd_new,fd_old);
		close(argv[argNum-1]);
		//close(fd_new);
	}
	else if (redType_f == 2)
	{
		fd_new = open(argv[argNum-1],O_WRONLY);
		fd_old = 0;
		dup2(fd_new,fd_old);
		close(argv[argNum-1]);
		//close(fd_new);
	}
	else if (redType_f == 3)
	{
		fd_new = open(argv[argNum-1],O_RDONLY);
		fd_old = 0;
		dup2(fd_new,fd_old);
		close(argv[argNum-1]);
	}
	else //no redirection
	{
		fd_new = -1;
		fd_old = -1;
	}
	printf("new fd is %d\n",fd_new);	
	return fd_new;
}

char** setargv(char** argv)
{
	char** argTok = malloc(sizeof(char*)*512);
	argTok[0] = "cat";
	argTok[1] = "<";
	argTok[2] = "file";
	return argTok;	
}

int main()
{
	size_t max_size = 512;
	char** argv = malloc(sizeof(char*)*max_size);
	int i;
	argv = setargv(argv);
	for (i = 0; i < max_size; ++i)
	{
		if (argv[i])
			printf("%s\n",argv[i]);
		else break;
	}
	printf("isRedirect of cmd = %d\n",isRedirect(argv[1]));
	fdchg(argv,max_size);
	char buff[32];
	read(3,buff,32);
	printf("%s",buff);
	return 0;
}
