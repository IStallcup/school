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
	int i, numcase = 1;;
	struct node *list1 = NULL;
	struct node *list2 = NULL;
	struct node *combine = NULL;
	struct node *iterator = NULL;
	
	/*
	
	//TEST CASE:
	//----------------------------------------------------
	//demonstration of how mergeList merges
	//	the contents of two lists
	printf("\nTest case number %d:\n", numcase);
	numcase++;
	for (i = 1; i <= 4; i++)
	{
		list1 = push(list1, i);
	}
	printf("Contents of list 1:\t");
	print(list1, size(list1));
	for (i = 8; i > 4; i--)
	{
		list2 = push(list2, i);
	}
	printf("Contents of list 2:\t");
	print(list2, size(list2));
	
	printf("Merged lists:\t\t");
	combine = mergeList(list1, list2);
	print(combine, size(combine));
	printf("Merged & sorted lists:\t");
	mergeSort(&list1, &list2);
	print(list1, size(list1));
	//print(list2, size(list2));
	//----------------------------------------------------
	
	list1 = NULL;
	list2 = NULL;
	
	//TEST CASE:
	//----------------------------------------------------
	//list1 and list2 are both empty
	printf("\nTest case number %d:\n", numcase);
	numcase++;
	printf("Contents of list 1:\t");
	print(list1, size(list1));
	printf("Contents of list 2:\t");
	print(list2, size(list2));
	printf("Merged lists:\t\t");
	combine = mergeList(list1, list2);
	print(combine, size(combine));
	mergeSort(&list1, &list2);
	printf("Merged & sorted lists:\t");
	print(list1, size(list1));
	//----------------------------------------------------

	list1 = NULL;
	list2 = NULL;
		
	//TEST CASE:
	//list1 is not empty, list2 is empty
	//expected output: list1 is sorted and displayed
	//----------------------------------------------------
	printf("\nTest case number %d:\n", numcase);
	numcase++;
	for (i = 0; i < 4; i++)
	{
		list1 = push(list1, i);
	}
	printf("Contents of list 1:\t");
	print(list1, size(list1));
	printf("Contents of list 2:\t");
	print(list2, size(list2));
	printf("Merged lists:\t\t");
	combine = mergeList(list1, list2);
	print(combine, size(combine));
	printf("Merged & sorted lists:\t");
	mergeSort(&list1, &list2);
	print(list1, size(list1));
	
	//----------------------------------------------------
	
	list1 = NULL;
	list2 = NULL;
	
	//TEST CASE:
	//list1 is empty, list2 is not
	//expected output, from intuitive knowledge of merging
	//	two lists and sorting them, would be list2 sorted
	//real output is null as if the first list is null the second
	//	is automatically set to be that as well
	//----------------------------------------------------
	printf("\nTest case number %d:\n", numcase);
	numcase++;
	for (i = 0;  i < 4; i++)
	{
		list2 = push(list2, i);
	}
	printf("Contents of list 1:\t");
	print(list1, size(list1));
	printf("Contents of list 2:\t");
	print(list2, size(list2));
	printf("Merged lists:\t\t");
	combine = mergeList(list1, list2);
	print(combine, size(combine));
	printf("Merged & sorted lists:\t");
	mergeSort(&list1, &list2);
	print(list1, size(list1));
	//----------------------------------------------------
	
	list1 = NULL;
	list2 = NULL;
	
	//TEST CASE:
	//Both list1 and list2 are set to two elements, ecah being zero.
	//	the lists are merged and sorted.
	//Expected: the merged/sorted list will be 0 0
	//Reality: The sorted list is 0
	//----------------------------------------------------
	printf("\nTest case number %d:\n", numcase);
	numcase++;
	list1 = push(list1, 0);
	list2 = push(list2, 0);
	printf("Contents of list 1:\t");
	print(list1, size(list1));
	printf("Contents of list 2:\t");
	print(list2, size(list2));
	printf("Merged lists:\t\t");
	combine = mergeList(list1, list2);
	print(combine, size(combine));
	printf("Merged & sorted lists:\t");
	mergeSort(&list1, &list2);
	print(list1, size(list1));
	//----------------------------------------------------
	
	list1 = NULL;
	list2 = NULL;
	
	//TEST CASE:
	//Both lists are set to multiple copies of the different numbers
	//list1 is set to be multiple ones and list2 is set to be multiple
	//	zeroes
	//Expected: list contains both zeroes and ones
	//Reality: list contains only zeroes
	//----------------------------------------------------
	printf("\nTest case number %d:\n", numcase);
	numcase++;
	for(i = 0; i < 4; i++)
	{
		list1 = push(list1, 1);
		list2 = push(list2, 0);
	}
	printf("Contents of list 1:\t");
	print(list1, size(list1));
	printf("Contents of list 2:\t");
	print(list2, size(list2));
	printf("Merged lists:\t\t");
	combine = mergeList(list1, list2);
	print(combine, size(combine));
	printf("Merged & sorted lists:\t");
	mergeSort(&list1, &list2);
	print(list1, size(list1));
	//----------------------------------------------------
	
	list1 = NULL;
	list2 = NULL;
	
	//TEST CASE:
	//The lists are set to contain the same elements in the same order.
	//Expected: The list becomes two of every element in order
	//Actual: The list is sorted but duplicates are removed
	//----------------------------------------------------
	printf("\nTest case number %d:\n", numcase);
	numcase++;
	for (i = 0; i < 4; i++)
	{
		list1 = push(list1, i);
		list2 = push(list2, i);
	}
	printf("Contents of list 1:\t");
	print(list1, size(list1));
	printf("Contents of list 2:\t");
	print(list2, size(list2));
	printf("Merged lists:\t\t");
	combine = mergeList(list1, list2);
	print(combine, size(combine));
	printf("Merged & sorted lists:\t");
	mergeSort(&list1, &list2);
	print(list1, size(list1));
	//----------------------------------------------------
	
	list1 = NULL;
	list2 = NULL;
	
	//TEST CASE:
	//
	//----------------------------------------------------
	printf("\nTest case number %d:\n", numcase);
	numcase++;
	
	printf("Contents of list 1:\t");
	print(list1, size(list1));
	printf("Contents of list 2:\t");
	print(list2, size(list2));
	printf("Merged lists:\t\t");
	combine = mergeList(list1, list2);
	print(combine, size(combine));
	printf("Merged & sorted lists:\t");
	mergeSort(&list1, &list2);
	print(list1, size(list1));
	//----------------------------------------------------
	
	list1 = NULL;
	list2 = NULL;
	
	*/
	
	//TEST CASE:
	//
	//----------------------------------------------------
	printf("\nTest case number %d:\n", numcase);
	numcase++;
	list1 = push(list1, 4);
	list1 = push(list1, 1);
	list1 = push(list1, 5);
	list1 = push(list1, 2);
	list1 = push(list1, 3);
	list1 = push(list1, 6);
	list1 = push(list1, 7);
	list1 = push(list1, 8);
	print(list1, size(list1));
	print(list2, size(list2));
	list2 = NULL;
	mergeSort(&list1, &list2);
	print(list1, size(list1));
	print(list2, size(list2));
	//----------------------------------------------------
	
	list1 = NULL;
	list2 = NULL;
	
	/*
	
	//TEST CASE:
	//
	//----------------------------------------------------
	printf("\nTest case number %d:\n", numcase);
	numcase++;
	for (i = 0; i < 4; i++)
	{
		list1 = push(list1, 3+i);
		list2 = push(list2, i);
	}
	
	printf("Contents of list 1:\t");
	print(list1, size(list1));
	printf("Contents of list 2:\t");
	print(list2, size(list2));
	
	combine = mergeList(list1, list2);
	iterator = combine;
	
	while (iterator->next != NULL)
	{
		iterator = iterator->next;
	}
	
	mergeSort(&combine, &iterator);
	printf("Merged & sorted lists:\t");
	print(combine, size(combine));
	//----------------------------------------------------
	
	*/
	
}