#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>

using namespace std;


class movie
{
	public:
		//Default Constructor
		movie();
		//Deconstructor/Destructor
		~movie();
		//Copy Constructor
		movie(const movie &);
		//Operator =
		void operator=(const movie &);
		
		//Sets name, stars, num_cast, cast, rating, copies and rented
		void setvalues(string, int, int, string*, string, int, int);
		
		//Accessor Functions
		string get_name();
		int get_stars();
		int get_num_cast();
		string get_cast(int);
		string* get_cast_point();
		string get_rating();
		int get_copies();
		int get_rented();
		
		//Mutator Functions
		void set_name(string);
		void set_stars(int);
		void set_num_cast(int);
		void set_cast(char*, int);
		void set_rating(string);
		void set_copies(int);
		void set_rented(int);
		
	private:
		string name;
		int stars;
		int num_cast;
		string *cast;
		string rating;
		int copies;
		int rented;
};


#endif