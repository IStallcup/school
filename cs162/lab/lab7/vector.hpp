#include <stdlib.h>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
template <class T>
class vector {
   private:
      T *v;
      int s;
	  int c;
   public:
   T operator[] (int i)
   {
	return v[i];
   }
   T at(int i)
   {
	/*try
	{
	std::cout << "try block" << std::endl;
	std::cout << "in block:" << v[i] << std::endl;
	}
	catch(const std::out_of_range& e){std::cout << "ERROR" << std::endl;}*/
	if (i >= s)
	{
		std::cout << "ERROR" << std::endl;
		exit(0);
	}
	else return v[i];
   }
   void resize()
   {
	
	T *temp;
	temp = new T[c];
	for (int  i = 0; i < c; i++)
	{
		temp[i] = v[i];	
	}
	delete [] v;
	v = new T[2*c];
	for (int  i = 0; i < c; i++)
	{
		v[i]=temp[i];
	}
	c *= 2;
	delete [] temp;
   }
   
   vector(int vecsize)
   {
	s = vecsize;
	v = new T[s];
	c = vecsize;
   }
   void operator=(vector<T> &other)
   {
	delete [] v;
	s = other.size();
	c = other.cap(); //added from capacity
	v = new T[s];
	for (int i = 0; i < s; i++)
	{
		v[i] = other.v[i];
	}
   }
	vector(vector<T> &other)
	{
		s = other.size();
		//added from capacity
		c = other.cap();
		v = new T[s];
		for (int i = 0; i < s; i++)
		{
			v[i] = other.v[i];
		}
	}
      vector(){
	 s=0;
	 v=NULL;
	 //added from capacity
	 c=1;
      }
      ~vector(){
	 delete [] v;
      }
      int size() {
	 return s;
      }
	  int cap() //added from capacity
	  {
		return c;
	  }
      void push_back(T ele) {
	 T *temp;
	 temp = new T[s];
	 for(int i=0; i<s-1; i++)
	    temp[i]=v[i];

	 delete [] v;
	 s++;
	 v = new T[s];

	 for(int i=0; i<s-1; i++)
	    v[i]=temp[i];

	 v[s-1]=ele;
	 delete [] temp;
      }
};