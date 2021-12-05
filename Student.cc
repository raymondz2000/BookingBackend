#include "Student.h"
#include <iostream>
#include <string>

 
Student::Student(){
    setstudent("raymond","101158903");
}

Student::Student(string student_name, string student_number){
    setstudent(student_name,student_number);
}
Student::Student(const Student& s){
    setstudent(s.name,s.number);
}

//setter 
void Student::setstudent(string student_name, string student_number){
    name = student_name;
    number = student_number;
}
void Student::setname(string student_name){
    name = student_name;
}
void Student::setnumber(string student_number){
    number = student_number;
}

//getter

string Student::getname(){
    return name;
}
string Student::getnumber(){
    return number;
}
//function
bool Student::lessThan(Student & s){
    if((this->name < s.getname())){
        return true;
    }
    else{
        return false;
    }
}

void Student::print(){
	cout <<"Student Name: " <<getname()<<" ,Student Number :"<<getnumber()<<endl;
}

