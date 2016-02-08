#include <iostream>

#define PROMPT "Please enter a whole number:"
#define NOT_PRIME "The number is not a prime number.\n" // /n instead of \n
#define PRIME "The number is a prime number.\n" //again no escape sequence
#define DONE 0			/* ends successful program */
#define FIRST_FACTOR 2  /* initial value in for loop, first possible prime factor is two */

using std::cout;
using std::cin;

int main ()
{
	int i;		 /* loop counter */
	int number; /* number provided by user */ //changed char to int

	cout << PROMPT; /* prompt user */
	cin >> number;	/* wait for user input */

	/* Prime numbers are defined as any number
	 * greater than one that is only divisible
	 * by one and itself. Dividing the number
	 * by two shortens the time it takes to 
	 * complete. */


	for (i = FIRST_FACTOR; i <= number/2; i++) //incrememt after variable used
		{ //no open braces
		//cout << number/2 << " " << i << "\n";
			if ( number%i == 0)
			{
				cout << NOT_PRIME << number; /* not prime */
				return DONE;	
			}
		
		}
	cout << PRIME;
	return 0;
}
