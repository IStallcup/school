#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool is_positive_int_recursive(string str_input, int i)
{
	if (i == 0)
		return true;
	--i;
	if(str_input.at(i) < '0' || str_input.at(i) > '9')
		return false;
	return is_positive_int_recursive(str_input, i);	

}

int main()
{
	cout << "Enter something." << endl;
	string str_input;
	cin >> str_input;
	int i = str_input.length();
	cout << i << endl;
	cout << is_positive_int_recursive(str_input, i) << endl;
}

