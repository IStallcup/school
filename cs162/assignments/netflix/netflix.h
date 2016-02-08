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
		movie* get_m_p();
		void set_m(int);
		
		int get_num_movies();
		int set_num_movies();
	private:
		movie *m;
		int num_movies;
};

#endif