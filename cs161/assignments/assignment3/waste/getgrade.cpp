#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int num_scores[5];
float sum_scores[5];
float weight[5];
string in_str;

bool number_check_at(string in_str)
{
	for (int x = 0; x < in_str.length(); x++)
	{
		if (in_str.at(x) == '.')
			cout << "float found" << endl;
		if ((in_str.at(x) < '0' || in_str.at(x) > '9') && in_str.at(x) != '.')
			return false;
	}
	cout << "number good" << endl;
	return true;
}

float number_check(string& in_str)
{
	cin >> in_str;
	while (number_check_at(in_str) == false)
	{
		cout << "Please enter a positive number:\t\t";
		cin >> in_str;
	}
	return atof(in_str.c_str());
}

int string_check_at(string in_str)
{
	if (in_str == "yes")
		return 1;
	if (in_str == "no")
		return 0;
	else return 2;
}

int string_check(string& in_str)
{
	cin >> in_str;
	while (string_check_at(in_str) == 2)
	{
		cout << "Please enter yes or no:\t\t\t\t";
		cin >> in_str;
	}
	return string_check_at(in_str);
}

int type_final(int i)
{
	if (i == 4)
	{
		cout << "Is there a final?\t\t\t\t";
		num_scores[i] = string_check(in_str);
		return 1;
	}
	else return 0;
}

void type_tree(int i)
{
	if (i == 0)
		cout << "test";
	if (i == 1)
		cout << "quiz";
	if (i == 2)
		cout << "lab";
	if (i == 3)
		cout << "assignment";
	else if (i == 4) cout << "final:\t\t";
}

void get_num_all()
{
	for (int i = 0; i < 5; i++)
	{
		if (type_final(i) == 1)
			break;
		cout << "Please enter the number of ";
		type_tree(i);
		if (i == 1)
			cout << "zes:\t\t";
		else cout << "s:\t\t";
		num_scores[i] = number_check(in_str);
	}
}

int get_sum_weights()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum = sum +  weight[i];
	}
	cout << "sum: " << sum << endl;
	if (sum == 100)
		return true;
	else 
	{
		cout << "Weights do not add to 100." << endl;
		return false;
	}
}

void get_weight_all()
{
	do{
		for (int i = 0; i < 5; i++)
		{
			while (num_scores[i] == 0)
			{
				cout << "skipping" << endl;
				i++;
			}
			cout << "Please enter the weight of ";
			type_tree(i);
			if (i == 1)
				cout << "zes:\t\t";
			else cout << "s:\t\t";
			weight[i] = number_check(in_str);
			cout << weight[i] << endl;
		}
	}while(get_sum_weights == 0);
}

void get_score_current(int i)
{
	cout << "Please enter scores for ";
	type_tree(i);
}

void get_scores_all()
{
	float temp_col;
	for (int i = 0; i < 5; i++)
	{
		for (int q = 0; q < num_scores[i]; q++)
		{
			get_score_current(i);
			cout << " " << q + 1 << ":\t\t"  << endl;
			temp_col = number_check(in_str);
			if (temp_col < 0 || temp_col > 100)
				cout << "bounds error" << endl;
			sum_scores[i] = sum_scores[i] + temp_col;
			cout << "sum: " << sum_scores[i] << endl;
		}
		cout << "category weight: " << weight[i] << endl;
		if (num_scores[i] != 0)
		{
			cout << "Average of sum: ";
			sum_scores[i] = sum_scores[i] / num_scores[i];
			cout << sum_scores[i] << endl;
		}
		sum_scores[i] = sum_scores[i] * (weight[i]/100.0);
		cout << "weighted sum: " << sum_scores[i] << endl;
	}
}

void final_grade_calc()
{
	float final_grade;
	for (int i = 0; i < 5; i++)
	{
		final_grade = final_grade + sum_scores[i];
	}
	cout << "Final grade: " << final_grade << endl;
}

int main()
{
	get_num_all();
	for (int j = 0; j < 5; j++)
		cout << num_scores[j] << " ";
	cout << endl;
	get_weight_all();
	for (int j = 0; j < 5; j++)
		cout << weight[j] << " ";
	cout << endl;
	get_scores_all();
	for (int l = 0; l < 5; l++)
		cout << sum_scores[l] << " ";
	final_grade_calc();
	cout << endl;
}
