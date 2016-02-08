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
		addMe->next = d->tail->prev;
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


int main()
{
	ListDeque d;
	initListDeque(&d);
	addFront(&d, createLnk('d'));
	print(&d);
	addBack(&d, createLnk('e'));
	print(&d);
	addFront(&d, createLnk('f'));
	print(&d);
	removeBack(&d);
	print(&d);
	removeFront(&d);
	print(&d);
}