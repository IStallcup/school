#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int arcg, char* argv[])
{
	char* src = "TEST STRING";
	int t,k,e,d,ii;
	for (ii = 0; ii < strlen(src); ii++)
	{
		t = src[ii];
		if (t == ' ')
			t = 91;
		printf("%c,%d,%d\n",t,t,t-64);
	
		FILE* KEY = fopen("mykey","r");
		k = fgetc(KEY);
		if (k == ' ')
			k = 91;
		printf("%c,%d,%d\n",k,k,k-64);
	
		e = (t - 64 + k - 64)%27;
		printf("%c,%d,%d\n",e+64,e,e+64);
	
		d = (e+27-(k-64))+64;
		printf("%c,%d,%d\n",d,d,d-64);
		printf("\n\n");
	}
}
