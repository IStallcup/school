#include <iostream>
#include <string>

using namespace std;

struct vehicle
{
	int wheels;
	int doors;
	string power;
	string name;
};

int main()
{
	cout << "How many vehicles do you have? ";
	int numv;
	cin >> numv;
	
	vehicle *list;
	list = new vehicle[numv];
	
	for (int i = 0; i < numv; i++)
	{
		cout << "What is this vehicle's name? ";
		cin.ignore();
		getline(cin, list[i].name);
		
		cout << "How many doors? ";
		cin >> list[i].doors;
		
		cout << "How is it powered? ";
		cin.ignore();
		getline(cin, list[i].power);
		
		cout << "How many wheels does it have? ";
		cin >> list[i].wheels;
	}
	
	for (int i = 0; i < numv; i++)
	{
		cout << list[i].name << ":" << endl;
		
		cout << "Vehicle " << i << " has ";
		cout << list[i].doors << " doors." << endl;
		
		cout << "Vehicle " << i << " is powered by ";
		cout << list[i].power << "." << endl;;
		
		cout << "Vehicle " << i << " has ";
		cout << list[i].wheels << " wheels." << endl;;
	}
}
