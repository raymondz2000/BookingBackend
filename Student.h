#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
/*
This header is include constructor of student and all necessary properties and 
comparing function for student and add student
*/
using namespace std;

class Student {
    public:
        //Student constructor
        Student();
        
        //constructor
        Student(string name, string number);
        //copy of constructor
        Student(const Student&);
        /* --------------------------------- setter --------------------------------- */

        void setname(string);
        void setnumber(string);
        void setstudent(string,string);

        //getter
        string getname();
        string getnumber();

        //function 
        bool lessThan(Student& s);
        //not necessary
        void print();
    
        
    private:
        //variable 
        string name;
        string number;
};
		
#endif