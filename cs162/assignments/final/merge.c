#include "./merge.h"
#include <stdio.h>
#include <stdlib.h>

int size(struct node *list) //returns size of a node
{
	if (list == NULL)
	{
		printf("List to be printed is NULL.\n");
		return 0;
	}
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
	if (list == NULL)
	{
		//printf("List to be printed is NULL.\n");
		return;
	}
	int i;
	struct node *iterator = NULL;
	iterator = list;
	for (i = 0; i < length; i++)
	{
		printf("%d ", iterator->info);
		
		iterator = iterator->next;
	}
	
	printf("\n");
}

struct node *push(struct node *list, int value) //addds value to beginning of a linked list, creating new node for it
{
	struct node *pointer = NULL;
	pointer = list;
	list = malloc(sizeof(struct node));
	(list)->info = value;
	(list)->next = pointer;
	return list;
}

void divideList(struct node *first1, struct node **first2)
{
	struct node *middle;
	struct node *current;
	if (first1 == NULL) //list is empty
		*first2 = NULL;
	else if (first1->next == NULL) //list only has one node
		*first2 = NULL;
	else
	{
		middle = first1;
		current = first1->next;
		if (current != NULL)
			current = current->next;
		while (current != NULL)
		{
			middle = middle->next;
			current = current->next;
			if (current != NULL)
				current = current->next;
		} //end while
		*first2 = middle->next;
		middle->next = NULL;
	} //end else
} //end divideList

struct node* mergeList(struct node* first1, struct node *first2)
{
	struct node *lastSmall; //pointer to last node
	struct node *newHead; //pointer to merged list
	
	if (first1 == NULL) //the first sublist is empty
		return first2;
	else if (first2 == NULL) //the second sublist is empty
		return first1;
	else
	{
		if (first1->info < first2->info) //compare the first nodes
		{
			newHead = first1;
			first1 = first1->next;
			lastSmall = newHead;
		}
		else
		{
			newHead = first2;
			first2 = first2->next;
			lastSmall = newHead;
		}
		while (first1 != NULL && first2 != NULL)
		{
			if (first1->info < first2->info)
			{
				lastSmall->next = first1;				
				lastSmall = lastSmall->next;
				first1 = first1->next;
			}
			else
			{
				lastSmall->next = first2;
				lastSmall = lastSmall->next;
				first2 = first2->next;
			}
		} //end while
		if (first1 == NULL) //first sublist is exhasuted first
			lastSmall->next = first2;
		else	//second sublist is exhausted first
			lastSmall->next = first1;
		return newHead;
	}
} //end mergeList

void recMergeSort(struct node** head)
{
	struct node* otherHead;
	if (*head != NULL)
		if ((*head)->next != NULL)
		{
			divideList(*head, &otherHead);
			recMergeSort(head);
			recMergeSort(&otherHead);
			*head = mergeList(*head, otherHead);
		}
} //end recMergeSort

void mergeSort(struct node **first, struct node **last)
{
	recMergeSort(first);
	if (*first == NULL)
		*last = NULL;
	else
	{
		*last = *first;
		while ((*last)->next != NULL)
		*last = (*last)->next;
	}
} //end mergeSort

int main()
{
	struct node *head = NULL;
	struct node *tail = NULL;
	int i;
	float r;
	
	//Test case 1
	//---------------------------
	head = push(head, 8);
	head = push(head, 3);
	head = push(head, 5);
	head = push(head, 6);
	printf("List:\t\t");
	print(head, size(head));
	mergeSort(&head, &tail);
	printf("List:\t\t");
	print(head, size(head));
	//---------------------------
	
	head = NULL;
	tail = NULL;
	
	//Test case 2
	//---------------------------
	for (i = 0; i < 4; i++)
	{
		if (i == 3)
			head = push(head, 0);
		else
			head = push(head, i);
	}
	printf("List:\t\t");
	print(head, size(head));
	mergeSort(&head, &tail);
	printf("List:\t\t");
	print(head, size(head));
	//---------------------------
	
	head = NULL;
	tail = NULL;
	
	//Test case 3
	//---------------------------
	for (i = 0; i < 3; i++)
	{
		head = push(head, i);
	}
	printf("List:\t\t");
	print(head, size(head));
	mergeSort(&head, &tail);
	printf("List:\t\t");
	print(head, size(head));
	//---------------------------
	
	head = NULL;
	tail = NULL;
	
	//Test case 4
	//---------------------------
	printf("List:\t\t");
	print(head, size(head));
	mergeSort(&head, &tail);
	printf("List:\t\t");
	print(head, size(head));
	//---------------------------
	
	head = NULL;
	tail = NULL;
	
	//Test case 5
	//---------------------------
	for (i = 0; i < 10; i++)
	{
		r = rand()%20;
		head = push(head, r);
	}
	printf("List:\t\t");
	print(head, size(head));
	mergeSort(&head, &tail);
	printf("List:\t\t");
	print(head, size(head));
	//---------------------------
	
	head = NULL;
	tail = NULL;
	
	//Test case 6
	//---------------------------
	for (i = -10; i < 0; i++)
		head = push(head, i);
	printf("List:\t\t");
	print(head, size(head));
	mergeSort(&head, &tail);
	printf("List:\t\t");
	print(head, size(head));
	//---------------------------
	
	head = NULL;
	tail = NULL;
	
	//Test case 6
	//---------------------------
	for (i = 0; i < 30; i++)
		tail = push(tail, 1);
	head = push(head, 1);
	head = push(head, 2);
	printf("List:\t\t");
	print(head, size(head));
	mergeSort(&head, &tail);
	printf("List:\t\t");
	print(head, size(head));
	//---------------------------
	
	
	head = NULL;
	tail = NULL;
	
	//Test case 7
	//---------------------------
	for (i = 0; i < 10; i++)
	{
		r = -rand()%120;
		head = push(head, r);
	}
	head = push(head, 1);
	head = push(head, 2);
	printf("List:\t\t");
	print(head, size(head));
	mergeSort(&head, &tail);
	printf("List:\t\t");
	print(head, size(head));
	//---------------------------
	
	
	head = NULL;
	tail = NULL;
	
	//Test case 8
	//---------------------------
	for (i = 0; i < 10; i++)
	{
		r = -rand()%120;
		head = push(head, r);
	}
	head = push(head, 1);
	head = push(head, 2);
	printf("List:\t\t");
	print(head, size(head));
	mergeSort(&head, &tail);
	printf("List:\t\t");
	print(head, size(head));
	//---------------------------
	
	
	head = NULL;
	tail = NULL;
	
	//Test case 9
	//---------------------------
	for (i = 1; i < 10; i++)
	{
		r = rand()%10;
		if (i%2 == 0)
			r = r*-1;
		head = push(head, r*i);
	}
	printf("List:\t\t");
	print(head, size(head));
	mergeSort(&head, &tail);
	printf("List:\t\t");
	print(head, size(head));
	//---------------------------
	
	
	head = NULL;
	tail = NULL;
	
	//Test case 10
	//---------------------------
	head->info = 'a';
	printf("List:\t\t");
	print(head, size(head));
	mergeSort(&head, &tail);
	printf("List:\t\t");
	print(head, size(head));
	//---------------------------
	
	
	
	return 0;
}
