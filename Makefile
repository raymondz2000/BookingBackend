objects = main.o Student.o Date.o Room.o Reservation.o Library.o

a1: $(objects)
	g++ -std=c++11  -o a1 $(objects)

main.o: main.cc Student.h Date.h Room.h Reservation.h Library.h a1-global.cc
	g++ -std=c++11  -c main.cc 

Library.o: Library.h Reservation.h Room.h Date.h Student.h Library.cc
	g++ -std=c++11  -c Library.cc

Reservation.o:	Reservation.h Room.h Date.h Student.h Reservation.cc
	g++ -std=c++11  -c Reservation.cc

Room.o: Room.h Room.cc
	g++ -std=c++11  -c Room.cc
	
Date.o:	Date.h Date.cc
	g++ -std=c++11  -c Date.cc
	
Student.o:	Student.h Student.cc
	g++ -std=c++11  -c Student.cc

clean:
	rm -f  *.o	a1 