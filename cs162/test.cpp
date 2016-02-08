#include <iostream>
#include <fstream>

//using namespace std;
using std::fstream;
using std::ios;

int main()
{
	std::fstream ifile;
	
	ifile.open("in.txt", std::ios::in);
	
	char buff[64];
	
	ifile >> buff;
	
	ifile.close();
	
	
	
	std::fstream ofile;
	
	ofile.open("out.txt", std::ios::out | std::ios::app);
	
	ofile << buff << std::endl;
	
	ofile.close();
	
	return 0;
}