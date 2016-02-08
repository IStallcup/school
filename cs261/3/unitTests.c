#include <stdio.h>
#include <stdlib.h>
#include "c_unit.h"
#include "ListDeque.h"

/* tests removeFrontListDeque() on an empty list */
void testFreeEmpty(UnitTestResult* result)
{
	/* freeListDeque() tests removeFrontListDeque() for 
	the entire list. */
	
	ListDeque d;
	initListDeque(&d);
	freeListDeque(&d);
	
	if (d.head != NULL)
		result->errMsg = "head is not NULL";
	else if (d.tail != NULL)
		result->errMsg = "tail is not NULL";
	else
		result->success = 1;
}

/* tests functionality of removeLinkListDeque(),
	removeBackListDeque() and removeFrontListDeque()
	by populating a list TEST then removing head,
	removing tail, then calling removeBack and removeFront. */
void testRemoveFull(UnitTestResult* result)
{
	ListDeque d;
	initListDeque(&d);
	
	TYPE third = 'T';
	TYPE second = 'E';
	TYPE first = 'S';
	
	TYPE testone;
	TYPE testtwo;
	TYPE testthree;
	
	addFrontListDeque(&d, first);
	addFrontListDeque(&d, second);
	addFrontListDeque(&d, third);
	addBackListDeque(&d, third);
	
	removeLinkListDeque(&d, d.head);
	testone = d.head->value;
	
	removeLinkListDeque(&d, d.tail);
	testtwo = d.head->value;
	
	removeBackListDeque(&d);
	testthree = d.tail->value;
	
	removeFrontListDeque(&d);
	
	if (testone == third)
		result->errMsg = "First value not removed";
	else if (testtwo == third)
		result->errMsg = "Last value not removed";
	else if (testthree == first)
		result->errMsg = "error in removeBackListDeque()";
	else if (!isEmptyListDeque(&d))
		result->errMsg = "error in removeFrontListDeque()";
	else
		result->success = 1;
	
	
}
 /* tests whether the list STRESSED will be correctly reversed into
	DESSERTS by comparing the reversed list with the string DESSERTS */
void testreverse(UnitTestResult* result)
{
	ListDeque d;
	initListDeque(&d);
	
	TYPE first = 'S';
	TYPE second = 'T';
	TYPE third = 'R';
	TYPE fourth = 'E';
	TYPE fifth = 'D';
	
	TYPE* word = malloc(sizeof(TYPE)*8);
	word[0] = fifth;
	word[1] = fourth;
	word[2] = first;
	word[5] = third;
	word[6] = second;
	word[3] = word[2];
	word[4] = word[1];
	word[7] = word[2]; /*spells DESSERT */
	
	TYPE* comp = malloc(sizeof(TYPE)*8);
	
	addBackListDeque(&d, first);
	addBackListDeque(&d, second);
	addBackListDeque(&d, third);
	addBackListDeque(&d, fourth);
	addBackListDeque(&d, first);
	addBackListDeque(&d, first);
	addBackListDeque(&d, fourth);
	addBackListDeque(&d, fifth);
	
	reverseListDeque(&d);
	
	DLink* temp;
	temp = d.head;
	
	comp[0] = temp->value;
	temp = temp->next;
	comp[1] = temp->value;
	temp = temp->next;
	comp[2] = temp->value;
	temp = temp->next;
	comp[3] = temp->value;
	temp = temp->next;
	comp[4] = temp->value;
	temp = temp->next;
	comp[5] = temp->value;
	temp = temp->next;
	comp[6] = temp->value;
	temp = temp->next;
	comp[7] = temp->value;
	
	int i;
	
	for (i = 0; i < 8; i++)
	{
		if (comp[i] != word[i])
			result->errMsg = "Reverse failed";
		else if (i == 7)
			result->success = 1;
	}
}

void testRemoveMiddle(UnitTestResult* result)
{
	ListDeque d;
	initListDeque(&d);
	
	TYPE robert = 'L';
	TYPE johnp = 'Z'; 
	TYPE johnb = 'E';
	TYPE jimmy = 'P';
	
	TYPE testvar1;
	TYPE testvar2;
	
	addBackListDeque(&d, robert);
	addBackListDeque(&d, johnp);
	addBackListDeque(&d, johnb);
	addBackListDeque(&d, jimmy);
	
	removeLinkListDeque(&d, d.head->next->next);
	
	testvar1 = d.head->next;
	testvar2 = d.tail->prev;
	
	if (testvar1 != testvar2)
		result->errMsg = "Incorrect removal";
	else
		result->success = 1;
}

void testAddMiddle(UnitTestResult* result)
{
	ListDeque d;
	initListDeque(&d);
	
	TYPE nevermore1 = 'R';
	TYPE nevermore2 = 'A';
	TYPE nevermore3 = 'V';
	TYPE nevermore4 = 'E';
	TYPE nevermore5 = 'N';
	
	TYPE frontTest;
	TYPE backTest;
	TYPE middleTest;
	
	addBackListDeque(&d, nevermore1);
	addBackListDeque(&d, nevermore2);
	DLink* temp = d.head->next;
	addLinkAfterListDeque(&d, temp, _createLink(nevermore3));
	addBackListDeque(&d, nevermore5);
	temp = temp->next->next;
	addLinkBeforeListDeque(&d, temp, _createLink(nevermore4));
	/* printListDeque(&d); */
	
	frontTest = d.head->value;
	backTest = d.tail->value;
	middleTest = d.tail->prev->prev->value;
	if (frontTest != nevermore1)
		result->errMsg = "head is incorrect";
	else if (backTest != nevermore5)
		result->errMsg = "tail is incorrect";
	else if (middleTest != nevermore3)
		result->errMsg = "middle is incorrect";
	else
		result->success = 1;
	
}

void custom_tests_master()
{
	int testNum = 1;
	
	UnitTestResult testResults;
	
	printf("\nCustom Testing Initiated\n****************************************\n");
	
	initTestResult(&testResults, testNum++, "testFreeEmpty");
	testFreeEmpty(&testResults);
	printResults(&testResults);
	
	initTestResult(&testResults, testNum++, "testRemoveFull");
	testRemoveFull(&testResults);
	printResults(&testResults);
	
	initTestResult(&testResults, testNum++, "testreverse");
	testreverse(&testResults);
	printResults(&testResults);
	
	initTestResult(&testResults, testNum++, "testAddMiddle");
	testAddMiddle(&testResults);
	printResults(&testResults);
	
	initTestResult(&testResults, testNum++, "testRemoveMiddle");
	testRemoveMiddle(&testResults);
	printResults(&testResults);
}