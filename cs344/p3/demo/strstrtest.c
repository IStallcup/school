#include <stdio.h>
#include <string.h>

char* parseInput(char* input)
{
	printf("parseInput start\n");
	char* token = strstr(input,">");
	return strstr(input,">");
}

int main()
{
	char** argv = malloc(sizeof(char*)*512);
	char cmdline[128];
	printf(": ");
	scanf("%s",cmdline);
	argv[1] = parseInput(cmdline);
	printf("parseInput end\n");
	printf("%s\n",*argv[0]);
	free(argv);
	return 0;
}
