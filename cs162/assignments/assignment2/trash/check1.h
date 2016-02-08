//movies.h

#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>

using namespace std;

class movie
{
	public:
		movie();
		~movie();
		
		movie(const movie& copy);
		
		void get_movie_info(movie);
		//void set_movie_info(movie);
		string get_name();
		int get_stars();
		int get_num_cast();
		string get_cast();
		string get_rating();
		int get_copies();
		
		
		
	private:
		string name;
		int stars;
		int num_cast;
		string *cast; //dynamic string array
		string rating;
		int copies;
};

class netflix 
{
	public:
		netflix();
		~netflix();
		
		movie get_m();
		int get_num_movies();
		
		void set_m();
		void set_num_movies();
		
		void access_m(int);
	private:
		movie *m;
		int num_movies;
};

void print_entry(int);

#endif

//movies_main.cpp

#include "./movies.h"
#include <iostream>
//#include <fstream>

using namespace std;
//using std::fstream;
//using std::ios;

void get_movies_master()
{
	netflix entry;
	cout << "How many movies to enter? ";
	entry.set_num_movies();
	entry.set_m();
	for (int i = 0; i < entry.get_num_movies(); i++)
	{
		entry.access_m(i);
	}
}

int main()
{
	cout << "Welcome to the Netflix database." << endl;
	cout << "Enter a new (M)ovie or (S)earch?" << endl;
	char select;
	cin >> select;
	
	while (select != 's' && select != 'm' && select != 'S' && select != 'M')
	{
		cout << "Invalid selection. Try again. ";
		cin >> select;
	}
	
	if (select == 'm' || select == 'M')
	{
		get_movies_master();
	}
	
	//netflix post;
	//cout << post.get_num_movies() << endl;
	
	//movie test;
	
	//test.get_movie_info(test);
	//test.set_movie_info(test);
	
}

//movies.cpp

#include "./movies.h"
#include <iostream>
#include <fstream>

using namespace std;
using std::fstream;
using std::ios;

//***************************************************	MOVIE	***************************************************

movie::movie()
{
	name = "Title";
	stars = 5;
	num_cast = 1;
	cast = new string[num_cast];
	cast[0] = "Sample Person";
	rating = "G";
	copies = 1;
}

movie::~movie()
{
	//delete[] cast; //causes seg fault?
}

movie::movie(const movie &orig)
{
	name = orig.name;
	stars = orig.stars;
	num_cast = orig.num_cast;
	//cast 
}

void movie::get_movie_info(movie test)
{
	char buff[64];
	cout << "What is the title? ";
	cin >> buff;
	//cout << "cin succeed" << endl;
	test.name = buff;
	//cout << "declare succeed" << endl;
	//cout << test.name << endl;
	//cout << "cout name succeed" << endl;
	fstream db;
	//cout << "fstream succeed" << endl;
	db.open("db.dat", ios::out | ios::app);
	db << test.name << '|' << endl;
	//cout << test.name << endl;
	db.close();
	//cout << "close succeed" << endl;
}

/*void movie::set_movie_info(movie test)
{
	
}*/

//***************************************************	NETFL***************************************************

netflix::netflix()	{/*default constructor empty*/}

netflix::~netflix()
{
	delete [] m;
}

void netflix::set_num_movies()
{
	int num_movies_t;
	cin >> num_movies_t;
	num_movies = num_movies_t;
}

int netflix::get_num_movies()
{
	return num_movies;
}

void netflix::set_m()
{
	m = new movie[num_movies];
}

void netflix::access_m(int i)
{
	movie current;
	
	cout << "Enter info: ";
	
	current.get_movie_info(current);
	
	cout << "Get succeeded" << endl;
	
	cout << endl;
}

//***************************************************	OTHER	***************************************************

void print_entry(int entrynum)
{
	fstream entry;
	
	entry.open("db.dat", ios::in);
	char buff[64];
	for (int i = 0; i < entrynum; i++)
	{
		entry.getline(buff, 64, '\n');
	}
	entry.close();
	cout << buff << endl;
}
