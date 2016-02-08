#include <iostream>
#include <string.h>

using namespace std;




int tree(char *argv[], int i)
{
	char key[4] = "tlqaf";
	cout << "strncmp value: " << endl;
	cout <<	strncmp (argv, key) << endl;

/*	if (argv[i] == "-t")
		return 0;
	if (argv[i] == "-q")
		return 1;
	if (argv[i] == "-a")
		return 2;
	if (argv[i] == "-l")
		return 3;
	if (argv[i] == "-f")
		return 4;
	cout << "Error" << endl;
	return 5;*/
}

int check_arg(char *argv[], char num_scores[], int i)
{
	cout << "checking argument..." << endl;
	if (i==0)
		return 0;
	--i;

	if (*argv[i] == '-')
	{
		cout << "found" << endl;
		cout << argv[i] << endl;
		if (argv[i] == "t")
		{
			cout << "test" << endl;
		}
//		int q = tree(argv, i);
//		if (q ==5)
//			return 0;
//		num_scores[q] = *argv[i+1];
//		cout << q << ": " << num_scores[q] << endl;
	}
	return check_arg(argv, num_scores, i);
}

int show_arg(char *argv[], int i)
{
	if (i==0)
		return 0;
	--i;

	cout << i << ": " << argv[i] << endl;
	return show_arg(argv, i);
}

int main(int argc, char *argv[])
{
	int i = argc;
	char num_scores[5];
	cout << "args: " << argc << endl;
	show_arg(argv, i);
	check_arg(argv, num_scores, i);
}
