#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *room;
	room = fopen("room1", "a+");
	
	fclose(room);
	return 0;
}
