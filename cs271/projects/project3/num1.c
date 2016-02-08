#include <stdio.h>

int main()
{
	int displayed = 9;
	
	int ecx;
	
	for (ecx; ecx < 5; ecx++)
	{
		printf("%d", displayed);
		displayed--;
	}
	
	printf("\n");
	
	return 0;
}