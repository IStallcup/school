#include "./netflix.h"
//#include "./movie.h"
#include <iostream>
#include <fstream>

using namespace std;
using std::fstream;
using std::ios;

int get_sel()
{
	int t;
	cout << "What term would you like to parse?" << endl;
	cout << "1-Name 2-Stars 3-Cast 4-Rating" << endl;	
	cin >> t;
	cin.clear();
	return t;
}

int main()
{
	int select = -1;
	
		while (select > -2)
		{
			cout << "What would you like to do?" << endl;
			cout << "1-Add Movie 2-Search Movies 0-Exit" << endl;
			cin >> select;
			if (select == 1)
			{
				movie_input();
			}
			if (select == 2)
			{
				search_movies();
			}
			if (select == 0)
				break;
			
	}
	return 0;
}