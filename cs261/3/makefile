default: prog 

ListDeque.o: ListDeque.c ListDeque.h type.h c_unit.h
	gcc -Wall -ansi -c ListDeque.c
	
unitTests.o: unitTests.c c_unit.h ListDeque.h
	gcc -Wall -ansi -c unitTests.c

prog: ListDeque.o unitTests.o main.c
	gcc -Wall -ansi -o prog ListDeque.o unitTests.o main.c

clean:
	rm ListDeque.o unitTests.o

cleanall: clean
	rm prog