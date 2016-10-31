#include "graph.h"

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void node::set_idx(int input_idx)
{
	idx = input_idx;	
}

int node::get_idx()
{
	return idx;
}

void node::set_val(int input_val)
{
	val = input_val;	
}

int node::get_val()
{
	return val;
}

void node::set_state(int input_state)
{
	state = input_state;
}

int node::get_state()
{
	return state;
}

void node::set_nbrs(vector<node> input_nbrs)
{
	nbrs = input_nbrs; //vector has operator= defined
}

vector<node> node::get_nbrs()
{
	return nbrs;
}
