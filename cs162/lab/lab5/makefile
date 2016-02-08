v.exe: main.o vehicle.o bike.o motorcycle.o skateboard.o car.o date.o
	g++ main.o vehicle.o bike.o motorcycle.o skateboard.o car.o date.o -o v.exe
main.o: main.cpp
	g++ -c main.cpp
vehicle.o: vehicle.cpp
	g++ -c vehicle.cpp
bike.o: bike.cpp
	g++ -c bike.cpp	
motorcycle.o: motorcycle.cpp
	g++ -c motorcycle.cpp
skateboard.o: skateboard.cpp
	g++ -c skateboard.cpp
car.o: car.cpp
	g++ -c car.cpp
date.o:
	
clean:
	rm -f *.o *.exe