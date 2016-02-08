rps.exe: main.o tools.o game.o play.o
	g++ main.o tools.o game.o play.o -o rps.exe
main.o: main.cpp
	g++ -c main.cpp
tools.o: tools.cpp
	g++ -c tools.cpp
game.o:game.cpp
	g++ -c game.cpp
play.o:play.cpp
	g++ -c play.cpp
clean:
	rm -f *.o *.exe