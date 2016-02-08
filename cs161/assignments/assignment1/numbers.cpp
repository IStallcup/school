/*********************
** Program Filename: numbers
** Author: Isaac Stallcup
** Date: 10/9/2014
** Description: Program to take	different variable types
**	(short, int, long) and print the largest and smallest
**	signed and unsigned values these variables can hold,
**	and then to take in five test scores and summarily
**	display their average in decimal, binary, hexadecimal
**	and octal number systems.
** Input: Five test scores, chosen by the user
** Output: The largest and smallest unsigned and signed
**	short, int, and long variables, and their corresponding
**	macro values from the climits library, and the average
**	of the five inputted test scores in decimal, hex, octal
**	and binary.
*********************/
#include <iostream> //for cout, endl, hex, oct, etc. etc.
#include <cmath> //for pow
#include <climits> //for macros SHRT_MIN, SHRT_MAX, etc. etc.
#include <iomanip> //for setprecision

using namespace std;


int main(){
	
	//Formatting:

	cout << "\n\n--------ASSIGNMENT ONE--------\nIsaac Stallcup" << endl << endl;

	/*This psuedofunction calculates the max and min signed and unsigned
 	* value for certain variable types, displays the macro values from
 	* climits then displays the caluclated values.*/

	cout << "Signed short Values:" << endl;	
	
	short sshrtmax = pow(2, (8*sizeof(signed short) - 1)) - 1;

	short sshrtmin =  -pow(2,(8*sizeof(signed short) - 1));
	
	cout << "Signed SHRT_MIN:\t" << SHRT_MIN;
	cout <<  "\t" << "Signed SHRT_MAX:\t" << SHRT_MAX << endl;

	cout << "Calculated SHRT_MIN:\t" << sshrtmin << "\t";
	cout  << "Calculated SHRT_MAX:\t" << sshrtmax << endl << endl;
	
	cout << "Unsigned short Values:" << endl;

	unsigned short ushrtmax = pow(2, 8*sizeof(unsigned short)) - 1;
	
	cout << "Unsigned USHRT_MIN:\t0\tUnsigned USHRT_MAX:\t" << USHRT_MAX << endl;

	cout << "Calculated USHRT_MIN:\t0\tCalculated USHRT_MAX:\t" << ushrtmax << endl << endl;


	cout << "Signed int Values:" << endl;

	int sintmax = pow(2, (8*sizeof(signed int) - 1)) - 1;

	int sintmin = -pow(2, (8*sizeof(signed int) - 1));

	cout << "Signed INT_MIN:\t\t" << INT_MIN <<  "\t";
	cout << "Signed INT_MAX:\t\t" << INT_MAX << endl;	
	
	cout << "Calculated INT_MIN:\t" << sintmin << "\t";
	cout  << "Calculated INT_MAX:\t" << sintmax << endl << endl;

	cout << "Unsigned int Values:" << endl;	

	unsigned int uintmax = pow(2, 8*sizeof(unsigned int)) - 1;

	cout << "Unsigned UINT_MIN:\t0\tUnsigned UINT_MAX:\t" << UINT_MAX << endl;

	cout << "Calculated UINT_MIN:\t0\tCalculated UINT_MAX:\t" << uintmax << endl << endl;


	cout << "Signed long Values:" << endl;

	long slngmax = pow(2, (8*sizeof(signed long) - 1)) - 1;

	long slngmin = -pow(2, (8*sizeof(signed long) - 1));

	cout << "Signed LONG_MIN:\t" << LONG_MIN << "\t";
	cout << "Signed LONG_MAX:\t" << LONG_MAX << endl;

	cout << "Calculated LONG_MIN:\t" << slngmin << "\t";
	cout  << "Calculated LONG_MAX:\t" << slngmax - 1 << endl << endl;
	//Somehow slngmax was still one too high, despite the
	//-1 on the end of its calculation, so another
	//one was subtracted.
	
	cout << "Unsigned long Values:" << endl;	

	unsigned long ulngmax = pow(2, 8*sizeof(unsigned long)) - 1;

	cout << "Unsigned ULONG_MIN:\t0\tUnsigned ULONG_MAX:\t" << ULONG_MAX << endl;

	cout << "Calculated ULONG_MIN:\t0\tCalculated ULONG_MAX:\t" << ulngmax - 1 << endl << endl;
	//Again ulngmax was one too large.
	

	cout << endl << endl;

	//More formatting:
	
	cout << "--------TEST SCORE AVERAGES--------" << endl;

	cout << "Please enter five test scores." << endl;

	int scoresum = 0; //sum/average of scores used for whole-number situations

	float fscoresum = 0; //used for non-whole-number situations

	float tempscore; //temp value for reading

	for (int iii = 0; iii < 5; iii++)
	{
		cout << "Test " << iii + 1 << ":";
		
		cin >> tempscore;

		fscoresum = fscoresum + tempscore;

		//cout << endl <<  scoresum << endl;
		
	}

	fscoresum = fscoresum/5; //fscoresum becomes the average of all 5 scores

	cout << endl << "Test average for 5 scores:\t";
	cout << fixed << setprecision(1) << fscoresum  << endl;

	scoresum = roundf(fscoresum);

	//scoresum here becomes the rounded average of the sum of the 5 scores

	cout << "Rounded score average:\t\t" << scoresum << endl;
	
	cout << "Hexadecimal average:\t\t" << hex << scoresum << endl;

	cout << "Octal average:\t\t\t" << oct << scoresum << endl;

	cout << "Binary average:\t\t\t";

	//the loop is iterated 6 times because 2^6 is the highest binary digit used

	for (int iii = 6; iii >= 0; iii--)
	{
		cout << scoresum/(int)pow(2, iii);
		//becuase of integer division this is either zero or one
		if ( scoresum/(int)pow(2, iii) >= 1)
		{
			//if the current power of 2 goes into the average/current average,
			//subtract that power of two from the average in order
			//to continue finding powers of two that add to the average.
			scoresum = scoresum - (int)pow(2, iii);
		}
	}
	cout << endl << endl << endl; //more formatting
	return 0;

}
