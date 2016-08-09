#ifndef DEQUEHELPERS_H
#define DEQUEHELPERS_H

#include <iostream>
#include <deque>
#include <fstream>
#include <cstdlib>

#define DEBUG 1

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

#endif
