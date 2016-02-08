netflix.exe: main.o netflix.o movie.o search_mov.o get_mov.o
	g++ main.o netflix.o movie.o search_mov.o get_mov.o -o netflix.exe
main.o: main.cpp
	g++ -c main.cpp	
netflix.o: netflix.cpp
	g++ -c netflix.cpp
movie.o: movie.cpp
	g++ -c movie.cpp
search_mov.o: search_mov.cpp
	g++ -c search_mov.cpp
get_mov.o: get_mov.cpp
	g++ -c get_mov.cpp
clean:
	rm -f *.o *.exe