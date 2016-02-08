#include <iostream>

using namespace std;

void displaymat(int **matrix, int *numcols, int *numrows)
{
	cout << *numrows << " x " << *numcols << " Matrix:" << endl;
	for (int l = 0; l < *numrows; l++)
	{
		for (int q = 0; q < *numcols; q++)
		{
			cout << matrix[l][q] << " ";
		}
		cout << endl;
	}
}

void get_size(int *numrows, int *numcols)
{
	
	cout << "How many rows? " << endl;
	cin >> *numrows;
	
	
	cout << "How many columns? " << endl;
	cin >> *numcols;
}

void result_calc(int *numrows, int *numcols, int **matrix, int **result)
{
	for (int r = 0; r < *numrows; r++)
		{
		cout << "parsing row" << endl;
			if (matrix[r] && matrix[r+1] && r+1 < *numrows)
			{	
				for (int c = 0; c < *numcols; c++)
				{
				cout << "parsing column" << endl;
					if (matrix[r][c]  && matrix[r][c+1] && c + 1 < *numcols)
					{
						cout << "indexing result" << endl;
						result[r][c] = matrix[r][c] + matrix[r+1][c] + matrix[r][c+1] + matrix[r+1][c+1];
					}
					else
					{
						break;
					}
				}
			}	
			else break;
		}
}

void cols_recursive (int *numrows, int *numcols, int **matrix, int **result, int row_r, int col_r)
{
	if (col_r == *numcols)
	{
		return;
	}
	result[row_r][col_r] = matrix[row_r][col_r] + matrix[row_r + 1][col_r] 
						   + matrix[row_r][col_r + 1] + matrix[row_r + 1][col_r + 1];
	return cols_recursive (numrows, numcols, matrix, result, row_r, col_r + 1);
}

void rows_recursive(int *numrows, int *numcols, int **matrix, int **result, int row_r, int col_r)
{
	if (row_r == *numrows)
		return;
	cols_recursive (numrows, numcols, matrix, result, row_r, col_r);
	return rows_recursive (numrows, numcols, matrix, result, row_r + 1, col_r);
}

void initialize(int *numrows, int *numcols, int **matrix, int *numrows_r, int *numcols_r, int **result)
{
	cout << "Initial matrix: " << *numrows << " x " << *numcols << endl;
	cout << "Result matrix: " << *numrows_r << " x " << *numcols_r << endl;
	
	for (int i = 0; i < *numrows; i++)
	{
		cout << "Initial: Initializing row " << i << " with " << *numcols << " columns" << endl;
		matrix[i] = new int[*numcols];
	}
	
	for (int i = 0; i < *numrows - 1; i++)
	{
		cout << "Result: Initializing row " << i << " with " << *numcols_r << " columns" << endl;
		result[i] = new int[*numcols_r];
	}
}

void getmatrix(int *numrows, int *numcols, int **matrix)
{
	for (int r = 0; r < *numrows; r++)
	{
		for (int s = 0; s < *numcols; s++)
		{
			cout << "Enter element (" << r << "," << s << "): ";
			cin >> matrix[r][s];
		}
	}
}

void pre_calc_master(int *numrows, int *numcols, int *numrows_r, int *numcols_r, int **matrix, int **result)
{
//	get_size(numrows, numcols);
//	*numrows_r = *numrows - 1;
//	*numcols_r = *numcols - 1;
	result = new int*[*numrows_r];
	initialize(numrows, numcols, matrix, numrows_r, numcols_r, result);
	getmatrix(numrows, numcols, matrix);
}

void recursive_master(int *numrows, int *numcols, int **matrix, int **result)
{
	int row_r = 0;
	int col_r = 0;
	rows_recursive(numrows, numcols, matrix, result, row_r, col_r);
	displaymat(result, numcols, numrows); 
}

void calc_master(int *numrows, int *numcols, int **matrix, int *numrows_r, int *numcols_r, int **result)
{
	/*get_size(numrows, numcols);
	*numrows_r = *numrows - 1;
	*numcols_r = *numcols - 1;
	initialize(numrows, numcols, matrix, numrows_r, numcols_r, result);
	getmatrix(numrows, numcols, matrix);*/
	pre_calc_master(numrows, numcols, numrows_r, numcols_r, matrix, result);
	displaymat(matrix, numcols, numrows);
	result_calc(numrows, numcols, matrix, result);
	*numcols -= 1;
	*numrows -= 1;
	displaymat(result, numcols, numrows); 	
	recursive_master(numrows, numcols, matrix, result);
	/*int row_r = 0;
	int col_r = 0;
	rows_recursive(numrows, numcols, matrix, result, row_r, col_r);
	displaymat(result, numcols, numrows); 	*/
}

int main()
{
	int *numrows = new int;
	int *numcols = new int;
	int **matrix = new int*[*numrows];
	get_size(numrows, numcols);
	int *numrows_r = new int; 
	*numrows_r = *numrows - 1;
	int *numcols_r = new int;
	*numcols_r = *numcols - 1;
	int **result; 
	calc_master(numrows, numcols, matrix, numrows_r, numcols_r, result);
/*	initialize(numrows, numcols, matrix, numrows_r, numcols_r, result);
	getmatrix(numrows, numcols, matrix);
	displaymat(matrix, numcols, numrows);
	result_calc(numrows, numcols, matrix, result);
	*numcols -= 1;
	*numrows -= 1;
	displaymat(result, numcols, numrows); 	
	int row_r = 0;
	int col_r = 0;
	rows_recursive(numrows, numcols, matrix, result, row_r, col_r);
	displaymat(result, numcols, numrows); 	*/
	return 0;
}