#include <iostream>
#include <string>
#include <cstdlib>

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
 *	Function: checkx
 *	Description: gets the x string, checks it to see if
 *		it is an integer, and re-gets it until it is, then
 *		converts the integer string to x
 *	Parameters: strx, x (given)
 *	Pre-conditions: strx is a number?
 *	Post-conditions: strx is a number, x is a number 
 ***********************************************************/

void checkx(std::string strx, int& x)
{
	std::cin >> strx;
	for (int lll = 0; lll < strx.length(); lll++)
	{
		while (strx.at(lll) < '0' || strx.at(lll) >= '9')
		{
			std::cout << "Please enter parameter x: ";
			std::cin >> strx;
			lll = 0;
		}
	}
	x = atoi(strx.c_str());
}

/***********************************************************
 *	Function: checky
 *	Description: gets the y string, checks it to see if
 *		it is an integer, and re-gets it until it is, then
 *		converts the integer string to y
 *	Parameters: stry, y (given)
 *	Pre-conditions: stry is a number?
 *	Post-conditions: stry is a number, y is a number 
 ***********************************************************/

void checky(std::string stry, int& y)
{
	std::cin >> stry;
	for (int uuu = 0; uuu < stry.length(); uuu++)
	{
		while (stry.at(uuu) < '0' || stry.at(uuu) >= '9')
		{
			std::cout << "Please enter parameter y: ";
			std::cin >> stry;
			uuu = 0;
		}
	}
	y = atoi(stry.c_str())
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
	std::string strx;
	checkx(strx, x);
	std::cout << "Please enter parameter y: ";
	std::string stry;
	checky(stry, y);
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
