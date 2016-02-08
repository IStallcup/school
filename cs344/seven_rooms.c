#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setConnections(FILE* room, char roomNames[7][6], int roomNum)
{
	int connections[7] = {-1,-1,-1,-1,-1,-1,-1};
	int i,j;
	int numConnections = (rand() % 4) + 3;
	printf("# conn. for room %s:%d\n",roomNames[roomNum],numConnections);
	int randConnection;
	/*printf("connections for %s\n",roomNames[roomNum]);*/
	for (j = 0; j < numConnections; ++j)
	{
	randConnection = rand() % 7;
	/*printf("\trandConnection = %d\n",randConnection);*/	
	while (randConnection == roomNum)
	{
		randConnection = rand() % 7;
		/*printf("\t*oops! reset to %d\n",randConnection);*/
	}
	i = 0;
	while (i < numConnections)
	{
		/*printf("\tconnections[%d] contains %d\n",i,connections[i]);*/
		if (connections[i] == randConnection)
		{
			/*printf("\tconnections[%d] == %d\n",i,randConnection);*/
			/* reset randConnection */
			randConnection = rand() % 7;
/*			printf("\trandConnection = %d\n",randConnection);	*/
			while (randConnection == roomNum)
			{
				randConnection = rand() % 7;
				/*printf("\t*oops! reset to %d\n",randConnection);*/
			}
			i = -1;
		}
		
		if (connections[i] == -1)
		{
			connections[i] = randConnection;
			/*printf("\tconnections[%d] set %s\n",i,roomNames[randConnection]);*/
/*			printf("\tconnections[%d] contains %d\n",i,connections[i]);*/
			break;
		}
   		++i;
	}
	}
	
	int k;
	for (k = 0; k < numConnections; ++k)
	{
		printf("connections[%d] = %d\n",k,connections[k]);
		fprintf(room,"CONNECTION %d:%s\n",k+1,roomNames[connections[k]]);
	}
	
}

void setType(FILE* room, int roomNum)
{
	char roomTypes[7][11] = {"START_ROOM","MID_ROOM",
		"MID_ROOM","MID_ROOM","MID_ROOM","MID_ROOM","END_ROOM"};
/* 	printf("room #%d, type %s\n",roomNum,roomTypes[roomNum]); */
	fprintf(room,"ROOM TYPE:%s\n",roomTypes[roomNum]);	
}

void createRoom(FILE* room, char roomNames[7][6], int roomNum)
{
	room = fopen(roomNames[roomNum],"w+");
	fprintf(room,"ROOM NAME:%s\n",roomNames[roomNum]);
	setConnections(room,roomNames,roomNum);
	setType(room,roomNum);
	fclose(room);
}

void printRoom(FILE* room, char roomNames[7][6], int roomNum)
{

}

int main()
{
	srand(time(NULL));
	char roomNames[7][6] = {"room0","room1","room2",
		"room3","room4","room5","room6"};
	int roomNum;
	FILE* room;
	for (roomNum = 0; roomNum < 7; ++roomNum)
	{
		createRoom(room,roomNames,roomNum);
		printRoom(room,roomNames,roomNum);
	}
	
}
