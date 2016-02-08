#ifndef ROOMBA_H
#define ROOMBA_H

#include <vector>

using namespace std;

class floor
{
	private:
		vector <vector <char> > v;
		int rows;
		int cols;
	public:
		
};

template <class T>
class room
{
	private:
		floor f;
		T *obj;
	public:
		room(const char*);
};

class roomba
{
	private:
		int battery;
		int total_moves;
};



#endif