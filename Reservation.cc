#include "Reservation.h"


Reservation::Reservation(Student* s,Room* r , Date& d){
    student = s;
    room = r;
    date = &d;
}
Reservation::Reservation(const Reservation& res){
    student = res.student;
    room = res.room;
    date = res.date;
}

Reservation::~Reservation() {
    //befareful
    // cout<<"Reservationdete"<<endl;
    //delete &student;
     
}
Student* Reservation::getStudent(){return student;}
Room* Reservation::getRoom(){return room;}
Date* Reservation::getDate(){return date;}

bool Reservation::lessThan(Reservation& res){
    if(this->getDate()->lessThan(*res.getDate())){
        return true;
    }else{
        return false;
    }
}

bool Reservation::overlaps(string r,Date& d){

    if((this->getRoom()->getroom_name() == r))
        { 
            return d.overlaps(*this->getDate());
        }
    else{
        return false;
    }
}



void Reservation::print(){

    cout<<"Reservation for:";
    this->student->print();
    cout<< "On Date:";
    this->date->print();
    cout<<"With Room requested: ";
    this->room->print();
    
}
 
    
