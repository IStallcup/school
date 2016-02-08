#include <iostream>
#include <cstdlib>

using namespace std;

struct matrix_define //why did you use me?
{
	int *numrows;
	int *numcols;
	int **matrix;
};

void show_matrix(matrix_define changeling)
{
	cout << *changeling.numrows << " x " << *changeling.numcols << " Matrix:" << endl;
	for (int r = 0; r < *changeling.numrows; r++)
	{
		for (int c = 0; c < *changeling.numcols; c++)
		{
			if (changeling.matrix[r][c] > 9)
				cout << changeling.matrix[r][c] << " ";
			else cout << changeling.matrix[r][c] << "  ";
		}
		cout << endl;
	}
}

void initialize_matrix(matrix_define changeling)
{
	for (int r = 0; r < *changeling.numrows; r++)
	{
		changeling.matrix[r] = new int[*changeling.numcols];
	}
}

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

void get_size(matrix_define initial)
{
	cout << "How many rows?\t\t";
	*initial.numrows = error_check();
	if (*initial.numrows == 1)
	{
		cout << "Matrix cannot have 1 row." << endl;
		exit(0);
	}
	
	cout << "How many columns?\t";
	*initial.numcols = error_check();
	if (*initial.numcols == 1)
	{
		cout << "Matrix cannot have 1 column." << endl;
		exit(0);
	}
}

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
					result.matrix[r][c] = (initial.matrix[r][c] + initial.matrix[r+1][c]+
									initial.matrix[r][c+1] + initial.matrix[r+1][c+1]);
				}
				else break;
			}
		}
		else break;
	}
}

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

int cols_recursive (matrix_define initial, matrix_define result, int numrowsrec, int numcolsrec)
{
	if (numcolsrec == *result.numcols)
		return 0;
	result.matrix[numrowsrec][numcolsrec] = initial.matrix[numrowsrec][numcolsrec] + initial.matrix[numrowsrec+1][numcolsrec]+
									 initial.matrix[numrowsrec][numcolsrec+1] + initial.matrix[numrowsrec+1][numcolsrec+1];
	return cols_recursive (initial, result, numrowsrec, numcolsrec+1);		
}

int rows_recursive (matrix_define initial, matrix_define result, int numrowsrec, int numcolsrec)
{
	if (numrowsrec == *result.numrows)
		return 0;
	cols_recursive (initial, result, numrowsrec, numcolsrec);
	return rows_recursive(initial, result, numrowsrec+1, numcolsrec);
}

void calc_rec(matrix_define initial, matrix_define result)
{
	int numrowsrec = 0;
	int numcolsrec = 0;
	cout << "Recursively calculating result matrix..." << endl;
	cout << "Result Matrix:" << endl;
	rows_recursive (initial, result, numrowsrec, numcolsrec);
}

void del_mem(matrix_define initial, matrix_define result)
{
	delete initial.numrows;
	delete initial.numcols;
	delete initial.matrix;
	delete result.numrows;
	delete result.numcols;
	delete result.matrix;
}

void work_initial(matrix_define initial)
{
	initialize_matrix(initial);
	get_matrix(initial);
	cout << "Initial Matrix:" << endl;
	show_matrix(initial);
}

void work_result(matrix_define initial, matrix_define result)
{
	calc_it(initial, result);
	show_matrix(result);
	
	clear_result(result);
	show_matrix(result);
	
	calc_rec(initial, result);
	show_matrix(result);
}

int main()
{
	matrix_define initial;
	initial.numrows = new int;
	initial.numcols = new int;
	get_size(initial);
	initial.matrix = new int*[*initial.numrows];
	work_initial(initial);
	
	matrix_define result;
	result.numrows = new int;
	result.numcols = new int;
	*result.numrows = *initial.numrows - 1;
	*result.numcols = *initial.numcols - 1;
	result.matrix = new int*[*result.numrows];
	initialize_matrix(result);
	
	work_result(initial, result);
	
	del_mem(initial, result);
	
	return 0;
}
















