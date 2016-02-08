default: prog 

ListDeque.o: ListDeque.c ListDeque.h type.h
	gcc -Wall -ansi -c ListDeque.c

graph.o: graph.h graph.c ListDeque.o
	gcc -Wall -ansi -c graph.c

prog: graph.o ListDeque.o main.c
	gcc -Wall -ansi -o prog graph.o ListDeque.o main.c
	
graph_josh.o: graph.h graph_josh.c ListDeque.o
	gcc -Wall -ansi -c graph_josh.c
	
josh: graph_josh.o ListDeque.o main.c
	gcc -Wall -ansi -o prog graph_josh.o ListDeque.o main.c

clean:
	rm ListDeque.o
	rm graph.o

cleanall: clean
	rm prog 