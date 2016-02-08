#include <iostream>
#include <cstdlib>

using namespace std;

int show_args(char *argv[], int i)
{
	if (i == 0)
		return 0;
	--i;
	cout << i << ": " <<  argv[i] << endl;
	return show_args(argv, i);
}

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

float error_check_number_f()
{
	string input_string;
	cin >> input_string;
	for (int r = 0; r < input_string.length(); r++)
	{
		while ((input_string.at(r) < '0' || input_string.at(r) > '9') && input_string.at(r) != '.')
		{
			cout << "Please enter a positive number." << endl;
			cin >> input_string;
			r = 0;
		}
	}
	return atof(input_string.c_str());
}

int print_type(char num_scores[])
{
	for (int t = 0; t < 5; t++)
	{
		type_tree(t);
		endings(t);
		if (!num_scores[t])
		{
			cout << "Error: No number supplied." << endl;
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
			if (yn == "no")
				return 0;
		}
		else cout << num_scores[t] << endl;
	}
	return 1;
}

int check_args(char *argv[], int i, char num_scores[])
{
	if (i == 0)
		return 0;
	--i;
	if (argv[i][0] == '-')
	{
		int num_holder = type_tree_arg(argv, i);
		if (num_holder == 5)
		{
			cout << "Error: Invalid character in command line arguments.";
			cout << endl;
			return 0;
		}
		num_scores[num_holder] = *argv[i+1];
	}
	return check_args(argv, i, num_scores);
}

void formatting_pre_weights()
{
	cout << "\n\n\t\tGrade Weights" << endl;
	cout << "Please enter the weight of each grade category, in %:" << endl;
}

void check_zero(int &zero_i)
{
	while (num_scores[zero_i] == 0)
		{
			zero_i++;
		}
}

void get_weight_all(char num_scores[], float weight[])
{
	formatting_pre_weights();
	float sum = 0;
	do{
		sum = 0;
		for (int weight_i = 0; weight_i < 5; weight_i++)
		{
			check_zero(weight_i);
			type_tree(weight_i);
			endings(weight_i);
			weight[weight_i] = error_check_number_f();
			sum = sum + weight[weight_i];
		}
		if (sum != 100)
			cout << "Weights do not add to 100." << endl;
	}while (sum != 100);
}

void numbering(int q, int i)
{
	if (i != 3 && i != 4)
		cout << " " << q+1 << ":\t\t\t\t\t";
	else
		cout << " " << q + 1 << ":\t\t\t\t";
}

void check_in_bounds(float& temp_col, string input_string)
{
	temp_col = error_check_number_f(input_string);
	while (temp_col < 0 || temp_col > 100)
	{
		cout << "Please enter a score between 0 and 100: ";
		temp_col = number_check(in_str);
	}
}

void get_score(int score_i, int score_q, float& temp_col)
{
	check_zero(score_i);
	type_tree(score_i);
	numbering(score_q, score_i);
	check_in_bounds(temp_col, input_string);
	sum_scores[score_i] = sum_scores[score_i] + temp_col;
}

void get_scores_all(char num_scores[], float weight[], float sum_scores[])
{
	//formatting_pre_scores();
	for (int score_i = 0; score_i < 5; score_i++)
	{
		for (int score_q = 0; score_q < num_scores[i]; score_q++)
		{
			get_score(score_i, score_q);
		}
		if (num_scores[score_i] != 0)
		{
			sum_scores[score_i] = sum_scores[score_i] / num_scores[score_i];
		}
		sum_scores[score_i] = sum_scores[score_i] * (weight[score_i]/100);
		cout << endl;
	}
}

int main(int argc, char *argv[])
{
	int i = argc;
	char *num_scores;
	num_scores = new char[5];
	check_args(argv, i, num_scores);
	if (print_type(num_scores) == 0)
		return 0;
	float *weight;
	weight = new float[5];
	get_weight_all(num_scores, weight);
	
	float *sum_scores;
	sum_scores = new float[5];
	get_scores_all(num_scores, sum_scores);
	
	delete sum_scores;
	delete weight;
	delete num_scores;
	return 0;
}
