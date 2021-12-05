A1
Authour: Raymond Zhu
Student#: 101158903


A1 PROGRAM: Similar to hotel backend manage system, add student, add room, add date, check overlap
during make reservation, check room exixt or not, anyone occupy the room? and then make a decision they 
can reserve or not, and print out

P.S: dynamically allocated is done, sorted is done , update is partially done (figure it out which day should be remove)
to avoid complier warning, i put -std=c++11 in make file is fine.

list of file:
Makefile
main.cc
a1-global.cc
Date.cc
Date.h
Library.cc
Library.h
Reservation.cc
Reservation.h
Room.cc
Room.h
Student.cc
Student.h



compile: make
run: ./a1
run with valgrind: 
valgrind --leak-check=yes --track-origins=yes -s --dsymutil=yes  ./a1 
valgrind --leak-check=full  --track-origins=yes -s --dsymutil=yes  --show-leak-kinds=all ./a1 
or
valgrind --leak-check=yes ./a1
clean: make clean 