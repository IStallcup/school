default: 1

node.o: node.c graph.h
	g++ -c node.c

graph.o: node.o graph.c
	g++ -c graph.c

dfs.o: graph.o dfs.c
	g++ -c dfs.c

1: graph.o node.o dfs.o main1.c 
	g++ graph.o node.o dfs.o main1.c -o 1
