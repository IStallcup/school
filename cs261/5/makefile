default: prog 

ListDeque.o: ListDeque.c ListDeque.h type.h
	gcc -Wall -ansi -c ListDeque.c

HashMap.o: HashMap.c HashMap.h
	gcc -Wall -g -ansi -c HashMap.c

prog: HashMap.o ListDeque.o main2.c
	gcc -Wall -ansi -g -o prog HashMap.o ListDeque.o main2.c

clean:
	rm HashMap.o
	rm ListDeque.o

cleanall: clean
	rm prog