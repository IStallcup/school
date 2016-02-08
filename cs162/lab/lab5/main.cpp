#include <iostream>
#include "./v.h"
#include "./b.h"
#include "./c.h"
#include "./m.h"
#include "./s.h"

using namespace std;

int main()
{
	vehicle v(4);
	bike b(1);
	vehicle *vptr = &b;
	
	/*cout << v.get_seats() << endl;
	cout << b.get_seats() << endl;
	cout << v.get_toll() << endl;
	cout << b.get_toll() << endl;
	cout << vptr->get_seats() << endl;
	cout << vptr->get_toll() << endl;*/
	
	vehicle *v_array[4] = {new bike(1), new bike(2), new car(4), new motorcycle(2)};
	
	for (int i = 0; i < 4; i++)
	{
		cout << "Vehicle " << i << ": ";
		cout << v_array[i]->get_toll() << endl;
		v_array[i]->set_day(24);
		cout << "It is now Friday." << endl;
		cout << v_array[i]->get_toll() << endl;
		v_array[i]->set_day(26);
		cout <<"It is now Sunday." << endl;
		cout << v_array[i]->get_toll() << endl << endl;
	}
	
	
	return 0;
}