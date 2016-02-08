#include <stdio.h>
#include <stdlib.h>

typedef struct DLink {
	char value;
	struct DLink* prev;
	struct DLink* next;
} DLink;

struct ListDeque {
	int size;
	DLink* head;
	DLink* tail;
};
typedef struct ListDeque ListDeque;


DLink* createLnk(char val)
{
	DLink* lnk = (DLink*)malloc(sizeof(DLink));
	lnk->value = val;
	lnk->next = NULL;
	lnk->prev = NULL;
	return lnk;
}

DLink* createSen()
{
	DLink* lnk = (DLink*)malloc(sizeof(DLink));
	lnk->prev = NULL;
	lnk->next = NULL;
	return lnk;
}

void initListDeque(ListDeque* d)
{
	d->size = 0;
	DLink* Sen = createSen();
	d->head = Sen;
	d->tail = Sen;
}

void removeBack(ListDeque* d)
{
	if (d->size == 0)
		return;
	else
	{
		free(d->tail->prev);
		d->tail->prev = d->tail->prev->prev;
		d->size--;
	}
}

void removeFront(ListDeque* d)
{
	if (d->size == 0)
		return;
	else
	{
		free(d->head->next);
		d->head->next = d->head->next->next;
		d->size--;
	}
}

void addFront(ListDeque* d, DLink* addMe)
{
	if (d->size == 0)
	{
		addMe->prev = d->head;
		addMe->next = d->tail;
		d->head->next = addMe;
		d->tail->prev = addMe;
		d->size++;
	}
	else
	{
		addMe->prev = d->head;
		addMe->next = d->head->next;
		d->head->next->next->prev = addMe;
		d->head->next = addMe;
		d->size++;
	}
}

void addBack(ListDeque* d, DLink* addMe)
{
	if (d->size == 0)
	{
		addMe->prev = d->head;
		addMe->next = d->tail;
		d->head->next = addMe;
		d->tail->prev = addMe;
		d->size++;
	}
	else
	{
		addMe->next = d->tail;
		addMe->prev = d->tail->prev;
		d->tail->prev->next = addMe;
		d->tail->prev = addMe;
		d->size++;
	}
}

void print(ListDeque *q)
{
	int i;
	DLink* lnk;
	lnk = q->head;
	printf("Size = %d [", q->size);
	for(i = 0; i < q->size + 1; i++)
	{
		printf("%c ", lnk->value);
		lnk = lnk->next;
	}
	printf("]\n");
}

void freeList(ListDeque* d)
{
	if (d->size == 0)
		return;
	else
	{
		int i;
		int toBeRemoved = d->size+1;
		for (i = 0; i < toBeRemoved; i++)
			removeFront(d);
	}
}

void cleanup(ListDeque* d)
{
	free(d->tail);
}

int main()
{
	ListDeque d;
	initListDeque(&d);
	addFront(&d, createLnk('2'));
	print(&d);
	addBack(&d, createLnk('3'));
	print(&d);
	addFront(&d, createLnk('1'));
	print(&d);
	removeBack(&d);
	print(&d);
	removeFront(&d);
	print(&d);
	freeList(&d);
	print(&d);
	addBack(&d, createLnk('a'));
	print(&d);
	addBack(&d, createLnk('b'));
	print(&d);
	addBack(&d, createLnk('c'));
	print(&d);
	addBack(&d, createLnk('d'));
	print(&d);
	addBack(&d, createLnk('e'));
	print(&d);
	addBack(&d, createLnk('f'));
	print(&d);
	addBack(&d, createLnk('g'));
	print(&d);
	addBack(&d, createLnk('h'));
	print(&d);
	addBack(&d, createLnk('i'));
	print(&d);
	addBack(&d, createLnk('j'));
	print(&d);
	addBack(&d, createLnk('k'));
	print(&d);
	addBack(&d, createLnk('l'));
	print(&d);
	addBack(&d, createLnk('m'));
	print(&d);
	addBack(&d, createLnk('n'));
	print(&d);
	addBack(&d, createLnk('o'));
	print(&d);
	addBack(&d, createLnk('p'));
	print(&d);
	addBack(&d, createLnk('q'));
	print(&d);
	addBack(&d, createLnk('r'));
	print(&d);
	addBack(&d, createLnk('s'));
	print(&d);
	addBack(&d, createLnk('t'));
	print(&d);
	addBack(&d, createLnk('u'));
	print(&d);
	addBack(&d, createLnk('v'));
	print(&d);
	addBack(&d, createLnk('w'));
	print(&d);
	addBack(&d, createLnk('x'));
	print(&d);
	addBack(&d, createLnk('y'));
	print(&d);
	addBack(&d, createLnk('z'));
	print(&d);
	freeList(&d);
	print(&d);
	cleanup(&d);
}