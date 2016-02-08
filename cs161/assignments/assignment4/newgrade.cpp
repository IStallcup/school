/*********************************************************************  
 ** Program Filename:  newgrade.cpp
 ** Author: Isaac Stallcup
 ** Date: 11/18/2014
 ** Description: As assignment 3, but gets numbers of assignments via
 ** 		command line arumgnent.
 ** Input: Numbers of tests, quizzes, labs, assignments, and final(s)
 ** 		in command line form (and in any order) templated thus:
 ** 		-t * -l * -q * -a * -f *
 ** Output:  Final grade in the class based on the scores input.
 *********************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

/*********************************************************************  
 ** Function: show_args
 ** Description: Recursive function; displays all command line arguments 
 ** 		in descending order
 ** Parameters:  char* argv[], int i [iterator value inherited from parent
			function]
 ** Pre-Conditions: argc > 0
 ** Post-Conditions:  N/A
 *********************************************************************/  

int show_args(char* argv[], int i)
{
	if (i == 0)
		return 0;
	--i;
	cout << i << ": " <<  argv[i] << endl;
	return show_args(argv, i);
}

/*********************************************************************  
 ** Function:  type_tree_arg
 ** Description: returns a value 0-4 based on the option of the current
 ** 		argv value
 ** Parameters:  char *argv[], int i 
 ** Pre-Conditions: none
 ** Post-Conditions:  return 0-4 based on which option argv's current
 ** 		value is, or 5 if there is an error
 *********************************************************************/  

int type_tree_arg(char *argv[], int i)
{
	if (argv[i][1] == 't')
		return 0;
	if (argv[i][1] == 'l')
		return 1;
	if (argv[i][1] == 'q')
		return 2;
	if (argv[i][1] == 'a')
		return 3;
	if (argv[i][1] == 'f')
		return 4;
	else return 5;
}

/*********************************************************************  
 ** Function:  type_tree
 ** Description: prints category type
 ** Parameters:  int t [iterator value inherited from parent function]
 ** Pre-Conditions: 0 <= t <= 4
 ** Post-Conditions:  none
 *********************************************************************/  

void type_tree(int t)
{
	if (t==0)
		cout << "Test";
	if (t==1)
		cout << "Lab";
	if (t==2)
		cout << "Quiz";
	if (t==3)
		cout << "Assignment";
	if (t==4)
		cout << "Final";
}

/*********************************************************************  
 ** Function:  endings
 ** Description: formatting function to display endings to category names
 ** Parameters:  int i [counting parameter passed from parent function]
 ** Pre-Conditions: none
 ** Post-Conditions:  none
 *********************************************************************/  

void endings(int i)
{
		if (i == 2)
			cout << "zes:\t\t\t\t";
		if (i == 3)
			cout << "s:\t\t\t\t";
		if (i == 4)
			cout << ":\t\t\t\t\t";
		if (i == 5)
			;
		else if (i != 2 && i != 4 && i != 3) cout << "s:\t\t\t\t\t";
}

/*********************************************************************  
 ** Function:  error_check_number
 ** Description: gets and checks for errors an input string, then returns
 ** 		the input in integer form.
 ** Parameters:  none
 ** Pre-Conditions: none
 ** Post-Conditions:  returns integer
 *********************************************************************/  

char error_check_number()
{
	string input_string;
	cin >> input_string;
	for (int r = 0; r < input_string.length(); r++)
	{
		while (input_string.at(r) < '0' || input_string.at(r) > '9')
		{
			cout << "Please enter a positive whole number." << endl;
			cin >> input_string;
			r = 0;
		}
	}
	return atoi(input_string.c_str());
}

/*********************************************************************  
 ** Function:  error_check_number_f
 ** Description: gets and checks for errors an input string, then returns
 ** 		the input in float form
 ** Parameters:  none
 ** Pre-Conditions: none
 ** Post-Conditions:  returns float
 *********************************************************************/  

float error_check_number_f()
{
	string input_string;
	cin >> input_string;
	for (int r = 0; r < input_string.length(); r++)
	{
		while ((input_string.at(r) < '0' || input_string.at(r) > '9') && input_string.at(r) != '.')
		{
			cout << "Please enter a positive whole number.\t";
			cin >> input_string;
			r = 0;
		}
	}
	return atof(input_string.c_str());
}

/*********************************************************************  
 ** Function:  error_check_number_f_bounds
 ** Description: gets and checks for errors an input string, then returns
 **			the input if it is between 0 and 100 in float form
 ** Parameters:  none
 ** Pre-Conditions: none
 ** Post-Conditions:  none
 *********************************************************************/  

float error_check_number_f_bounds()
{
	string input_string;
	cin >> input_string;
	int check_bound = -1;
	while(check_bound < 0 || check_bound > 100)
	{
		for (int r = 0; r < input_string.length(); r++)
		{
			while ((input_string.at(r) < '0' || input_string.at(r) > '9') && input_string.at(r) != '.')
			{
				cout << "Please enter a positive whole number.\t";
				cin >> input_string;
				r = 0;
			}
		}
		check_bound = atof(input_string.c_str());
		if (check_bound < 0 || check_bound > 100)
		{
			cout << "Error: number out of bounds. Input number" << endl;
			cout << "between 0 and 100, inclusive.\t\t";
			cin >> input_string;
		}
	}
	
	return atof(input_string.c_str());
}

/*********************************************************************  
 ** Function:  error_type
 ** Description: displays the number of scores input to the screen,
 **			unless there is not a value input for an option; in that
 ** 		case it asks the user if they made a mistake. Based on their
 **			input, either reads in another input or exits.
 ** Parameters:  int num_scores[]
 ** Pre-Conditions: none
 ** Post-Conditions:  returns 0 if error; otherwise returns 1
 *********************************************************************/  

int error_type(int *num_scores)
{
	for (int t = 0; t < 5; t++)
	{
		type_tree(t);
		endings(t);
		if (!num_scores[t])
		{
			cout << "Error: no number supplied." << endl;
			cout << "Do you wish to substitute a value? ";
			string yn;
			cin >> yn;
			while (yn != "yes" && yn != "no")
			{
				cout << "Please enter yes or no." << endl;
				cin >> yn;
			}
			if (yn == "yes")
			{
				cout << "Please enter the number of scores: " << endl;
				num_scores[t] = error_check_number();
			}
			if (yn == "no")
				return 0;
		}
		else cout << num_scores[t] << endl;
	}
	return 1;
}

/*********************************************************************  
 ** Function:  error_check_arg
 ** Description: error checks command line arguments
 ** Parameters:  char *argv[], int i
 ** Pre-Conditions: none
 ** Post-Conditions:  returns 0 if error found; otherwise returns
 **			next command line argument in argv
 *********************************************************************/  

int error_check_arg(char *argv[], int i)
{
	int u = 0;
	for (int u = 0; u < 2; u++)
	{
		cout << "argv[i+1]: " << argv[i+1] << endl;
		if ((argv[i+1][u] < '0' || argv[i+1][u] > '9') && argv[i+1][u] != NULL)
		{
			cout << "Invalid character in command line arguments." << endl;
			cout << "Substituting zero." << endl;
			return 0;
		}
	}
	cout << "error_check_arg result: " << atoi(argv[i+1]) << endl;
	return atoi(argv[i+1]);
}

/*********************************************************************  
 ** Function:  print_type
 ** Description: if num_scores has an empty element, confirms that
 ** 		the user intentionally left the element blank.
 ** Parameters:  int num_scoresp[]
 ** Pre-Conditions: 
 ** Post-Conditions:  
 *********************************************************************/  

int print_type(int num_scores[])
{
	for (int t = 0; t < 5; t++)
	{
		type_tree(t);
		endings(t);
		if (!num_scores[t])
		{
			/*cout << "Error: No number supplied." << endl;
			cout << "Do you wish to substitute a value?" << endl;
			string yn;
			cin >> yn;
			while (yn != "yes" && yn != "no")
			{
				cout << "Please enter yes or no." << endl;
				cin >> yn;
			}
			if (yn == "yes")
			{
				cout << "Please enter the number of scores:" << endl;
				num_scores[t] = error_check_number();				
			}
			if (yn == "no")*/
				return 0;
		}
		else cout << num_scores[t] << endl;
	}
	return 1;
}

/*********************************************************************  
 ** Function:  check_args
 ** Description: checks command arguments for errors, sets 
 ** Parameters:  
 ** Pre-Conditions: 
 ** Post-Conditions:  
 *********************************************************************/  

int check_args(char *argv[], int i, int num_scores[])
{
	if (i==0)
		return 0;
	--i;
	
	if (argv[i][0] == '-')
	{
		/*cout << "check_args found - at position " << i << endl;*/
		int num_holder = type_tree_arg(argv, i );
		if (num_holder == 5)
		{
			cout << "Error: Invalid character in command arguments.";
			cout << endl;
			return 0;
		}
		int res_holder = 	atoi(argv[i+1]);
		/*cout << "res_holder: " << res_holder << endl;
		cout << "num_holswe: " << num_holder << endl;*/
		num_scores[num_holder] = atoi(argv[i+1]);
		/*cout << "num_scores[" << num_holder << "]: " << num_scores[num_holder] << endl;*/
	}
	
	return check_args(argv, i, num_scores);
}

/*********************************************************************  
 ** Function: formatting_pre_weights
 ** Description:  formatting function
 ** Parameters:  none
 ** Pre-Conditions: none
 ** Post-Conditions:  none
 *********************************************************************/  

void formatting_pre_weights()
{
	cout << "\n\n\t\tGrade Weights" << endl;
	cout << "Please enter the weight of each grade category, in %: " << endl;
}

/*********************************************************************  
 ** Function: check_zero
 ** Description:  checks to see if num_scores at an iterator is zero; if
 **			it is, it iterates it
 ** Parameters:  int zero_i [passed by reference], int num_scoresp[]
 ** Pre-Conditions: none
 ** Post-Conditions:  none
 *********************************************************************/  

void check_zero(int &zero_i, int num_scores[])
{
	while (num_scores[zero_i] == 0)
		{
			zero_i++;
		}
}

/*********************************************************************  
 ** Function: get_weight_all
 ** Description: gets weights for each 
 ** 	category from the user
 ** Parameters: none
 ** Pre-conditions: none
 ** Post-conditions: none
 *********************************************************************/  

void get_weight_all(int num_scores[], float weight[])
{
	formatting_pre_weights();
	float sum = 0;
	do{
		sum = 0;
		for (int weight_i = 0; weight_i < 5; weight_i++)
		{
			check_zero(weight_i, num_scores);
			type_tree(weight_i);
			endings(weight_i);
			weight[weight_i] = error_check_number_f();
			sum = sum + weight[weight_i];
		}
		if (sum != 100)
			cout << "Weights do not add to 100." << endl;
	}while (sum != 100);
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
		cout << " " << q+1 << ":\t\t\t\t\t";
	else
		cout << " " << q + 1 << ":\t\t\t\t";
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
 
void get_score(int score_i, int score_q, int num_scores[], float sum_scores[])
{
	check_zero(score_i, num_scores);
	type_tree(score_i);
	numbering(score_q, score_i);
	sum_scores[score_i] = sum_scores[score_i] + error_check_number_f_bounds();
	//cout << "Current sum of " << sum_scores[score_i] << endl;
}

/***************************************
 * Function: get_scores_all
 * Description: master function to get
 * 	all scores of all types from the user
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ****************************************/
 
void get_scores_all(int num_scores[], float weight[], float sum_scores[])
{
	for (int score_i = 0; score_i < 5; score_i++)
	{
		for (int score_q = 0; score_q < num_scores[score_i]; score_q++)
		{
			get_score(score_i, score_q, num_scores, sum_scores);
		}
		if (num_scores[score_i] != 0)
		{
			sum_scores[score_i] = sum_scores[score_i] / num_scores[score_i];
		}
		cout << "Average score for category: " << sum_scores[score_i] << endl;
		sum_scores[score_i] = sum_scores[score_i] * (weight[score_i]/100);
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

 void display_parts(float sum_scores[])
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
 
void final_grade_calc(float sum_scores[])
{
	display_parts(sum_scores);
	float final_grade;
	for (int i = 0; i < 5; i++)
	{
		final_grade = final_grade + sum_scores[i];
	}
	cout << "====================================================" << endl;
	cout << "\t\t\tFinal grade:\t" << final_grade << " %" << endl;
}

/***************************************
 * Function: formatting_pre_scores
 * Description: formatting function before
 * 	checking args
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 ****************************************/
 
void formatting_pre_args(int argc)
{
	cout << endl << endl;
	cout << "====================================================" << endl;
	cout << "\t\tGrade Calculator" << endl;
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
 
int main(int argc, char *argv[])
{
	int i = argc;
	//show_args(argv, i);
	int *num_scores = new int[5];
	formatting_pre_args(argc);
	check_args(argv, i, num_scores);
	
	if (print_type(num_scores) == 0)
	{
		return 0;	
	}
	
	float *weight = new float[5];
	get_weight_all(num_scores, weight);
	cout << endl;
	
	float *sum_scores = new float[5];
	get_scores_all(num_scores, weight, sum_scores);
	
	final_grade_calc(sum_scores);
	
	delete sum_scores;
	delete weight;
	delete num_scores;
	return 0;
}


























