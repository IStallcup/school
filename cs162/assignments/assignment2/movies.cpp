#include "./movies.h"
#include <iostream>
#include <fstream>

using namespace std;
using std::fstream;
using std::ios;

//***************************************************	MOVIE	***************************************************

movie::movie()
{
	
}

movie::movie(int num_cast_temp)
{
	//num_cast = num_cast_temp;
	//cast = new string[num_cast];
}

movie::~movie()
{
	//delete [] cast;
}

movie::movie(const movie &other) //copy constructor
{
	num_cast = other.get_num_cast();
	if (num_cast == 0) cast = NULL;
	else {
		cast = new string[num_cast];
		for (int i = 0; i < num_cast; i++)
		{
			cast[i] = other.cast[i];
		}
	}
}

void movie::operator=(const movie &other)
{
	if (cast != NULL) delete [] cast;
	num_cast = other.get_num_cast();
	if (num_cast == 0) cast = NULL;
	else {
		cast = new string[num_cast];
		for (int i = 0; i < num_cast; i++)
		{
			cast[i] = other.cast[i];
		}
	}
}

string movie::get_name() const
{
	return name;
}

int movie::get_stars() const
{
	return stars;
}

int movie::get_num_cast() const
{
	return num_cast;
}

string movie::get_cast() const
{
	/*for (int i = 0; i < num_cast; i++)
	{
		
	}*/
	return *cast;
}

string movie::get_rating() const
{
	return rating;
}

int movie::get_copies() const
{
	return copies;
}

int movie::get_rented() const
{
	return rented;
}

void movie::set_name(char buff[])
{
	cout << "set_name buff: " << buff << endl;
	name = buff;
}

void movie::set_stars(char buff[])
{
	cout << "set_stars buff: " << buff << endl;
	stars = buff[0];
}

void movie::set_num_cast(char buff[])
{
	cout << "set_num_cast buff: " << buff << endl;
	num_cast = buff[0];
}

void movie::set_cast(char buff[])
{
	
}

void movie::set_rating(char buff[])
{
	cout << "set_rating buff: " << buff << endl;
	rating = buff;
}

void movie::set_copies(char buff[])
{
	cout << "set_copies buff: " << buff << endl;
	copies = buff[0];
}

void movie::set_rented(char buff[])
{
	cout << "set_rented buff: " << buff << endl;
	rented = buff[0];
}



//***************************************************	NETFLIX	   ***************************************************

netflix::netflix()
{
	fstream database;
	
	cout << "Opening file db.dat..." << endl;
	
	database.open("db.dat", ios::in);
	
	char *buff = new char[256];
	
	int *num_movies_temp = new int;
	
	while (!database.eof())
	{
		database.getline(buff, 256, '|');
		cout << buff;
	}
	
	database.close();
	
	
	delete num_movies_temp;
	delete [] buff;
}

netflix::~netflix()
{
	
}



//***************************************************	OTHER	***************************************************

void create_movie() //lab 4
{
	movie test(8);
}

void copy_movie(movie original) //lab 4
{
	cout << original.get_num_cast() << endl;
}

void assign_movie(movie original) //lab 4
{
	movie test(8);
	cout << test.get_num_cast() << endl;
	test = original;
	cout << "after assign: " << test.get_num_cast() << endl;
}

void populate_netflix()
{
	
}
















