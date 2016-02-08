#include "./c.h"

car::car():vehicle()
{
	
}

car::car(int x):vehicle(x)
{
	
}

int car::get_toll()
{
	if (get_day_week() == 5)
	{
		return 10*get_seats();
	}
	
	return 20*get_seats();
}