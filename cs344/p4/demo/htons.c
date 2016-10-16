#include <arpa/inet.h>
#include <stdio.h>

int main()
{
	printf("%d,%d\n",1,htons(1));
	printf("%d,%d\n",256,htons(256));
	return 0;
}
