ass1.exe: ass1.o play_ass1.o
	g++ ass1.o play_ass1.o -o ass1.exe
ass1.o: ass1.cpp
	g++ -c ass1.cpp
play_ass1.o: play_ass1.cpp
	g++ -c play_ass1.cpp
clean:
	rm -f *.o *.out *.exe