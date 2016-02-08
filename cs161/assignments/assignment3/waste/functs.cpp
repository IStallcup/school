#include <iostream>
#include <cstdl>
#include <string>



using namespace std;

void check_str_tests(string& strntests)
{
	int q = 0;
	while (strntests == "0")
	{
		cout << "Please enter a non-zero number: ";
		cin >> strntests;
	}
	while (q < strntests.length())
	{
		if (strntests.at(q) < '0' || strntests.at(q) > '9')
		{
			cout << "please enter a whole positive number:";
			cin >> strntests;			
			while (strntests == "0")
			{
				cout << "Please enter a non-zero number: ";
				cin >> strntests;
			}
		}
		else (q++);
	}
}


void ntestscon(string strntests, int& ntests)
{
	if (strntests != "0")
		ntests = atoi(strntests.c_str());
}

int get_num_tests(int& ntests)
{
	string strntests;
	cin >> strntests;
	check_str_tests(strntests);
	ntestscon(strntests, ntests);
	return ntests;
}


void sizecheck(int& score)
{
	while (score < 0 || score > 100)
	{
		std::cout << "enter a number between 1 and 100: ";
	}
}

void strscorecon(string strscore, int& score)
{
	score = atoi(strscore.c_str());
}

void strcheck(string& strscore, int& score)
{
	for (int j = 0; j < strscore.length(); j++)
	{
		while (strscore.at(j) < '0' || strscore.at(j) > '9')
		{
			cin >> strscore;
			j =  0;
		}
		strscorecon(strscore, score);
		sizecheck(score);
	}
}

void get_scores(int ntests, int& sumscores, int score)
{
	string strscore;
	std::cin >> strscore;
	strcheck(strscore, score);
	cout << strscore;
}

void avg_scores(int ntests, int sumscores, int score)
{
	int u = 0;
	while (u < ntests)
	{
		get_scores(ntests, sumscores, score); 
		u++;
	}
int main()
{
	int ntests;
	ntests = get_num_tests(ntests);
	int sumscores, score;
	avg_scores(ntests, sumscores, score);
	return 0;
}




