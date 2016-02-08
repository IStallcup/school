#include "./netflix.h"
#include "./movie.h"
#include <iostream>
#include <fstream>

using namespace std;
using std::fstream;
using std::ios;

netflix::netflix()
{
	num_movies = 0;
	if (num_movies != 0)
	{
		m = new movie[num_movies];
	}
	else {m = NULL;}
}

netflix::~netflix()
{
	if (num_movies != 0)
	{
		delete [] m;
	}
}

int netflix::set_num_movies()
{
	if (num_movies != 0){return num_movies;}
	
	char buff[256];
	
	fstream database;
	
	database.open("netflix.dat", ios::in);
	
	while(!database.eof())
	{
		database.getline(buff, 256);
		//cout << buff << endl;
		num_movies++;
	}
	
	if (m == NULL)
	{
		m = new movie[num_movies];
	}
	
	return num_movies;
}

int netflix::get_num_movies()
{
	return num_movies;
}

netflix::netflix(const netflix &orig)
{
	num_movies = orig.num_movies;
	if (num_movies != 0)
	{
		m = new movie[num_movies];
		for (int i = 0; i < num_movies; i++)
		{
			m[i] = orig.m[i];
		}
	}
}

movie netflix::get_m(int a)
{
	return m[a];
}

void netflix::set_m(int num_movies)
{
	m = new movie[num_movies];
}

movie* netflix::get_m_p()
{
	return m;
}