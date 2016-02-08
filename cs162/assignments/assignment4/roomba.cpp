#include "./roomba.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
using std::ios;
using std::fstream;

Floor::Floor(const char* filename1, char *argv[])
{	
	cout << "Floor non-default constructor" << endl;
	filename = filename1;
	fstream floorplan;
	floorplan.open(filename, ios::in);
	plan = new char *[10];
	for (int i = 0; i < 10; i++)
	{
		plan[i] = new char[10];
	}
	int j  = 0;
	while (!floorplan.eof())
	{
		floorplan.getline(plan[j], 10, '\n');
		cout << plan[j] << endl;
		j++;
	}
	floorplan.close();
	obj_row = atoi(argv[6]);
	obj_col = atoi(argv[8]);
	
}

Floor::Floor()
{
	//default constructor
}

Floor::~Floor()
{
	for (int i = 0; i < 10; i++)
	{
		delete[] plan[i];
	}
	delete [] plan;
	plan = NULL;
}

Roomba::Roomba(char *argv[])
{
	battery = atoi(argv[4]);
	total_moves = atoi(argv[10]);
}
