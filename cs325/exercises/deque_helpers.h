#include <iostream>

using namespace std;

void printDeque(deque<int> dqe)
{
	for (int i = 0; i < dqe.size(); i++)
	{
		cout << dqe.at(i) << " ";
	}
	cout << endl;
}
