#include <iostream>

#include "Date.h"
#include "Library.h"
#include "Reservation.h"
#include "a1-global.cc"
#include "Room.h"
#include "Student.h"

using namespace std;

int main(){
    //different days
    Date d1(2020,1,23,9,3);
    Date d2(2020,1,24,9,3);
    testDate(d1,d2,false);
    //different hour 
    Date d3(2020,1,23,12,3);
    Date d4(2020,1,23,9,2);
    testDate(d3,d4,false);
     //different hour 2
    Date d5(2020,1,23,10,3);
    Date d6(2020,1,23,9,1);
    testDate(d5,d6,false);
    //different hour 3
    Date d7(2020,1,23,10,3);
    Date d8(2020,1,23,9,2);
    testDate(d7,d8,true);

    //different hour 4
    Date d9(2020,1,23,9,2);
    Date d10(2020,1,23,9,2);
    testDate(d9,d10,true);

    //test add room
    //Library *li = new Library();
    //not allocate in heap 
    Library li;
    populate(li);
    //line();
    testReservations(li);
    //delete li;
}

