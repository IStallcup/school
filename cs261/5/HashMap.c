#include "HashMap.h"
#include <stdlib.h>
#include <stdio.h>

/* ************************************************************************
	Various Hashing functions
************************************************************************ */
int _hashFunction1(char* str)	
{
	int i;
    int result = 0;

	for (i = 0; str[i] != '\0'; i++){
        result += str[i];
	}
    return abs(result);
}

int _hashFunction2(char* str)
{
	int i;
    int result = 0;

	for (i = 0; str[i] != '\0'; i++){
        result += i * str[i];
	}
    return abs(result);
}

int _hashFunction3(char* str)
{
	int i;
    int result = 0;
	int c = 33;

	for (i = 0; str[i] != '\0'; i++){
        result += c * str[i];
		c *= c;	
	}
    return abs(result);
}

int _hashFunction4(char* str)
{
	int i;
    int result = 5381;

	for (i = 0; str[i] != '\0'; i++){
        result = 33*result + str[i];
	}
    return abs(result);
}

int _hashFunction5(char* str)
{
	int i;
    int result = 0;

	for (i = 0; str[i] != '\0'; i++){
        result -= (result << 4)^(result >> 28)^str[i];
	}
    return abs(result);
}

/* Function which is responsible for choosing which hash function
	gets executed, returns the result from that hash function.
	param: str			The string to be hashed
	param: hashChoice	The number of the hash function to be called
	ret:	result from hashing str given the appropriate hash function,
			0 if hashChoice was not in the legal range [1-5] ([1-6] if
			doing the extra credit) 

*/
int _hash(char* str, int hashChoice)
{
	switch(hashChoice)
	{
	case 1:
		return _hashFunction1(str);
	case 2:
		return _hashFunction2(str);
	case 3:
		return _hashFunction3(str);
	case 4:
		return _hashFunction4(str);
	case 5:
		return _hashFunction5(str);
	default:
		printf("************************\nINVALID HASH CHOSEN\n************************\n");
		return 0;
	}
}

/* Responsible for setting up the hash map
	param:	hm			The hash map to be initialized
	param:	tableSize	Number of chains (linked lists) which should be stored
						in the array representing the hash map.
	param: hashChoice	the number of the hash function that we would like
						to use when performing operations on the hash map.
	post: An array of linked lists has been dynamically allocated
	post: Each linked list in the array has been initialized
	post: tableSize, hashChoice, and numItems are initialized
 */
void initHashMap(HashMap* hm, int tableSize, int hashChoice)
{
	int i;
	hm->table = (ListDeque*)malloc(sizeof(ListDeque)*tableSize);
	for (i = 0; i < tableSize; i++)
	{
		initListDeque(&hm->table[i]);
	}
	hm->tableSize = tableSize;
	hm->numItems = 0;
	hm->hashChoice = hashChoice;
}

/*	Responsible for freeing the memory associated with the hash map
	param:	hm		The hash map to be released
	
	post: the key stored within each link of the linked list is released
	IMPORTANT!!!!!!!!!!!! This is due to the fact that getWord is mallocing
	space for the strings representing keys for this assignment.
	This code is not general, but should be placed here anyway.
	
	post: each linked list in the array of linked lists is released
	post: the array of linked lists itself is released
*/
void freeHashMap(HashMap* hm)
{
	int i;
	DLink* tempLnk;
	for (i = 0; i < hm->tableSize; i++)
	{
		
		tempLnk = hm->table[i].head;
		while (tempLnk)
		{
			free(tempLnk->value.key);
			tempLnk = tempLnk->next;
		}
	}
	free(hm->table);
	hm->table = NULL;
}

/*	This function will insert items into the hash map.
	If duplicate keys are added, the old map element(key, value pair)
	should be overwritten.
	IMPORTANT!!!!!!!!! in the case of a duplicate add, be sure to free the key
	associated with the element because it was dynamically allocated by getWord.
	This code is not general, but should be placed here anyway.
	
	param: hm		hash map to perform the insert in
	param: toAdd	Element to add to the map.  Note that this type
					should conform to the type stored in the linked list
	post: the element has been added to the collection and properly book-kept??
*/
void insertHashMap(HashMap* hm, TYPE toAdd)
{
	int tempHash = _hash(toAdd.key, hm->hashChoice) % hm->tableSize;
	if (toAdd.value == 1)
	{
		addBackListDeque(&hm->table[tempHash], toAdd);
		hm->numItems++;
		return;
	}
	DLink* tempLnk = hm->table[tempHash].head;
	MapElement* tempElement = atHashMap(hm, toAdd.key);
	while (tempLnk)
	{
		if (tempElement == &tempLnk->value)
		{
			removeLinkListDeque(&hm->table[tempHash], tempLnk);
			tempLnk->value.key = NULL;
			free(tempLnk->value.key);
			tempLnk->value.key = NULL;
			addBackListDeque(&hm->table[tempHash], toAdd);
		}
		tempLnk = tempLnk->next;
	}
	hm->numItems++;
}

/*	This function is responsible for returning the element(key, value pair)
	associated with a particular key, if it exists
	param: hm		hasm map to perform the lookup in
	param: key		the key to look up in the hash map
	ret:	pointer to the map element where the argument key is found if it exists
			NULL otherwise
	post:	none
*/
MapElement* atHashMap(HashMap* hm, KeyType key)
{
	int tempHash = _hash(key, hm->hashChoice) % hm->tableSize;
	if (hm->table[tempHash].size == 0)
		return NULL;
	DLink* tempLnk = hm->table[tempHash].head;
	while (tempLnk)
	{
		if (strcmp(tempLnk->value.key, key) == 0)
			return &tempLnk->value;
		tempLnk = tempLnk->next;
	}
	return NULL;
}

/*	This function is responsible for removing the argument key form the argument hash table
	(if it exists)
	
	param: hm		The hash map to have a key (potentially) removed from
	param: key		the key of the element which we would like to remove
	post:	if the key was not found, one
			otherwise, the map element (key, value pair) has been removed
			from the hashMap, and the map is properly book-kept??
			
	IMPORTANT!!!!!!!!!!!! Due to the fact that getWord is mallocing
	space for the strings representing keys for this assignment, this function needs
	to free the key stored in the map element.
	This code is not general, but should be placed here anyway.
*/
void removeHashMap(HashMap* hm, KeyType key)
{
	int i;
	MapElement* removeMe;
	DLink* tempLnk;
	for (i = 0; i < hm->tableSize; i++)
	{
		removeMe = atHashMap(hm, key);
		if (removeMe)
		{
			tempLnk = hm->table[i].head;
			while (tempLnk)
			{
				if (strcmp(key, tempLnk->value.key) == 0)
				{
					removeLinkListDeque(&hm->table[i], tempLnk);
					free(tempLnk->value.key);
					hm->numItems--;
					return;
				}
				tempLnk = tempLnk->next;
			}
		}
	}
}

/*	Indicates the length of the longest chain in the argument hashmap	
	param:	hm		hash table to find the longest chain in
	ret:	the length of the longest chain in the hash table
*/
int longestChain(HashMap* hm)
{
	int chainMax = 0;
	int i;
	for (i = 0; i < hm->tableSize; i++)
	{
		if (hm->table[i].size > chainMax)
			chainMax = hm->table[i].size;
	}
	return chainMax;
}

/*	Indicates the number of empty buckets contained in the argument hashmap	
	param:	hm		hash table to count the number of empty buckets in
	ret:	the number of buckets contained in the hash table which are empty.
*/
int emptyBuckets(HashMap* hm)
{
	int numBuckets = 0;
	int i;
	for (i = 0; i < hm->tableSize; i++)
	{	
		if (hm->table[i].size == 0)
			numBuckets++;
	}
	return numBuckets;
}

/*	Indicates the number of collisions that have occured upon insertion into this
	hash table 
	
	Note: You do not need to perform bookkeeping on this as inserts come, you can 
	calculate this based on the length of the chains.
	Ex. A chain of length 2 has had 1 collision
	
	param:	hm		hash table to count the number of collisions upon insert
	ret:	the number of collisions that have occured as a result of insertion
*/
int numCollisions(HashMap* hm)
{
	int numCols = 0;
	int i;
	for (i = 0; i < hm->tableSize; i++)
	{
		if (hm->table[i].size != 0)
			numCols += hm->table[i].size - 1;
	}
	return numCols;
}

/*	Print useful information about the hash map
	param:	hm				map for which we would like to print contents/statistics
	param:	showBuckets		Indicates whether or not we should print the contents
	post:	statistics have been printed, perhaps contents of the hash map
*/
void printHashMap(HashMap* hm, int showBuckets)
{
	int i;
	if(showBuckets)
		for(i = 0; i < hm->tableSize; ++i)
			printListDeque(&hm->table[i]);
		
	printf("\nHash Table Size: %d\n", hm->tableSize);
	printf("Number of items: %d\n", hm->numItems);
	printf("Hash Function Choice: %d\n", hm->hashChoice);
	printf("Load Factor: %f\n", (float)hm->numItems/(float)hm->tableSize);
	printf("Longest Chain: %d\n", longestChain(hm));
	printf("%% of Buckets Empty: %f\n", (float)emptyBuckets(hm)/(float)hm->tableSize);
	printf("%% of inserts resulting in a collision: %f\n", (float)numCollisions(hm)/(float)hm->numItems);
	
}