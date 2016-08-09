#include <iostream>
#include <deque>
#include "dequeHelpers.h"
#include <algorithm>

void conquer(deque<int>* data, deque<int>* prime)
{
	deque<int> storage;
	deque<int>::iterator diter = data->begin();
	deque<int>::iterator piter = prime->begin();

	cout << "comparing " << *diter << " with " << *piter << endl;

	while (diter != data->end() && piter != prime->end())
	{
		if (*diter < *piter)
		{
			cout << *diter << " < " << *piter << endl;
			storage.push_back(*diter);
			diter++;
		}
		else if (*diter > *piter)
		{
			cout << *diter << " > " << *piter << endl;
			storage.push_back(*piter);
			piter++;
		}
	}
	if (diter == data->end())
		while (piter != prime->end())
		{
			storage.push_back(*piter);
			piter++;
		}
	else if (piter == prime->end())
		while (diter != data->end())
		{
			storage.push_back(*diter);
			diter++;
		}	
	cout << "storage is ";
	printDqe(storage);
	data->clear();
//	reverse(storage.begin(), storage.end());
	deque<int>::iterator siter = storage.begin();
	while (siter != storage.end())
	{
		cout << "adding " << *siter << endl;
		data->push_back(*siter);
		siter++;
	}
	cout << "data now ";
	printDqe(*data);
}

void divide(deque<int>* data)
{
	cout << "dividing deque ";
	printDqe(*data);
	if (data->size() == 1)
		return;
	int temp;
	deque<int> prime;
	cout << "size/2 = " << (data->size() / 2) << endl;
	deque<int>::iterator iter = data->begin();
	int half = data->size() / 2;
	for (int i = 0; i < half; i++)
	{
		cout << "val = " << *iter << endl;
		temp = *iter;
		prime.push_back(temp);
		data->pop_front();
		iter++;	
	}
	divide(&prime);
	divide(data);
	cout << "working with deques ";
	printDqe(*data);
	cout << "and ";
	printDqe(prime);
	conquer(data, &prime); //pointer fuckery required
}

int main()
{
	deque<int> data;
	buildDqe(&data);
	printDqe(data);
	divide(&data);
}
