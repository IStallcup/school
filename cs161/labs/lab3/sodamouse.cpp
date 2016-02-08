#include <iostream>

using namespace std;

int main()
{
	float lethalmouse;
	cout << "How many milligrams of sweetener kill a mouse? ";
	cin >> lethalmouse;

	float mouseweight;
	cout << "How many grams does a mouse weigh? ";
	cin >> mouseweight;
	mouseweight = (1/1000)*mouseweight;

	float dieterweight;
	cout << "How much will the dieter weigh after";
	cout << " they finish dieting, in kilograms? ";
	cin >> dieterweight;

	float age;
	cout << "How long will you live, in years? ";
	cin >> age;
	age = age*52;

	float nsodas;
	cout << "How many sodas do you drink per week? ";
	cin >> nsodas;

	cout << "Diet soda has 1/10 of 1\% sweetener by mass." << endl;
	cout << "A Diet Coke also weighs 355.1g." << endl;
	const float NSWEETENER = .001*355.1;

	float ld50 = (lethalmouse/mouseweight);
	float gramstokill = ((ld50*dieterweight)/1000);
	float sodastokill = gramstokill/NSWEETENER;
	float sodasinlife = nsodas*age;

	cout << "You require " << gramstokill << " g to kill you." << endl;
	cout << "You will consume " << sodasinlife*NSWEETENER << "g in your lifetime." << endl; 

	if (sodastokill >= sodasinlife)
	{
		cout << "You gon' die!" << endl;
	}

	if (sodastokill < sodasinlife)
	{
		cout << "You gon' live!" << endl;
	}


}

