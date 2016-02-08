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

bool is_valid_arguments(char *info[])
{
	for (int a = 2; a < 8; a++)
	{
		if (atoi(info[a]) < 0 && info[a] != '-r' && info[a] != '-c' && info[a] != '-p')
			cout << "error" << endl;
	}
	
	/*if (atoi(info[2]) < 1 || atoi(info[4]) < 1 || atoi(info[6]) < 1)
	{
		cout << "Error - Number of rows/columns/pieces is invalid. Exiting." << endl;
		return 0;
	}*/
	
	else return 1;
}

void print_board(game *connect, char *info[])
{
	for (int iii = 0; iii < (*connect).r; iii++)
	{
		cout << iii+1 << "  ";
		for (int jjj = 0; jjj < (*connect).c; jjj++)
		{
			cout << (*connect).board[iii][jjj] << "  ";
		}
		cout << endl;
		if (iii == ((*connect).r - 1))
		{
			cout << "   ";
			for (int hhh = 0; hhh < (*connect).c;  hhh++)
			{
				cout << hhh + 1 << "  ";
			}
			cout << endl;
		}
	}
}

char** create_table(int r, int c)
{
	char **board = new char*[r];
	for (int iii = 0; iii < r; iii++)
	{
		board[iii] = new char[c];
		for (int jjj = 0; jjj < c; jjj++)
		{
			board[iii][jjj] = '.';
		}
	}
		
	return board;
}

void set_game_info(game *connect, char *info[])
{
	
	(*connect).r = atoi(info[2]);
	(*connect).c = atoi(info[4]);
	(*connect).board = create_table((*connect).r, (*connect).c);
}

bool check_winner(game *connect)
{
	
}

void play_game(game *connect)
{
	int turns = 1;
	//while (check_winner(game) == false)
	//{
	//}
}

int main(int argc, char* argv[]) //goes in seperate file
{
	if (is_valid_arguments(argv) != 0 && argc < 8 && argc != 1) //if statement?
	{
		game *connect;
		connect = new game;
		set_game_info(connect, argv);
		print_board(connect, argv);
		
	} else{cout << "Goodbye." << endl;}
	return 0;
}