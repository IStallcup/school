#include <cstdlib>
#include <iostream>
#include "cn.h"

using namespace std;

/*struct game
{
	char **board;
	int r, c, p;
	char p1;
	char p2;
};*/

bool is_valid_arguments(char **array)
{
	for (int aa = 0; aa < 6; aa++)
	{
		if (!array[aa])
			break;
		if (array[aa][0] == '-')
		{
			if (array[aa][1] == 'p')
			{
				cout << "P: " << array[aa+1][0] << endl;
			}
			if (array[aa][1] == 'c')
			{
				cout << "C: " << array[aa+1][0] << endl;
			}
			if (array[aa][1] == 'r')
			{
				cout << "R: " << array[aa+1][0] << endl;
			}
			if (array[aa][1] != 'p' &&  array[aa][1] != 'c' && array[aa][1] != 'r')
			{
				cout << "Invalid Argument." << endl;
				return false;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	if (is_valid_arguments(argv) == false)
	{
		cout << "Hello" << endl;
	}
}