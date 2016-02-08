#include <iostream>
#include <cmath>

using namespace std;

double f(double input_value)
{
	double output_value;
	
	output_value = pow(input_value, 2);
	
	output_value += (input_value * 2);
	
	output_value -= 2;
	
	return output_value;
}

int main()
{
	double x_initial;
	double x_pre_initial;
	
	cout << "Secant method of f(x)" << endl;
	
}