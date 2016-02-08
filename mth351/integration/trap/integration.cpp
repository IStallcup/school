#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void read_data(int *xn_arry)
{
	fstream data;
	if (data.is_open())
	{
		cout << "File is open. Oops!" << endl;
		exit(0);
	}
	
	data.open("points.dat", fstream::in);
	
	
	
	data.close();
}

int main()
{
	cout << "\t\t--Integration - Trapezoidal Ruler--" << endl;
	cout << "\t\t\t--Isaac Stallcup--" << endl;
	
	int xn_arry[64];
	
	read_data(xn_arry);
}