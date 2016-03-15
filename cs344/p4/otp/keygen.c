#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
	//error checking begins here
	if (argc == 1)
	{
		fprintf(stderr,"keygen: not enough arugments\n");
		exit(1);
	}

	int i, length;
	char randC;
	srand(time(NULL));

	//trace statements begin here
	/*printf("args=%d\n",argc);
	for (i = 0; i < argc; i++)
		printf("argv[%d] = %s\n",i,argv[i]);*/
	//trace statements end here
	
	length = atoi(argv[1]);

	for (i = 0; i <= length; i++)
	{		
		randC = rand() % 27 + 65;
		if (randC == 91)
		{
			randC = ' ';
		}
		printf("%c",randC);
	}

	return 0;
		
}
