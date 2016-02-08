/******************************************************
** Program: roomba.cpp
** Author: Isaac Stallcup
** Date: 05/26/2015
** Description: Simulates Roomba in a room
** Input:
** Output:
******************************************************/
#include "./roomba.h"
#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std;
using std::ios;
using std::fstream;

void check_arguments(int argc, char* argv[])
{
	if (argc != 11)
	{
		cout << "Error  - Invalid number of arguments. Try again." << endl;
		exit(0);
	}
	if (argv[1][0] != '-' || argv[1][1] != 'f')
	{
		cout << "Error - Invalid argument 1: input was ";
		cout << argv[1][0] << argv[1][1] << " instead of -f." << endl;
	}
	if (argv[3][0] != '-' || argv[3][1] != 'b')
	{
		cout << "Error - Invalid argument 3: input was ";
		cout << argv[3][0] << argv[3][1] << " instead of -b." << endl;
	}
	if (argv[5][0] != '-' || argv[5][1] != 'r')
	{
		cout << "Error - Invalid argument 5: input was ";
		cout << argv[5][0] << argv[5][1] << " instead of -r." << endl;
	}
	if (argv[7][0] != '-' || argv[7][1] != 'c')
	{
		cout << "Error - Invalid argument 7: input was ";
		cout << argv[7][0] << argv[7][1] << " instead of -c." << endl;
	}
	if (argv[9][0] != '-' || argv[9][1] != 'v')
	{
		cout << "Error - Invalid argument 9: input was ";
		cout << argv[9][0] << argv[9][1] << " instead of -v." << endl;
	}
}

void try_file(int argc, char* argv[], const char* filename)
{
	cout << "Opening file " ;
	fstream floorplan;	
	cout << filename << "..." << endl;
	try {
	floorplan.exceptions (ifstream::failbit);
	floorplan.open(filename, ios::in);
	floorplan.close();
	}
	catch(ifstream::failure e) {
		cout << "File opening failed." << endl;
		exit(0);
	}
	cout << "File opening succeeded." << endl;
}

int main(int argc, char* argv[])
{
	check_arguments(argc, argv);
	const char* filename = argv[2];
	try_file(argc, argv, filename);
	cout << "It's roomba time!" << endl;
	Floor floorplan(filename, argv);
	cout << "Goodbye." << endl;
	return 0;
}