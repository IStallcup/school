/*******************************************************************
** Program: lists.exe
** Author: Isaac Stallcup
** Date: 06/05/2015
** Description: Reads in a list of numbers, then orders them
**		in descending or ascending order based on user input
** Input: Numbers, yes/no, ascending/descending
** Output: Ordered/sorted list
*******************************************************************/


#include "./list.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct node *list = NULL;
	printf("Enter 0 to end number input process.\n");
	do {
		list = NULL;
		do {
			printf("Enter a number: ");
			scanf("%d", &num);
			if (num == 0) break;
			list = push(list, num);
			printf("List so far: ");
			print(list, size(list));
		} while (num != 0);
		printf("Sort ascending or descending? ");
		scanf("%1s", ans);
		if (ans[0] == 'a') list = sort_ascending(list);
		if (ans[0] == 'd') list = sort_descending(list);
		printf("Sorted list:\n");
		print(list, size(list));
		printf("Run again? ");
		scanf("%1s", ans);
	} while (ans[0] == 'y');
	
	return 0;
}