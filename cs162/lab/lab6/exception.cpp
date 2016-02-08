#include <iostream>
#include <exception>
#include <string>

using namespace std;

int main()
{
	string s;
	try 
	{
		s.at(0);
	}
	
	catch(exception &e)
	{
		cout << "divide by zero" << endl;
	}
}