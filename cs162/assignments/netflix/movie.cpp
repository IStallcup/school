#include "./netflix.h"
#include "./movie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;
using std::fstream;
using std::ios;

movie::movie() //default constructor
{
	name = "";
	stars = 0;
	num_cast = 0;
	if (num_cast != 0)
	{
		cast = new string[num_cast];
	}
	else if (num_cast == 0) cast = NULL;
	rating = "";
	copies = 0;
	rented = 0;
}

movie::~movie() //destructor
{
	if (num_cast != 0 || cast != NULL) delete [] cast;
}

movie::movie(const movie &orig) //copy constructor
{
	name = orig.name;
	stars = orig.stars;
	num_cast = orig.num_cast;
	if (num_cast != 0)
	{
		cast = new string[num_cast];
		for (int i = 0; i < num_cast; i++)
		{
			cast[i] = orig.cast[i];
		}
	}
	rating = orig.rating;
	copies = orig.copies;
	rented = orig.rented;
}

movie::movie(string iname, int istars, int inum_cast, string icast[], string irating, int icopies, int irented)
{ //sets up a movie with all the information given
	name = iname;
	stars = istars;
	num_cast = inum_cast;
	if (num_cast != 0)
	{
		cast = new string[num_cast];
		for (int i = 0; i < num_cast; i++)
		{
			cast[i] = icast[i];
		}
	}
	else if (num_cast == 0) cast = NULL;
	rating = irating;
	copies = icopies;
	rented = irented;
}


string movie::get_name()
{
	return name;
}

int movie::get_stars()
{
	return stars;
}

int movie::get_num_cast()
{
	return num_cast;
}

string movie::get_cast(int num)
{
	return cast[num];
}

string* movie::get_cast_point()
{
	return cast;
}

string movie::get_rating()
{
	return rating;
}

int movie::get_copies()
{
	return copies;
}

int movie::get_rented()
{
	return rented;
}

void movie::set_name(string iname)
{
	name = iname;
}

void movie::set_stars(int istars)
{
	stars = istars;
}

void movie::set_num_cast(int inum_cast)
{
	num_cast = inum_cast;
}

void movie::set_cast(string* icast, int inum_cast)
{
	if (inum_cast == 0){cast = NULL;}
	else 
	{
		cast = new string[inum_cast];
		for (int i = 0; i < inum_cast; i++)
		{
			cast[i] = icast[i];
		}
	}
}

void movie::set_rating(string irating)
{
	rating = irating;
}

void movie::set_copies(int icopies)
{
	copies = icopies;
}

void movie::set_rented(int irented)
{
	rented = irented;
}

string get_iname(string iname) //gets movie name
{
	cout << "What is the movie's name?" << endl;
	cin.ignore();
	getline(cin, iname);
	return iname;
}

int get_istars(int istars) //gets # stars
{
	cout << "How many stars does the movie get?" << endl;
	cin >> istars;
	return istars;
}

int get_inum_cast(int inum_cast) //gets # cast
{
	cout << "How many actors star?" << endl;
	cin >> inum_cast;
	return inum_cast;
}

string* get_icast(string* icast, int inum_cast) //gets cast
{
	if (inum_cast != 0){icast = new string[inum_cast];}
	else if (inum_cast == 0){return NULL;}
	cin.ignore();
	for (int i = 0; i < inum_cast; i++)
	{
		cout << "What is actor " << i + 1 << "'s name?" << endl;
		std::getline(std::cin, icast[i]);
	}
	return icast;
}

string get_irating(string irating) //gets rating
{
	cout << "What rating does the movie have?" << endl;
	cin >> irating;
	return irating;
}

int get_icopies(int icopies) //gets # copies
{
	cout << "How many copies are there?" << endl;
	cin >> icopies;
	return icopies;
}

int get_irented(int irented) //gets # copies rented
{
	cout << "How many copies are rented?" << endl;
	cin >> irented;
	return irented;
}

void get_movie()
{
	string iname, irating;
	int istars, inum_cast, icopies, irented;
	string *icast;
	
	//sets up and gets the information necessary to populate data file
	//for a given movie
	
	iname = get_iname(iname);
	istars = get_istars(istars);
	inum_cast = get_inum_cast(inum_cast);
	icast = get_icast(icast, inum_cast);
	irating = get_irating(irating);
	icopies = get_icopies(icopies);
	irented = get_irented(irented);
	
	//uses non-default constructor to create movie object with associated
	//information
	movie input(iname, istars, inum_cast, icast, irating, icopies, irented);
	
	netflix read;
	
	int inum_movies = read.set_num_movies();
	
	fstream database;
	
	database.open("netflix.dat", ios::out | ios::app);
	
	//writes the movie information in the next spot in the text file
	database << endl << inum_movies << "|" << input.get_name() << "|";
	database << input.get_stars() << "|" << input.get_num_cast() << "|";
	for (int i = 0; i < input.get_num_cast(); i++)
	{
		database << input.get_cast(i) << ",";
	}
	database << "|" << input.get_rating() << "|";
	database << input.get_copies() << "|" << input.get_rented() << "|";
	
	database.close();
	delete [] icast;
}

string get_icast_member(string icast_member) //asks which actor user wants
{
	cout << "Which actor do you want to search for?" << endl;
	cin.ignore();
	std::getline(cin, icast_member);
	return icast_member;
}

void parse_name(string iname) //searches text file for a name
{
	bool decision;
	
	char buff[256];
	
	int irented;
	
	fstream database;
	
	database.open("netflix.dat", ios::in | ios::out | ios::app);
	
	while(!database.eof())
	{
		for (int i = 0; i < 8; i ++)
		{
			database.getline(buff, 256, '|');
			if (iname.compare(buff) == 0) //if iname and the current buffer are the same
			{
				cout << "Found!" << endl;
				cout << "Would you like to rent this movie (1/0)? ";
				cin >> decision;
			}
			if (i == 7 && decision == true) //if we have reached the rent field
			{
				cout << "Renting movie..." << endl;
				decision == false;
				irented = atoi(buff);
				//database << irented + 1; //should be incrementing copies available for renting
			}
			decision == false;
		}
		database.getline(buff, 2);
	}
	
	database.close();
}

void parse_stars(int istars) //searches text file for # stars
{
	bool decision;
	
	char buff[256];
	
	int irented;
	
	fstream database;
	
	database.open("netflix.dat", ios::in | ios::out | ios::app);
	
	while(!database.eof())
	{
		for (int i = 0; i < 8; i ++)
		{
			database.getline(buff, 256, '|');
			if (atoi(buff) == istars && i == 2) //if buff is # stars and we're in the right place
			{
				cout << "Found!" << endl;
				cout << "Would you like to rent this movie (1/0)? ";
				cin >> decision;
			}
			if (i == 7 && decision == true)
			{
				cout << "Renting movie..." << endl;
				decision == false;
				irented = atoi(buff);
				//database << irented + 1;
			}
			decision == false;
		}
		database.getline(buff, 2);
	}
	
	database.close();
}

void parse_cast(string icast_member) //searhces for an actor
{
	bool decision;
	
	char buff[256];
	
	char iname[256];
	
	int irented;
	
	fstream database;
	
	database.open("netflix.dat", ios::in | ios::out | ios::app);
	
	while(!database.eof())
	{
		for (int i = 0; i < 8; i ++)
		{
			database.getline(buff, 256, '|');
			if (i == 1)
			{
				strcpy(iname, buff); //copies name of movie to a c-string
			}
			while (i == 3)
			{
				database.getline(buff, 256, ',');
				if (icast_member.compare(buff) == 0) //if member's name is the same as buff
				{
					cout << "Movie: " << iname << endl; //prints name of movie
					cout << "Would you like to rent this movie (1/0)? ";
					cin >> decision;
				}
				if (database.peek() == '|')
				{
					break;
				}
			}
			if (i == 7 && decision == true)
			{
				cout << "Renting movie..." << endl;
				decision == false;
				irented = atoi(buff);
				//database << irented + 1;
			}
			decision == false;
		}
		database.getline(buff, 2);
	}
	
	database.close();
}

void parse_rating(string irating) //parses for ratings
{
	bool decision;
	
	char buff[256];
	
	char iname[256];
	
	int irented;
	
	fstream database;
	
	database.open("netflix.dat", ios::in | ios::out | ios::app);
	
	while(!database.eof())
	{
		for (int i = 0; i < 8; i ++)
		{
			database.getline(buff, 256, '|');
			if (i == 1)
			{
				strcpy(iname, buff);
			}
			if (irating.compare(buff) == 0)
			{
				cout << "Movie: " << iname << endl;
				cout << "Would you like to rent this movie (1/0)? ";
				cin >> decision;
			}
			if (i == 7 && decision == true)
			{
				cout << "Renting movie..." << endl;
				decision == false;
				irented = atoi(buff);
				//database << irented + 1;
			}
			decision == false;
		}
		database.getline(buff, 2);
	}
	
	database.close();
}

void search_movies() //initiates searching for movies
{
	cout << "What would you like to search for?" << endl;
	cout << "1-Name 2-Stars 3-Cast 4-Rating" << endl;
	int select, istars;
	string iname, icast_member, irating;
	cin >> select;
	if (select == 1) 
	{
		iname = get_iname(iname);
		parse_name(iname);
	}
	if (select == 2) 
	{
		istars = get_istars(istars);
		parse_stars(istars);
	}
	if (select == 3) 
	{
		icast_member = get_icast_member(icast_member);
		parse_cast(icast_member);
	}
	if (select == 4) 
	{
		irating = get_irating(irating);
		parse_rating(irating);
	}
}
