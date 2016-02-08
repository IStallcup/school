#include <iostream>

using namespace std;

int main()
{
	cout << "Please enter a number: ";
	int num;
	cin >> num;

	for (int iii = 2; iii < num; iii++)
	{
		for (int qqq = 2; qqq <= iii; qqq++)
		{
			if (num%qqq != 0)
			{
				cout << qqq << endl;
	
			}
		}
	}

}
