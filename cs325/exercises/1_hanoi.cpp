#include <cstdlib>
#include <iostream>

using namespace std;

void printArry (char* arry, int size)
{
	for (int i = 0; i < size; i++)
		cout << arry[i] << " ";
	cout << endl;
}

void populate (char* arry, int size, bool fill, char label)
{
	arry[0] = label;
	for (int i = 1; i <= size; i++)
	{

	}
}

int main(int argc, char** argv)
{
	int size = atoi(argv[1])+1;
	char* A = new char[size];
	char* B = new char[size];
	char* C = new char[size];

	populate(A, size, true, 'A');	

	printArry(A, size);

	delete(A);
	return 0;
}
