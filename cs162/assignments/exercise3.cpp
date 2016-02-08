#include <fstream>
#include <iostream>

using namespace std;
using std::fstream;
using std::ios;

class Thing
{
	private:
	int x;
	int y;
	static int z;
	public:
	Thing()
		{x = y = z;}
	static void putThing (int a)
	{ z = a; }
	void print();
};

void Thing::print()
{
	cout << "x:" << x << " y:" << y << " z:" << z << endl;
}

int Thing::z = 3;

int main()
{
	Thing one, two, three;
	one.print();
	two.print();
	three.print();
}