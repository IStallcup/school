/******************************************************
** Program: netflix.exe
** Author: Isaac Stallcup
** Date: 04/29/2015
** Description: Reads or scans in movies and associated data.
** Input: Movie information, or sundry selective inputs.
** Output: Requested movie information.
******************************************************/

#include "./netflix.h"
#include "./movie.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int select = -1; //selects function

	while (select > -2)
	{	
		cout << "Enter desired functionality: 1-Get 2-Search 0-Exit" << endl;
		cin >> select;
		if (select == 1)
		{
			get_movie();
		}
		if (select == 2)
		{
			search_movies();
		}
		if (select == 0)
		{
			return 0;
		}
	}
	
	return 0;
}