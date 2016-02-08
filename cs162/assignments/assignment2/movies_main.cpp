#include "./movies.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
using std::fstream;
using std::ios;

int main()
{
	//lab 4 stuff
	/*create_movie();
	movie test(13);
	copy_movie(test);
	assign_movie(test);*/
	
	//movie test;
	
	char input[256];
	
	cout << "(1) Search or (2) Add?";
	
	cin >> input;
	
	while (input[0] != '1' && input[0] != '2')
	{
		cout << "Incorrect input. Try again. ";
		cin >> input;
	}
	
	if (input[0] == '1')
	{
	
	/*
	char buff[256];
	
	cout << "What do you want to search for? ";
	
	//cin.flush();	
	cin.get(input, 256);
	
	fstream search;
	search.open("db.dat", ios::in);
	
	int search_line = 0;
	int *line_store = new int;
	
	while(!search.eof())
	{
		//cout << endl << endl << "Iteration number " << search_line << ":";
		for (int i = 0; i < 9; i++)
		{
			//cout << i << ":";
			search.getline(buff, 256, '|');
			if (strcmp(buff, input) == 0)
			{
				//cout << "(We found it!)";
				*line_store = search_line;
			}
			cout << buff << "|"/* << " *** "*//*;
		}
		search_line++;
	}
	search.close();
	if (*line_store == 0)
	{
		cout << "Not found." << endl;
	}
	else {
	cout << endl << "Found at line " << *line_store << endl;
	}
	
	fstream pop;
	pop.open("db.dat", ios::in);
	
	int pop_line = 0;
	
	movie found;
	
	while (!pop.eof())
	{
		for (int i = 0; i < 9; i++)
		{
			pop.getline(buff, 256, '|');
			//cout << buff << " ";
			if (i == 8)
			{
				pop.getline(buff, 2);
				//cout << endl;
			}
		}
		pop_line++;
		if (pop_line == *line_store)
		{
			//cout << "At line! ";
			for (int i = 0; i < 9; i++)
			{
				pop.getline(buff, 256, '|');
				if (i == 1)
				{
					found.set_name(buff);
				}
				if (i == 2)
				{
					found.set_stars(buff);
				}
				if (i == 3)
				{
					found.set_num_cast(buff);
				}
				/*if (i == 4)
				{
					found.set_cast(buff);
				}*//*
				if (i == 5)
				{
					found.set_rating(buff);
				}
				if (i == 6)
				{
					found.set_copies(buff);
				}
				if (i == 7)
				{
					found.set_rented(buff);
				}
				
				//cout << "M" <<  buff << " ";
			}
			cout << found.get_name() << endl;
		}
	}*/
	}	
	
	if (input[0] == '2')
	{
		
		
		//populate_netflix();
	}
	
	
	cout << "Ending Program." << endl;
	return 0;
}