#ifndef ROOM_H
#define ROOM_H
/*
This header is include constructor of room and all necessary properties and 
comparing function for create and add the room
*/
#include <iostream>
#include <string>

using namespace std;

class Room {
    public:
       
        Room();
        //constructor
        Room (string name, int capacity,int computers,bool whiteboard);

        //copy constructor
        Room (const Room&);

        //setter
        void setroom_name (string);
        void setroom_capacity (int );
        void setroom_computer (int );
        void setroom_hasWhiteboard (bool );
        void setroom (string ,int ,int , bool );
        void setroom(Room&);

        //getter

        string getroom_name ();
        int getroom_capacity();
        int getroom_computer();
        bool hasWhiteboard ();

        //function
        bool meetsCriteria (int capacity, int computers, bool whiteboard);
        bool lessThan (Room& r);
        void print();
    private:
        string name;
        int capacity;
        int computers;
        bool whiteboard;

};
		
#endif