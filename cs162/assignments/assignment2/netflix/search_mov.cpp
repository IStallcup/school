#include "./netflix.h"
#include "./movie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

void search_movies()
{
	netflix search;
	
	int searchnum = search.get_num_movies();
	
	int sel = get_sel();
	
	
	

	/*string input;
	
	char crent;
	
	char buff[256];
	
	int r;
	
	if (sel == 1)
	{
		cout << "What is the title?";
		cin.ignore();
		std::getline(std::cin, input);
		
		for (int i = 0; i < searchnum; i++)
		{
			
			cout << search.get_m(i).get_name() << endl;
			if (input == search.get_m(i).get_name())
			{
				cout << "found" << endl;
			}
		}
	}
	
	if (sel == 2)
	{
		cout << "How many stars?";
		cin >> input;
		for (int i = 0; i < searchnum; i++)
		{
			//cout << search.get_m(i).get_stars() << endl;
			if (input[0] == search.get_m(i).get_stars())
			{
				cout << "\tMovie: " << search.get_m(i).get_name() << endl;
				cout << "\tStars: " << char(search.get_m(i).get_stars()) << endl;
				cout << "\tCast: ";
				for (int j = 0; j < search.get_m(i).get_num_cast(); j++)
				{
					cout << search.get_m(i).get_cast(j) << ", ";
				}
				cout << endl << "\tRating: " << search.get_m(i).get_rating() << endl;
				cout << "Copies: " << char(search.get_m(i).get_copies()) << endl;
				cout << "Rented: " << char(search.get_m(i).get_rented()) << endl;
				
				cout << "Rent this movie? ";
				cin >> crent;
				if (crent == 'y')
				{
					r = search.get_m(i).get_rented();
					r++;
					
					fstream database;
					
					database.open("./netflix.dat", ios::in | ios::out | ios::app);
					
					for (int k = 0; k <= i; k++)
					{
						for (int l = 0; l < 8; l++)
						{
							database.getline(buff, 256, '|');
							if (k == i && l == 7)
							{
								database << '&';
								cout << endl << buff << endl;
							}
						}
					}
					
					database.close();
				}
				if (crent != 'y')
				{
					cout << "Movie not rented." << endl;
				}
			}
		}
	}
	if (sel == 4)
	{
		cout << "What rating?";
		cin.ignore();
		std::getline(std::cin, input);
		for (int i = 0; i < searchnum; i++)
		{
			//cout << search.get_m(i).get_rating() << endl;
			if (input == search.get_m(i).get_rating())
			{
				//cout << "Entry Found." << endl;
				cout << "\tMovie: " << search.get_m(i).get_name() << endl;
				cout << "\tStars: " << char(search.get_m(i).get_stars()) << endl;
				cout << "\tCast: ";
				for (int j = 0; j < search.get_m(i).get_num_cast(); j++)
				{
					cout << search.get_m(i).get_cast(j) << ", ";
				}
				cout << endl << "\tRating: " << search.get_m(i).get_rating() << endl;
				cout << "Copies: " << char(search.get_m(i).get_copies()) << endl;
				cout << "Rented: " << char(search.get_m(i).get_rented()) << endl;
				
				cout << "Rent this movie? ";
				cin >> crent;
				if (crent == 'y')
				{
					r = search.get_m(i).get_rented();
					r++;
					
					fstream database;
					
					database.open("netflix.dat", ios::in | ios::out | ios::app);
					
					for (int j = 0; j < searchnum; j++) //for each movie
					{
						for (int i = 0; i < 8; i++) //as there are 8 fields in the data file
						{
							database.getline(buff, 256, '|');
							if (i == 7)
							{
								cout << "Rented: ";
								database << r;
							}
							cout << buff;
						}
					}
					
					database.close();
				}
				if (crent != 'y')
				{
					cout << "Movie not rented." << endl;
				}
			}
		}
	}*/
}