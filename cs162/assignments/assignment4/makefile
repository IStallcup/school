roomba.exe: main.o roomba.o
	g++ main.o roomba.o -o roomba.exe
main.o: main.cpp
	g++ -c main.cpp
roomba.o: roomba.cpp
	g++ -c roomba.cpp
clean:
	rm -f *.o *.exe