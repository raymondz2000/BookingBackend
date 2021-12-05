#include "Room.h"

//constructor
Room::Room(){
    setroom("1",1,1,false);
}

Room::Room(string room_name, int room_capacity = 1,int room_computers =0,bool room_haswhiteboard = false){
    setroom(room_name, room_capacity, room_computers,room_haswhiteboard);
}
Room::Room(const Room& r){
    setroom(r.name,r.capacity,r.computers,r.whiteboard);
}

//setter
void Room::setroom_name(string room_name){
    name = room_name;
}
void Room::setroom_capacity(int room_capacity){
    capacity = room_capacity;
}
void Room::setroom_computer(int room_computers){
    computers = room_computers;
}
void Room::setroom_hasWhiteboard(bool room_haswhiteboard){
    whiteboard = room_haswhiteboard;
}
void Room::setroom(string room_name,int room_capacity,int room_computers,bool room_haswhiteboard){
    setroom_name(room_name);
    setroom_capacity(room_capacity);
    setroom_computer(room_computers);
    setroom_hasWhiteboard(room_haswhiteboard);
}
void Room::setroom(Room& r){
	setroom(r.name,r.capacity,r.computers,r.whiteboard);
}
//getter

string Room::getroom_name(){return name;}
int Room::getroom_capacity(){return capacity;}
int Room::getroom_computer(){return computers;}
bool Room:: hasWhiteboard (){return whiteboard;}

//functions 
bool Room::meetsCriteria(int room_capacity = 1 ,int room_comuters = 1, bool room_whiteboard=false){
    bool meetwhiteboard;
    
    //cout <<"in meet function "<<(this->capacity >= room_capacity) <<(this->computers>= room_comuters)<<(this->whiteboard)<<"in value room is "<<room_whiteboard<<endl;

    if((this->whiteboard== true && room_whiteboard==true)||(this->whiteboard== false && room_whiteboard==false)){
       meetwhiteboard = true;
    }
    else if (this->whiteboard== true && room_whiteboard == false){
        meetwhiteboard = true;
    }
    else if (this->whiteboard== false && room_whiteboard == true){
        meetwhiteboard = false;
    }
    if((this->capacity >= room_capacity) && (this->computers>= room_comuters) && meetwhiteboard ) {
        //cout <<"in meet function room whiteboard "<<" yes "<<endl;
        return true;
    }
    else{
        return false;
    }
    
}

bool Room::lessThan(Room& r){
    if(this->name<r.getroom_name()){
        return true;
    }
    else{
        return false;
    }
}

void Room:: print(){
    if(hasWhiteboard()==1){
        cout <<"Room name: "<<name<<","<<" Room capacity: "<<capacity<<","<<"Room computers: "<<computers<<", room with NO Whiteboard"<<endl;
    }
    else{
         cout <<"Room name: "<<name<<","<<" Room capacity: "<<capacity<<","<<"Room computers: "<<computers<<", room with Whiteboard"<<endl;
    }
}
