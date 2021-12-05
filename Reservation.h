#ifndef RESERVATION_H
#define RESERVATION_H
/*
This header is include constructor of make reservation and all necessary properties and 
function, manage reservation.
*/
#include <iostream>
#include <string>
#include "Student.h"
#include "Room.h"
#include "Date.h"


using namespace std;

class Reservation{
    public:
         
       
        //constructor and destructor
        Reservation(const Reservation&);
        Reservation(Student*,Room*,Date&);
        //Reservation(const Reservation&);
        
        ~Reservation();

        //functions
        bool lessThan(Reservation& );
        bool overlaps(string, Date&);
        void print();
        //getter
        Student* getStudent();
        Room* getRoom();
        Date* getDate();


    private:
         Student* student;
         Room* room;
         Date* date;
};
#endif