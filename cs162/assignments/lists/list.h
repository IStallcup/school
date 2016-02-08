#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
};

char ans[2];
int num;
int len;

int size(struct node *list) //returns size of a node
{
	int l = 1;
	struct node *iterator = NULL;
	iterator = list;
	
	while (iterator->next != NULL)
	{
		l++;
		iterator = iterator->next;
	}
	
	return l;
}

void print(struct node *list, int length) //prints a linked list
{
	int i;
	struct node *iterator = NULL;
	iterator = list;
	for (i = 0; i < length; i++)
	{
		printf("%d ", iterator->val);
		iterator = iterator->next;
	}
	
	printf("\n");
}

struct node *push(struct node *list, int value) //addds value to beginning of a linked list, creating new node for it
{
	struct node *pointer = NULL;
	pointer = list;
	list = malloc(sizeof(struct node));
	(list)->val = value;
	(list)->next = pointer;
	return list;
}

void iterate_descending(struct node *list, int *x, int i)
{
	
	int j, temp;
	for (j = 0; j < size(list)-1; j++)
	{
		for (i = 0; i < size(list)-1; i++)
		{
			if (x[i] < x[i+1])
			{
				temp = x[i+1];
				x[i+1] = x[i];
				x[i] = temp;
			}
		}
	}
}


//copies each node of the linked list into an element of an array, then rearranges the
//array to be in a descending order via iterate_descending
//and stores elements back in a linked list that is returned.
struct node *sort_descending(struct node *list) //sorts a linked list descending
{
	printf("Sorting...\n");
	struct node *comp;
	comp = list;
	/*printf("Comp:\n");
	print(comp, size(comp));*/
	int *x = malloc(sizeof(int) * size(list));
	int i;
	for (i = 0; i < size(list); i++)
	{
		x[i] = comp->val;
		comp = comp->next;
	}
	iterate_descending(list, x, i);
	struct node *ret;
	for (i = size(list)-1; i >= 0; i--)
	{
		ret = push(ret, x[i]);
	}
	//print(ret, size(ret));
	
	return ret;
}

void iterate_ascending(struct node *list, int *x, int i)
{
	
	int j, temp;
	for (j = 0; j < size(list)-1; j++)
	{
		for (i = 0; i < size(list)-1; i++)
		{
			if (x[i] > x[i+1])
			{
				temp = x[i];
				x[i] = x[i+1];
				x[i+1] = temp;
			}
		}
	}
}


//copies each node of the linked list into an element of an array, then rearranges the
//array to be in an ascending order via iterate_ascending
//and stores elements back in a linked list that is returned.
struct node *sort_ascending(struct node *list)
{
	printf("Sorting...\n");
	struct node *comp;
	comp = list;
	//printf("Comp:\n");
	//print(comp, size(comp));
	int *x = malloc(sizeof(int) * size(list));
	int i;
	for (i = 0; i < size(list); i++)
	{
		x[i] = comp->val;
		comp = comp->next;
	}
	
	iterate_ascending(list, x, i);
	
	struct node *ret;
	for (i = size(list)-1; i >= 0; i--)
	{
		ret = push(ret, x[i]);
	}
	//print(ret, size(ret));
	
	return ret;
}


#endif
