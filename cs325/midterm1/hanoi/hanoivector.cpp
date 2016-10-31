#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void printTower(vector<int> T)
{
	for (int i = 0; i < T.size(); i++)
		cout << T.at(i) << ",";
	cout << endl;
}

void printA(vector<int> A)
{
	cout << "src: ";
	printTower(A);
}

void printB(vector<int> B)
{
	cout << "tmp: ";
	printTower(B);
}

void printC(vector<int> C)
{
	cout << "dst: ";
	printTower(C);
}

void printAll(vector<int> A, vector<int> B, vector<int> C)
{
	printA(A);
	printB(B);
	printC(C);
	cout << endl;
}

void initTowers(vector<int> &A, vector<int> &B, vector<int> &C, int size)
{
	for (int i = 0; i < size; i++)
	{
		A.push_back(i+1);
		B.push_back(0);
		C.push_back(0);
	}
}

void swap(vector<int> &src, vector<int> &dst)
{
	int i = 0;
	int j = 0;
	for(i = 0; i < src.size()-1; i++)
		if (src.at(i) != 0)
			break;

//	cout << "i=" << i << endl;

	for(j = 0; j < dst.size()-1; j++)
		if (dst.at(j+1) != 0)
			break;
	
//	cout << "j=" << j << endl;

	dst.at(j) = src.at(i);
	src.at(i) = 0;

	
}

void sortTowers(vector<int> &src, vector<int> &tmp, vector<int> &dst, int n)
{
	if (n == 0)
		return;
	sortTowers(src, dst, tmp, n-1);
	swap(src, tmp);
	sortTowers(dst, tmp, src, n-1);
}

int main(int argc, char* argv[])
{
	if (argc == 1)
		return 0;
	int size = atoi(argv[1]);
	
	vector<int> A;
	vector<int> B;
	vector<int> C;

	initTowers(A, B, C, size);

	printAll(A, B, C);
	
	sortTowers(A, B, C, size);

	printAll(A, B, C);
}
