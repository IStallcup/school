#include "./mult_div.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

bool is_valid_dimensions(char *m, char *n)
{
	while (atoi(m) < 0)
	{
		cout << "You did not input a valid number of rows.\nPlease enter another value." << endl;
		cin >> *m;
	}
	
	while (atoi	(n) < 0)
	{
		cout << "You did not input a valid number of columns.\nPlease enter another value." << endl;
		cin >> *n;
	}
	
	return true;
}

mult_div_values** create_table(int m, int n)
{
	mult_div_values **table;
	
	table = new mult_div_values*[m];
	
	for (int i = 0; i < m; i++)
	{
		table[i] = new mult_div_values[n];
	}
	
	return table;
}

void set_mult_values(mult_div_values **table, int m, int n)
{
	cout << "Multiplication Table:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			table[i][j].mult = (i + 1) * (j + 1);
			cout << table[i][j].mult << "  ";
		}
		
		cout << endl;
	}
	cout << endl;
}

void set_div_tables(mult_div_values **table, int m, int n)
{
	cout << "Division Table:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			table[i][j].div = ((float)i + 1) / ((float)j + 1);
			cout << fixed;
			cout << setprecision(2);
			cout << table[i][j].div << "  ";
		}
		
		cout << endl;
	}
	cout << endl;
}

void delete_table(mult_div_values ***table, int m)
{
	for (int i = 0; i < m; i++)
	{
		delete table[i];
	}
	delete table;
}

void reprompt(char *m, char *n)
{
	cout << "How many rows? ";
	cin >> *m;
	cout << "How many columns? ";
	cin >> *n;
}

void run(char *m, char *n)
{
	is_valid_dimensions(m, n);
	mult_div_values **table;
	table = create_table(atoi(m), atoi(n));
	set_mult_values(table, atoi(m), atoi(n));
	set_div_tables(table, atoi(m), atoi(n));
}