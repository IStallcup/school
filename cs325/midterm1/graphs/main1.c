#include "graph.h"
#include "defs.h"
#include <iostream>

using namespace std;

int main()
{
	graph G;
	G.numNodes = 5;
	createFullBinTree(G);
	printGraph(G);

	vector<node> mem;

	cout << "dfs_pre" << endl;
	mem = DFSpre(G.nodeSet.at(0), mem);
	cout << "post dfs_pre" << endl;
	cout << "pre-order squence list:";
	for (int i = 0; i < mem.size(); i++)
		cout << mem.at(i).get_idx() << " ";
	cout << endl;
	
	mem.clear();

	cout << "dfs_post" << endl;
	mem = DFSpost(G.nodeSet.at(0), mem);
	cout << "post dfs_post" << endl;
	cout << "post-order squence list:";
	for (int i = 0; i < mem.size(); i++)
		cout << mem.at(i).get_idx() << " ";
	cout << endl;
	return 0;
}

