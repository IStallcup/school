#include <iostream>
#include <cstring>

using namespace std;

int show_arg(char *argv[], int i)
{
	if (i == 0)
	{
		return 0;
	}
	--i;
	cout << i << ": " << argv[i] << endl;
	return show_arg(argv, i);
}

int show_array(char *x[], int i)
{

	if (i == 0)
	{
		return 0;
	}
	--i;
	cout << i << ": " << *x[i] << endl;
	return show_array(x, i);
}

int set_array(char *x[], int i, char* argv[])
{

	if (i == 0)
	{
		return 0;
	}
	--i;
	*x[i] = *argv[i];
	return set_array(x, i, argv);
}

char str_scan(char *argv[], char *appended[])
{
	cout << *argv[2] << endl;
	*appended = strcpy(*appended, *argv);	
	cout << *appended << endl;
	char look[]= "lqfa";
	int leng = strcspn(*appended, look);
	cout << "l: " << leng << endl;
	strncat(*appended, *appended, leng);
	cout << *appended << endl;
	return **appended;
}

int check_arg(int argc, char *argv[], int i)
{
	if (i == 0)
		return 0;
	--i;
	if (*argv[i] == '-')
	{
		cout << "- found at position " << i << endl;
		cout << "type: " << endl;
		cout << "following char: " << argv[i+1] << endl;
	}
	return check_arg(argc, argv, i);
}

char check_string(char *argv[], int i, char *appended[])
{
	if (i == 0)
		return 'D';
	--i;
	cout << "i: " << i << endl;
	char look[] = "tsfqa";
	int leng = strcspn(*appended, look);
	if (leng == i)
	{
		cout << *appended[i] << endl;
	}
	//strncat(*appended, *appended, leng);
	//cout << *appended << endl;

	/*if (*argv[i] == '0')
	{
		cout << i << endl;
		cout << argv[i] << endl;
	}*/
	return check_string(argv, i, appended);
}


//contents of argv -> num_scores, but not ordered
int check_args_new(char *argv[], int i, char *num_scores, int j)
{
	for (int q = i - 1; q > 0; q--)
	{
		if (*argv[q] == *"-" && q != (i - 1))
		{
			cout << argv[q] << "=" << argv[q+1] << endl;
			num_scores[j] = *argv[q+1];
			cout << num_scores[j] << endl;
			j++;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int i = argc;
	show_arg(argv, i);
	char num_scores[5] = {NULL};
	int j = 0;
	check_args_new(argv, i, &*num_scores, j);
//	char *appended = new char [argc];
//	show_array(&appended, i);
//	cout << check_string(argv, i, &appended) << endl;
//	cout <<	str_scan(argv, appended) << endl;
//	check_arg(argc, argv, i);
}
