#include <iostream>
#include <cstdlib>
#include <string>
#include "header.h"

void numget(std::string& str_num_scores)
{
	std::cout << "Number of test scores you wish to input: ";
	std::cin >> str_num_scores;
}

void strcheck(std::string& str_num_scores)
{
	for (int iii; iii < str_num_scores.length(); iii++)
	{
		while (str_num_scores.at(iii) < '0' || str_num_scores.at(iii) > '9') 
		{
			numget(str_num_scores);
			iii = 0;
		}
	}
}

void strconvert(std::string& str_num_scores, int& num_scores)
{
	num_scores = atoi(str_num_scores.c_str());
}


void get_scores_num(int& num_scores, std::string& str_num_scores)
{
	numget(str_num_scores);
	strcheck(str_num_scores);
	strconvert(str_num_scores, num_scores);
}

void score_instruct()
{
	std::cout << "Please enter a number between 0 and 100." << std::endl;
}


void scoreget(std::string& str_score, int qqq, int counter)
{
	std::cout << "Enter score number " << counter << ": ";
	std::cin >> str_score;
}


void scorecheck(std::string& str_score, int& qqq, int counter)
{
	for (int qqq; qqq < str_score.length(); qqq++)
	{
		while (str_score.at(qqq) < '0' || str_score.at(qqq) > '9')
		{
			score_instruct();
			scoreget(str_score, qqq, counter);
			qqq = 0;
		}
	}
}

void scoresloop(std::string& str_score)
{
	for (int qqq; qqq < num_scores; qqq++)
	{
		scoreget(str_score, qqq, counter);
		scorecheck(str_score, qqq, counter);
	   	counter++;	
	}
}

void get_scores(int num_scores, int& score, std::string& str_score)
{
	scoresloop(str_score);
}


int main()
{
	get_scores_num(num_scores, str_num_scores);
	get_scores(num_scores, score, str_score);
	return 0;
}
