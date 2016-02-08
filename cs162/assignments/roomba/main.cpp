#include "./roomba.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	const char* filename = argv[2];
	try {
	fstream floorplan;
	floorplan.exceptions (ifstream::failbit);
	floorplan.open(filename, ios::in);
	floorplan.close();
	}
	catch(ifstream::failure e) {
		cout << "File opening failed." << endl;
		return 0;
	}
	room <roomba> r;
	//non-default constructor will set up floor from
	//	the input file that has been checked
	//floor will be input element by element using getline
	//	with space as a delimiter, and pushback on the
	//	vector as each element is added.
	return 0;
}