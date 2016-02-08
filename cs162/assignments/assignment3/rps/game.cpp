#include "./game.h"
#include <iostream>

using namespace std;


void tool::setstr(int istr)
{
	str = istr;
}

void tool::settype(char itype)
{
	type = itype;
}

int tool::get_str()
{
	return str;
}

char tool::get_type()
{
	return type;
}

tool* rpsgame::get_meat()
{
	return meat;
}

void rpsgame::test()
{
	cout << "testing" << endl;
}

void rpsgame::set_meat(int istr, char itype)
{
	meat->setstr(istr);
	meat->settype(itype);
}