#ifndef LIBRARY_H
#define LIBRARY_H
/*
This header is include constructor of library, function of add student,room and test 
room avaliable and make reservation
*/
#include <iostream>
#include <string>
#include "Student.h"
#include "Room.h"
#include "Reservation.h"
#include "Date.h"

using namespace std;

class Library {
    public:
        //constructor
        Library ();
        //destructor
        ~Library ();
         
        
        bool addStudent(const string& name, const string& number);
        bool addRoom(string name, int capacity =1,int computers=0,bool whiteboard= false);
        bool getStudent(const string& name, Student** student);
        bool getRoom(const string& roomName, Room** room);
        bool isFree(const string& room, Date&);

        bool makeReservation(const string& student, const string& room, Date&);
        void update(Date&);
        void printReservations();
        
    private:
        Student** student_array;
        Room* room_array[100];
        Reservation** reservation_array;
         
         

};
#endif