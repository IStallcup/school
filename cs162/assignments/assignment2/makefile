movies.exe: movies.o movies_main.o
	g++ movies.o movies_main.o -o movies.exe
movies.o: movies.cpp
	g++ -c movies.cpp
movies_main.o: movies_main.cpp
	g++ -c movies_main.cpp
exe: 
	rm -f *.o *.exe *.out
clean:
	rm -f *.o *.out