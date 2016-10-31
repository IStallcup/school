#include "graph.h"

#include <iostream>
#include <vector>

using namespace std;

vector<node> DFSpre(node curr, vector<node> mem)
{	
	//inspect each node as you arrive at it
	cout << "curr idx=" << curr.get_idx() << endl;
	mem.push_back(curr);
	cout << "mem now ";
	for (int i = 0; i < mem.size(); i++)
		cout << mem.at(i).get_idx() << " ";
	cout << endl;
	cout << "nbrs are ";
	for (int i = 0; i < curr.get_nbrs().size(); i++)
	{
		cout << curr.get_nbrs().at(i).get_idx() << " ";
	}
	cout << endl;
	if (!curr.get_nbrs().empty())
	{
		cout << "neighbors of " << curr.get_idx() << " are not empty" << endl;
		for (int i = 0; i < curr.get_nbrs().size(); i++)
		{
			mem = DFSpre(curr.get_nbrs().at(i),mem);
		}
	}
	else if (curr.get_nbrs().empty())
		cout << "neighbors empty" << endl;
	cout << "mem now ";
	for (int i = 0; i < mem.size(); i++)
		cout << mem.at(i).get_idx() << " ";
	cout << endl;
	return mem;
}

vector<node> DFSpost(node curr, vector<node> mem)
{	
	//inspect each node as you arrive at it
	cout << "mem now ";
	for (int i = 0; i < mem.size(); i++)
		cout << mem.at(i).get_idx() << " ";
	cout << endl;
	if (!curr.get_nbrs().empty())
	{
		cout << "neighbors are not empty" << endl;
		for (int i = 0; i < curr.get_nbrs().size(); i++)
			mem = DFSpost(curr.get_nbrs().at(i),mem);
	}
	cout << curr.get_idx() << endl;
	mem.push_back(curr);
	cout << "mem now ";
	for (int i = 0; i < mem.size(); i++)
		cout << mem.at(i).get_idx() << " ";
	cout << endl;
	return mem;
}
