#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void setConnections(FILE* room, char roomNames[7][6], int roomNum)
{
	printf("start setConnections for room# %d\n",roomNum);
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
		fprintf(room,"CONNECTION %d: %s\n",k+1,roomNames[connections[k]]);
	}
}

void setType(FILE* room, int roomNum)
{
	char roomTypes[7][11] = {"START_ROOM","MID_ROOM",
/*  array of types of rooms; though only three logical rooms,
 *  this structure allows for rooms one and seven to have appropriate
 *  types and the others to be mid rooms. */
		"MID_ROOM","MID_ROOM","MID_ROOM","MID_ROOM","END_ROOM"};
	fprintf(room,"ROOM TYPE: %s\n",roomTypes[roomNum]);
}

void createRoom(FILE* room,char roomNames[7][6],int roomNum,char dirName[32],
		char pathsToRooms[7][38])
{

	char pathToRoom[38];
	strcpy(pathToRoom,dirName);
	strcat(pathToRoom,roomNames[roomNum]);
	/*printf("pathToRoom=%s\n",pathToRoom);*/
	/*open perscribed room */
	room = fopen(pathToRoom,"w+");
	/*output name of room to room*/
	fprintf(room, "ROOM NAME: %s\n",roomNames[roomNum]);
	/*setConnections(room,roomNames,roomNum);*/
	setConnections(room,roomNames,roomNum);
	setType(room,roomNum);
	fclose(room);
	strcpy(pathsToRooms[roomNum],pathToRoom);
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















int printRoom(FILE* room, char inBuff[64], char workingName[6],
	   char workingConnections[6][6], char pathsToRooms[7][38],
	   int workingRoom, char roomNames[7][6], int numSteps,
	   char stepPath[64][6])
{
	/* iterator */
	int i;
	/*printf("working room# is %d\n",workingRoom);*/
	/*printf("working room is %s\n",pathsToRooms[workingRoom]);*/
	room = fopen(pathsToRooms[workingRoom],"r");
	fscanf(room,"%s",inBuff); /* gets ROOM */
	fscanf(room,"%s",inBuff); /* gets NAME: */
	fscanf(room,"%s",inBuff); /* gets actual name of working room */
	strcpy(workingName,inBuff); /* puts buffer into workingName */
	strcpy(stepPath[numSteps],inBuff); /* adds buffer into path taken */
	for (i = 0; i < 7; i++)
	{
		fscanf(room,"%s",inBuff); /* gets CONNECTION */
		fscanf(room,"%s",inBuff); /* gets NAME: */
		fscanf(room,"%s",inBuff); /* gets actual name of connection/third field */
		if (inBuff[0] != 'S' && inBuff[0] != 'E' && inBuff[0] != 'M')
			strcpy(workingConnections[i],inBuff); /* if buffer is not a room type */
		else if (inBuff[0] == 'E')
		{
			fclose(room);
			return 10; /* return 10; value says that we are done */
		}
		else break; /* otherwise stop loop */
	}
	fclose(room);
	int numConnections = i;
	printf("CURRENT LOCATION: %s\n",workingName);
	printf("POSSIBLE CONNECTIONS: ");
	/* prints possible connections with appropriate punctuation */
	for (i = 0; i < numConnections; ++i)
	{
		if (i == (numConnections - 1))
			printf("%s.\n",workingConnections[i]);
		else
			printf("%s,",workingConnections[i]);
	}
	int successFlag = 0;
	while (successFlag == 0)
	{
		printf("WHERE TO? >");
		scanf("%s",inBuff);
		/* loop iterates through each connection to working room, and
		 * checks the connection to the destination room; if no successes,
		 * then it errors out and asks for input again. If it finds success,
		 * it continues on. */
		for (i = 0; i < numConnections; ++i)
		{
			if (strcmp(inBuff,workingConnections[i]) == 0)
			{
				successFlag = 1;
				break;
			}
			else if (i == (numConnections - 1))
				printf("I don't know how to %s.\n",inBuff);
		}
	}
	/*printf("going to %s\n",workingConnections[i]);*/
	int l;
	for (l = 0; l < 6; ++l)
	{
		int compResult = strcmp(workingConnections[i],roomNames[l]);
	/*	printf("index %d	%s vs. %s: %d\n",l,workingConnections[i],roomNames[l],compResult); */
		if (compResult == 0)
			break;
	}
	/*printf("i sends to %s\n",pathsToRooms[i]);*/
	/*printf("l sends to %s\n",pathsToRooms[l]);*/
	return l;
}

void playGame(FILE* room, char roomNames[7][6], char pathsToRooms[7][38])
{
	/* variable setup */
	int i;
	int workingRoom = 0;
	char inBuff[64];
	char workingName[6];
	char workingConnections[6][6];
	int numSteps = 0;
	char stepPath[64][6];
	while (workingRoom != 10)
	{
		/* play the game */
		workingRoom = printRoom(room, inBuff, workingName,
		   	workingConnections, pathsToRooms, workingRoom,roomNames,
			numSteps,stepPath);
		numSteps++;
	}

	/* victory message */
	printf("YOU HAVE FOUND THE END ROOM, CONGRATULATIONS!\n");
	printf("YOU TOOK %d STEPS. YOUR PATH TO VICTORY WAS:\n",numSteps-1);
	for (i = 1; i < numSteps; i++)
	{
		printf("%s\n",stepPath[i]);
	}

}

int main()
{
	printf("start of program flow\n");
	/* get pid */
	int pid = getpid();
	/* will hold name of directory */
	char dirName[32];
	/* prints formatted text to dirName */
	snprintf(dirName,32,"stallcui.rooms.%d/",pid);
	/* printf("dirName=%s\n",dirName); */
	mkdir(dirName,0755);

	srand(time(NULL)); /* seed random # generation */

	/* sorry not sexy :( */
	char allNames[10][6] = {"room0","room1","room2",
			/*create array of all rooms*/
				"room3","room4","room5","room6","room7","room8","room9"};
	char roomNames[7][6]; /*create array that will contain used rooms */
	char pathsToRooms[7][38];
	int roomNum; /* iterator to keep track of which room we're on */
	FILE* room;
	chooseRooms(allNames,roomNames); /* choose which 7 rooms will be used */
	for (roomNum = 0; roomNum < 7; ++roomNum)
	{
		printf("loop to create rooms #%d\n",roomNum);
		createRoom(room,roomNames,roomNum,dirName,pathsToRooms);
	}
	playGame(room,roomNames,pathsToRooms);
	return 0;
}
