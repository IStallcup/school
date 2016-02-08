/*********************
** Program Filename: cond
** Author: Isaac Stallcup
** Date: 10/15/2014
** Description:
** Input:
** Output:
*********************/
#include <iostream> //for cout, endl, hex, oct, etc. etc.
#include <cmath> //for pow
#include <climits> //for macros SHRT_MIN, SHRT_MAX, etc. etc.
#include <iomanip> //for setprecision

using namespace std;


int main()
{

	//Formatting:

	cout << "\n\n--------ASSIGNMENT TWO--------\nIsaac Stallcup" << endl << endl;

	cout << "--------TEST SCORE AVERAGES--------" << endl;

	cout << "Please enter the number of test scores you wish to average." << endl;

	int nscores;

	cin >> nscores;

	int scoresum = 0; //sum/average of scores used for whole-number situations

	float fscoresum = 0; //used for non-whole-number situations

	float tempscore; //temp value for reading

	for (int iii = 0; iii < nscores; iii++)
	{
		cout << "Test " << iii + 1 << ":";

		cin >> tempscore;

		while (tempscore <= 0 || tempscore >= 100)
		{
			cout << "Please enter a value between 0 and 100.";
			cin >> tempscore;
		}

		fscoresum = fscoresum + tempscore;

		//cout << endl <<  scoresum << endl;

	}

	fscoresum = fscoresum/nscores; //fscoresum becomes the average of all 5 scores

	cout << endl << "Test average for " << nscores << "  scores:\t";
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
