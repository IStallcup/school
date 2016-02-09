#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void setConnections(FILE* room, char roomNames[7][6], int roomNum)
{
	/* placeholder to store which connections have been made */
	int connections[7] = {-1,-1,-1,-1,-1,-1,-1};	
	/* iterators */
	int i, j;
	/* sets # connections between 3 and 6 */
	int numConnections = (rand() % 4) + 3;
	/* selector for which room to add */
	int randConnection;
	for (j = 0; j < numConnections; ++j)
	{
		/* choose a random room # between 0 and 7 */
		randConnection = rand() % 7;
		/* room # cannot be that of the current room */
		while (randConnection == roomNum)
			randConnection = rand() % 7;
		i = 0;
/* this while loop goes through the array connections,
 * which holds the rooms already connected to the working
 * room, and checks the selected randConnection against
 * each element; if it finds a match, it resets 
 * randConnection and starts over. If it reaches the end
 * (i.e. if the room is not already connected) it adds it
 * to connections. */
		while (i < numConnections)
		{
			/* if randConnection's room is already connected */
			if (connections[i] == randConnection)
			{
				/* reset randConnection */
				randConnection = rand() % 7;
				/* again ensure that room chosen is not the working room */
				while (randConnection == roomNum)
					randConnection = rand() % 7;
		/* set i to -1, so that the end of the 
		 * loop iterates it to 0 (start loop over again) */
				i = -1;
			}

		/* if i has already been reset, this if statement fails. 
		 * Otherwise, if the i-th element of connections is empty
		 * (that is if we have checked all the connections so far)
		 * then add randConnection to the connections array and halt loop */
			if (connections[i] == -1)
			{
				connections[i] = randConnection;
				break;
			}

			/* iterate i */
			++i;
		}
	}
	
	/* new loop to actually output formatting to rooms */
	int k;
	for (k = 0; k < numConnections; ++k)
	{
		/*printf("outputting to room %s: %s\n",
				roomNames[roomNum],roomNames[connections[k]]);*/
		fprintf(room,"CONNECTION %d:%s\n",k+1,roomNames[connections[k]]);
	}
}

void setType(FILE* room, int roomNum)
{
	char roomTypes[7][11] = {"START_ROOM","MID_ROOM",
/*  array of types of rooms; though only three logical rooms,
 *  this structure allows for rooms one and seven to have appropriate
 *  types and the others to be mid rooms. */
		"MID_ROOM","MID_ROOM","MID_ROOM","MID_ROOM","END_ROOM"};
	fprintf(room,"ROOM TYPE:%s\n",roomTypes[roomNum]);
}

void createRoom(FILE* room,char roomNames[7][6],int roomNum,char dirName[32])
{
	char pathToRoom[38];
	strcpy(pathToRoom,dirName);
	strcat(pathToRoom,roomNames[roomNum]);
	/*printf("pathToRoom=%s\n",pathToRoom);*/
	/*open perscribed room */
	room = fopen(pathToRoom,"w+");
	/*output name of room to room*/
	fprintf(room, "ROOM NAME:%s\n",roomNames[roomNum]);
	/*setConnections(room,roomNames,roomNum);*/
	setConnections(room,roomNames,roomNum);
	setType(room,roomNum);
	fclose(room);
}

void chooseRooms(char allNames[10][6], char roomNames[7][6])
{
	/* initialize array to track rooms that have been chosen */
	int chosenRooms[7] = {-1,-1,-1,-1,-1,-1,-1};
	int i, j; /* iterators */
	int roomChoice; /* current choice of room; will be random */
	for (i = 0; i < 7; ++i)
	{
		roomChoice = rand() % 10; /* choose random # between 0 and 9 */
		for (j = 0; j < i; j++)
		/* iterate from 0 to i; checks the chosenRooms array */
		{
			if (chosenRooms[j] == roomChoice) 
			/*if our currently chosen room has already been selected... */
			{
				roomChoice = rand() % 10; /* try again! */
				j = -1; /* reset j to -1; end of loop resets it to 0 */
			}
		}
		/* add the room choice to chosenRooms */
		chosenRooms[i] = roomChoice;
		/* copy the corresponding chosen room from allNames to roomNames */
		strcpy(roomNames[i],allNames[chosenRooms[i]]);
	}
}

int main()
{
	/* get pid */
	int pid = getpid();
	/* will hold name of directory */
	char dirName[32];
	/* prints formatted text to dirName */
	snprintf(dirName,32,"stallcui.rooms.%d/",pid);
	/* printf("dirName=%s\n",dirName); */
	mkdir(dirName,0755);

	srand(time(NULL)); /* seed random # generation */
	char allNames[10][6] = {"room0","room1","room2",
			/*create array of all rooms*/
				"room3","room4","room5","room6","room7","room8","room9"};
	char roomNames[7][6]; /*create array that will contain used rooms */
	int roomNum; /* iterator to keep track of which room we're on */
	FILE* room;
	chooseRooms(allNames,roomNames); /* choose which 7 rooms will be used */
	for (roomNum = 0; roomNum < 7; ++roomNum)
	{
		createRoom(room,roomNames,roomNum,dirName);
	}
	return 0;
}
