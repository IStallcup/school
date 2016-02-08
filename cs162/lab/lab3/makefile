hospital.exe: hospital_main.o pharmacy.o surgery.o patientaccount.o
	g++ hospital_main.o pharmacy.o surgery.o patientaccount.o -o hospital.exe
hospital_main.o: hospital_main.cpp
	g++ -c hospital_main.cpp
pharmacy.o: pharmacy.cpp
	g++ -c pharmacy.cpp
surgery.o: surgery.cpp
	g++ -c surgery.cpp
patientaccount.o: patientaccount.cpp
	g++ -c patientaccount.cpp
clean:
	rm -f *.out *.o *.exe