#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream grd_dat;
	cout << "Opening file 'grades.dat'..." << endl;
	if (!grd_dat.is_open())
		grd_dat.open("grades.dat", fstream::in | fstream::out | fstream::app);
	else {cout << "Error - file already open. Exiting." << endl; return -1;}
	cout << "Success." << endl;
	
	
	
	grd_dat.close();
	return 0;
}