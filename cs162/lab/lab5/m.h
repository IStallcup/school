#ifndef M_H
#define M_H

#include "./v.h"

class motorcycle : public vehicle
{
	public:
		motorcycle();
		motorcycle(int);
		int get_toll();
};


#endif