#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	FILE *room;
	room = fopen("room1", "w+");
	fputs("ROOM NAME:\n",room);
	int i;
	int numConnections = rand() % 3;
	numConnections += 3;
	printf("numConnections = %d\n", numConnections);
	for (i = 0; i < numConnections; ++i)
	{
		fputs("CONNECTIONsiiasdasdf:sdfasdf:\n",room);	
	}
	fclose(room);
	return 0;
}
