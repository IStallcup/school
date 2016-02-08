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

bool check_odd(int **board, int num_disks, int source)
{
	if (board[num_disks][source] % 2 == 0 || board[num_disks][source] == 0)
		return false;
	else return true;
}

int move_disk(int **board, int num_disks, int dest, int source, int num_max_disks)
{
	/*cout << "moving disk" << num_disks << endl;
	if (num_disks == 1)
	{
		board[0][0] = 0;
		board[0][dest] = 1;
	}
	if (check_odd(board, num_disks, source) == true)
	{
		cout << "odd" << endl;
		if (num_max_disks % 2 == 0)
		{
			cout << "Dest is 3" << endl;
			dest = 3;
		}
	
		else 
		{
			cout << "Dest is 2" << endl;
			dest = 2;
		}
		cout << "check_odd: " << check_odd(board, num_disks - 1, dest) << endl;
		board[num_disks-1][dest-1] = num_disks;
		board[num_disks-1][source] = 0;
		show_board(board, num_max_disks);
		source = dest;
		move_disk(board, num_disks-1, dest, source, num_max_disks);
		return 0;
	}
	else if (check_odd(board, num_disks, source) == false)
	{
		cout << "even" << endl;
		if (num_max_disks % 2 == 0)
		{
			cout << "Dest is 3" << endl;
			dest = 3;
		}
	
		else 
		{
			cout << "Dest is 2" << endl;
			dest = 2;
		}
		cout << "check_odd: " << check_odd(board, num_disks - 1, dest) << endl;
		board[num_disks-1][dest] = num_disks;
		board[num_disks-1][source-1] = 0;
		show_board(board, num_max_disks);
		return 0;
	}
	return 0;*/
}

int towers(int **board, int num_disks, int dest, int source, int num_max_disks)
{
	
	if (num_disks == 1)
	{
		move_disk(board, num_disks, dest, source, num_max_disks);
		//show_board(board, num_max_disks);
		return 0;
	}
	towers(board, num_disks -1, dest, source, num_max_disks);
	move_disk(board, num_disks, dest, source, num_max_disks);
	//show_board(board, num_max_disks);
	return towers(board, num_disks -1, dest, source, num_max_disks);
}

int main()
{
	int num_disks;
	cout << "How many disks?" << endl;
	cin >> num_disks;
	int num_max_disks = num_disks;
	int *board[num_disks];
	//declares num_disks rows for board
	for (int i = 0; i < num_disks; i++)
	{
		board[i] = new int[3]; //declares 3 columns per row
		//board[n][q], where n is the row number
		//and q is the column number
	}
	
	initialize_board(board, num_disks);
	
	show_board(board, num_disks);
	
	/*int source = 1, dest;
	
	if (num_disks % 2 == 0)
	{
		cout << "Dest is 3" << endl;
		dest = 2;
	}
	
	else 
	{
		cout << "Dest is 2" << endl;
		dest = 1;
	}
	*/
	//towers(board, num_disks, dest, source, num_max_disks);
	for (int i = 0; i < num_disks; i++)
	{
		board[num_disks][0] = 0;
		board[num_disks][1] = num_disks;
	}
	show_board(board, num_disks);
}