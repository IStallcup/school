#ifndef V_H
#define V_H

#include "./date.h"

class vehicle
{
	private:
		int seats;
		Date today;
	public:
		Date get_today();
		void set_day(int);
		int get_day_week();
		vehicle();
		vehicle(int);
		int get_seats();
		virtual int get_toll();
};

#endif