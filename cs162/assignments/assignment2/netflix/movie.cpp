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


movie::movie()
{
	//empty default constructor to prevent interference with setting values of them
}

movie::~movie()
{
	//delete [] cast;
}

movie::movie(const movie &orig)
{
	name = orig.name;
	stars = orig.stars;
	num_cast = orig.num_cast;
	cast = new string[num_cast];
	for (int i = 0; i < num_cast; i++)
	{
		cast[i] = orig.cast[i];
	}
	rating = orig.rating;
	copies = orig.copies;
	rented = orig.rented;
}

void movie::setvalues(string iname, int istars, int inum_cast, string* icast, string irating, int icopies, int irented)
{
	name = iname;
	stars = istars;
	num_cast = inum_cast;
	cast = new string[num_cast];
	cout << endl << "Allocated" << endl;
	for (int i = 0; i < num_cast; i++)
	{
		cast[i] = icast[i];
	}
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

void movie::set_cast(char *inbuff, int inum_cast)
{
	cast = new string[inum_cast];
	cout << "Allocated cast[]" << endl;
	
	char **buff = new char*[5];
	cout << "Allocated buff" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Allocated buff[" << i << "]" << endl;
		buff[i] = new char[256];
	}
	int i = 0, j = 0, k = 0;
	
	while (i < inum_cast)
	{
		while (j < 256)
		{
			buff[i][j] = inbuff[k];
			k++;
			if (inbuff[k] == ',')
			{
				k++;
				j = 0;
				break;
			}
			j++;
		}
		cast[i] = buff[i];
		cout << "cast[" << i << "]: " << cast[i] << endl;
		i++;
	}
	
	for (int i = 0; i < 5; i++)
	{
		delete buff[i];
		cout << "Deallocated: buff[" << i << "]" << endl;
	}
	cout << "buff[] deallocated" << endl;
	delete [] buff;
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
