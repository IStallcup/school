rps.exe: main.o rock.o paper.o scissors.o game.o
	g++ main.o game.o paper.o -o rps.exe
main.o: main.cpp
	g++ -c main.cpp
rock.o: rock.cpp
	g++ -c rock.cpp
paper.o: paper.cpp
	g++ -c paper.cpp
scissors.o: scissors.cpp
	g++ -c scissors.cpp
game.o: game.cpp
	g++ -c game.cpp
clean:
	rm -f *.o *.exe *.out