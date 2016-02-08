#include <iostream>



using namespace std;

int main()
{
	float weightoz;
	cout << "How much cereal is in a box, in ounces?" << endl;
	cin >> weightoz;
	cin.get();
	
	int age;
	cout << "How long do you expect to live?" << endl;
	cin >> age;
	cin.get();

	int cereal_week;
	cout << "How many boxes of cereal do you eat per week?" << endl;
	cin >> cereal_week;
	cin.get();

	const float OZPTON = 35273.92;	

	float ton;
	ton = weightoz/OZPTON;
	
	int totalboxes;
	totalboxes = (age*52)*cereal_week;
	
	cout << "Weight of a box in tons is " << ton  << endl;

	ton = OZPTON/weightoz;

	cout << "Number of boxes per ton of cereal is " << ton << endl;
	
	cout << "Total number of boxes eaten in a lifetime is " << totalboxes << endl;

	return 0;

}

