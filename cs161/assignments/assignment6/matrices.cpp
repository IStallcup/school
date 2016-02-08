/*********************************************************************
** Program Filename: matrices.cpp 
** Author: Isaac Stallcup
** Date: 12/4/2014
** Description: Reads the size of a matrix and its entries from the
** 		user, then combines its entries into a matrix one row/column
** 		smaller than the one entered by the user.
** Input: Size and entries of matrix
** Output: Resulting smaller matrix
*********************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;


//I used this form instead of the given form, as in my view
//a more efficient use of structs is to create a data structure
//for each matrix and use it to hold information about the result
//and initial matrix.

struct matrix_define
{
	int *numrows;
	int *numcols;
	int **matrix;
};

/*********************************************************************
** Function: show_matrix
** Description: displays a matrix
** Parameters: matrix_define changeling (placeholder struct)
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 

void show_matrix(matrix_define changeling)
{
	cout << *changeling.numrows << " x " << *changeling.numcols << " Matrix:" << endl;
	for (int r = 0; r < *changeling.numrows; r++)
	{
		for (int c = 0; c < *changeling.numcols; c++)
		{
			if (changeling.matrix[r][c] > 9)
			//space helps format 2 digit numbers
				cout << changeling.matrix[r][c] << " ";
			else cout << changeling.matrix[r][c] << "  ";
		}
		cout << endl;
	}
}

/*********************************************************************
** Function: initialize_matrix
** Description: for each row of a matrix, creates a columnar value
** Parameters: matrix_define changeling (placeholder struct)
** Pre-Conditions: none
** Post-Conditions: each row has appropriate number of columnar values
*********************************************************************/ 

void initialize_matrix(matrix_define changeling)
{
	for (int r = 0; r < *changeling.numrows; r++)
	{
		changeling.matrix[r] = new int[*changeling.numcols];
	}
}

/*********************************************************************
** Function: error_check
** Description: gets input, checks it to see if it is an integer, then
**		if input is an integer returns it
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: input is an integer
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
** Description: prompts user for number of rows and columns in the initial matrix
** Parameters: matrix_define initial
** Pre-Conditions: none
** Post-Conditions: number of rows and columns in the initial matrix 
**		are not 1
*********************************************************************/ 

void get_size(matrix_define initial)
{
	cout << "How many rows?\t\t";
	*initial.numrows = error_check();
	if (*initial.numrows == 1)
	{
		cout << "Matrix cannot have 1 row." << endl;
		exit(0); //other option is to read in value again
	}
	
	cout << "How many columns?\t";
	*initial.numcols = error_check();
	if (*initial.numcols == 1)
	{
		cout << "Matrix cannot have 1 column." << endl;
		exit(0);
	}
}

/*********************************************************************
** Function: get_matrix
** Description: asks the user for each entry of the initial matrix
** Parameters: matrix_define initial
** Pre-Conditions: none
** Post-Conditions: initial matrix has been populated with user generated
**		values
*********************************************************************/ 

void get_matrix(matrix_define initial)
{
	cout << "Entries of Initial Matrix" << endl;
	for (int r = 0; r < *initial.numrows; r++)
	{
		for (int c = 0; c < *initial.numcols; c++)
		{
			cout << "Enter element (" << r << "," << c << "):\t";
			initial.matrix[r][c] = error_check();
		}
	}
}

/*********************************************************************
** Function: calc_it
** Description: iterates through rows and columns of initial matrix, 
**		setting the element of the result matrix equal to the assigned 
**		elements of the initial matrix and checking to see if this process
**		is valid each time
** Parameters: matrix_define initial, matrix_define result 
** Pre-Conditions: none
** Post-Conditions: result matrix has been iteratively calculated
*********************************************************************/ 

void calc_it(matrix_define initial, matrix_define result)
{
	cout << "Iteratively calculating result matrix..." << endl;
	cout << "Result Matrix:" << endl;
	for (int r = 0; r < *initial.numrows; r++)
	{
		if (initial.matrix[r] && initial.matrix[r+1] && r < *initial.numrows)
		{
			for (int c = 0; c <= *initial.numcols; c++)
			{
				if (initial.matrix[r][c] && initial.matrix[r][c+1] && c < *initial.numcols)
				{
					result.matrix[r][c] = (initial.matrix[r][c] 
									+ initial.matrix[r+1][c]
									+ initial.matrix[r][c+1]
									+ initial.matrix[r+1][c+1]);
				}
				else break;
			}
		}
		else break;
	}
}

/*********************************************************************
** Function: clear_result
** Description: clears the result matrix by setting each element to 0
** Parameters: matrix_define result
** Pre-Conditions: none
** Post-Conditions: result matrix is 0 matrix
*********************************************************************/ 

void clear_result(matrix_define result)
{
	cout << "Clearing result matrix..." << endl;
	for (int r = 0; r < *result.numrows; r++)
	{
		for (int c = 0; c < *result.numcols; c++)
		{
			result.matrix[r][c] = 0;
		}
	}
}

/*********************************************************************
** Function: cols_recursive
** Description: recursively iterates through each columnar element in a row,
**		calculating each as per the assignment's directions
** Parameters: matrix_define initial, matrix_define result, int numrowsrec,
**		int numcolsrec 
** Pre-Conditions: numcolsrec != the numcols value of result
** Post-Conditions: the current columnar value has been calculated
*********************************************************************/ 

int cols_recursive (matrix_define initial, matrix_define result, int numrowsrec, int numcolsrec)
{
	if (numcolsrec == *result.numcols) //counts up to number of columns in result matrix
		return 0;
	result.matrix[numrowsrec][numcolsrec] = initial.matrix[numrowsrec][numcolsrec] + 
											initial.matrix[numrowsrec+1][numcolsrec] +
											initial.matrix[numrowsrec][numcolsrec+1] + 
											initial.matrix[numrowsrec+1][numcolsrec+1];
	return cols_recursive (initial, result, numrowsrec, numcolsrec+1);		
}

/*********************************************************************
** Function: rows_recursive
** Description: recursively iterates through rows of the result matrix,
**		calculates each columnar value for the entire row then moves to 
**		next row.
** Parameters: matrix_define initial, matrix_define result, int numrowsrec,
**		int numcolsrec 
** Pre-Conditions: numrowsrec != the numrows value of result
** Post-Conditions: the current row's columnar values have been calculated
*********************************************************************/ 

int rows_recursive (matrix_define initial, matrix_define result, int numrowsrec, int numcolsrec)
{
	if (numrowsrec == *result.numrows) //counts up to number of rows in result matrix
		return 0;
	cols_recursive (initial, result, numrowsrec, numcolsrec);
	return rows_recursive(initial, result, numrowsrec+1, numcolsrec);
}

/*********************************************************************
** Function: calc_rec
** Description: recursively calculates values for result matrix from
**		initial matrix
** Parameters: matrix_define initial, matrix_define result 
** Pre-Conditions: none
** Post-Conditions: result matrix has been recursively calculated
*********************************************************************/ 

void calc_rec(matrix_define initial, matrix_define result)
{
	int numrowsrec = 0;
	int numcolsrec = 0;
	cout << "Recursively calculating result matrix..." << endl;
	cout << "Result Matrix:" << endl;
	rows_recursive (initial, result, numrowsrec, numcolsrec);
}

/*********************************************************************
** Function: work_initial
** Description: sets, gets and shows the initial matrix
** Parameters: matrix_define initial
** Pre-Conditions: none
** Post-Conditions: initial matrix is of the user-determined size,
**		and has had its values input by the user
*********************************************************************/ 

void work_initial(matrix_define initial)
{
	initialize_matrix(initial);
	get_matrix(initial);
	cout << "Initial Matrix:" << endl;
	show_matrix(initial);
}

/*********************************************************************
** Function: set_initial
** Description: prepares the matrix for operations
** Parameters: matrix_define initial
** Pre-Conditions: none
** Post-Conditions: initial matrix is of the user-determined size,
**		and has had its values input by the user
*********************************************************************/ 

void set_initial(matrix_define *initial)
{
	initial->numrows = new int;
	initial->numcols = new int;
	get_size(*initial);
	initial->matrix = new int*[*initial->numrows];
	work_initial(*initial);
}

/*********************************************************************
** Function: work_result
** Description: calculates the result matrix iteratively and recursively
** Parameters: matrix_define initial, matrix_define result
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 

void work_result(matrix_define initial, matrix_define result)
{
	calc_it(initial, result);
	show_matrix(result);
	
	clear_result(result);
	show_matrix(result);
	
	calc_rec(initial, result);
	show_matrix(result);
}

/*********************************************************************
** Function: set_result
** Description: prepares the result matrix for operations
** Parameters: matrix_define *initial (passed by reference), matrix_define
**		*result (passed by reference)
** Pre-Conditions: none
** Post-Conditions: result matrix has been calculated and displayed
*********************************************************************/ 

void set_result(matrix_define *initial, matrix_define *result)
{
	result->numrows = new int;
	result->numcols = new int;
	*result->numrows = *initial->numrows - 1;
	*result->numcols = *initial->numcols - 1;
	result->matrix = new int*[*result->numrows];
	initialize_matrix(*result);
	work_result(*initial, *result);
}

/*********************************************************************
** Function: del_mem
** Description: deallocates memory
** Parameters: matrix_define initial, matrix_define result
** Pre-Conditions: none
** Post-Conditions: initial and result numrows, numcols and matrix
**		memory deallocated.
*********************************************************************/ 

void del_mem(matrix_define initial, matrix_define result)
{
	delete initial.numrows;
	delete initial.numcols;
	delete initial.matrix;
	delete result.numrows;
	delete result.numcols;
	delete result.matrix;
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
	matrix_define initial;
	set_initial(&initial);
	
	matrix_define result;
	set_result(&initial, &result);
	
	del_mem(initial, result);
	
	return 0;
}
















