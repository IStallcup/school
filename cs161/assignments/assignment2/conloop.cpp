/************************************************************
 * Program Filename: conloop.cpp
 * Author: Isaac Stallcup
 * Date: 10/22/2014
 * Description: Prompts user for number of
 * 	test scores to input, accepts that many
 * 	test scores, averages them then outputs
 * 	the anwer to the screen.
 * Input: Number of test scores, that many test scores.
 * Output: Average of the inputtted scores.
*************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

int main () 
{
	
	std::cout << "How many test scores would you like to input? ";
	std::string nscoresstr;		//number of scores; string for error checking
	std::cin >> nscoresstr;

	int qqq = 0;				//couting variable
	int nscores = 0;			//will be number of scores

	//error checking courtesy of Jennifer
	while (qqq < nscoresstr.length()) 	//check through string one character at a time
	{
		while (nscoresstr == "0")   //cannot average/input 0 test scores
		{
				std::cout << "Please enter a non-zero number: ";
				std::cin >> nscoresstr;
		}
		if (nscoresstr.at(qqq) < '0' || nscoresstr.at(qqq) > '9')	//if current character is not a number
		{
			std::cout << "Please enter a whole positive number: ";	//negative & nonwhile numbers are rejected
			std::cin >> nscoresstr;									//get input again
			while (nscoresstr == "0")   //cannot average/input 0 test scores
			{
				std::cout << "Please enter a non-zero number: ";
				std::cin >> nscoresstr;
			}
			qqq = 0;	 //reset while loop to check newly inputted string from the beginning
		}
		else (qqq++); //if the currently examined character is a number, increment counting variable
	}
	if (nscoresstr != "0") //if the input is not zero...
		nscores = atoi(nscoresstr.c_str()); //set it to nscores
	else
	{
		std::cout << "Error: 0 scores" << std::endl << "Exiting..." << std::endl;
		exit(0);
	}
	std::string scorestring;	//each score; string for error checking
	float sumscores = 0;			//sum of scores
	float score;					//will be score

	for (int iii = 0; iii < nscores; iii++)
	{	
		std::cout << "Enter test score number " << iii + 1 << ": ";
		std::cin >> scorestring;
		//error checking loop
		for (int jjj = 0; jjj < scorestring.length(); jjj++) //check each character in the string
		{

			   	//check if the character is a number
			while ((scorestring.at(jjj) < '0' || scorestring.at(jjj) > '9') && scorestring.at(jjj) != '.')
			{
				std::cout << "Please enter a positive number: "; //if not get the string again
				std::cin >> scorestring;							   //until the user inputs a number
			}

			score = atof(scorestring.c_str()); //convert string to float

			while (score <= 0 || score >= 100) //check if number is between 0 and 100
			{
				std::cout << "Please enter a number between 0 and 100: ";
				std::cin >> scorestring;	//get string
				score = atof(scorestring.c_str()); //convert string to int
			}
		}

		//score = atof(scorestring.c_str()); //convert string to int again
		sumscores = sumscores + score; //add score to sum of scores
	}

	//average scores and output them
	std::cout << "Average of " << nscores << " scores: " << sumscores / nscores << std::endl;


}
