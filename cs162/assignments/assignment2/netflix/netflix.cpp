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


netflix::netflix()
{
	fstream netflix;
	
	netflix.open("netflix.dat", ios::in); //open data file
	
	num_movies = 0;
	
	while (!netflix.eof()) //until eof
	{
		for (int i = 0; i < 8; i++) {netflix.getline(inbuff, 256, '|');} //increment through each data space of each movie
		netflix.getline(inbuff, 2);	 //disregard end line, null term
		num_movies++; //increment number of movies
	}
	
	netflix.close(); //close data file
	
	m = new movie[num_movies]; //create array of movies with size = number of movies.
	
	netflix.open("netflix.dat", ios::in); //open file again
	
	for (int j = 0; j < num_movies; j++) //for each movie
	{
		for (int i = 0; i < 8; i++) //as there are 8 fields in the data file
		{
			netflix.getline(inbuff, 256, '|');
			if (i == 1) {m[j].set_name(inbuff);} //second field = name
			if (i == 2) {m[j].set_stars(inbuff[0]);} //third field = stars, etc etc
			if (i == 3) {int t = atoi(inbuff); m[j].set_num_cast(t);} //num cast must be integer
			if (i == 4) {m[j].set_cast(inbuff, m[j].get_num_cast());}
			if (i == 5) {m[j].set_rating(inbuff);}
			if (i == 6) {m[j].set_copies(inbuff[0]);}
			if (i == 7) {m[j].set_rented(inbuff[0]);}
		}
		netflix.getline(inbuff, 2); //disregard newline, null term
	}
	
	netflix.close(); //close data file
}

netflix::~netflix()
{
	for (int i = 0; i < num_movies; i++)
	{
		delete m[i].get_cast_point();
	}
	delete [] m;
}

int netflix::get_num_movies()
{
	return num_movies;
}

movie netflix::get_m(int q)
{
	return m[q];
}