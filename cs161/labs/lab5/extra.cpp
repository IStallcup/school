#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int is_positive_float(std::string strx)
{
	int chkdec;
	cin >> strx;
	for (int iii; iii < strx.length(); iii++)
	{
		if (strx.at(iii) == '.')
			chkdec = 1;
		if ((strx.at(iii) <= '0' || strx.at(iii) > '9') && strx.at(iii) != '.')
		{
			return 0;
		}
	}
	if (chkdec == 1)
		return 1;
}

int main()
{
	cout << "Please enter a floating point number: ";
	string strx;
	cout << is_positive_float(strx) << endl;
}

