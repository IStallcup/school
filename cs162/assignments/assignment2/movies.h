#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>

using namespace std;

class movie
{
	public:
		movie();
		movie(int);
		~movie();
		movie(const movie &);
		void operator=(const movie &);
		
		string get_name() const;
		int get_stars() const;
		int get_num_cast() const;
		string get_cast() const;
		string get_rating() const;
		int get_copies() const;
		int get_rented() const;
		
		void set_name(char[]);
		void set_stars(char[]);
		void set_num_cast(char[]);
		void set_cast(char[]);
		void set_rating(char[]);
		void set_copies(char[]);
		void set_rented(char[]);
		
	private:
		string name;
		int stars;
		int num_cast;
		string *cast;
		string rating;
		int copies;
		int rented;
};

class netflix 
{
	public:
		netflix();
		~netflix();
	private:
		movie *m;
		int num_movies;
};

void create_movie();
void copy_movie(movie);
void assign_movie(movie);

void populate_netflix();

#endif
