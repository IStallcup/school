#include <iostream>
#include <string>
#include <cstdlib>
#include "gradehead.h"

/***************Formatting********************/

void formatting_one()
{
  	std::cout << "\n\t\t  Grade Calculator"<< std::endl;
	std::cout << "====================================================" << std::endl << std::endl;
}

void formatting_two()
{
	std::cout << "\n\n\t\t\tGrade Weights" << std::endl << std::endl;
}

void formatting_three()
{
	std::cout << "\n\n\t\t\tScores" << std::endl;
	std::cout << "\tPlease enter all scores in percent form." << std::endl;
}

void formatting_four()
{
	std::cout << "\n\n\t\tFinal Grade" << std::endl << std::endl;
}

/***************Error Checking*****************/

int yn_check(std::string in_str)
{
	if (in_str == "yes")
		return 1;
	if (in_str == "no")
		return 0;
	if (in_str != "yes" || in_str != "no")
		return 2;
}

int yn_error_check(std::string& in_str)
{
	std::cin >> in_str;
	while (yn_check(in_str) == 2)
	{
		std::cout << "Please enter only yes or no:\t\t\t";
		std::cin >> in_str;
	}
	return yn_check(in_str);
}

bool f_num_check(std::string in_str)
{
	for (int x = 0; x < in_str.length(); x++)
	{
		if ((in_str.at(x) < '0' || in_str.at(x) > '9') && in_str.at(x) != '.')
			return false;
	}
	return true;
}

bool num_check(std::string in_str)
{
	for (int x = 0; x < in_str.length(); x++)
	{
		if (in_str.at(x) < '0' || in_str.at(x) > '9')
			return false;
	}
	return true;
}

void error_check(std::string& in_str)
{
	std::cin >> in_str;
	while(num_check(in_str) == false)
	{
		std::cout << "Enter only a whole, positive number:\t\t";
		std::cin >> in_str;
	}
}

bool zero_check(std::string in_str)
{
	if (in_str == "0")
		return false;
	else return true;
}

void float_check(std::string& in_str)
{
	std::cin >> in_str;
	while (zero_check(in_str) == false || f_num_check(in_str) == false)
	{
		std::cout << "Enter only a positive number:\t\t\t";
		std::cin >> in_str;
	}
}


/***************Get numbers****************/

int get_num_test()
{
	std::cout << "How many tests are in the class?\t\t";
	error_check(in_str);
	is_test = zero_check(in_str);
	return atoi(in_str.c_str());
}

int get_num_quiz()
{
	std::cout << "How many quizzes?\t\t\t\t";
	error_check(in_str);
	is_quiz = zero_check(in_str);
	return atoi(in_str.c_str());
}

int get_num_lab()
{
	std::cout << "How many labs?\t\t\t\t\t";
	error_check(in_str);
	is_lab = zero_check(in_str);
	return atoi(in_str.c_str());
}

int get_num_assign()
{
	std::cout << "How many assignments?\t\t\t\t";
	error_check(in_str);
	is_assign = zero_check(in_str);
	return atoi(in_str.c_str());
}

bool get_is_final()
{
	std::cout << "Is there a final?\t\t\t\t";
	return yn_error_check(in_str);
}

void get_num_all()
{
	num_test = get_num_test();
	num_quiz = get_num_quiz();
	num_lab = get_num_lab();
	num_assign = get_num_assign();
	is_final = get_is_final();
}

/****************rGet weights************/
r_check(in_str);
		zero_check(in_str);

int get_w_test()
{
	if (is_test == false)
		return 0;
	std::cout << "What percent of the class's grade is tests?\t";
	float_check(in_str);
	return atof(in_str.c_str());
}

int get_w_quiz()
{
	if (is_quiz == false)
		return 0;
	std::cout << "What percent is quizzes?\t\t\t";
	float_check(in_str);
	return atof(in_str.c_str());
}

int get_w_lab()
{
	if (is_lab == false)
		return 0;
	std::cout << "What percent is labs?\t\t\t\t";
	float_check(in_str);
	return atof(in_str.c_str());
}

int get_w_assign()
{
	if (is_assign == false)
		return 0;
	std::cout << "What percent is assignments?\t\t\t";
	float_check(in_str);
	return atof(in_str.c_str());
}

int get_w_final()
{
	if (is_final == false)
		return 0;
	std::cout << "What percent is the final?\t\t\t";
	float_check(in_str);
	return atof(in_str.c_str());
}

int is_only_final()
{

	if (!is_test && !is_quiz && !is_lab && !is_assign)
	{
		w_final = 100;
		return 1;
	}
	else return 0;
}

int is_only_assign()
{
	if (!is_test && !is_quiz && !is_lab && !is_final)
	{
		w_assign = 100;
		return 1;
	}
	else return 0;
}

int is_only_test()
{
	if (!is_quiz && !is_lab && !is_assign && !is_final)
	{
		w_test = 100;
		return 1;
	}
	else return 0;
}


int check_skip()
{
	if (is_only_test() || is_only_final() || is_only_assign())
	{	
		std::cout << "Only one weighted category detected." << std::endl;
		return 1;
	}
	else return 0;
}

void get_w_all()
{
	w_test = get_w_test();
	w_quiz = get_w_quiz();
	w_lab = get_w_lab();
	w_assign = get_w_assign();
	w_final = get_w_final();
}

void get_w_master()
{
	do{
		if (w_sum != 0)
			std::cout << "The percents entered do not add to 100.\nPlease try again." << std::endl;
		if (check_skip() == 1)
			break;
		get_w_all();
		w_sum = w_test + w_quiz + w_lab + w_assign + w_final;
	}while (w_sum < 100 || w_sum > 100);
}

/*******************Get scores***************/

void bounds_check()
{
	float_check(in_str);
	float temp_bounds_check = atof(in_str.c_str());
	while(temp_bounds_check < 0 || temp_bounds_check > 100)
	{
		std::cout << "Please enter a score between 0 and 100. " << std::endl;
		float_check(in_str);
		temp_bounds_check = atof(in_str.c_str());
	}
}

void printscores(int i)
{
	std::cout << "Please enter the ";
	if (i == 0 || i == 20)
		std::cout << i + 1 << "st score:\t\t\t";
	if (i == 1 || i == 21)
		std::cout << i + 1 << "nd score:\t\t\t";
	if (i == 2 || i == 22)
		std::cout << i + 1 << "rd score:\t\t\t";
	if ((i >= 3 && i <=19) || (i >= 23 && i <=29))
		std::cout << i + 1 << "th score:\t\t\t";
}

int get_a_test()
{
	if (is_test == false)
		return 0;
	std::cout << "\nFor " << num_test << " test(s): " << std::endl;
	for (int i = 0; i < num_test; i++)
	{
		printscores(i);
		bounds_check();
		a_test = a_test + atof(in_str.c_str());
	}
	a_test = (a_test/num_test) * (w_test/100);
	return a_test;
}

int get_a_quiz()
{
	if (is_quiz == false)
		return 0;
	std::cout << "\nFor " << num_quiz << " quzz(es): " << std::endl;
	for (int i = 0; i < num_quiz; i++)
	{
		printscores(i);
		bounds_check();
		a_quiz = a_quiz + atof(in_str.c_str());
	}
	a_quiz = (a_quiz/num_quiz) * (w_quiz/100);
	return a_quiz;
}

int get_a_lab()
{
	if (is_lab == false)
		return 0;
	std::cout << "\nFor " << num_lab << " lab(s): " << std::endl;
	for (int i = 0; i < num_lab; i++)
	{
		printscores(i);
		bounds_check();
		a_lab = a_lab + atof(in_str.c_str());
	}
	a_lab = (a_lab/num_lab) * (w_lab/100);
	return a_lab;
}

int get_a_assign()
{
	if (is_assign == false)
		return 0;
	std::cout << "\nFor " << num_assign << " assignment(s): " << std::endl;
	for (int i = 0; i < num_assign; i++)
	{
		printscores(i);
		bounds_check();
		a_assign = a_assign + atof(in_str.c_str());
	}
	a_assign = (a_assign/num_assign) * (w_assign/100);
	return a_assign;
}

int get_a_final()
{
	if (is_final == false)
		return 0;
	std::cout << "\nPlease enter the final exam score:\t\t";
	bounds_check();
	a_final = atof(in_str.c_str());
	a_final = a_final * (w_final/100);
	return a_final;
}

void get_a_all()
{
	a_test = get_a_test();
	a_quiz = get_a_quiz();
	a_lab = get_a_lab();
	a_assign = get_a_assign();
	a_final = get_a_final();
}

/*********************Final Grade***************/

void display_test()
{
	if (is_test != false)
		std::cout << "Grade earned from tests:\t\t\t" << a_test << std::endl;
}

void display_quiz()
{
	if (is_quiz != false)
		std::cout << "Grade earned from quizzes:\t\t\t" << a_quiz << std::endl;
}

void display_lab()
{
	if (is_lab != false)
		std::cout << "Grade earned from labs:\t\t\t\t" << a_lab << std::endl;
}

void display_assign()
{
	if (is_assign != false)
		std::cout << "Grade earned from assignments:\t\t\t" << a_assign << std::endl;
}

void display_final()
{
	if (is_final != false)
		std::cout << "Grade earned from final exam:\t\t\t" << a_final << std::endl;
}

void final_grade()
{
	grade_final = a_test + a_quiz + a_lab + a_assign + a_final;
	std::cout << "====================================================" << std::endl;
	std::cout << "\tFinal Grade:\t\t\t\t" << grade_final << "%" << std::endl;
}

void display_grade()
{
	display_test();
	display_quiz();
	display_lab();
	display_assign();
	display_final();
	final_grade();
}

int main()
{
	formatting_one();
	get_num_all();
	formatting_two();
	get_w_master();
	formatting_three();
	get_a_all();
	formatting_four();
	display_grade();
}
