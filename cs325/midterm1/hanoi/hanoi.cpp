#include <iostream>
#include <cstdlib>

using namespace std;

void printTower(int* T, int size)
{
	for (int i = 0; i < size; i++)
		cout << T[i] << ",";
	cout << endl;
}

void printA(int* A, int size)
{
	cout << "src: ";
	printTower(A,size);
}

void printB(int* B, int size)
{
	cout << "tmp: ";
	printTower(B,size);
}

void printC(int* C, int size)
{
	cout << "dst: ";
	printTower(C,size);
}

void printAll(int* A, int* B, int* C, int size)
{
	printA(A, size);
	printB(B, size);
	printC(C, size);
}

void initTowers(int* &A, int size)
{
	for (int i = 0; i < size; i++)
		A[i] = i+1;
}

void swap(int* &src, int* &dst, int size, int n)
//swaps idx-th elements of src and dst
{
	int low = 0;
	n--;
	//make low the index of the highest-index 0 in dst
	while (dst[low] == 0)
	{
		low++;
		if (low == size)
		{
			low--;
			break;
		}
		if (dst[low] != 0)
		{
			low--;
			break;
		}
	}	
	cout << "low=" << low << " n=" << n << endl;
	dst[low] = src[n];
	src[n] = 0;
	cout << endl;

}

void sortTowers(int* &src, int* &tmp, int* &dst, int size, int n)
{
	if (n == 0)
		return;
	sortTowers(src,dst,tmp,size,n-1);
	printAll(src,tmp,dst,size);
	swap(src,tmp,size,n);
	printAll(src,tmp,dst,size);
	swap(tmp,dst,size,n);
}

int main(int argc, char* argv[])
{
	if (argc == 1)
		return 0;
	int size = atoi(argv[1]);
	cout << size << endl;
	
	int* A = new int[size];
	int* B = new int[size];
	int* C = new int[size];

	initTowers(A, size);

	sortTowers(A, B, C, size, size);
	
	printAll(A, B, C, size);
	
	delete(C);
	delete(B);
	delete(A);
}
