#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//from cplusplus.com page on generate()
struct c_unique
{
	int current;
	c_unique() {current=0;}
	int operator()() {return ++current;}
} UniqueNumber;

void buildPancakes(vector<int>* pancakes)
{
	//generate then randomly shuffle the pancake pile
	generate(pancakes->begin(), pancakes->end(), UniqueNumber);
	random_shuffle(pancakes->begin(), pancakes->end());
}

void printPancakes(vector<int> pancakes)
{
	for (int i = 0; i < pancakes.size(); i++)
		cout << pancakes.at(i) << " ";
	cout << endl;
}

void flip(vector<int>* pancakes, int n)
{
	vector<int>::iterator floc = pancakes->begin();
	for (int i = 0; i <= n; i++)
		++floc;
	reverse(pancakes->begin(), floc);
	printPancakes(*pancakes);
}

void pancakeSort(vector<int>* pancakes, int n)
{
	if (n == 0)
		return;
	cout << "looking thru ";
	for (int i = 0; i < n; i++)
	{
		cout << pancakes->at(i) << " ";
	}
	cout << "for " << n << endl;
	
	for (int i = 0; i < n; i++)
	{
		if (pancakes->at(i) == n)
		{
			//we've found the desired pancake
			if (i == 0)
			{
				//we're at the top
				cout << "at the top" << endl;
				//flip entire stack
				flip(pancakes, n-1);
				break;
			}
			else if (i == n-1)
			{
				//we're at the bottom
				cout << "at the bottom" << endl;
				//do nothing, move on
				break;
			}
			else
			{
				cout << "flip after #" << i+1 << endl;
				//flip after the "i+1"th pancake
				flip(pancakes, i);
				//then flip the entire stack
				flip(pancakes, n-1);
				break;
			}
		}
	}
	pancakeSort(pancakes, n-1);

}

int main(int argc, char* argv[])
{
	srand(unsigned(time(0)));
	
	vector<int> pancakes (atoi(argv[1]));

	buildPancakes(&pancakes);

	printPancakes(pancakes);

	pancakeSort(&pancakes, pancakes.size());

	return 0;
}
