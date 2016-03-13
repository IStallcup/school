#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		fprintf(stderr,"encode:error in arguments\n");
		exit(1);
	}
	int k,a,r;
	printf("%s\n",argv[1]);
	printf("%s\n",argv[2]);
	const char* filename = argv[2];
	FILE* KEY = fopen(filename,"r");
	//check size here
	k = fgetc(KEY);
	printf("%c\n",k);
	printf("%d\n",k-64);

	a = argv[1][0];
	printf("%c\n",a);
	printf("%d\n",a-64);

	r = a - 64 + k - 64;
	printf("%d\n",r);
	printf("%d\n",(r%27));
	printf("%c\n",(r%27)+64);
	
	return 0;
}
