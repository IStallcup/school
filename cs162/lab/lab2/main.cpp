#include "./Date.h"
#include <iostream>

using namespace std;

int main()
{
	Date choice1(0, 0, 0000);
	cout << choice1.get_day() << endl;
	cout << choice1.get_month() << endl;
	cout << choice1.get_year() << endl;
	cout << endl;
	Date choice2(3, 15, 2015);
	cout << choice2.get_day() << endl;
	cout << choice2.get_month() << endl;
	cout << choice2.get_year() << endl;
	choice2.set_date(4, 8, 2015);
	choice2.print_a();
	choice2.print_b();
	choice2.print_c();
	return 0;
}
