netflix.exe: main.o netflix.o movie.o
	g++ main.o netflix.o movie.o -o netflix.exe
netflix.o: netflix.cpp
	g++ -c netflix.cpp
movie.o: movie.cpp
	g++ -c movie.cpp
clean:
	rm -f *.o *.exe