#include "./netflix.h"
#include "./movie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;
using std::fstream;
using std::ios;

void movie_input()
{	
	string iname;
	int istars;
	int inum_cast;
	string *icast;
	string irating;
	int icopies;
	int irented;
	
	//read_movie_input(iname, istars, inum_cast, icast, irating, icopies, irented);
	
	cout << "What is the movie's name?" << endl;
	cin.ignore();
	getline(cin, iname);
	
	cout << "How many stars does the movie get?" << endl;
	cin >> istars;
	
	cout << "How many actors star?" << endl;
	cin >> inum_cast;
	
	icast = new string[inum_cast];
	cin.ignore();
	for (int i = 0; i < inum_cast; i++)
	{
		cout << "Who stars?" << endl;
		
		std::getline(cin, icast[i]);
		cout << icast[i] << endl;
	}
	
	cout << "What is its rating?" << endl;
	cin >> irating;
	
	cout << "How many copies available?" << endl;
	cin >> icopies;
	
	cout << "How many are rented out?" << endl;
	cin >> irented;
	
	cout << "Creating movie..." << endl;
	
	movie input;
	
	input.setvalues(iname, istars, inum_cast, icast, irating, icopies, irented);
	
	fstream movies;
	
	movies.open("netflix.dat", ios::out | ios::app);
	
	netflix database;
	
	movies << endl << database.get_num_movies() << "|" << input.get_name() << "|";
	movies << input.get_stars() << "|" << input.get_num_cast() << "|";
	for (int i = 0; i < inum_cast; i++)
	{
		movies << input.get_cast(i) << ",";
		cout << "set actor" << endl;
	}
	movies << "|" << input.get_rating() << "|" << input.get_copies() << "|" << input.get_rented() << "|";
	
	movies.close();
	
	cout << "Done adding movie." << endl;
}