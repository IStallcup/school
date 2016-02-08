Date.exe: main.o Date.o
	g++ main.o Date.o -o Date.exe
main.o: main.cpp
	g++ -c main.cpp
Date.o: Date.cpp
	g++ -c Date.cpp

clean:
	rm -f *.o