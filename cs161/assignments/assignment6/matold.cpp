/*********************************************************************
** Program Filename: matrix.cpp
** Author: Isaac Stallcup
** Date: 11/25/14
** Description: Reads the size of a matrix and its entries from the
** 		user, then combines its entries into a matrix one row/column
** 		smaller than the one entered by the user.
** Input: Size and entries of matrix
** Output: Resulting smaller matrix
*********************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

/*********************************************************************
** Function: show_matrix
** Description: prints a matrix
** Parameters: int **matrix (2 dimensional array), int *numrows (pointer
** 		to dynamically created number of rows), int *numcols (pointer to
** 		dynamically created number of columns)
** Pre-Conditions: **matrix exists, *nunmrows and *numcols > 0
** Post-Conditions: none
*********************************************************************/ 

void show_matrix(int **matrix, int *numrows, int *numcols)
{
	cout << *numrows << " x " << *numcols << " Matrix:" << endl;
	for (int r = 0; r < *numrows; r++)
	{
		for (int c = 0; c < *numcols; c++)
		{
			if (matrix[r][c] > 9)
				cout << matrix[r][c] << " ";
			else cout << matrix[r][c] << "  ";
		}
		cout << endl;
	}
}

/*********************************************************************
** Function: initialize_matrix
** Description: creates matrix with numrows and numcols rows and columns
**		respectively
** Parameters: int **matrix (2 dimensional array), int *numrows (pointer
** 		to dynamically created number of rows), int *numcols (pointer to
** 		dynamically created number of columns)
** Pre-Conditions: **matrix exists, *nunmrows and *numcols > 0
** Post-Conditions: none
*********************************************************************/ 
	
void initialize_matrix(int **matrix, int *numrows, int *numcols)
{
	for (int r = 0; r < *numrows; r++)
	{
		matrix[r] = new int[*numcols];
	}
}

/*********************************************************************
** Function: error_check
** Description: checks an input for errors, does not proceed until input
** 		is free of errors
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: input is a sequence of numbers each between 0 and 9
*********************************************************************/ 

int error_check()
{
	string input;
	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		if (input.at(i) < '0' || input.at(i) > '9')
		{
			cout << "Error: Invalid. Retry:\t";
			cin >> input;
			i = 0;
		}
	}
	return atoi(input.c_str());
}

/*********************************************************************
** Function: get_size
** Description: gets the size of the input matrix
** Parameters: int *numrows (pointer to dynamically created number of rows), 
** 		int *numcols (pointer to dynamically created number of columns)
** Pre-Conditions: none
** Post-Conditions: *numrows and *numcols are not zero
*********************************************************************/ 

void get_size(int *numrows, int *numcols)
{
	cout << "How many rows?\t\t";
	*numrows = error_check();
	if (*numrows == 1)
	{
		cout << "Matrix cannot have 1 row." << endl;
		exit(0);
	}
	cout << "How many columns?\t";
	*numcols = error_check();
	if (*numcols == 1)
	{
		cout << "Matrix cannot have 1 column." << endl;
		exit(0);
	}
}

/*********************************************************************
** Function: get_matrix
** Description: gets entries of initial matrix 
** Parameters: int **matrix (2 dimensional array), int *numrows (pointer
** 		to dynamically created number of rows), int *numcols (pointer to
** 		dynamically created number of columns)
** Pre-Conditions: **matrix exists, *nunmrows and *numcols > 0
** Post-Conditions: each element in the matrix is error checked
*********************************************************************/ 

void get_matrix(int **matrix, int *numrows, int *numcols)
{
	cout << "Entries of Initial Matrix" << endl;
	for (int r = 0; r < *numrows; r++)
	{
		for (int c = 0; c < *numcols; c++)
		{
			cout << "Enter element (" << r << "," << c << "):\t";
			matrix[r][c] = error_check();
		}
	}
}

/*********************************************************************
** Function: calc_it
** Description: iteratively takes each element of the initial array
** 		first by row then by column and then, for each element, 
** 		adds to it the element in the next row, next column and next
** 		row and column, then returns it to the same element in a result
**		array. If this is impossible, it stops.
** Parameters: int **matrix (2 dimensional array), int **result (2 dimensional array), 
** 		int *numrows (pointer to dynamically created number of rows), 
** 		int *numcols (pointer to dynamically created number of columns)
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 

void calc_it(int **matrix, int **result, int *numrows, int *numcols)
{
	cout << "Iteratively calculating result matrix..." << endl;
	cout << "Result Matrix:" << endl;
	for (int r = 0; r <= *numrows; r++)
	{
		if (matrix[r] && matrix[r+1] && r < *numrows)
		{
			for (int c = 0; c <= *numcols; c++)
			{
				if (matrix[r][c] && matrix[r][c+1] && c < *numcols)
				{
					result[r][c] = (matrix[r][c] + matrix[r+1][c]+
									matrix[r][c+1] + matrix[r+1][c+1]);
				}
				else break;
			}
		}
		else break;
	}
}

/*********************************************************************
** Function: clear_result
** Description: sets each element of the result matrix to zero
** Parameters: int **result (2 dimensional array), int *numrows (pointer
** 		to dynamically created number of rows), int *numcols (pointer to
** 		dynamically created number of columns)
** Pre-Conditions: **result exists, *nunmrows and *numcols > 0
** Post-Conditions: each element in the matrix is zero
*********************************************************************/ 

void clear_result(int **result, int *numrows, int *numcols)
{
	cout << "Clearing result matrix..." << endl;
	for (int r = 0; r < *numrows; r++)
	{
		for (int c = 0; c < *numcols; c++)
		{
			result[r][c] = 0;
		}
	}
}

/*********************************************************************
** Function: cols_recursive
** Description: recursively calculates each element in the result matrix
**		as in calc_it
** Parameters: int **result (2 dimensional array), int **matrix (2 diemsional array)
**		int *numrows (pointer to dynamically created number of rows), 
** 		int *numcols (pointer to dynamically created number of columns),
**		numrowsrec (variable counting how many times the function has iterated thru rows)
**		numcolsrec (variable counting how many times the function has iterated thru columns)
** Pre-Conditions: numcolsrec != *numcols
** Post-Conditions: each element in the chosen column of the current row
**		is calculaed as in calc_it
*********************************************************************/ 

int cols_recursive (int **matrix, int **result, int *numrows, int *numcols, int numrowsrec, int numcolsrec)
{
	if (numcolsrec == *numcols)
		return 0;
	result[numrowsrec][numcolsrec] = matrix[numrowsrec][numcolsrec] + matrix[numrowsrec+1][numcolsrec]+
									 matrix[numrowsrec][numcolsrec+1] + matrix[numrowsrec+1][numcolsrec+1];
	return cols_recursive (matrix, result, numrows, numcols, numrowsrec, numcolsrec+1);		
}

/*********************************************************************
** Function: rows_recursive
** Description: recursively iterates through each row, runs cols_recursive for
**		each element in the selected row
** Parameters: int **result (2 dimensional array), int **matrix (2 diemsional array)
**		int *numrows (pointer to dynamically created number of rows), 
** 		int *numcols (pointer to dynamically created number of columns),
**		numrowsrec (variable counting how many times the function has iterated thru rows)
**		numcolsrec (variable counting how many times the function has iterated thru columns)
** Pre-Conditions: numrowsrec != *numrows
** Post-Conditions: each element in the chosen row
**		is calculaed as in calc_it
*********************************************************************/ 

int rows_recursive (int **matrix, int **result, int *numrows, int *numcols, int numrowsrec, int numcolsrec)
{
	if (numrowsrec == *numrows)
		return 0;
	cols_recursive (matrix, result, numrows, numcols, numrowsrec, numcolsrec);
	return rows_recursive(matrix, result, numrows, numcols, numrowsrec+1, numcolsrec);
}

/*********************************************************************
** Function: calc_rec
** Description: runs rows_recursive for the initial matrix; calculates
**		the elements of the result matrix as in calc_it
** Parameters:  int **matrix (2 dimensional array), int **result (2 dimensional array), 
** 		int *numrows (pointer to dynamically created number of rows), 
** 		int *numcols (pointer to dynamically created number of columns)
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 

void calc_rec(int **matrix, int **result, int *numrows, int *numcols)
{
	int numrowsrec = 0;
	int numcolsrec = 0;
	cout << "Recursively calculating result matrix..." << endl;
	cout << "Result Matrix:" << endl;
	rows_recursive (matrix, result, numrows, numcols, numrowsrec, numcolsrec);
}

/*********************************************************************
** Function: calculate_result_matrix
** Description: calculates, iteratively and recursively, the result matrix,
**		clearing it in between and showing the result matrix each time
**		an operation is performed.
** Parameters: int **matrix (2 dimensional array), int **result (2 dimensional array), 
** 		int *numrows (pointer to dynamically created number of rows), 
** 		int *numcols (pointer to dynamically created number of columns)
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 

void calculate_result_matrix(int **matrix, int **result, int *numrows, int *numcols)
{
	calc_it(matrix, result, numrows, numcols);
	show_matrix(result, numrows, numcols);
	
	clear_result(result, numrows, numcols);
	show_matrix(result, numrows, numcols);
	
	calc_rec(matrix, result, numrows, numcols);
	show_matrix(result, numrows, numcols);
}

/*********************************************************************
** Function: set_initial
** Description: initializes, gest the elements of and shows the initial matrix
** Parameters: int **matrix (2 dimensional array), int *numrows (pointer
** 		to dynamically created number of rows), int *numcols (pointer to
** 		dynamically created number of columns)
** Pre-Conditions: none
** Post-Conditions: matrix is initialized, has values
*********************************************************************/ 

void set_initial(int **matrix, int *numrows, int *numcols)
{
	initialize_matrix(matrix, numrows, numcols);
	get_matrix(matrix, numrows, numcols);	
	cout << "Initial Matrix:" << endl;
	show_matrix(matrix, numrows, numcols);
}

/*********************************************************************
** Function: dec_nums
** Description: decrements int *numrows and *numcols
** Parameters: int *numrows (pointer to dynamically created number of rows), 
**		int *numcols (pointer to dynamically created number of columns)
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 

void dec_nums(int *numrows, int *numcols)
{
	*numrows -= 1;
	*numcols -= 1;
}

/*********************************************************************
** Function: del_arrays
** Description: deallocates memory
** Parameters: int **matrix (2 dimensional array), int **result (2 dimensional array), 
** 		int *numrows (pointer to dynamically created number of rows), 
** 		int *numcols (pointer to dynamically created number of columns)
** Pre-Conditions: none
** Post-Conditions: matrix, result, numrows, numcols are deallocated
*********************************************************************/ 

void del_arrays(int **matrix, int **result, int *numrows, int *numcols)
{
	delete matrix;
	delete result;
	delete numrows;
	delete numcols;
}

/*********************************************************************
** Function: main
** Description: runs functions to achieve functionality as described
**		in program header
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: result matrix has been calculated and displayed
**		iteratively and recursively
*********************************************************************/ 

int main()
{
	int *numrows = new int;
	int *numcols = new int;
	get_size(numrows, numcols);
	int **matrix = new int*[*numrows];
	set_initial(matrix, numrows, numcols);
	
	dec_nums(numrows, numcols);
	
	int **result = new int*[(*numrows)- 1];
	initialize_matrix(result, numrows, numcols);
	
	calculate_result_matrix(matrix, result, numrows, numcols);
	
	del_arrays(matrix, result, numrows, numcols);
	
	return 0;	
}





