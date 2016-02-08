#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ListDeque.h"

/*	Create a link for a value.
	Use this function in your add operations to make it easier to allocate links

	param: 	val		the value to store in the newy created link
	pre:	none
	post:	a link is allocated on the heap, storing the argument value
	ret:	the newly allocated link
*/
DLink* _createLink(TYPE val)
{
	DLink* lnk = (DLink*) malloc(sizeof(DLink));
   	assert(lnk != 0);
	
	lnk->value = val;
	return lnk;
}


/* ************************************************************************
	Basic Operations
************************************************************************ */

/* Initializes a deque.

	param: 	d		pointer to the deque
	pre:	d is not null
	post:	size, head, and tail are initialized
*/
void initListDeque(ListDeque* d)
{
	/*FIXME you will write this function */

	d->size = 0;
	d->head = NULL;
	d->tail = NULL;

}

/* Runtime Analysis
	This function has runtime of O(1) as the function simply initializes the
	ListDeque.
	Best case: O(1)
	Worst case: O(1)
*/

/*
	Circularity/Sentinels:
	This function would not be simplified by using circularity or sentinels. However
	to use them, this function would have to change in that instead of being set to NULL
	the head and tail pointers would be set to the sentinels used.
*/


/*	De-allocate all links of the deque.
	Write this function in terms of a remove function, such as removeBack.

	param: 	d		pointer to the deque
	pre:	d is not null
	post:	All links are de-allocated
*/
void freeListDeque(ListDeque* d)
{	
	if(d->head == NULL || d->tail == NULL || d == NULL)
		return;
	else
	{
		/* Removes from the front of the list as long as the head is pointing at something*/
		while(d->head != NULL)
		{
			removeFrontListDeque(d);
		}
	}

}


/* Runtime Analysis:
	This function is O(N) as the while loop is checked after each call to removeFrontListDeque(),
	and removeFrontListDeque() changes the position of the d->head pointer. This means it effectively
	iterates through the list, giving an O(N) runtime.
	Best case: O(N)
	Worst case: O(N)
*/

/*
   Circularity/Sentinels:
	The while loop's condition would have to change if sentinels are used to reflect the fact that d->head points
	to a sentinel, not the first element, so there would be slightly more work required to determine if the list
	was empty yet; probably a call to isEmptyListDeque().
	Circularity would not change this function.
*/

/* Check whether the deque is empty.

	param: 	d		pointer to the deque
	pre:	d is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyListDeque(ListDeque *d) 
{

	/*FIXME you will write this function */

	/* If head is NULL the list must be empty*/
	if(d->head == NULL){
		return 1;
	}

	return 0;
}

/* Runtime Analysis:
	This function's runtime is O(1) as it is a simple check of a pointer.
	Best case: O(1)
	Worst case: O(1)
*/

/* Circularity/Sentinels:
	If sentinels are used, the if statement would need to be changed to reflect head pointing to a sentinel,
	probably by inspecting what the sentinel points to.
	Circularity would not change this function.
*/

/* Get the value stored in the link at the front of the deque

	param: 	d		pointer to the deque
	pre:	d is not null 
	pre:	d is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontListDeque (ListDeque *d) 
{
   assert(!isEmptyListDeque(d));
   return d->head->value;
}

/* Runtime Analysis:
	This function's runtime is, beyond the call to assert(), O(1). To remove any uncertainty, the call to 
	assert() could be replaced with a simple check of the pointer, or a call to isEmptyListDeque() though
	the call may change the runtime where the pointer check will not.
	Best case: O(1)
	Worst case: O(1)
*/

/* Circularity/Sentinels:
	With sentinels, the function may not change depending on the behaviour of isEmptyListDeque(). If isEmptyListDeque()
	does not change in functionality, this is the case. However, if isEmptyListDeque() does not account for changes
	with sentinels, the sentinels' pointers must be compared to check if the list is empty.
	Beyond error checking, the function will behave the same, returning instead the head sentinel's next pointer.
	With circularity this function behaves the same.
*/

/* Get the value stored in the link at the back of the deque

	param: 	d		pointer to the deque
	pre:	d is not null
	pre:	d is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backListDeque(ListDeque *d)
{
	/*FIXME you will write this function */
	TYPE var;

	var = d->tail->value;

	return var;
}


/* Runtime Analysis:
	This function's runtime is O(1) as it simply creates, sets then returns a singular value.
*/

/* Circularity/Sentinels:
	As mentioned above, with sentinels this function would have to reflect d->tail pointing to a sentinel (this is
	also the case in circularity with sentinels). With circularity without sentinels this function behaves the same.
*/

/*	Adds a link AFTER another link.
	Write your other add functions in terms of addAfter and addBefore when possible.
 
	param: 	d			pointer to the deque
	param: 	addAfter	pointer to the existing link in the deque
	param: 	newLnk		pointer to the new link to add after the existing link
	pre:	d is not null
	pre: 	newLnk has been properly initialized
	pre:	addAfter is in the deque if it is not a NULL pointer
	post:	newLnk is added into the deque AFTER the existing link
 */
void addLinkAfterListDeque(ListDeque* d, DLink* addAfter, DLink* newLnk)
{
	/* First case: the list is empty */
	/* Head and Tail are allocated and given newLnk to point at */
	if(d->head == NULL)
	{	
		d->head = newLnk;
		d->tail = newLnk;
		newLnk->next = NULL;
		newLnk->prev = NULL;
	}
	/* Second case: you are adding after the last thing in the list */
	/* AddAfter gets newLnk and tail is set to point at the new end (newLnk) */
	else if(addAfter == d->tail)
	{
		addAfter->next = newLnk;
		d->tail = newLnk;
		newLnk->prev = addAfter;
		newLnk->next = NULL;
	}
	/* Third case: you are adding into the middle of the LL somewhere */
	/* the new lnk's next and prev get Add afters next and addafter respectively */
	/* addafter's next and the thing addafter next is pointing to get newLnk */
	else
	{
		newLnk->next = addAfter->next;
		newLnk->prev = addAfter;
		newLnk->next->prev = newLnk;
		addAfter->next = newLnk;
	}

	d->size += 1;
}

/* Runtime Analysis:
	In the case the list is empty, the runtime is O(1) as the function performs simple pointer arrangement. Similarly 
	when the link to be added after is the tail, the link to be added is already created so pointer rearrangement is
	all that is required, giving an O(1) runtime.
	However, if the link is to be added somewhere else, and addAfter is somewhere in the middle of the list, to get to it
	requires following multiple pointers, it requires O(N) time as this process of following pointers is proportional to the
	size of the linked list.
	Best case: O(1)
	Worst case: O(N)
*/

/* Circularity/Sentinels:
	With circularity, the tail case would have to be changed to include newLnk->next getting d->head instead of NULL, and d->head->prev
	to get newLnk to maintain the circular behaviour of the list.
	With sentinels, the function would have to change to reflect changes in the sentinel's pointers instead of in head and tail.
*/

/* Adds a link BEFORE another link.
	Write your other add functions in terms of addAfter and addBefore when possible.
 
	param: 	d			pointer to the deque
	param: 	addBefore	pointer to the existing link in the deque
	param: 	newLnk		pointer to the new link to add before the existing link
	pre:	d is not null
	pre: 	newLnk has been properly initialized
	pre:	addBefore is in the deque if it is not a NULL pointer
	post:	newLnk is added into the deque BEFORE the existing link
 */
void addLinkBeforeListDeque(ListDeque* d, DLink* addBefore, DLink* newLnk)
{
	
	/*FIXME you will write this function */

	/* First case: the LL is empty */
	/* Head and Tail are allocated memory and assigned NewLnk to point at */
	if(d->head == NULL)
	{
		d->head = newLnk;
		d->tail = newLnk;
		newLnk->next = NULL;
		newLnk->prev = NULL;
	}
	/* Second case: you are given the front of the list to add to */
	/* addBefore prev gets newLnk to point at, and head is changed to newLnk */
	else if(addBefore == d->head)
	{
		addBefore->prev = newLnk;
		d->head = newLnk;
		newLnk->next = addBefore;
		newLnk->prev = NULL;
	}
	/* Third case: you add somewhere in the middle */
	/* the neccesary pointer changes are made to adjust to newLnk */
	else
	{
		newLnk->prev = addBefore->prev;
		newLnk->next = addBefore;
		newLnk->prev->next = newLnk;
		addBefore->prev = newLnk;
	}

	d->size += 1;
}


/* Runtime Analysis:
	Similar to addLinkAfterListDeque(), this function is at best O(1) when the head or tail are accessed,
	and at worst O(N) for accessing somewhere in the middle.
	Best case: O(1)
	Worst case: O(N)
*/

/* Circularity/Sentinels:
	As with addLinkAfterListDeque(), circularity would necessitate changes from NULL to head or tail depending on the case
	in order to maintain the circular nature of the list. Sentinels would not change the behavior, instead slightly changing
	where the function looked in regards to its pointers.
*/


/*	Remove a link from the deque.
	Write our other remove functions in terms of this function when possible.
	Be careful not to use a pointer that you have already freed when returning.

	param: 	d		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	d is not null 
	pre:	d is not empty
	pre:	lnk is in the deque 
	post:	lnk is removed from the deque
	ret:	The pointer which follows lnk
*/
DLink* removeLinkListDeque(ListDeque *d, DLink *lnk)
{
	/*FIXME you will write this function */

	DLink* temp;

	/* First Case: you are removing the first item in the LL */
	if(lnk == d->head)
	{
		/* FC Case 1: There is only one item in the LL */
		/* lnk is freed (also freeing head and tail in the process) */
		/* head and tail are given NULL and the size is decrimented by 1 (making it zero) */
		if(lnk == d->tail)
		{
			free(lnk);
			d->head = NULL;
			d->tail = NULL;
			d->size -= 1;
			/* the function returns here to avoid a double free caused by freeing lnk at the bottom */
			return NULL;
		}
		/* FC Case 2: There is more than one item in the LL */
		/* head is changed to next, the next links previous case (previously the head) is given NULL */
		else
		{
			d->head = lnk->next;
			lnk->next->prev = NULL;
		}
	}
	/* Second Case: you are given the last item to remove */
	/* tail is changed to the previous, the previous items next case (previously the tail) is given NULL */
	else if(lnk == d->tail)
	{
		d->tail = lnk->prev;
		lnk->prev->next = NULL;
	}
	/* Third Case: you are given some item in the middle to remove */
	/* the two links on either side of the removing link are given each other to point at */
	else
	{
		temp = lnk->next;
		lnk->next->prev = lnk->prev;
		lnk->prev->next = temp;
	}

	/* The lnk is removed at the end */
	free(lnk);

	d->size -= 1;

	return NULL;
}

/* Runtime Analysis:
	The function is O(1) when it is not required to travel along the length of the list, i.e. when the removed
	links are at the beginning or end. Otherwise to access the middle of the list, there is a required runtime
	of O(N) as the number of pointers followed is proportional to the size of the list.
	Best case: O(1)
	Worst case: O(N)
*/

/* Circularity/Sentinels:
	With circularity, removing a link is unchanged other than manipulating pointers in the case of removing head and/or tail.
	Sentinels would change little other than simple pointer changes.
*/


/* ************************************************************************
	Deque Interface
************************************************************************ */

/*	Adds a link to the back of the deque.
	Write this function in terms of addLinkAfter() when possible.

	param: 	d		pointer to the deque
	param: 	val		value for the link to be added
	pre:	d is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackListDeque (ListDeque *d, TYPE val) 
{
	/*FIXME you will write this function */

	/* addLinkAfterListDeque is called here as a case for adding to the back of the deque exists within it */

	addLinkAfterListDeque(d, d->tail, _createLink(val));
 
}


/* Runtime Analysis:
	O(1) as it simply makes a single function call.
*/

/* Circularity/Sentinels:
	Circularity and sentinels would not change this function.
*/

/*	Adds a link to the front of the deque.
	Write this function in terms of addLinkBefore when possible.

	param: 	d		pointer to the deque
	param: 	val		value for the link to be added
	pre:	d is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontListDeque(ListDeque *d, TYPE val)
{
	/*FIXME you will write this function */

	/* addLinkBeforeListDeque is called here as a case for adding to the front of the deque exists within it */

	addLinkBeforeListDeque(d, d->head, _createLink(val));
}


/* Runtime Analysis:
	O(1) as it simply makes a single function call.
*/

/* Circularity/Sentinels:
	Circularity and sentinels would not change this function.
*/


/*	Remove the front of the deque.
	Write this function in terms of removeLinkListDeque().

	param: 	d		pointer to the deque
	pre:	d is not null
	pre:	d is not empty
	post:	the front is removed from the deque
*/
void removeFrontListDeque (ListDeque *d) 
{
	/*FIXME you will write this function */

	/* removeLinkListDeque is called here as a case for removing an item from the front of the deque exists within it */

	removeLinkListDeque(d, d->head);

}


/* Runtime Analysis:
	O(1) as it simply makes a single function call.
*/

/* Circularity/Sentinels:
	Circularity and sentinels would not change this function.
*/


/* Remove the back of the deque.
	Write this function in terms of removeLinkListDeque().

	param: 	d		pointer to the deque
	pre:	d is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackListDeque(ListDeque *d)
{
	/*FIXME you will write this function */

	/* removeLinkListDeque is called here as a case for removing an item from the back of the dequeu exists within it */

	removeLinkListDeque(d, d->tail);
}

/* Runtime Analysis:
	O(1) as it simply makes a single function call.
*/

/* Circularity/Sentinels:
	Circularity and sentinels would not change this function.
*/



/* ************************************************************************
	Bag Interface
************************************************************************ */
/*	Returns whether or not the given value is stored in the deque

	param:	d		pointer to the deque
	param:	val		value that we are looking for in the deque
	ret:	1 if val is contained in d, 0 otherwise
*/
int containsListDeque(ListDeque* d, TYPE val)
{
	/*FIXME you will write this function */

	int i;

	DLink* current;

	current = d->head;

	/* iterates through the LL and returns 1 if the value matches at any location */
	for(i = 0; i < d->size; i++)
	{
		if(current->value == val)
		{
			return 1;
		}
		current = current->next;
	}
	return 0;
}


/* Runtime Analysis:
	This is O(N) as it iterates through the list once, meaning its runtime is proportional
	to the size of the list.
*/

/* Circularity/Sentinels:
	Circularity and sentinels would not change, other than sentinels requiring extra pointer work to account for
	head/tail pointing to a sentinel.
*/


/* Removes the first occurrence of the given value from the list.

	param:	d		pointer to the deque
	param:	val		value that we are looking for in the deque
	post:	first occurrence of val is removed from the list
*/
void removeListDeque(ListDeque* d, TYPE val)
{
	/*FIXME you will write this function */

	int i;

	DLink* current;

	current = d->head;

	/* iterates through the LL and runs RemoveLinkListDeque at the current lnk if it matches */
	for(i = 0; i < d->size; i++)
	{
		if(current->value == val)
		{
			removeLinkListDeque(d, current);
			return;
		}
		current = current->next;
	}
	return;
}


/* Runtime Analysis:
	This runtime is O(N) as it iterates through the list searching for a value, then calls a function
	when it finds the value it seeks.
*/

/* Circularity/Sentinels:
	Circularity and sentinels would change little other than pointer adjustment in the case of sentinels.
*/


/* Reverse the deque.  Note that careful swapping of the pointers inside each link
	(next and prev) will cause a reverse, provided head and tail are updated properly.

    param:  d       pointer to the deque
    pre:    d is not null
    post:   the deque is reversed
*/
void reverseListDeque(ListDeque *d)
{
	/*FIXME you will write this function */

	int i;
	DLink* current;
	DLink* temp;

	current = d->head;

	/************************************************************************************\
	 * Imagine a conga line of people.
	 * Suddenly the conga line reverses and all people who previously had their
	 * hands on the shoulders of the person in front of them switch and put their
	 * hands on the shoulders of the person behind them.
	 * Then the person who was at the head of the conga line becomes the tail of the line
	 * and vice versa,
	 * that's what happens in this function 
	\***********************************************************************************/
	for(i = 0; i < d->size; i++)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;

		current = current->prev;
	}

	temp = d->head;
	d->head = d->tail;
	d->tail = temp;

}


/* Runtime Analysis:
	This function is O(N) as it iterates through the list swapping pointers; its runtime is proportional
	to the size of the list and hence has a runtime of O(N).
*/

/* Circularity/Sentinels:
	With circularity and sentinels this function would not change other than adjusting pointers dealing with head and tail.
*/


/*	Print the links in the deque from front to back

	param: 	d		pointer to the deque
	pre:	d is not null
	post: 	the links in the deque are printed from front to back
*/
void printListDeque(ListDeque *q)
{
	DLink* lnk = q->head;
	printf("Size = %d [ ", q->size);
	while(lnk != NULL)
	{
		printf("%c, ", lnk->value->label);
		lnk = lnk->next;
	}
	printf("]\n");
}


/* Runtime Analysis:
	This function iterates through the list, and consequently has a runtime of O(N).
*/

/* Circularity/Sentinels:
	This function's while loop conditions would have to be adjusted in the case of both. With circularity
	the function would endlessly loop around the function looking for NULL, which in the case of circularity cannot happen.
	Instead, examining if the current pointer is identical to the tail pointer is a more effective way of ending the iteration.
	With sentinels, sentinels cannot be printed and provide a convenient place to start and stop printing/other iteration, and
	pointers to head/tail should be adjusted to account for the sentinels' presence.
*/
