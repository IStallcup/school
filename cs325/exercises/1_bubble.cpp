#include <iostream>
#include <stdio.h>
#include <deque>

using namespace std;

deque<int>* sort()
{
	return
}

int main()
{
	deque<int> arry;
	arry.push_back(8);
	arry.push_back(6);
	arry.push_back(7);
	arry.push_back(4);
	arry.push_back(3);
	arry.push_back(5);
	arry.push_back(9);

	for (int i = 0; i < arry.size(); i++)
	{
		cout << arry.at(i) << ", ";
	}
	cout << endl;

	arry = sort(&arry);
	
	for (int i = 0; i < arry.size(); i++)
	{
		cout << arry.at(i) << ", ";
	}
	cout << endl;
}
