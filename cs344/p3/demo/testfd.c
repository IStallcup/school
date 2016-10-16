#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int redirectType(char* argTok)
{
	if (argTok[0] == '>') //redirect stdout
		return 0;
	else if (argTok[0] == '<') //redirect stdin
		return 1;
	else return -1; //no redirection
}

void fdchg(char** argv, size_t max_size)
{
	int argNum,tokBool,fd;
	char* path;
	char buff[32];
	for (argNum = 0; argNum < max_size; ++argNum)
	{
		if (!argv[argNum])
			break;
		tokBool = redirectType(argv[argNum]);
		printf("argv[%d]=%s,tokBool=%d\n",argNum,argv[argNum],tokBool);
		path = strcat("./",argv[argNum+1]);
		if (open(path,O_WRONLY) == -1)
			printf("hull breanch\n");
		else
		{
			read(stdin,buff,32);
			close(path);
		}
		printf("testing path %s\n",path);
		if (tokBool == 0)
		{
			if (!argv[argNum+1])
			{
				printf("file %s DNE\n",argv[argNum+1]);
				break;
			}
			fd = open(argv[argNum+1],O_WRONLY);
			if (fd < 0)
				perror("smallsh");
			dup2(fd,0);
			close(argv[argNum+1]);
			
			//testing area
			read(3,buff,32);
			printf("%s",buff);	
		}
		else if (tokBool == 1)
		{
			if(!argv[argNum+1])
			{
				printf("file %s DNE\n",argv[argNum+1]);
				break;
			}
			fd = open(argv[argNum+1],O_RDONLY);
			if (fd < 0)
				perror("smallsh");
			dup2(fd,1);
			close(argv[argNum+1]);
			
			//testing area
			read(3,buff,32);
			printf("%s",buff);	
		}
	}
}

char** tokcmd(char** argv, size_t max_size)
{
	int argNum = 0;
	char** argTok = malloc(sizeof(char*)*max_size);
	argTok[argNum] = strtok(*argv," \n");
	while (argTok[argNum] != NULL)
	{
		++argNum;
		argTok[argNum] = strtok(NULL, " \n");
		printf("argTok[%d]=%s\n",argNum,argTok[argNum]);
	}
	free(argTok);
	return argTok;
}

char** getcmd(char** argv, size_t max_size)
{
	getline(argv,&max_size,stdin);
	argv = tokcmd(argv,max_size);
	return argv;
}

int main()
{
	size_t max_size = 512;
	char** argv = malloc(sizeof(char*)*max_size);
	int i;
	argv = getcmd(argv,max_size);
	for (i = 0; i < max_size; ++i)
	{
		if (argv[i] == NULL)
			break;
		printf("argv[%d]=%s\n",i,argv[i]);
	}
	fdchg(argv,max_size);
}
