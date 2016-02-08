#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>


using namespace std;

int determine_CharState(char input)
{
	if (input == 120) //x
		return 1;
	else if (input == 94) //^
		return 2;
	else if (input == 43) //+
		return 3;
	else if (input == 45) //-
		return 4;
	else if (input >= 48 && input <= 57) //numeral
		return 5;
	else return 0; //empty
}

char* derive(char* input_poly, int* CharState, int stateLocation, int charsPoly)
{
	char output_poly[64]; //hard-coded limit of output polynomial; be careful, to be fixed later
	char exponent_array[64]; //exponent has same issue
	int exponent;
	cout << "Deriving..." << endl;
	if (!CharState[stateLocation]) //make sure that the start location in CharState actually exists
		return "error"; //if not exit
	int degreeChars = 0; //#chars in nth degree polynomial
	for (int i = stateLocation; i < charsPoly; i++) //go through CharState to parse the # chars in nth degree element of polynomial
	{
		if (CharState[i] == 3 || CharState[i] == 4) //if beyond the nth degree, exit
			break;
		cout << CharState[i] << endl;
		degreeChars++; //increase # chars in nth degree
	}
	
	//now we know where the nth degree element is and how long it is; all that remains is to perform exponent rule of differentiation
	int j = 0;
	output_poly[j] = 'a'; //********************************************************************************************************************deleted when passed?????
	j++;
	for (int i = stateLocation+2; i < degreeChars; i++)
	{
		exponent_array[j] = input_poly[i];
		output_poly[j] = input_poly[i]; //also sets output polynomial's first few elements to the exponent
		cout << output_poly[j];
		if (i+1 == degreeChars) {exponent_array[j]--;}
		j++;
	}
	
	output_poly[j] = 'x';
	cout << output_poly[j];
	j++;
	output_poly[j] = '^';
	cout << output_poly[j];
	j++;
	cout << "exponent : " << exponent_array;
	for (int i = 0; i < degreeChars-2; i++)
	{
		output_poly[j] = exponent_array[i];
		j++;
	}
	cout << endl << output_poly << endl;
	return output_poly;
}

char* coefficient_derive(char* input_poly, int* CharState, int stateLocation) //also handles constants
{
	cout << "Coefficient Deriving..." << endl;
	if (!CharState[stateLocation])
		return "error";
	return input_poly;
}

int main(int argc, char* argv[])
{
	char* master_poly = argv[1]; //put argument polynomial into a character string
	cout << "polynomial: " << master_poly << endl;
	int charsPoly = strlen(master_poly); //calculate # of characters in polynomial
	//array to hold the type of each character in a polynomial
	int CharState[charsPoly]; //0=empty, 1=x, 2=^, 3=+, 4=-, 5=numeral
	for (int i = 0; i < charsPoly; i++) //set character state array
	{
		CharState[i] = determine_CharState(master_poly[i]); //set each element of array to corresponding character state
		cout << CharState[i];
	}
	cout << endl;
	for (int i = 0; i < charsPoly; i++)
	{
		if (CharState[i] == 5)
			cout << coefficient_derive(master_poly, CharState, i) << endl;
		else if (CharState[i] == 1)
			cout << derive(master_poly, CharState, i, charsPoly) << endl;
		else return 0;
	}
	
	
	return 0;
}