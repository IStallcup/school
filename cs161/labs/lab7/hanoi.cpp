#include <iostream>

using namespace std;

void show_board(int **board, int num_disks)
{
	for (int q = 0; q < num_disks; q++)
		{
			for (int l = 0; l < 3; l++)
			{
				cout << board[q][l];
			}
			cout << endl;
		}
}

void initialize_board(int **board, int num_disks)
{
	int b = 1;
	for (int m = 0; m < num_disks; m++)
	{
		board[m][0] = b;
		b++;
	}
}

int main()
{
	int num_disks;
	cout << "How many disks?" << endl;
	cin >> num_disks;
	
	int *board[num_disks];
	for (int i = 0; i < num_disks; i++)
	{
		board[i] = new int[3];
	}
	
	
	
	initialize_board(board, num_disks);
	
	show_board(board, num_disks);
	
}
