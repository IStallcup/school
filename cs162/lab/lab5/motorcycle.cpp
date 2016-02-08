#include "./m.h"

motorcycle::motorcycle():vehicle()
{
	
}

motorcycle::motorcycle(int x):vehicle(x)
{
	
}

int motorcycle::get_toll()
{
	if (get_day_week() == 0)
	{	
		return 10*get_seats();
	}
	return 20*get_seats();
}
