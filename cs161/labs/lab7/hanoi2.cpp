#include <iostream>

using namespace std;

void show_board(int n_disk, int *board[])
{
	for (int i = 0; i < n_disk; i++)
	{
		for (int q = 0; q < 3; q++)
		{
			cout << board[i][q] << " ";
		}
		cout << endl;
	}
}

void towers(int from_col, int to_col, int *board[], int n_disk)
{
	cout << "Which column move from? ";
	cin >> from_col;
	int col_i = 0;
	for (int i = 0; i < n_disk; i++)
	{
		if( board[i][from_col - 1] > board[i][from_col - 2])
		{
			cout << "ok" << endl;
			break;
		}
		col_i++;
	}
	
	cout << "Which column move to? ";
	
	cin >> to_col;
	for (int i = 0; i < n_disk; i++)
	{
		if (board[i][from_col - 1] > board[i][to_col - 1])
		{
			cout << "ok" << endl;
			break;
		}
	}
}

int main()
{
	cout << "How many disks? ";
	int n_disk;
	cin >> n_disk;
	int *board[3];
	for (int r = 0; r < n_disk; r++)
	{
		board[r] = new int[3];
		board[r][0] = r+1;
	}
	
	cout << "Initial state: " << endl;
	
	int from_col, to_col;
	
	show_board(n_disk, board);
	
	towers(from_col, to_col, board, n_disk);
	
	for (int r = n_disk - 1; r > 0; r--)
	{
		delete board[r];
	}
	
}