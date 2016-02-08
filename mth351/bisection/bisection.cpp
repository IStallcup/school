#include <iostream>
#include <cmath>

using namespace std;

double f(double input)
{
	double result;
	result = pow(input, 2);
	result += (2*input);
	result -= 2;
	return result;
}

double bijection(double upperbound, double lowerbound, double epsilon, double delta, int maxNumIterations, int currentIterations)
{
	if (currentIterations > maxNumIterations)
	{
		cout << "Max # Iterations reached." << endl;
		return -1;
	}
	
	/*cout << "upperbound: " << upperbound << endl;
	cout << "lowerbound: " << lowerbound << endl;
	cout << "currentIterations: " << currentIterations << endl;
	cout << "maxNumIterations: " << maxNumIterations << endl;*/
	
	double midpoint;
	midpoint = ((upperbound - lowerbound) / 2) + lowerbound;
	
	if (fabs(upperbound - lowerbound) < epsilon)
	{
		cout << "Epsilon limit reached." << endl;
		return midpoint;
	}
	
	/*cout << "midpoint: " << midpoint << endl;
	cout << "abs(f(midpoint)) = " << fabs(f(midpoint)) << endl;*/

	if (fabs(f(midpoint)) < delta)
	{
		cout << "Delta limit reached." << endl;
		return midpoint;
	}		
	cout << "f(midpoint)f(lowerbound) = " << f(midpoint) * f(lowerbound) << endl;
	cout << "f(midpoint)f(upperbound) = " << f(midpoint) * f(upperbound) << endl;
	if (f(midpoint) * f(lowerbound) < 0)
	{
		cout << "Sign change detected, root in interval betweeen " << lowerbound << " & " << midpoint << endl;
		return bijection(midpoint, lowerbound, epsilon, delta, maxNumIterations, ++currentIterations);
	}
	else if (f(midpoint) * f(upperbound) < 0)
	{
		cout << "Sign change detected, root in interval betweeen " << midpoint << " & " << upperbound << endl;
		return bijection(upperbound, midpoint, epsilon, delta, maxNumIterations, ++currentIterations);
	}
	else
	{
		cerr << "******No roots in selected bounds." << endl;
		return 	0;
	}
}

int main()
{
	double upperbound;
	double lowerbound;
	double epsilon;
	double delta;
	int maxNumIterations = 50;
	
	cout << "f(x) = x^2 + 2x -2" << endl;
	cout << "f(a); a = {0, 1, 2, ... , 5}" << endl;
	for (int a = 0; a <= 5; a++)
		cout << f(a) << endl;
	
	cout << "Upper bound: ";
	cin >> upperbound;
	cout << "Lower bound: ";
	cin >> lowerbound;
	cout << "Epsilon: ";
	cin >> epsilon;
	cout << "Delta: ";
	cin >> delta;
	
	cout << "Given tolerances, root is at approximately x = " << bijection(upperbound, lowerbound, epsilon, delta, maxNumIterations, 0) << endl;
	
	return 0;
}