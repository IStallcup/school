#ifndef DATE_H
#define DATE_H

#include <time.h>

class Date
{
	public:
		Date();
		Date(int month, int day, int year);
		void set_date(int tempM, int tempD, int tempY);
		int get_day();
		int get_month();
		int get_year();
		void print_a();
		void print_b();
		void print_c();
	private:
		int month;
		int day;
		int year;
};
/*
void Date::print_a(int month, int day, int year);
	//print format X/XX/XX

void Date::print_b(int month, int day, int year);
	//print format Xmonth XX, XXXX

void Date::print_c(int month, int day, int year);
	//print format XX Xmonth XXXX

Date::Date(int month, int day, int year);
	//error checking
	//number of days checking

Date::Date();
/*{
	month = 1;
	day = 1;
	year = 2001;
}*/

#endif