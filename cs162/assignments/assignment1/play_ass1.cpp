/******************************************************
** Program: ass1.exe
** Author: Isaac Stallcup
** Date: 04/08/2015
** Description: Using command line input, structs and various
**		pointers, plays connect n with the user.
** Input: -r X -c Y -p Z, where -r -c and -p are options for
**		rows, columns and contiguous pieces needed to win respectively
**		and X, Y and Z are integers.
** Output: prints the board after a move, then when a player has won
**		loop until no longer desired.
******************************************************/

#include "./ass1.h"
#include <iostream>

using namespace std; 											//standard namespace

int main(int argc, char *argv[])
{
	if (argc < 7 || argc > 7)									//if arguments do not include
	{															//-c X -r Y -p Z and the .exe
		cout << "Error: insufficient arguments." << endl;		//there are too few arguments,
		return 0;												//so program ends.
	}
	int choice = 1;
	while (choice != 0)											//continue while user chooses to
	{
		if (run_main(argv) == 0)								//runs program's functions
			break;												//if return 0 (args invalid),
																//exit the choice loop
		cout << "Play again? 1 yes 0 no: ";
		cin >> choice;											//get user choice once game
	}															//has ended
	return 0;
}