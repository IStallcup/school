#include <iostream>
#include <cmath>

using namespace std;

void get_bounds(float& lower_bound, float& upper_bound){
cout << "Upper bound: " << endl;
cin >> upper_bound;
cout << "Lower bound: " << endl;
cin >> lower_bound;
}

float sum_rect, sum_trap, bound_distance = 0;

//optional declaration


void integrate_rectangle(float lower_bound, float upper_bound){
float sum_rect = 0;
float rect_number = 0;

cout << "Enter number of rectangles:" << endl;
cin >> rect_number;
cout << bound_distance/rect_number << endl;
for (float x=lower_bound; x < upper_bound; x = x +(bound_distance/rect_number)){
	cout << "running" << endl;
		sum_rect += ((pow(x,5)+10)*(bound_distance/rect_number));
		cout << sum_rect << endl;
	}
	cout << sum_rect << endl;
}
	
		
void integrate_trapezoid(float lower_bound, float upper_bound){
float sum_trap = 0;
float trap_number = 0;
float triangle = 0;
float rect_trap = 0;

cout << "Enter number of trapezoids:" << endl;
cin >> trap_number;

for (float z=lower_bound; z < upper_bound; z = z + (bound_distance/trap_number)){
		rect_trap = ((pow(z,5))+10)*(bound_distance/trap_number);
		triangle = ((((pow(z+(bound_distance/trap_number),5))+10)-(pow(z,5)+10))*(bound_distance/trap_number))/2;
		sum_trap += rect_trap + triangle;
	}
	cout << sum_trap << endl;
}

int main(){


float upper_bound, lower_bound =0;
get_bounds(lower_bound, upper_bound);
bound_distance = upper_bound-lower_bound;
integrate_rectangle(lower_bound, upper_bound);
integrate_trapezoid(lower_bound, upper_bound);
}

