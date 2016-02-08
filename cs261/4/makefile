default: bst 

BST.o: BST.c BST.h type.h
	gcc -Wall -ansi -c BST.c

bst: BST.o main.c
	gcc -Wall -ansi -lm -o bst BST.o main.c

clean:
	rm BST.o

cleanall: clean
	rm bst