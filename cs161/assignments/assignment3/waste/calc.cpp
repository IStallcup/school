#include <iostream>
#include <cstdlib>
#include <string>
#include "calchead.h"

void check_is_num(std::string& temp_string)
{
	for (int iii; iii < temp_string.length(); iii++)
	{
		while (temp_string.at(iii) < '0' || temp_string.at(iii) > '9')
		{
			if (temp_string.at(iii) == ' ')
			{
				std::cout << "Enter a whole number: ";
				std::cin >> temp_string;
				iii = 0;
				break;
			}
			std::cout << "Enter a whole number: ";
			std::cin >> temp_string;
			iii = 0;
		}
	}
}

void check_is_float(std::string& temp_string)
{
	for (int iii; iii < temp_string.length(); iii++)
	{
		while ((temp_string.at(iii) < '0' || temp_string.at(iii) > '9') && temp_string.at(iii) != '.')
		{
			if (temp_string.at(iii) == ' ')
			{
				std::cout << "Enter a whole number: ";
				std::cin >> temp_string;
				iii = 0;
				break;
			}
			std::cout << "Enter a whole number: ";
			std::cin >> temp_string;
			iii = 0;
		}
	}
}

int check_is_yn(std::string temp_string)
{
	if (temp_string == "yes" || temp_string == "y")
		return 1;
	else if (temp_string == "no" || temp_string == "n")
		return 0;
	else if (temp_string != "yes" && temp_string != "y" && temp_string != "no" && temp_string != "n")
		return 2;
}

void get_num_test(int& num_test)
{
	std::cout << "How many tests are there? ";
	std::cin >> temp_string;
	check_is_num(temp_string);
	num_test = atoi(temp_string.c_str());
}

void get_num_quiz(int& num_quiz)
{
	std::cout << "How many quizzes are there? ";
	std::cin >> temp_string;
	check_is_num(temp_string);
	num_quiz = atoi(temp_string.c_str());
}

void get_num_assign(int& num_assign)
{
	std::cout << "How many assignments are there? ";
	std::cin >> temp_string;
	check_is_num(temp_string);
	num_assign = atoi(temp_string.c_str());
}

void get_num_lab(int& num_lab)
{
	std::cout << "How many labs are there? ";
	std::cin >> temp_string;
	check_is_num(temp_string);
	num_lab = atoi(temp_string.c_str());
}

void get_b_final(bool& final)
{
	std::cout << "Is there a final? ";
	std::cin >> temp_string;
	while (check_is_yn(temp_string) == 2)
	{
		std::cout << "Enter yes or no: ";
		std::cin >> temp_string;
	}
	final = check_is_yn(temp_string);
}

void get_num_all(int& num_test, int& num_quiz, int& num_assign, int& num_lab, bool& final)
{
	get_num_test(num_test);
	get_num_quiz(num_quiz);
	get_num_assign(num_assign);
	get_num_lab(num_lab);
	get_b_final(final);
}


void get_w_test(float& w_test)
{
	std::cout << "What is the weight of the tests, in %? ";
	std::cin >> temp_string;
	check_is_float(temp_string);
	w_test = atof(temp_string.c_str());
}

void get_w_quiz(float& w_quiz)
{
	std::cout << "What is the weight of the quizzes, in %? ";
	std::cin >> temp_string;
	check_is_float(temp_string);
	w_quiz = atof(temp_string.c_str());
}

void get_w_assign(float& w_assign)
{
	std::cout << "What is the weight of the assignments, in %? ";
	std::cin >> temp_string;
	check_is_float(temp_string);
	w_assign = atof(temp_string.c_str());
}

void get_w_lab(float& w_lab)
{
	std::cout << "What is the weight of the labs, in %? ";
	std::cin >> temp_string;
	check_is_float(temp_string);
	w_lab = atof(temp_string.c_str());
}

void get_w_final(float& w_final)
{
	std::cout << "What is the weight of the final, in %? ";
	std::cin >> temp_string;
	check_is_float(temp_string);
	w_final = atof(temp_string.c_str());
}

bool check_w(float w_test, float w_quiz, float w_assign, float w_lab, float w_final)
{
	if ((w_test + w_quiz + w_assign + w_lab + w_final) != 100)
	{
		std::cout << "Weights do not add to 100. " << std::endl;
		return false;
	}
	else if ((w_test + w_quiz + w_assign + w_lab + w_final) == 100)
	{
		return true;
	}
}

//TWELVE LINES, BE CAREFUL!
void get_w_all(float& w_test, float& w_quiz, float& w_assign, float& w_lab, bool final, float& w_final)
{
	do {
	if (num_test != 0)
		get_w_test(w_test);
	if (num_quiz != 0)
		get_w_quiz(w_quiz);
	if (num_assign != 0)
		get_w_assign(w_assign);
	if (num_lab != 0)
		get_w_lab(w_lab);
	if (final == true)
		get_w_final(w_final);
	}while(check_w(w_test, w_quiz, w_assign, w_lab, w_final) == 0);
}

void get_s_lab(float& s_lab, int num_lab)
{
	for (int i = 0; i < num_lab; i++)
	{
	}
}

void get_s_final(float& s_final)
{
	std::cout << "What is the score of the final, in %? ";
	std::cin >> temp_string;
	check_is_float(temp_string);
	s_final = atof(temp_string.c_str());
}

void get_s_all(float& s_test, float& s_quiz, float& s_assign, float& s_lab, bool final, float& s_final, int num_test, int num_quiz, int num_assign, int num_lab)
{
	/*if (num_test != 0)
		get_s_test(s_test, num_test);
	if (num_quiz != 0)
		get_s_quiz(s_quiz, num_quiz);	
	if (num_assign != 0)
		get_s_assign(s_assign, num_assign);
	if (num_lab != 0)
		get_s_lab(s_lab, num_lab);*/
	if (final == true) 
		get_s_final(s_final);
}

int main()
{
	get_num_all(num_test, num_quiz, num_assign, num_lab, final);
	get_w_all(w_test, w_quiz, w_assign, w_lab, final, w_final);	
	get_s_all(s_test, s_quiz, s_assign, s_lab, final, s_final, num_test, num_quiz, num_assign, num_lab);
}
