#ifndef NETFLIX_H
#define NETFLIX_H

#include "./movie.h"
#include <iostream>

using namespace std;

class netflix
{
	public:
		netflix();
		~netflix();
		netflix(const netflix &);
		
		movie get_m(int);
		int get_num_movies();
	private:
		movie *m;
		int num_movies;
		char inbuff[256];
};

void movie_input();
void search_movies();
int get_sel();

#endif