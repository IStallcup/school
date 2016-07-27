#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>

#define DEBUG 0

using namespace std;

void printDqe(deque<int> data)
{
	if (data.empty())
		return;
	for (deque<int>::iterator iter = data.begin(); iter != data.end(); iter++)
		cout << *iter << " ";
	cout << "\n";
}

//bug: adds 0 to sortme.txt
void buildDqe(deque<int>* data)
{
	fstream input;
	input.open("./sortme.txt", ios::in);
	char* holder;
	int temp;
	while (!input.eof())
	{
		input.getline(holder, 64, '\n');
		temp = atoi(holder);
		if (temp != 0) //bug fix, see above
		{
			if (DEBUG == 1) cout << "adding " << temp << " to deque" << endl;
			data->push_front(temp);
		}
	}
	input.close();
}

deque<int> partition(deque<int>* data)
{
	if (DEBUG == 1) cout << "beginning partition with deque ";
	if (DEBUG == 1) printDqe(*data);
	
	int temp;
	deque<int> prime; //holds secondary deque if needed
	deque<int>::iterator pivot = data->end(); 
	pivot--; //data->end() is empty space at end, fix by decrementing
	
    if (DEBUG == 1) cout << "pivot: " << *pivot << endl;
	while (*data->begin() != *pivot)
	{	
		if (*data->begin() >= *pivot)
		{
			if (DEBUG == 1) cout << *data->begin() << " gt " << *pivot << endl;
			temp = *data->begin();
			data->pop_front();
			data->push_back(temp);
			if (DEBUG == 1) printDqe(*data);
		}
		else if (*data->begin() < *pivot)
		{
			if (DEBUG == 1) cout << *data->begin() << " lt " << *pivot << endl;
			temp = *data->begin();
			data->pop_front();
			prime.push_front(temp);
			if (DEBUG == 1) cout << "main: ";
			if (DEBUG == 1) printDqe(*data);
			if (DEBUG == 1) cout << "prime: ";
			if (DEBUG == 1) printDqe(prime);
		}
	}
	temp = *pivot;
	data->pop_front();	
	if (data->size() > 1)
		partition(data);
	if (prime.size() > 1)
	{
		if (DEBUG == 1) cout << "prime partition: ";
		if (DEBUG == 1) printDqe(prime);
		partition(&prime);
		if (DEBUG == 1) cout << "prime is ";
		if (DEBUG == 1) printDqe(prime);
	}
	if (DEBUG == 1) cout << "re-adding " << temp << endl;
	data->push_front(temp);
	
	if (!prime.empty())
	{
		reverse(prime.begin(), prime.end());
		while (prime.size() > 0)
		{
			temp = *prime.begin();
			if (DEBUG == 1) cout << "prime: pushing " << temp << endl;
			data->push_front(temp);
			prime.pop_front();
		}
	}
	if (DEBUG == 1) cout << "post partition: ";
	if (DEBUG == 1) printDqe(*data);	
	return *data;
}

int main()
{
	deque<int> data;
	buildDqe(&data);
	if (data.size() > 1)
		partition(&data);
	printDqe(data);
}
