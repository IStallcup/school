/***************************************
 *Program Filename: gradefinal.cpp
 *Author: Isaac Stallcup
 *Date: 11/6/2014
 *Description: Takes in all relevant grade
 *	data for a class, returns final grade.
 *Input: Numbers, class weight and individual
 *	scores for tests, quizzes, labs
 *	assignments and final
 *Output: Final grade in the class.
 ****************************************/
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//gloabl variables are bad, but until I tried to
//turn the program in on TEACH I was using a header
//file to declare them, but as there was no way to
//turn in the header file (or at least
//none that I know of), and  the program didn't work
//when I tried to declare them at certain times,
//I just left them here.
float temp_col;			//temporary collection for scores
int num_scores[5];		//array for number of scores for 5 categories
float sum_scores[5];	//array for sums of scores for 5 categories
float weight[5];		//array for weight of scores for 5 categories
string in_str;			//input string for many functions

/***************************************
 * Function: number_check_worker
 * Description: increments through input
 * 	string, checks each character to see
 * 	if it is a number or decimal point
 * Parameters: in_str [input string]
 * Pre-conditions: in_str is not empty
 * Post-conditions: if in_str contains a
 * 	non-digit, non-decimal character, 
 * 	returns false, otherwise return true
 ****************************************/

bool number_check_worker(string in_str)
{
	for (int x = 0; x < in_str.length(); x++)
	{
		//if the number is not a float
		if ((in_str.at(x) < '0' || in_str.at(x) > '9') && in_str.at(x) != '.')
			return false; //return false
	}
	return true;
}

/***************************************
 * Function: number_check
 * Description: checks an input to see if
 * 	it is a number
 * Parameters: in_str [input string]
 * Pre-conditions: none
 * Post-conditions: returns the float value
 * the user input (it must be float)
 ****************************************/

float number_check(string& in_str)
{
	cin >> in_str;
	//while the input string is not a nubmer
	while (number_check_worker(in_str) == false)
	{
		cout << "Please enter a positive number:\t\t";
		cin >> in_str;
	}
	//convert the string (which must be a number)
	//to a float, return it
	return atof(in_str.c_str());
}

/***************************************
 * Function: string_check_worker
 * Description: checks if input string is
 * 	"yes", "no" or neither
 * Parameters: in_str [input string]
 * Pre-conditions: none
 * Post-conditions: returns true if yes,
 * 	false if no, and error code 2 if neither
 ****************************************/

int string_check_worker(string in_str)
{
	if (in_str == "yes")
		return 1;
	if (in_str == "no")
		return 0;
	else return 2; //error code
}

/***************************************
 * Function: string_check
 * Description: gets input string, checks
 * 	if it is "yes", "no" or neither, then 
 * 	returns a 1 or 0 depending on the string
 * 	being "yes" or "no"
 * Parameters: in_str [input string]
 * Pre-conditions: none
 * Post-conditions: in_str is "yes" or "no";
 * 	returns the appropriate boolean value
 ****************************************/

int string_check(string& in_str)
{
	cin >> in_str;
	//while the input is not yes or no
	while (string_check_worker(in_str) == 2)
	{
		cout << "Please enter yes or no:\t\t\t\t";
		cin >> in_str;
	}
	//return 1 or 0 if yes or no respectively
	return string_check_worker(in_str);
}

/***************************************
 * Function: type_final
 * Description: interrupts loop asking
 * 	for numbers of scores, as there can
 * 	only be one final score
 * Parameters: int i [incrementing variable
 * 	passed from parent function]
 * Pre-conditions: i is either 4 or not 4
 * Post-conditions: returns true if there
 * 	is a final, otherwise returns false
 ****************************************/

int type_final(int i)
{
	if (i == 4)
	{
		cout << "\nIs there a final?\t\t\t\t";
		num_scores[i] = string_check(in_str);
		return 1;
	}
	else return 0;
}

/***************************************
 * Function: type_tree
 * Description: formatting function to print
 * 	various names of various score types
 * Parameters: int i [incrementing variable
 * 	passed from parent function]
 * Pre-conditions: i is between 0 and 5
 * Post-conditions: none
 ****************************************/

void type_tree(int i)
{
	if (i == 0)
		cout << "\tTest";
	if (i == 1)
		cout << "\tQuiz";
	if (i == 2)
		cout << "\tLab";
	if (i == 3)
		cout << "\tAssignment";
	else if (i == 4) cout << "\tFinal";
}

/***************************************
 * Function: endings
 * Description: formatting function to aid
 * 	in asking for or displaying information
 * Parameters: int i [incrementing variable
 * 	passed from parent function]
 * Pre-conditions: i is between 0 and 5
 * Post-conditions: none
 ****************************************/

void endings(int i)
{
		if (i == 1)
			cout << "zes:\t\t\t\t";
		if (i == 3)
			cout << "s:\t\t\t\t";
		if (i == 4)
			cout << ":\t\t\t\t\t";
		if (i == 5)
			;
		else if (i != 1 && i != 4 && i != 3) cout << "s:\t\t\t\t\t";
}

/***************************************
 * Function: formatting_pre_num
 * Description: formatting function before
 * 	asking for numbers of scores
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ****************************************/

void formatting_pre_num()
{
	cout << "\n\t\tGrade Calculator" << endl;
	cout << "=================================================" << endl << endl;
	cout << "\t\tNumber of scores" << endl;
	cout << "For this class, please enter the number of:" << endl;
}

/***************************************
 * Function: get_num_all
 * Description: gets the number of tests,
 * 	quizzes, labs, assignments and if there
 * 	is a final in the class by running the
 * 	appropriate functions
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ****************************************/

void get_num_all()
{
	formatting_pre_num();
	for (int i = 0; i < 5; i++)
	{
		if (type_final(i) == 1)
			break; //if we ask for the final
		type_tree(i);
		endings(i);
		num_scores[i] = number_check(in_str);
	}
}

/***************************************
 * Function: formatting_pre_weights
 * Description: formatting function before
 * 	asking for weights of categories
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ****************************************/

void formatting_pre_weights()
{
	cout << "\n\n\t\tGrade Weights" << endl;
	cout << "Please enter the weight of each grade category, in %:" << endl;
}

/***************************************
 * Function: check_zero
 * Description: checks to see if there are
 * 	none of a grade category in the class
 * Parameters: int i [incrementing variable
 * 	passed from parent function]
 * Pre-conditions: int i is or is not zero 
 * Post-conditions: increments i if there
 * 	are no scores for the current grade type
 ****************************************/

void check_zero(int& i)
{
	while (num_scores[i] == 0)
	{
		i++; //increment i
	}
}

/***************************************
 * Function: get_weight_all
 * Description: gets weights for each 
 * 	category from the user
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ****************************************/

void get_weight_all()
{
	formatting_pre_weights();
	float sum = 0;
	do{
		sum = 0;
		for (int i = 0; i < 5; i++)
		{
			check_zero(i);
			type_tree(i);
			endings(i);
			weight[i] = number_check(in_str);
			sum = sum + weight[i];
		}
		if (sum != 100)
			cout << "Weights do not add to 100." << endl;
	}while (sum != 100);
}

/***************************************
 * Function: formatting_pre_scores
 * Description: formatting function before
 * 	getting scores from the user
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ****************************************/

void formatting_pre_scores()
{
	cout << "\n\n\t\tScores" << endl;
	cout << "Please enter scores in percent form." << endl;
}

/***************************************
 * Function: numbering
 * Description: helps display sequential
 * 	numbering for getting scores
 * Parameters: int q, int i [incrementing
 * 	variables from parent function
 * Pre-conditions: none
 * Post-conditions: none
 ****************************************/

void numbering(int q, int i)
{	
	if (i != 3 && i != 4)
		cout << " " << q + 1 << ":\t\t\t\t\t";
	else
		cout << " " << q + 1 << ":\t\t\t\t";
}

/***************************************
 * Function: check_in_bounds
 * Description: gets a score input, checks
 * 	to see if it is between zero and 100,
 * 	if it is not gets it until it is
 * Parameters: float temp_col [temporary
 * 	collected value from parent function;
 * 	passed by address]
 * Pre-conditions: none
 * Post-conditions: temp_col is between
 * 0 and 100
 ****************************************/

void check_in_bounds(float& temp_col)
{
	temp_col = number_check(in_str);
	while (temp_col < 0 || temp_col > 100)
	{
		cout << "\tPlease enter a score between 0 and 100: ";
		temp_col = number_check(in_str);
	}
}

/***************************************
 * Function: get_score
 * Description: runs functions associated
 * 	with getting a score from the user
 * Parameters: int i, int q [incrementation
 * 	values passed from parent function], 
 * 	temp_col [temporary collected value that
 * 	will eventually be a score]
 * Pre-conditions: none
 * Post-conditions: none
 ****************************************/

void get_score(int i, int q, float& temp_col)
{
	check_zero(i);	
	type_tree(i);
	numbering(q, i);
	check_in_bounds(temp_col);
	//temp_col = number_check(in_str);
		//note: check_in_bounds contains the above
		//line of code, but also error checks it
		//and makes sure it is within bounds
	sum_scores[i] = sum_scores[i] + temp_col;
}

/***************************************
 * Function: get_scores_all
 * Description: master function to get
 * 	all scores of all types from the user
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ****************************************/

void get_scores_all()
{
	formatting_pre_scores();
	for (int i = 0; i < 5; i++)
	{
		//if the number of scores is zero, the average
		//of the zero scores remains zero
		for (int q = 0; q < num_scores[i]; q++)
		{
			get_score(i, q, temp_col);
		}
		if (num_scores[i] != 0)
		{
			sum_scores[i] = sum_scores[i] / num_scores[i];
		}
		sum_scores[i] = sum_scores[i] * (weight[i]/100.0);
		cout << endl;
	}
}

/***************************************
 * Function: display_parts
 * Description: displays grade earned
 * 	from individual score categories
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ****************************************/

//functino exists for ease of use and
//convenience
void display_parts()
{
	cout << "Percent of final grade earned from:" << endl;
	for (int i = 0; i < 5; i++)
	{
		type_tree(i);
		endings(i);
		cout << sum_scores[i] << " %" << endl;
	}
	cout << endl;
}

/***************************************
 * Function: final_grade_calc
 * Description: calculates and displays
 * 	final grade based on user input
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ****************************************/

void final_grade_calc()
{
	display_parts();
	float final_grade;
	for (int i = 0; i < 5; i++)
	{
		final_grade = final_grade + sum_scores[i];
	}
	cout << "=================================================" << endl;
	cout << "\t\t\tFinal grade:\t" << final_grade << " %" << endl;
}

/***************************************
 * Function: main
 * Description: main function; performs
 * 	functionality as described in program
 * 	header
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ****************************************/

int main()
{
	get_num_all();
	get_weight_all();
	get_scores_all();
	final_grade_calc();
	return 0;
}
