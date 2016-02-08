#include "./mult_div.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
	char *m = argv[1];
	char *n = argv[2];
	int qcontinue = 1;
	while (qcontinue  != 0)
	{
		run (m, n);
		cout << "Continue? ";
		cin >> qcontinue;
		if (qcontinue != 0)
		{
			reprompt(m, n);
		}
	}
	
}