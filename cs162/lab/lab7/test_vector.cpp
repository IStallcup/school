#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either stmt. We wouldn't 
//be able to compare our vector template to the Standard 
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

void do_things(vector<int> v)
{	
	v.resize();
	cout << v.cap() << endl;
}



int main (){
   vector<int> v;   //Our vector class
   std::vector<int> stdv; //Standard vector
	vector<int> q;
	v = q;
	
   //Compare operation of our vector to std
   v.push_back(23);
   stdv.push_back(23);
   stdv.push_back(32);
   stdv.push_back(64);
   
	cout << v.size() << endl;
	do_things(v);
	cout << v.size() << endl;
	
	cout << v[0] << endl;
	cout << v.at(0) << endl;
	std::vector<int>::iterator i; //vector iterator
	i = stdv.begin();
	cout << "Forward" << endl;
	for (int j = 0; j < stdv.size(); j++)
	{
		cout << "The contente of element: " << *i << endl;
		i++;
	}
	i = stdv.end();
	cout << "Reverse" << endl;
	i--;
	for (int q = stdv.size(); q > 0; q--)
	{
		cout << "The contents of element: " << *i << endl;
		i--;
	}
		
	
	
	cout << v.at(200) << endl;
	
	
	
   return 0;
}
