#include "./Date.h"
#include <iostream>
#include <string>

using namespace std;
//#include as needed

void Date::print_a() 	//print format X/XX/XX
{
	cout << month << "/" << day << "/" << year % 100 << endl;
	//print month value (with formatting)
	//print day value
	//print year value
}

void Date::print_b()		//print format Xmonth XX, XXXX
{
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	cout << months[month - 1] << " " << day << ", " << year << endl;
	//switch or if tree to print selected item from array of months; ex array[0] = 'January'
	//	where input month -1 is used as the element in the array.
	//print day value (with formatting)
	//print year value 
}

void Date::print_c()		//print format XX Xmonth XXXX
{
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	cout << day << " " << months[month - 1] << " " << year << endl;
	
	//print day value (with formatting)
	//as above, print month using logic structure with array mapping month numbers to month namespace
	//print year
}

Date::Date(int monthT, int dayT, int yearT)		//non-default constructor
{
	//error checking
	while (monthT > 12 || monthT < 1)
	{
		cout << "Incorrect month; please try again. ";
		cin >> monthT;
	}
	
	if (monthT == 2)
	{
		while (((yearT % 4 == 0) && dayT > 29) || ((yearT % 4 != 0) && dayT > 28))
		{	
			cout << "Incorrect number of days; please try again. ";
			cin >> dayT;
		}
	}
	
	while (dayT <= 0 || (((monthT % 7) % 2) == 0 && dayT > 31) || ((((monthT % 7) % 2) == 1) && dayT > 30))
	{
		cout << "Incorrect number of days; please try again. ";
		cin >> dayT;
	}
	
	while (yearT < 1)
	{
		cout << "Incorrect year; please try agian. ";
		cin >> yearT;
	}
	
	year = yearT;
	month = monthT;
	day = dayT;
	
	//check to see if integers; if not prompt for value or exit
	//check if input days is <31, month is <12, year is >0
	//logic tree for checking max days against month values; array of # days with each month, check against
	//	each month's value
	//for february, leap years are always %4 == 0 so days can be 29

	//set month, day, year to input values after checking
}

int Date::get_day()
{
	return day;
}

int Date::get_month()
{
	return month;
}

int Date::get_year()
{
	return year;
}

Date::Date()									//default constructor
{
	month = 1;
	day = 1;
	year = 2001;
}

void Date::set_date(int tempM, int tempD, int tempY)
{
	month = tempM;
	day = tempD;
	year = tempY;
}
