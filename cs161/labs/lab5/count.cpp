#include <iostream>


/***********************************************************
 *	Function: up
 *	Description: counts up from 0 to given parameter x
 *	Parameters: x (given)
 *	Pre-conditions: x is an integer greater than or
 *		equal to zero
 *	Post-conditions: this remains true 
 ***********************************************************/

void up(int x)
{
	std::cout << "Counting from 0 to " << x << " :" << std::endl;
	for (int iii = 0; iii <= x; iii++)
	{
		std::cout << iii << std::endl;
	}
}

/***********************************************************
 *	Function: down
 *	Description: counts down from parameter x to 0
 *	Parameters: x (given)
 *	Pre-conditions: x is an integer greater than or
 *		equal to zero
 *	Post-conditions: this remains true 
 ***********************************************************/

void down(int x)
{
	std::cout << "Counting from " << x << " to 0:" << std::endl;
	for (int jjj = 0; jjj <= x; jjj++)
	{
		std::cout << x - jjj << std::endl;
	}
}

/***********************************************************
 *	Function: xlessy
 *	Description: counts from x to y if x is less than y
 *	Parameters: x, y (given)
 *	Pre-conditions: x, y are integers greater than or
 *		equal to zero
 *	Post-conditions: this remains true 
 ***********************************************************/

void xlessy(int x, int y)
{
	for (int q = x; q <= y; q++)
	{
		std::cout << q << std::endl;
	}
}

/***********************************************************
 *	Function: xgreaty
 *	Description: counts up from y to x if x is greater than y
 *	Parameters: x, y (given)
 *	Pre-conditions: x, y are integers greater than or
 *		equal to zero
 *	Post-conditions: this remains true 
 ***********************************************************/

void xgreaty(int x, int y)
{
	for (int j = y; j <= x; j++)
	{
		std::cout << j << std::endl;
	}
}

/***********************************************************
 *	Function: between
 *	Description: checks which is greater--x or y--then runs
 *		a function based on which is greater
 *	Parameters: x, y (given)
 *	Pre-conditions: x, y are integers greater than or
 *		equal to zero
 *	Post-conditions: this remains true 
 ***********************************************************/

void between(int x, int y)
{
	if (x < y)
	{
		std::cout << "x < y" << std::endl;
		xlessy(x, y);
	}

	if (x > y)
	{
		std::cout << "x > y" << std::endl;
		xgreaty(x, y);
	}
}

/***********************************************************
 *	Function: getstyff
 *	Description: asks for user to input paratmeters x, y,
 *		then gets them
 *	Parameters: x, y
 *	Pre-conditions: none
 *	Post-conditions: x, y are integers greater than or
 *		equal to zero 
 ***********************************************************/

void getstuff(int& x, int& y)
{
	std::cout << "Please enter parameter x: ";
	std::cin >> x;
	std::cout << "Please enter parameter y: ";
	std::cin >> y;
}

/***********************************************************
 *	Function: main
 *	Description: main function; runs all other functions
 *	Parameters: x, y
 *	Pre-conditions: none
 *	Post-conditions: none 
 ***********************************************************/

int main()
{
	int x, y;
	getstuff(x, y);
	up(x);
	down(x);
	between(x, y);
}
