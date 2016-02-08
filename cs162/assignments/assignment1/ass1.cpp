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

#include <iostream>
#include <cstdlib>

using namespace std; 											//standard namespace	

struct game {													//required struct
	char **board;
	int r, c, p;
	char p1;
	char p2;
};

bool is_valid_arguments(char *info[])							//required function
{
	for (int a = 1; a < 8; a++)									//iterates 8x as there are max
	{															//7 accepted command line arguments
		if (!info[a])
			break;
		if (*info[a] == '-')									//checks each for option operator -...
		{
			if (info[a][1] != 'p' && info[a][1] != 'c' && info[a][1] != 'r')	//...then checks the next character to see
			{																	//if the option is valid.
				cout << "Error: Invalid Argument at position " << a << "; alpha error." << endl;
				return false;									//if option invalid, return false.
			}
		}
		if (atoi(info[a]) <= 1 && *info[a] != '-')				//if the argument is not an option and
		{														//less than or equal to one, exit.
			cout << "Error: Invalid Argument at position " << a << "; num error." << endl;
			return false;
		}
	}
	return true;												//if no errors, return true.
}

void print_board(game *connect)									//function to print board.
{
	for (int e = 0; e < (*connect).r; e++)
	{
		for (int f = 0; f < (*connect).c; f++)
		{
			cout << (*connect).board[e][f] << " ";
		}
		cout << endl;
	}
}

char **create_table(int rows, int cols)							//required function
{
	char **board = new char*[rows];								//creates array of pointers for each row
	for (int c = 0; c < rows; c++)								
	{															//creates array of chars for each column
		board[c] = new char[cols];								//equal to number of rows
		for (int d = 0; d < cols; d++)
		{
			board[c][d] = '.';									//sets each element in board to '.'
		}
	}
	return board;												//return newly created board
}

void set_game_info(game *connect, char *info[])					//required function
{
	for (int b = 0; b < 8; b++)
	{
		if (!info[b])											//if no argument at position,
			break;												//exit loop (for error cases)
		if (*info[b] == '-')									//if there is an option detected...
		{
			if (info[b][1] == 'p')								//...and it is p, set # pieces to the next arg
				(*connect).p = atoi(info[b+1]);
			if (info[b][1] == 'r')								//...and it is r, set # rows to the next arg
				(*connect).r = atoi(info[b+1]);
			if (info[b][1] == 'c')								//...and it is c, set # columns to the next arg
				(*connect).c = atoi(info[b+1]);
		}
	}
	(*connect).p1 = '1';										//player 1 will have 1 as a playing piece
	(*connect).p2 = '2';										//player 2 will have 2 as a playing piece
	(*connect).board = create_table((*connect).r, (*connect).c);//runs function to generate board
}

bool check_rows(game *connect, int sameness)
{
	char *row = new char[(*connect).c];							//creates new array for a row
																//with # elements equal to the # columns
	for (int nrows = 0; nrows < (*connect).r; nrows++)			//for each row...
	{
		sameness = 0;
		for (int ncols = 0; ncols < (*connect).c; ncols++)		//iterate thru the columns and...
		{
			row[ncols] = (*connect).board[nrows][ncols];		//set the new row array's column'th element 
																//to be the current element of the board
			if (row[ncols] == row[ncols-1] && row[ncols] != '.')//then if this new element is the same as the previous,
			{													//increment the "sameness"
				sameness++;
				if ((sameness + 1) == (*connect).p)				//if sameness is equal to # pieces needed to win,
				{												//return that we have a winner.
					return true;
				}
			}
		}
	}
	delete[] row;
	return false;
}

bool check_cols(game *connect, int sameness)
{
	char *col = new char[(*connect).r];							//creates new array for a column
																//with # elements equal to the # rows
	for (int ncols = 0; ncols < (*connect).c; ncols++)			//for each column...
	{
		sameness = 0;
		for (int nrows = 0; nrows < (*connect).r; nrows++)		//iterate thru the rows and...
		{
			col[nrows] = (*connect).board[nrows][ncols];		//set the new column array's row'th element 
																//to be the current element of the board
			if (col[nrows] == col[nrows-1] && col[nrows] != '.')//then if this new element is the same as the previous,
			{													//increment the "sameness"
				sameness++;
				if ((sameness + 1) == (*connect).p)				//if sameness is equal to # pieces needed to win,
				{												//return that we have a winner.
					return true;
				}
			}
		}
	}
	delete[] col;
	return false;
}

bool check_diag(game *connect, int sameness)
{
	char *diag = new char[(*connect).r];						//create new array for storing a diagonal.
	int rowmax = (*connect).r;									//create max # rows variable, to be used in function
	int colmax = (*connect).c * 2;								//create max # cols varabiel, equal to 2x the number of columns to aid in diagonal checking
	for (int ncols = 0; ncols < colmax; ncols++)				//iterate thru the columns
	{
		sameness = 0;											//reset sameness
		
		for (int nrows = 0; nrows < rowmax; nrows++)			//iterate thru each column's row
		{
			diag[ncols + nrows]	 = (*connect).board[nrows][ncols + nrows];	//set the diagonal array element equal to the current iterated board element
			//cout << ncols + nrows << ": " << diag[ncols + nrows] << " ";
			if (diag[ncols + nrows] == diag[ncols + nrows - 1]				//if the diagonal element is the same as the previous...
			&& (diag[ncols + nrows] != '.' &&( diag[ncols + nrows]			//and the diagonal element is nonempty, and filled with a player piece...
			== (*connect).p1 || diag[ncols + nrows] == (*connect).p2)))
			{										
				sameness++;										//iterate sameness, then if sameness = p exit with winner.
				if (sameness + 1 == (*connect).p)
				{
					return true;
				}
			}
		}
		
		//*************************************NOTE*************************************
		//Below is failed attempt, kept for own use.
		//******************************************************************************
		
		
		
		
		//cout << endl;
		
		//rowmax--;
		
		/*diag[ncols] = (*connect).board[0][ncols];
		cout << ncols << ": " << diag[ncols] << " ";
		
		diag[ncols + 1] = (*connect).board[1][ncols+1];
		cout << ncols + 1 << ": " << diag[ncols + 1] << " ";
		
		diag[ncols + 2] = (*connect).board[2][ncols+2];
		cout << ncols + 2 << ":	 " << diag[ncols + 2] << " ";
		
		diag[ncols + 2] =*/ 
		
		/*if ((*connect).board[1][ncols-1] == '.' || (*connect).board[1][ncols-1] == (*connect).p2 || (*connect).board[1][ncols-1] == (*connect).p1)
		{
			diag[ncols-1] = (*connect).board[0][ncols];
			cout << ncols + 1 << ": " << diag[ncols-1] << " ";
		}
		if ((*connect).board[2][ncols-2] == '.' || (*connect).board[2][ncols-2] == (*connect).p2 || (*connect).board[2][ncols-2] == (*connect).p1)
		{
			diag[ncols+0] = (*connect).board[1][ncols - 1];
			cout << ncols << ": " << diag[ncols+0] << " ";
		}
		if ((*connect).board[3][ncols-3] == '.' || (*connect).board[3][ncols-3] == (*connect).p2 || (*connect).board[3][ncols-3] == (*connect).p1)
		{
			diag[ncols+1] = (*connect).board[2][ncols - 2];
			cout << ncols << ": " << diag[ncols+1] << " " << endl;
		}
		else cout << endl;*/
		//cout << ncols + 1 << ": " << (*connect).board[0][ncols] << " " << ncols << ": " << (*connect).board[1][ncols - 1] << endl;
	}
	
	
	delete[] diag;
	return false;
}

bool check_winner(game *connect)							//required function
{
	int sameness;											//creates sameness
	if (check_rows(connect, sameness) == true				//if won by rows, cols or diag return true
	|| check_cols(connect, sameness) == true
	|| check_diag(connect, sameness) == true)
		return true;
	return false;
}

int turncount(game *connect, int turns)					//increment turns; if turns = rows*cols, board is full
{
	if (turns == (*connect).r * (*connect).c)
		{
			cout << "Board is full." << endl;
			return 0;
		}
	cout << "Turn " << turns + 1 << endl;
}

void check_player(game *connect, int rowsel, int choice, int turns)
{
	if ((*connect).board[rowsel][choice] == '.')			//if the selected place is empty...
	{
		if (turns % 2 == 0)									//and if turns is even, p1 is going so place 1
		{
			(*connect).board[rowsel][choice] = (*connect).p1;
		}
		if (turns % 2 != 0)									//and if turns is odd, p2 is going so place 2
		{
			(*connect).board[rowsel][choice] = (*connect).p2;
		}
	}
}

void check_full(game *connect, int choice, int turns)
{
	int rowsel = ((*connect).r - 1);					//chooses rowsel to be # rows - 1 (iterates to)
	while ((*connect).board[rowsel][choice] != '.')		//while the selected place in board is not empty
	{
		rowsel--;										//decrement the selected *row*.
		if (rowsel == -1)								//if we've run out of places in a column that are empty, ask for another column.
		{
			cout << "Column is full. Select another." << endl;
			cin >> choice;
			choice--;
			rowsel = ((*connect).r - 1);
		}
	}
	check_player(connect, rowsel, choice, turns);		//place piece
}

void play_game(game *connect)								//required function
{
	cout << "Please select a column to place your piece in." << endl;
	int turns = 0;
	while (check_winner(connect) == false)
	{
		if (turncount(connect, turns) == 0) break;
		int choice;
		cin >> choice;										//cin user choice
		
		while (choice > (*connect).c)						//if invalid, error message
		{
			cout << "Invalid column. Try again. " << endl;
			cin >> choice;
		}
		choice--;											//choice is 1 more than the array addressed column
		check_full(connect, choice, turns);					//checks if column is full; places piece
		turns++;											//# turns goes up
		print_board(connect);								//print board
	}
	if (turns != (*connect).r * (*connect).c)				//if we have exited loop and the board is not full, someone has won
		cout << "Player has won!" << endl;
	
}

void delete_table(game *connect)							//required function
{
	for (int c = 0; c < (*connect).r; c++)					//deletes memory allocated by program
	{
		delete[] (*connect).board[c];
	}
	delete[] (*connect).board;
	(*connect).board = 0;
}

int run_main(char* argv[])									//runs main functionality of program
{
	if (is_valid_arguments(argv) == false) return 0;
	game *connect;
	connect = new game;
	set_game_info(connect, argv);
	print_board(connect);
	play_game(connect);
	delete_table(connect);
	delete connect;
	connect = 0;
}

/*int main(int argc, char *argv[])
{
	int choice = 1;
	while (choice != 0)
	{
	if (is_valid_arguments(argv) == false)
		return 0;
	game *connect;
	connect = new game;
	set_game_info(connect, argv);
	print_board(connect);
	//while (check_winner(connect) == false)
	//{
		play_game(connect);
	//}
	
	delete_table(connect);
	
	delete connect;
	connect = 0;
	
	cout << "Play again? 1 yes 0 no: ";
	cin >> choice;
	}
	
	cout << "Goodbye." << endl;
}*/