#ifndef C_H
#define C_H

#include "./v.h"

class car : public vehicle
{
	public:
		car();
		car(int);
		int get_toll();
};

#endif