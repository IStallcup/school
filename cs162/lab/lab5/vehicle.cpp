#include "./v.h"

vehicle::vehicle()
{
	seats = 1;
	today.set_day(29);
	today.set_month(4);
	today.set_year(2015); //Wednesday
}

Date vehicle::get_today()
{
	return today;
}

int vehicle::get_day_week()
{
	return today.get_day_of_week();
}

void vehicle::set_day(int x)
{
	today.set_day(x);
}

vehicle::vehicle(int x)
{
	seats = x;
	today.set_day(29);
	today.set_month(4);
	today.set_year(2015); //Wednesday
}

int vehicle::get_seats()
{
	return seats;
}

int vehicle::get_toll()
{
	return 20*seats;
}