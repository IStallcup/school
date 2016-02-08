rps.exe:main.o game.o tools.o rps.o
	g++ main.o game.o tools.o rps.o -o rps.exe
main.o:main.cpp
	g++ -c main.cpp
game.o:game.cpp
	g++ -c game.cpp
tools.o:tools.cpp
	g++ -c tools.cpp
rps.o:rps.cpp
	g++ -c rps.cpp
clean:
	rm -f *.o *.exe