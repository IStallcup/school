#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "BST.h"

int main (int argc, const char * argv[])
{
	int i;
	int ary[6] = { 94, 73, 59, 45, 65, 26}; 
	
	BST* t = newBST();
	
	Task firstTask, secondTask, thirdTask, fourthTask;
	firstTask.name = "blarg";
	firstTask.priority = 11;
	
	secondTask.name = "foo";
	secondTask.priority = 34;
	
	thirdTask.name = "bar";
	thirdTask.priority = 23;
	
	fourthTask.name = "scraz";
	fourthTask.priority = 37;
	
	printf("Adding 23\n");
	addBST(t, thirdTask);	printBST(t);
	printf("contains(34) = %d\n", containsBST(t, secondTask));
	
	printf("Adding 34\n");
	addBST(t, secondTask);	printBST(t);
	printf("contains(34) = %d\n", containsBST(t, secondTask));
	
	printf("Adding 11\n");
	addBST(t, firstTask);	printBST(t);
	printf("contains(37) = %d\n", containsBST(t, fourthTask));
	
	printf("Adding 37\n");
	addBST(t, fourthTask);	printBST(t);
	printf("contains(37) = %d\n", containsBST(t, fourthTask));
	
	removeBST(t, thirdTask); printBST(t);
	removeBST(t, secondTask); printBST(t);
	removeBST(t, fourthTask); printBST(t);
	removeBST(t, firstTask); printBST(t);
	
	for(i = 0; i < 6; ++i)
	{
		firstTask.priority = ary[i];
		addBST(t, firstTask);
	}
	printBST(t);
	printf("\n");
	
	return 0;
}