#include <iostream>
int main()

{

	cout << "Do you like vi as an editor? ";
	int yesno;
	cin >> yesno;
	if (yesno == true)
		cout << "You love vi!" << endl;
	if (yesno == false)
		cout << "You hate vi!" << endl;

	return 0;

}
