#include <iostream>
#include <stdio.h>
#include <deque>

using namespace std;

void insert(deque<int>* sortme, int temp)
{
	//can I make this recursive? deviation from example given in class is large...
	//probably not.
	int idx = 0;
	int slop[sortme->size()];
	cout << "inserting " << temp << endl;
	for (int i = 0; i < sortme->size(); i++)
	{
		if (sortme->at(i) > temp)
			cout << "pos " << i << " > temp" << endl;
		else
			idx++;
	}

	cout << "insert temp at position " << idx << endl;	
	if (idx == 0)
		sortme->push_front(temp);	
	else if (idx == sortme->size())
		sortme->push_back(temp);
	//need to fix case where item belongs in the middle of
	//list, I think... think more on this
	else
	{
		for (int i = 0; i < idx; i++)
		{
			slop[i] = sortme->front();
			sortme->pop_front();
			cout << slop[i] << endl;
		}
		sortme->push_front(temp);
		for (int i = idx - 1; i >= 0; i--)
		{
			if (slop[i]) //extra protection from inserting garbage
				sortme->push_front(slop[i]);
		}
	}

	cout << "array: ";
	for (int i = 0; i < sortme->size(); i++)
	{
		cout << sortme->at(i) << ", ";
	}
	cout << endl;
}

deque<int> sort(deque<int>* sortme)
{
	if (sortme->size() == 1)
		return *sortme;
	
	int temp = sortme->at(sortme->size() - 1);
	cout << "temp = " << temp << endl;
	sortme->pop_back();

	sort(sortme);
	
	insert(sortme, temp);

	return *sortme;
}

int main()
{
	deque<int> sortme;
	sortme.push_back(8);
	sortme.push_back(6);
	sortme.push_back(7);
	sortme.push_back(4);
	sortme.push_back(3);
	sortme.push_back(5);
	sortme.push_back(9);

	for (int i = 0; i < sortme.size(); i++)
	{
		cout << sortme.at(i) << ", ";
	}
	cout << endl;

	sortme = sort(&sortme);
	
	for (int i = 0; i < sortme.size(); i++)
	{
		cout << sortme.at(i) << ", ";
	}
	cout << endl;
}
