all: lab clean

CC = g++
exe_file = lab
$(exe_file): lab.o prog.o
	$(CC) lab.o prog.o -o $(exe_file)
mult_div.o: lab.cpp
	$(CC) -c lab.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
clean:
	rm -f *.out *.o