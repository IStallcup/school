#include "./lab.h"
#include <stdlib.h>
#include <stdio.h>


int length(struct node *head)
{
	int counter = 1;

	struct node *iterator = NULL;
	iterator = head;

	while(iterator->next != NULL)
	{
		counter++;
		iterator = iterator->next;	
	}


	return counter;
}


void push(struct node **head, int value) //add to front of list
{
	struct node *insptr = NULL;
	insptr = *head;
	*head = malloc(sizeof(struct node));

	(*head)->val = value;
	(*head)->next = insptr;
}


void append(struct node **head, int value) //add to rear of list
{
	struct node *insptr = *head;
	struct node *end;

	end = malloc(sizeof(struct node));
	end->val = value;
	end->next = NULL;

	if(insptr == NULL)
	{
		*head = end;
	}
	else
	{
		while(insptr->next != NULL)
		{
			insptr = insptr->next;
		}
		insptr->next = end;
	}
}


void print(struct node *head, int length)
{
	int i;
	struct node *iterator = NULL;
	iterator = head;

	for(i=0; i<length; i++)
	{
		printf("%d ", iterator->val);
		iterator = iterator->next;
	}
	printf("\n");
}
