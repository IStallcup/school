#include <stdlib.h>
template <class T>
class vector {
	private:
		T *v;
		int s;
	public:
   
	vector(vector<T> &other)
	{
		if (other.V)
		{
			v = other.V;
		}
		else {v = NULL;}
		s = other.s;	
	}
   
	vector()
	{
		s=0;
		v=NULL;
	}
    ~vector()
	{
		delete [] v;
     }
    int size() 
	{
		return s;
    }
    void push_back(T ele) 
	{
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