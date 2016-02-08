#include <iostream>
#include <string>

using namespace std;


void wordcount(string array_string)
{
	int word_count = 1;
	for (int i = 0; i < array_string.length(); i++)
	{
		//cout << array_string.at(i) << endl;
		if (array_string.at(i) == ' ')
		{
			word_count++;
		}
	}
	cout << "there are " << word_count << " words" << endl;
	
}

void lettercount(int array_size, char *array)
{
	int letter_count = 0;
	
	for (int k = 0; k < array_size; k++)
	{
		for (int y = 0; y < array_size; y++)
		{
			if (array[k] == array[y])
			{
				//cout << "found repeated char " << array[k] << endl;
				letter_count++;
			}
			
		}
		cout << "found " << letter_count << " of char " << array[k] << endl;
		letter_count = 0;
	}
}

void letter_string(string array_string)
{
	int letter_count = 0;
	
	for (int l = 0; l < array_string.length(); l++)
	{
		for (int m = 0; m < (array_string.length()); m++)
		{
			if (array_string.at(l) == array_string.at(m))
			{
				letter_count++;
			}
		}
		cout << "There are " << letter_count << " occurrences of character " << array_string.at(l) << endl;
		letter_count = 0;
	}
}

int main()
{
	cout << "Please enter the size of the array" << endl;
	int array_size;
	cin >> array_size;
	cin.ignore();
	cout << "Please enter your sentence: " << endl;
	string array_string;
	getline(cin, array_string);
	wordcount(array_string);
	char *array;
	array = new char[array_size];
	for (int a = 0; a < array_string.length(); a++)
	{
		array[a] = array_string.at(a);
	}
	lettercount(array_size, array);
	return 0;
}