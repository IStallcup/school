#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int pnum;
	cout << "Input a whole number: ";
	cin >> pnum;

	int chkpr = 0;
	for (int iii = 2; iii <= pnum; iii++)
	{
		for (int qqq = 2; qqq <= iii; qqq++)
		{
			if (pnum % qqq == 0 && pnum != qqq)
			{
				cout << pnum << " is not prime." << endl;
				chkpr = 1;
				break;
			}
			
			else if (pnum == qqq)
			{
				cout << pnum << " is prime." << endl;
				chkpr = 1;
				break;
			}
		}

		if (chkpr == 1)
			break;
		if (iii + 1 == pnum || iii == pnum)
		{
			cout << pnum << " is prime." << endl;
			break;
		}

	}
	
	return 0;

}
