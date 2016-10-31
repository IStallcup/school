#include "graph.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void setupNbrs2(graph &g, vector<int> vals, vector< vector<int> > listoflists)
{
	cout << "setupNbrs2" << endl;
	//vals are the index-ordered values for nodes in order of indcies
	//listoflists is the LIST OF LISTS of neighbors for each indexed node?
	vector<node> tmp_nbrs;
	int tmpll_idx = 0;
	for (int i = 0; i < g.numNodes; i++)
	{
		cout << "setting up node idx " << i << endl;
		tmpll_idx = 0;
		tmp_nbrs.clear();
		//set value appropriately
		g.nodeSet.at(i).set_val(vals.at(i));
		cout << "set val successfully" << endl;
		if (listoflists.at(i).empty())
			cout << "empty" << endl;
		else
		{
			for (int j = 0; j < listoflists.at(i).size(); j++)
			{
				cout << listoflists.at(i).at(j) << endl;
				tmp_nbrs.push_back(g.nodeSet.at(listoflists.at(i).at(j)));
			}
			g.nodeSet.at(i).set_nbrs(tmp_nbrs);
			for (int k = 0; k < 2; k++)
				cout << g.nodeSet.at(i).get_nbrs().at(k).get_idx() << endl;
		}
	}	
}

void setupNbrs1(graph &g)
{
	vector<node> nodes0;
	nodes0.push_back(g.nodeSet.at(1));
	nodes0.push_back(g.nodeSet.at(2));
	g.nodeSet.at(0).set_nbrs(nodes0);
/*in future do this elsewhere*/	g.nodeSet.at(0).set_val(14);
/*in future do this elsewhere*/	g.nodeSet.at(1).set_val(5);
/*in future do this elsewhere*/	g.nodeSet.at(2).set_val(23);
}

void setupNodes(graph &g)
{
	node tmp;
	for (int i = 0; i < g.numNodes; i++)
	{	
		tmp.set_idx(i);
		tmp.set_state(0);
		cout << "node " << i << ": " << endl;
		cout << "idx=" << tmp.get_idx() << endl;
		g.nodeSet.push_back(tmp);			
	}
}

void createFullBinTree(graph &g)
{
	setupNodes(g);
	vector<int> vals;
	vals.push_back(2);
	vals.push_back(8);
	vals.push_back(4);
	vals.push_back(5);
	vals.push_back(7);
	vector< vector<int> > listoflists;
	vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	listoflists.push_back(tmp);
	tmp.clear();
	tmp.push_back(3);
	tmp.push_back(4);
	listoflists.push_back(tmp);
	tmp.clear();
	listoflists.push_back(tmp);
	tmp.clear();
	listoflists.push_back(tmp);
	tmp.clear();
	listoflists.push_back(tmp);
//	setupNbrs1(g);
	setupNbrs2(g, vals, listoflists);
}

void printGraph(graph g)
{
	cout << "graph has " << g.numNodes << " nodes" << endl;
	for (int i = 0; i < g.numNodes; i++)
	{
		node curr = g.nodeSet.at(i);
		cout << "node " << i << endl;
		cout << "status " << curr.get_state() << endl;
		cout << "val " << curr.get_val() << endl;
		cout << "nbrs ";
		for (int j = 0; j < curr.get_nbrs().size(); j++)
		{
			cout << curr.get_nbrs().at(j).get_idx() << " "; 
		}
		cout << endl << endl;
	}
}
