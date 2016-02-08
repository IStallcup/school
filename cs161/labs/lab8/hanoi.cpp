#include <iostream>

using namespace std;

void showboard(int **board, int numdisk)
{
	for (int l = 0; l < numdisk; l++)
	{
		for (int L = 0; L < 3; L++)
		{
			cout << board[l][L];
		}
		cout << endl;
	}
}

int solve(int **board, int numdisk)
{
	int source, dest, srow = 0, drow = 0, err;
	bool solved = false;
	while (solved = false)
	{
		showboard(board, numdisk);
		cout << "Which line move from? ";
		cin >> source;
		cout << "Which line move to? ";
		cin >> dest;
		while (board[srow][source] == 0)
		{
			if (srow == numdisk)
			{
				cout << "ERROR" << endl;
				err = 1;
				break;
			}
			srow++;
		}
		cout << "Moving element " << board[srow][source] << "from row " << srow << " and column " << source << "." << endl;
		if (err == 1)
			break;
	}
	if (err == 1)
		return 2;
}

int main()
{
	cout << "How many disks? ";
	int numdisk;
	cin >> numdisk;
	
	int *board;
	
	for (int i = 0; i < numdisk; i++)
	{
		board[i] = new int[3];
	}
	
	for (int q = 0; q < numdisk; q++)
	{
		board[q][0] = q + 1;
	}
	
	
	for (int r = numdisk - 1; r > 0; r--)
	{
		delete board[r];
	}

	return 0;
}