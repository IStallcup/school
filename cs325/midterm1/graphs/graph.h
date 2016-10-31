#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class node {
	private:
		int idx;   //identifier for the node
		int state; //0 = inactive, 1 = active, 2 = sorted? think on this
		int val;	//value of the node
		vector<node> nbrs; //array of indices of child nodes
	public:
		void set_idx(int);
		int get_idx();
		
		void set_val(int);
		int get_val();

		void set_state(int);
		int get_state();

		void set_nbrs(vector<node>);
		vector<node> get_nbrs();
};

class graph {
	public:
		int numEdges;
		int numNodes;	
		vector<node> nodeSet;
};

//be careful with pointer witchery!
void createFullBinTree(graph &g);

void setupNodes(graph &g);

void printGraph(graph g);

#endif
